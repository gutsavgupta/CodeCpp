/********************************************************
 * ******************************************************
 * Authur: Utsav Gupta
 * Date: 11-Jan-2018
 * File contain my function definiton of Heap.h
 * ******************************************************
 * ******************************************************/

#include <stdio.h>
#include "MyHeap.h"

////////////   Utility function /////////////////

static inline void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static inline int parent(int index)
{
    return (index-1)/2;
}

static inline int left(int index)
{
    return (2*index + 1);
}

static inline int right(int index)
{
    return (2*index + 2);
}

static inline void MinHeapify(int x)
{
    if(HeapSize > 0)
    {
        int l = left(x);
        int r = right(x);

        int smallest = x;
        if(l<HeapSize && HeapArray[l] < HeapArray[smallest])
        {
            smallest = l;
        }
        if(r<HeapSize && HeapArray[r] < HeapArray[smallest])
        {
            smallest = r;
        }

        if(smallest != x)
        {
            swap(&HeapArray[smallest],&HeapArray[x]);
            MinHeapify(smallest);
        }
    }
}

////////////////////////////////////////////////

///////////// Main Function ////////////////////

void HeapInit(int *arr, int msize)
{
    HeapSize = 0;
    if(arr == NULL) // take default array //
    {
        HeapArray = Array;
        MaxHeapSize = MAX_HEAP_SIZE;
    }
    else
    {
        HeapArray = arr;
        MaxHeapSize = msize;
    }
}

void HeapInsert(int x)
{
    if(HeapSize>=MaxHeapSize)
    {
        PRINT(("ERROR:: Heap buffer overflow for element %d\n",x));
        return;
    }
    else
    {
        HeapArray[HeapSize]=x;
        HeapSize++;

        int i = HeapSize-1;
        while(i>=0 && (HeapArray[i]<HeapArray[parent(i)]))
        {
            swap(&HeapArray[i],&HeapArray[parent(i)]);
            i = parent(i);
        }
    }
}

int HeapExtractMin()
{
    if(HeapSize == 0)
    {
        PRINT(("ERROR:: HeapSize is zero\n"));
        return -1;     
    }
    else if(HeapSize == 1)
    {
        HeapSize = 0;
        return HeapArray[0];
    }
    else
    {
        int min = HeapArray[0];
        HeapSize--;

        HeapArray[0] = HeapArray[HeapSize];
        MinHeapify(0);
        return min;
    }
    return -1;
}

void HeapKeyDecrease(int index, int value)
{
    if(index >= HeapSize)
    {
        PRINT(("ERROR:: Wrong index passes in HeapKeyDec() [%d]\n",index));
        return;
    }
    else
    {
        int currVal = HeapArray[index];
        if(currVal<value)
        {
            PRINT(("ERROR:: Value passed [%d] is greater than curr value [%d] \n",value,currVal));
        }
        else
        {
            int i = index;
            HeapArray[i] = value;
            while(i>=0 && (HeapArray[i]<HeapArray[parent(i)]))
            {
                swap(&HeapArray[i],&HeapArray[parent(i)]);
                i = parent(i);
            }
        }
    }
}

void HeapKeyDelete(int index)
{
    if(index >= HeapSize)
    {
        PRINT(("ERROR:: Wrong index passes in HeapKeyDel() [%d]\n",index));
        return;
    }
    else
    {
        HeapKeyDecrease(index, MIN_HEAP_INFY);
        HeapExtractMin();
    }
}

void HeapDebugPrint()
{
    PRINT(("THE HEAP SIZE IS: %d\n",HeapSize));
    PRINT(("THE MAX HEAP SIZE IS: %d\n",MaxHeapSize));

    int i;
    for(i=0; i<HeapSize; i++)
    {
        PRINT(("%d ",HeapArray[i]));
    }
    PRINT(("\n"));
}

///////////////////////////////////////////////