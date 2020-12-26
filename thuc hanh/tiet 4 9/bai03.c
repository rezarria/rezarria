//205748010310003
//VO TA NAM
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct PHAN_SO_S
{
    int32_t tu;
    int32_t mau;
} PHAN_SO;
typedef PHAN_SO* PHAN_SO_P;

typedef struct TAP_HOP_PHAN_SO_S
{
    uint64_t n;
    PHAN_SO_P phanSo;
} TAP_HOP_PHAN_SO;
typedef TAP_HOP_PHAN_SO* TAP_HOP_PHAN_SO_P;

TAP_HOP_PHAN_SO_P   taoTapHop();
TAP_HOP_PHAN_SO_P   taoPhanSo(TAP_HOP_PHAN_SO_P tapHop);
TAP_HOP_PHAN_SO_P   nhapPhanSo(TAP_HOP_PHAN_SO_P tapHop);
void                hienTapHop(TAP_HOP_PHAN_SO_P tapHop);

int main()
{
    hienTapHop(nhapPhanSo(taoTapHop()));
    return EXIT_SUCCESS;
}

TAP_HOP_PHAN_SO_P   taoTapHop()
{
    TAP_HOP_PHAN_SO_P tapHop = (TAP_HOP_PHAN_SO_P)calloc(1llu, sizeof(TAP_HOP_PHAN_SO));
    return tapHop;
}

TAP_HOP_PHAN_SO_P taoPhanSo(TAP_HOP_PHAN_SO_P tapHop)
{
    printf("Nhap so phan so can nhap : ");
    scanf("%llu", &tapHop->n);
    PHAN_SO_P phanSo = (PHAN_SO_P)calloc(tapHop->n, sizeof(PHAN_SO));
    return phanSo;
}

TAP_HOP_PHAN_SO_P nhapPhanSo(TAP_HOP_PHAN_SO_P tapHop)
{
    for (uint64_t i = 0llu; i < tapHop->n; i++)
    {
        printf("Phan so thu %5llu\n", i);
        printf("Mau so/t:/t");
        scanf("%lld", &tapHop->phanSo[i].mau);
        printf("Tu so\t:\t");
        scanf("%lld", &tapHop->phanSo[i].tu);
    }
    return tapHop;
}

void hienTapHop(TAP_HOP_PHAN_SO_P tapHop)
{
    printf("\n---------------------------\n");
    for (uint64_t i = 0llu; i < tapHop->n; i++)
    {
        printf("> %lld / %lld\n", tapHop->phanSo[i].mau, tapHop->phanSo[i].tu);
    }
}
