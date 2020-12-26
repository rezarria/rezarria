//205748010310003
//VO TA NAM
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define __MAX_LENGTH_OF_NAME 256
#define __MAX_NUMBER_OF_SCORE 3
#define __INT_LENGTH 35,
#define __FRAC_LENGTH 2,
#define __STRING_LENGTH 36,
#define __FLOAT_LENGTH __INT_LENGTH __FRAC_LENGTH

/*
    Khai báo các struct và các typedef
    Có 3 struct     RECORD,     MGR,    REPORT
    Có 3 typedef    RECORD_P,   MGR_P,  REPORT_P

    INFO        :   Dùng để chứa các thông tin của sinh viên
    INFO_P      :   Là con trỏ của RECORD

    LIST        :   Dùng để chứa INFO bằng INFO_P
    LIST_P      :   Là con trỏ của LIST

    REPORT      :   Dùng để chứa các kết quả là các INFO phù hợp sau khi lọc INFO trong MGR
                    Dùng trỏ của INFO_P để lưu lại địa chỉ, thay vì tạo mới gây tốn tài nguyên
    REPORT_P    :   Là con trỏ của REPORT
*/
typedef struct INFO_S
{
    uint64_t idStudent;
    char* nameStudent;
    uint64_t ageStudent;
    float scoreStudent[__MAX_NUMBER_OF_SCORE];
    float sumOfScoreStudent;
} INFO;
typedef INFO* INFO_P;

typedef struct LIST_S
{
    uint64_t numberOfInfo;
    INFO_P infoList;
} LIST;
typedef LIST* LIST_P;

typedef struct REPORT_S
{
    uint64_t numberOfInfoAddr;
    INFO_P* infoAddrList;
} REPORT;
typedef REPORT* REPORT_P;

/*
----------------Các hàm tạo struct
    LIST_P      createList             ()                       Tạo một LIST và xuất địa chỉ ra
    LIST_P      createInfoInList       (LIST_P)                 Tạo một n (theo người dùng) INFO vào LIST theo LIST_P của input và xuất LIST_P của input ra
    REPORT_P    createReport           ()                       Tạo một REPORT được REPORT_P xuất ra trỏ tới
----------------Các hàm nhập, nạp dữ liệu vàoo struct
    INFO_P      importInfo             (INFO_P)                 Nhập các thông tin vào INFO theo địa chỉ của input và xuất địa chỉ đó ra
    LIST_P      importInfoInList       (LIST_P)                 Nhập các thông tin vào các INFO của LIST_P của input và xuất LIST_P của input ra
    void        importReport           (REPORT_P, INFO_P)       Dùng để nạp INFO của input vào REPORT của input
    uint64_t    importUi64             ()                       Dùng để nhập một giá trị uint64 và trả về giá trị đó
    string      importString           ()                       Dùng để nhập một xâu và trả về xâu đó
    float       importFloat            ()                       Dùng để nhập một số thực và trả về số thực đó
----------------Các hàm lọc struct và dữ liệu
    REPORT_P    fillByScore             (LIST, float)           Lọc các Info của LIST_P của input theo giá trị float của input
                                                                và tập hợp lại trong REPORT được REPORT_P xuất ra trỏ tới.
----------------Các hàm hiện thông tin stuct
    void        displayInfoInList       (LIST)                  Hiện các thông tin của các RECORD đang được chứa trong LIST_P của input
    void        dusplayReport           (REPORT_P)              Hiện các thông tin của các RECORD đang được chứa trong REPORT_P của input
----------------Các hàm điều chỉnh
    LIST_P      customNumberInfoInList  (LIST_P, uint64_t)      Điều chỉnh số lượng INFO trong LIST theo LIST_P theo đối số uint64 của input, output chính là địa chỉ
                                                                của LIST mới điều chỉnh
*/
LIST_P      createList();
LIST_P      createInfoInList(LIST_P list);
REPORT_P    createReport();
INFO_P      importInfo(INFO_P info);
LIST_P      importInfoInList(LIST_P list);
void        importReport(REPORT_P report, INFO_P info);
uint64_t    importUi64();
char*       importString();
float       importFloat();
REPORT_P    fillByScore(LIST_P list, float score);
void        displayInfoInList(LIST_P list);
void        displayReport(REPORT_P report);
void        calcSumOfScore(INFO_P info);
LIST_P      customNumberInfoInList(LIST_P list, uint64_t n);

int32_t main()
{
    //Tạo LIST -> Tạo INFO trong LIST đó theo người dùng -> Nhập thông tin INFO của LIST đó
    //-> Lọc các INFO của LIST đó vào REPORT -> In kết quả trong REPORT đó ra
    displayReport(fillByScore(importInfoInList(createInfoInList(createList())), 15.0f));
    return EXIT_SUCCESS;
}

