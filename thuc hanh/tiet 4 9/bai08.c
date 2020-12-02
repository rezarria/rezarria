#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define __max_length_of_name 256
#define defualt_salary 1050000.0L
// Bi loi o dau do :))))
typedef struct NODE_S NODE;
typedef NODE* NODE_P;
struct NODE_S {
	NODE_P front, back;
	char name[__max_length_of_name];
	long double ratio;
	long double salary;
};

bool    aloneNODE(NODE_P node);
void    linkNODE(NODE_P lnode, NODE_P rnode);
NODE_P  unlinkNODE(NODE_P node);
NODE_P  createNODE();
NODE_P  pushNODE(NODE_P lnode, NODE_P rnode);
NODE_P  importNODE(NODE_P node);
NODE_P  importInfo(NODE_P node);
NODE_P  sortNODE(NODE_P node);
NODE_P  insertIncreNODE(NODE_P lnote, NODE_P rnote);
NODE_P  displayNODE(NODE_P node);

int main()
{
	NODE_P node = sortNODE(importNODE(NULL));
	displayNODE(node);
	return EXIT_SUCCESS;
}

NODE_P createNODE()
{
	NODE_P node = (NODE_P)calloc(1llu, sizeof(NODE));
	linkNODE(node, node);
	return node;
}

NODE_P pushNODE(NODE_P lnode, NODE_P rnode)
{
	if (lnode)
	{
		linkNODE(lnode->back, rnode);
		linkNODE(rnode, lnode);
		return lnode;
	}
	return rnode;
}

NODE_P importNODE(NODE_P node)
{
	if (node == NULL)
		node = importInfo(createNODE());
	printf("Nhap q de thoat\n");
	printf("Nhap n de them\n");
	char i = 0;
	do {
		i = getchar();
		fseek(stdin, 0, SEEK_END);
		if (i == 'n')
			pushNODE(node, importInfo(createNODE()));
	} while (i != 'q');
	return node;
}

NODE_P importInfo(NODE_P node)
{
	printf("\n---------------\n");
	printf("Ho va ten\t:\t");
	fgets(node->name, __max_length_of_name, stdin);
	printf("Ti le luong\t:\t");
	scanf("%Lf", &node->ratio);
	long double g = node->ratio * defualt_salary;
	node->salary = g;
	printf("\n---------------\n");
	return node;
}

NODE_P sortNODE(NODE_P node)
{
	NODE_P p = unlinkNODE(node->front);
	while (!aloneNODE(node))
	{
		NODE_P q = unlinkNODE(node->front);
		p = insertIncreNODE(p, q);
	}
	p = insertIncreNODE(p, node);
	return p;
}

NODE_P insertIncreNODE(NODE_P lnode, NODE_P rnode)
{
	if (rnode->salary >= lnode->front->salary)
	{
		linkNODE(lnode->front, rnode);
		linkNODE(rnode, lnode);
	}
	else
		if (rnode->salary < lnode->salary)
		{
			linkNODE(lnode->front, rnode);
			linkNODE(rnode, lnode);
			lnode = rnode;
		}
		else
		{
			NODE_P cur = lnode;
			do
				if ((cur->salary <= rnode->salary) && (rnode->salary <= cur->back->salary))
				{
					linkNODE(rnode, cur->back);
					linkNODE(cur, rnode);
					break;
				}
				else
					cur = cur->back;
			while (true);
		}
	return lnode;
}

void linkNODE(NODE_P lnode, NODE_P rnode)
{
	lnode->back = rnode;
	rnode->front = lnode;
}

NODE_P unlinkNODE(NODE_P node)
{
	if (!aloneNODE(node))
	{
		linkNODE(node->front, node->back);
		linkNODE(node, node);
	}
	return node;
}

bool aloneNODE(NODE_P node)
{
	return ((node == node->back) || (node == node->front));
}

NODE_P displayNODE(NODE_P node)
{
	printf("Danh sach nhan vien\n");
	NODE_P cur = node;
	do
	{
		printf("-----------------------------------------\n");
		printf("Ho va ten\t:\t%s", cur->name);
		printf("Ti le luong\t:\t%3.3Lf\n", cur->ratio);
		printf("Luong\t\t:\t%9.3f\n", cur->salary);
		cur = cur->back;
	} while (cur != node);
	return node;
}