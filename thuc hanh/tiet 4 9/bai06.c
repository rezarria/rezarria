#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct NODE_S
{
    void* ptr;
    struct NODE_S* next;
};

typedef struct NODE_S NODE;

struct PS_S
{
    double tu, mau;
};

typedef struct PS_S PS;

NODE* createNODE();
NODE* lastNODE(NODE* node);
NODE* pushNODE(NODE* node, NODE* last);
NODE* surfNODE(NODE** node);
NODE* linkPtr(NODE* node, void* ptr);

PS* createPS();
PS* importPS(PS* ps);
PS* Ps(NODE* node);
char getChar();
void displayPS(PS* ps);

NODE* createPSList();
NODE* displayPSList(NODE* list);

double sumOfPS(NODE* list);

double importDouble();
double importDouble_f(FILE* input);

void stdClean();

int32_t main()
{
    NODE* list;
    list = createPSList();
    displayPSList(list);
    printf("Tong = %llf\n", sumOfPS(list));
    return EXIT_SUCCESS;
}

void stdClean()
{
    stdin->_base += stdin->_cnt;
    fflush(stdin);
}

double importDouble()
{
    return importDouble_f(stdin);
}

double importDouble_f(FILE* input)
{
    stdClean();
    double n;
    scanf("%lf", &n);
    return n;
}

PS* createPS()
{
    return (PS*)calloc(1llu, sizeof(PS));
}

PS* importPS(PS* ps)
{
    printf("-------------------------\n");
    printf("Tu so\t: ");
    ps->tu = importDouble();
    printf("Mau so\t: ");
    ps->mau = importDouble();
    printf("-------------------------\n");
    return ps;
}

PS* Ps(NODE* node)
{
    return (PS*)node->ptr;
}

char getChar()
{
    char c = getchar();
    stdClean();
    return c;
}

NODE* createPSList()
{
    NODE* list;
    char c;
    printf("Nhap n de tao pha nso moi\n");
    printf("Nhap '\\' de thoat\n");
    do
        switch (c = getChar())
        {
        case 'n':
            list = pushNODE(list, linkPtr(createNODE(), (void*)importPS(createPS())));
            break;
        case '\\':
            printf("Thoat\n\n\n");
        }
    while (c != '\\');

    return list;
}

NODE* displayPSList(NODE* list)
{
    do
        displayPS(Ps(list));
    while (surfNODE(&list));

}

void displayPS(PS* ps)
{
    printf("%2.2lf/%2.2lf\n", ps->tu, ps->mau);
}

double sumOfPS(NODE* list)
{
    double tren = 0.0, duoi = 1.0;
    NODE* p = list;
    do
        duoi *= Ps(p)->mau;
    while (surfNODE(&p));
    p = list;
    do
        tren += Ps(p)->tu * duoi / Ps(p)->mau;
    while (surfNODE(&p));
    return tren / duoi;
}

NODE* createNODE()
{
    return (NODE*)calloc(1llu, sizeof(NODE));
}

NODE* pushNODE(NODE* node, NODE* last)
{
    if (node)
        lastNODE(node)->next = last;
    else
        node = last;
    return node;
}

NODE* lastNODE(NODE* node)
{
    return node ? (node->next ? lastNODE(node->next) : node) : NULL;
}

NODE* surfNODE(NODE** node)
{
    *node = (*node)->next;
    return *node;
}

NODE* linkPtr(NODE* node, void* ptr)
{
    node->ptr = ptr;
    return node;
}