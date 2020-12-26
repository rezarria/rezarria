//205748010310003
//VO TA NAM
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct COMPLEX_S
{
    long double thuc;
    long double ao;
} COMPLEX;
typedef COMPLEX* COMPLEX_P;

typedef struct LIST_S
{
    uint64_t n;
    COMPLEX_P complex;
} MGR;
typedef MGR* MGR_P;

MGR_P   taoMgr();
MGR_P   taoComplex(MGR_P mgr);
MGR_P   nhapComplex(MGR_P mgr);
void    hienMgr(MGR_P mgr);
void hienComplex(COMPLEX_P complex);

int32_t main()
{
    hienMgr(nhapComplex(taoComplex(taoMgr())));
    return EXIT_SUCCESS;
}

MGR_P taoMgr()
{
    MGR_P mgr = (MGR_P)calloc(1llu, sizeof(MGR));
    return mgr;
}

MGR_P taoComplex(MGR_P mgr)
{
    printf("Nhap so phuc can nhap : ");
    scanf("%llu", &mgr->n);
    mgr->complex = (COMPLEX_P)calloc(mgr->n, sizeof(COMPLEX));
    return mgr;
}

MGR_P nhapComplex(MGR_P mgr)
{
    printf("\n--------------------------\n");
    for (uint64_t i = 0llu; i < mgr->n; i++)
    {
        printf("So phu thu %llu\n", i);
        printf("Phan thuc\t:\t");
        scanf("%llf", &mgr->complex[i].thuc);
        printf("Nhap phan ao\t:\t");
        scanf("%llf", &mgr->complex[i].ao);
    }
    return mgr;
}

void hienMgr(MGR_P mgr)
{
    printf("\n--------------------------\n");
    for (uint64_t i = 0llu; i < mgr->n; i++)
        hienComplex(&mgr->complex[i]);
}

void hienComplex(COMPLEX_P complex)
{
    if (complex->ao == 0.0L)
        printf("%6.3llf\n", complex->thuc);
    else
        if (complex->thuc == 0.0L)
            printf("%6.3llfi\n", complex->ao);
        else
            printf("%6.3llf + %6.3llfi\n", complex->thuc, complex->ao);
}
