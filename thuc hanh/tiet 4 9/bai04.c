#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct COMPLEX_S
{
    long double real;
    long double virtual;
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


int main()
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
        scanf("%llf", &mgr->complex[i].real);
        printf("Nhap phan ao\t:\t");
        scanf("%llf", &mgr->complex[i].virtual);
    }
    return mgr;
}

void hienMgr(MGR_P mgr)
{
    printf("\n--------------------------\n");
    for (uint64_t i = 0llu; i < mgr->n; i++)
        printf("So phu thu %llu/t:/t%6.3llf + i * %6.3llf\n", i, mgr->complex[i].real, mgr->complex[i].virtual);
}

