#include <stdio.h>

int left(int i);
int right(int i);
int parent(int i);
int is_max_heap(int arr[], int heap_size);

int main(void)
{
    int is_heap;

    int H[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 2};
    int heap_size = ((sizeof(H)/sizeof(H[0])) - 1);

    is_heap = is_max_heap(H, heap_size);
    if(is_heap == 1)
        printf("Array is Max heap.\n");
    else
        printf("Array not max heap.\n");

    printf("\n\n\n");

    int H1[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 4};
    int heap_size1 = ((sizeof(H)/sizeof(H[0])) - 1);

    is_heap = is_max_heap(H1, heap_size1);
    if(is_heap == 1)
        printf("Array is Max heap.\n");
    else
        printf("Array not max heap.\n");

    return 0;
}

// left add
int left(int i)
{
    return 2*i;
}

//  right add
int right(int i)
{
    return 2*i+1;
}

// parent node
int parent(int i)
{
    return i/2;
}

// is max heap
int is_max_heap(int arr[], int heap_size)
{
    int i, p;

    for(i = heap_size; i > 1; i--)
    {
        p = parent(i);
        printf("i = %d, p = %d\tarr[i] = %d, arr[p] = %d\n", i, p, arr[i], arr[p]);

        if(arr[p] < arr[i])
            return 0;
    }
    return 1;
}
