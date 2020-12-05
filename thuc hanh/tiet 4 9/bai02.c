#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define __max_length_of_name 256
#define __max_number_of_score 3

/*
    Khai báo các struct và các typedef
    Có 3 struct     RECORD,     MGR,    REPORT
    Có 3 typedef    RECORD_P,   MGR_P,  REPORT_P

    RECORD      :   Dùng để chứa các thông tin của sinh viên
    RECORD_P    :   Là con trỏ của RECORD

    MGR         :   Dùng để chứa RECORD bằng RECORD_P
    MGR_P       :   Là con trỏ của MGR

    REPORT      :   Dùng để chứa các kết quả là các RECORD phù hợp sau khi lọc RECORD trong MGR
                    Dùng trỏ của RECORD_P để lưu lại địa chỉ, thay vì tạo mới gây tốn tài nguyên
    REPORT_P    :   Là con trỏ của REPORT
*/
typedef struct INFO_S
{
    uint64_t idStudent;
    char* name[__max_length_of_name];
    uint32_t dob[3];
    char* sex[__max_length_of_name];
    float score[__max_number_of_score];
    float t;
} RECORD;
typedef RECORD* RECORD_P;

typedef struct LIST_S
{
    uint64_t n;
    RECORD_P record;
} MGR;
typedef MGR* MGR_P;

typedef struct REPORT_S
{
    uint64_t n;
    RECORD_P* record;
} REPORT;
typedef REPORT* REPORT_P;

/*
----------------Các hàm tạo struct
    MGR_P       taoMgr          ()                      Tạo một MGR và xuất địa chỉ ra
    MGR_P       taoRecord       (MGR_P)                 Tạo một n (theo người dùng) RECORD vào MGR_P của input và xuất MGR_P của input ra
    REPORT_P    taoReport       ()                      Tạo một REPORT được REPORT_P xuất ra trỏ tới
----------------Các hàm nhập, nạp dữ liệu vàoo struct
    MGR_P       nhapThongTin    (MGR_P)                 Nhập các thông tin vào các RECORD của MGR_P của input và xuất MGR_P của input ra
    void        napReport       (REPORT_P, RECORD_P)    Dùng để nạp RECORD của input vào REPORT của input
----------------Các hàm lọc struct và dữ liệu
    REPORT_P    fill            (MGR, float)            Lọc các RECORD của MGR_P của input theo giá trị float của input
                                                        và tập hợp lại trong REPORT được REPORT_P xuất ra trỏ tới.
----------------Các hàm hiện thông tin stuct
    void        hienRecord      (MGR)                   Hiện các thông tin của các RECORD đang được chứa trong MGR_P của input
    void        hienReport      (REPORT_P)              Hiện các thông tin của các RECORD đang được chứa trong REPORT_P của input
*/

MGR_P taoMgr();
MGR_P createInfoInMGR(MGR_P mgr);
MGR_P nhapThongTin(MGR_P mgr);
REPORT_P fill(MGR_P mgr, float score);
REPORT_P taoReport();
void hienRecord(MGR_P mgr);
void hienReport(REPORT_P report);
void napReport(REPORT_P report, RECORD_P record);

int main()
{
    //Tạo MGR -> Tạo RECORD trong MGR đó theo người dùng -> Nhập thông tin RECORD của MGR đó
    //-> Lọc các RECORD của MGR đó vào REPORT -> In kết quả trong REPORT đó ra
    hienReport(fill(nhapThongTin(createInfoInMGR(taoMgr())), 15.0f));
    return EXIT_SUCCESS;
}

MGR_P taoMgr()
{
    MGR_P mgr = (MGR_P)calloc(1ull, sizeof(MGR));
}

MGR_P createInfoInMGR(MGR_P mgr)
{
    printf("Nhap so thi sinh : ");
    scanf("%llu", &mgr->n);
    mgr->record = (MGR_P)calloc(mgr->n, sizeof(RECORD));
    printf("Da tao xong %llu ban ghi trang\n", mgr->n);
    return mgr;
}

