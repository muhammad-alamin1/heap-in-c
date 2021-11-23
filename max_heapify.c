#include <stdio.h>

int left(int i);
int right(int i);
int parent(int i);
void max_heapify(int arr[], int heap_size, int i);
void print_heap(int heap[], int heap_size);
void build_max_heap(int heap[], int heap_size);

int main(void)
{
    int H[] = {0, 12, 7, 1, 3, 10, 17, 19, 2, 5};
    int size = ((sizeof(H)/sizeof(H[0])) - 1);

    // before call
    print_heap(H, size);
    printf("\n\n\n");

    //max_heapify(H, size, 1);
    //print_heap(H, size);

    build_max_heap(H, size);
    print_heap(H, size);

    return 0;
}

// add left
int left(int i)
{
    return 2*i;
}

// add right;
int right(int i)
{
    return 2*i+1;
}

// parent
int parent(int i)
{
    return i/2;
}

// max heapify
void max_heapify(int arr[], int heap_size, int i)
{
    int l, r, largest, temp;

    l = left(i);
    r = right(i);

    if(l <= heap_size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if(r <= heap_size && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        max_heapify(arr, heap_size, largest);
        /*
            Recursion base case:

            if(largest == i)
                return ;

            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            max_heapify(arr, heap_size, largest);
            }
        */
    }
}

// print heap
void print_heap(int heap[], int heap_size)
{
    int i;

    for(i = 1; i <= heap_size; i++)
    {
        printf("%d ", heap[i]);
    }
}

// build max heap
void build_max_heap(int heap[], int heap_size)
{
    int i;

    for(i = heap_size/2; i >= 1; i--)
    {
        max_heapify(heap, heap_size, i);
    }
}
