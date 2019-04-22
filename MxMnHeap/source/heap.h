#ifndef __MYHEAP__
/********************************************************
 * ******************************************************
 * Authur: Utsav Gupta
 * Date: 11-Jan-2018
 * File contain my implementation of Heap Lib
 * goal is to create min and max heap both
 * ******************************************************
 * ******************************************************/

#define __MYHEAP__
#include <stdio.h>

///////////// Constant definitions ////////////
#define DEBUG
#define MAX_HEAP_SIZE (50000)
#define MAX_HEAP_INFY (99999999)
#define MIN_HEAP_INFY (-99999999)
///////////////////////////////////////////////

/////////??//// Debug Definitons //??//////////
#ifdef DEBUG
#define PRINT(x) printf x
#else
#define PRINT(x) do{} while(0)
#endif
///////////////////////////////////////////////

//////////// GlobalVar definitions ////////////
int Array[MAX_HEAP_SIZE];
int MaxHeapSize;
int HeapSize;
int *HeapArray;
///////////////////////////////////////////////

//////////////// Heap Functions ///////////////
void HeapInit(int *arr, int msize);

void HeapInsert(int x);

int HeapExtractMin();

void HeapKeyDecrease(int index, int value);

void HeapKeyDelete(int index);

void HeapDebugPrint();
///////////////////////////////////////////////

#endif