MGR_P nhapThongTin(MGR_P mgr)
{
    printf("Bat dau nhap thong tin\n");
    for (uint64_t i = 0llu; i < mgr->n; i++)
    {
        RECORD_P p = &mgr->record[i];
        p->t = 0.0f;
        printf("Ho so thu %5llu\n", i);
        printf("Ma so bao danh\t:\t");
        scanf("%llu", &p->idStudent);
        printf("Ho va ten\t:\t");
        fflush(stdin);
        fgets(p->name, __max_length_of_name, stdin);
        printf("Ngay sinh\n");
        printf("Ngay\t\t:\t");
        scanf("%u", &p->dob[0]);
        printf("Thang\t\t:\t");
        scanf("%u", &p->dob[1]);
        printf("Nam\t\t:\t");
        scanf("%u", &p->dob[2]);
        printf("Gioi tinh\t:\t");
        fflush(stdin);
        fgets(p->sex, __max_length_of_name, stdin);
        for (uint64_t j = 0llu; j < __max_number_of_score; j++)
        {
            printf("Diem %llu\t\t:\t", j + 1ull);
            scanf("%f", &p->score[j]);
            p->t += p->score[j];
        }
    }
    return mgr;
}

REPORT_P fill(MGR_P mgr, float score)
{
    printf("Bat dau loc cac thi sinh co tong diem >= %3.2f\n", score);
    REPORT_P report = taoReport();
    for (uint64_t i = 0llu; i < mgr->n; i++)
        if (mgr->record[i].t >= score)
            napReport(report, &mgr->record[i]);
    return report;
}

void hienRecord(MGR_P mgr)
{
    printf("Danh sach cac thi sinh\n");
    for (uint64_t i = 0llu; i < mgr->n; i++)
    {
        RECORD_P p = &mgr->record[i];
        printf("------------------------------\n");
        printf("So bao danh\t:\t%5llu\n", p->idStudent);
        printf("Ho va ten\t:\t%6s", p->name);
        printf("Ngay sinh\t:\t%02u/%02u/%04u\n", p->dob[0], p->dob[1], p->dob[2]);
        printf("Gioi tinh\t:\t%6s", p->sex);
        for (uint64_t j = 0llu; j < __max_number_of_score; j++)
            printf("Diem %llu\t\t:\t%5.2f\n", j + 1llu, p->score[j]);
        printf("Tong diem\t:\t%5.2f\n", p->t);
    }
}

void hienReport(REPORT_P report)
{
    printf("Co %5llu thi sinh\n", report->n);
    for (uint64_t i = 0llu; i < report->n; i++)
    {
        RECORD_P p = report->record[i];
        printf("------------------------------\n");
        printf("So bao danh\t:\t%5llu\n", p->idStudent);
        printf("Ho va ten\t:\t%6s", p->name);
        printf("Ngay sinh\t:\t%02u/%02u/%04u\n", p->dob[0], p->dob[1], p->dob[2]);
        printf("Gioi tinh\t:\t%6s", p->sex);
        for (uint64_t j = 0llu; j < __max_number_of_score; j++)
            printf("Diem %llu\t\t:\t%5.2f\n", j + 1llu, p->score[j]);
        printf("Tong diem\t:\t%5.2f\n", p->t);
    }
}

void napReport(REPORT_P report, RECORD_P record)
{
    report->n++;
    report->record = (RECORD_P*)realloc(report->record, sizeof(RECORD_P) * report->n);
    report->record[report->n - 1llu] = record;
}

REPORT_P taoReport()
{
    REPORT_P report = (REPORT_P)calloc(1ull, sizeof(REPORT));
    report->record = (RECORD_P*)calloc(1ull, sizeof(RECORD_P));
    return report;
}