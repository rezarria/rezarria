#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>



/*
	struct TIME bao gồm 3 biến uint64_t hour, minute, second
	coi struct này là thời gian có giờ phút giây số nguyên
	
	struct MGR bao gồm 2 biến uint64_t n và TIME_P *time
	coi struct này là cặp tài liệu vì TIME được lưu dưới dạng danh sách địa chỉ (TIME**) chứa không phải một mảng thống nhất liên tục
*/

typedef struct TIME_S
{
	uint64_t hour, minute, second;
} TIME;
typedef TIME* TIME_P;

typedef struct LIST_S
{
	uint64_t n;
	TIME_P* time;
} MGR;
typedef MGR* MGR_P;

MGR_P createMgr();
TIME_P createTime(uint64_t hour, uint64_t minute, uint64_t second);
MGR_P createTimeInMgr(MGR_P mgr);
MGR_P importMgr(MGR_P mgr);
MGR_P sortTime(MGR_P mgr);
MGR_P displayMgr(MGR_P mgr);
void fixTime(TIME_P time);
void sortUint64PP(uint64_t** begin, uint64_t** end, uint64_t step);
/*
	MGR_P	createMgr();
		Trả về con trỏ trỏ tới MGR trống
	TIME_P	createTime(uint64_t hour, uint64_t minute, uint64_t second);
		Trả về con trỏ trỏ tới TIME đã có giá trị được sửa lại từ các input
	MGR_P	createTimeInMgr(MGR_P mgr);
		Tạo n TIME vào vào mgr và trả con trỏ chính là mgr ra
	MGR_P	importMgr(MGR_P mgr);
		Nhập thông tin của các TIME trong mgr và trả con trỏ chính là mgr ra
	MGR_P	sortTime(MGR_P mgr);
		Sắp xêp lại TIME theo thứ tự tăng dần trong mgr và trả con trỏ chính là mgr ra
	MGR_P	displayMgr(MGR_P mgr);
		Hiện thị các TIME trong mgr và trả con trỏ chính là mgr ra
	void	fixTime(TIME_P time);
		Sửa lại thời gian trong time theo đúng quy luật
	void	sortUint64PP(uint64_t** begin, uint64_t** end, uint64_t step);
		Sắp xếp lại danh sách của các khối mảng uint64
		thay vì hoán đổi giá trị thì hoán đổi thứ tự địa chỉ của các khối mảng trong danh sách
*/
int main()
{
	displayMgr(sortTime(displayMgr(importMgr(createTimeInMgr(createMgr())))));
	return EXIT_SUCCESS;
}

MGR_P createMgr()
{
	return (MGR_P)calloc(1llu, sizeof(MGR));
}

TIME_P createTime(uint64_t hour, uint64_t minute, uint64_t second)
{
	TIME_P time = (TIME_P)calloc(1llu, sizeof(TIME));
	time->hour = hour;
	time->minute = minute;
	time->second = second;
	fixTime(time);
	return time;
}

void fixTime(TIME_P time)
{
	if (time->second > 59llu)
	{
		time->minute += time->second / 60llu;
		time->second %= 60llu;
	}
	if (time->minute > 59llu)
	{
		time->hour += time->minute / 60llu;
		time->minute %= 60llu;
	}
}

MGR_P createTimeInMgr(MGR_P mgr)
{
	printf("Nhap so thoi gian can nhap : ");
	scanf_s("%llu", &mgr->n);
	mgr->time = (TIME_P*)calloc(mgr->n, sizeof(TIME_P));
	return mgr;
}

MGR_P importMgr(MGR_P mgr)
{
	uint64_t hour, minute, second;
	for (uint64_t i = 0llu; i < mgr->n; i++)
	{
		printf("Nhap thoi gian thu %llu\n", i);
		printf("Gio\t:\t");
		scanf_s("%llu", &hour);
		printf("Phut\t:\t");
		scanf_s("%llu", &minute);
		printf("Giay\t:\t");
		scanf_s("%llu", &second);
		mgr->time[i] = createTime(hour, minute, second);
	}
	return mgr;
}

MGR_P sortTime(MGR_P mgr)
{
	uint64_t i = 3llu;
	do
	{
		i--;
		sortUint64PP((uint64_t**)mgr->time, (uint64_t**)mgr->time + mgr->n - 1llu, i);
	} while (i);
	return mgr;
}

MGR_P displayMgr(MGR_P mgr)
{
	printf("\n----------------------\n");
	for (uint64_t i = 0llu; i < mgr->n; i++)
	{
		TIME_P time = mgr->time[i];
		printf("Thoi gian %4llu\t:\t%05llu:%02llu:%02llu\n", i, time->hour, time->minute, time->second);
	}
	return mgr;
}

void sortUint64PP(uint64_t** begin, uint64_t** end, uint64_t step)
{
	uint64_t** p = begin;
	uint64_t n = end - begin;
	for (uint64_t i = 0llu; i < n; i++)
		for (uint64_t j = i + 1llu; j < n + 1llu; j++)
			if (p[i][step] > p[j][step])
			{
				p[i] = (uint64_t*)((size_t)p[i] ^ (size_t)p[j]);
				p[j] = (uint64_t*)((size_t)p[i] ^ (size_t)p[j]);
				p[i] = (uint64_t*)((size_t)p[i] ^ (size_t)p[j]);
			}
}
