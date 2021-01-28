#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_S NODE;
struct NODE_S
{
    NODE *next;
    int n;
};

NODE *last(NODE *node)
{
    return (!node->next) ? node : last(node->next);
}

void push(NODE *node, int n)
{
    NODE *p = (NODE *)calloc(1llu, sizeof(NODE));
    p->n = n;
    last(node)->next = p;
}

NODE *docTuTep(char *ten)
{
    NODE *node = (NODE *)calloc(1llu, sizeof(NODE));
    FILE *f = fopen(ten, "r");
    fscanf(f, "%d", &node->n);
    int tmp;
    while (!feof(f))
    {
        fscanf(f, "%d", &tmp);
        push(node, tmp);
    }
    fclose(f);
    return node;
}

NODE *surft(NODE **node)
{
    *node = node[0]->next;
    return *node;
}

void freeNODE(NODE *node)
{
    if (node)
    {
        freeNODE(node->next);
        free(node);
    }
}

int tongDuongChan(NODE *node)
{
    int t = 0;
    do
        if (node->n > 0 && node->n % 2 == 0)
            t += node->n;
    while (surft(&node));
    return t;
}

int main()
{
    NODE *node = docTuTep("input.txt");
    FILE *f = fopen("output.txt", "w");
    fprintf(f, "%d", tongDuongChan(node));
    fclose(f);
    freeNODE(node);
    return 0;
}