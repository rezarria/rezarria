#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define __MAIN__ int32_t main(int32_t argc, char** argv)

//-------------------------------------------------------------------------------------------
typedef struct NODE_S NODE;
struct NODE_S
{
    void* ptr;
    NODE* next;
};

NODE* createNODE();
NODE* lastNODE();
NODE* pushNODE();
//-------------------------------------------------------------------------------------------


void test();