void calcSumOfScore(INFO_P info)
{
    for (uint64_t i = 0; i < __MAX_NUMBER_OF_SCORE; i++)
        info->sumOfScoreStudent += info->scoreStudent[i];
}

INFO_P  importInfo(INFO_P info)
{
    printf("Ma so bao danh\t:\t");
    info->idStudent = importUi64();
    printf("Ho va ten\t:\t");
    info->nameStudent = importString();
    printf("Tuoi\t\t:\t");
    info->ageStudent = importUi64();
    for (uint64_t j = 0; j < __MAX_NUMBER_OF_SCORE; j++)
    {
        printf("Diem %3llu\t:\t", j + 1ull);
        info->scoreStudent[j] = importFloat();
        info->sumOfScoreStudent += info->scoreStudent[j];
    }
    calcSumOfScore(info);
    printf("Tong diem\t:\t%3.2f\n", info->sumOfScoreStudent);
}

void importReport(REPORT_P report, INFO_P info)
{
    report->numberOfInfoAddr++;
    report->infoAddrList = (INFO_P*)realloc(report->infoAddrList, sizeof(INFO_P) * report->numberOfInfoAddr);
    report->infoAddrList[report->numberOfInfoAddr - 1llu] = info;
}

LIST_P importInfoInList(LIST_P list)
{
    printf("Bat dau nhap thong tin\n");
    for (uint64_t i = 0llu; i < list->numberOfInfo; i++)
    {
        printf("Ho so thu %3llu\n", i);
        importInfo(&list->infoList[i]);
    }
    return list;
}

REPORT_P createReport()
{
    return (REPORT_P)calloc(1ull, sizeof(REPORT));
}

LIST_P createList()
{
    LIST_P list = (LIST_P)calloc(1ull, sizeof(LIST));
}

LIST_P createInfoInList(LIST_P list)
{
    printf("Nhap so thi sinh : ");
    customNumberInfoInList(list, importUi64());
    printf("Da tao xong %3llu ban ghi trang\n", list->numberOfInfo);
    return list;
}

void displayInfo(INFO_P info)
{
    printf("------------------------------------------------------------\n");
    printf("So bao danh\t:\t%*llu\n", __INT_LENGTH info->idStudent);
    printf("Ho va ten\t:\t%*s", __STRING_LENGTH info->nameStudent);
    printf("Tuoi\t\t:\t%*llu\n", __INT_LENGTH info->ageStudent);
    for (uint64_t j = 0llu; j < __MAX_NUMBER_OF_SCORE; j++)
        printf("Diem %llu\t\t:\t%*.*f\n", j + 1, __FLOAT_LENGTH info->scoreStudent[j]);
    printf("Tong diem\t:\t%*.*f\n", __FLOAT_LENGTH info->sumOfScoreStudent);
}

void displayInfoInList(LIST_P list)
{
    printf("Danh sach cac thi sinh\n");
    for (uint64_t i = 0llu; i < list->numberOfInfo; i++)
        displayInfo(&list->infoList[i]);
}

void displayReport(REPORT_P report)
{
    printf("Co %*llu thi sinh\n", __INT_LENGTH report->numberOfInfoAddr);
    for (uint64_t i = 0llu; i < report->numberOfInfoAddr; i++)
        displayInfo(report->infoAddrList[i]);
}

LIST_P customNumberInfoInList(LIST_P list, uint64_t n)
{
    list->numberOfInfo = n;
    list->infoList = (INFO_P)calloc(list->numberOfInfo, sizeof(INFO));
    return list;
}

REPORT_P fillByScore(LIST_P list, float score)
{
    printf("Bat dau loc cac thi sinh co tong diem >= %3.2f\n", score);
    REPORT_P report = createReport();
    for (uint64_t i = 0llu; i < list->numberOfInfo; i++)
        if (list->infoList[i].sumOfScoreStudent >= score)
            importReport(report, &list->infoList[i]);
    return report;
}

uint64_t importUi64()
{
    printf("uint64> ");
    uint64_t n;
    scanf("%llu", &n);
    return n;
}

char* importString()
{
    char* str = (char*)calloc(__MAX_LENGTH_OF_NAME, sizeof(char));
    fputs("string> ", stdout);
    fseek(stdin, 0l, SEEK_SET);
    fgets(str, __MAX_LENGTH_OF_NAME, stdin);
    return (char*)realloc((void*)str, sizeof(char) * (strlen(str) + 1llu));
}

float importFloat()
{
    printf("float> ");
    float n;
    scanf("%f", &n);
    return n;
}
