#include <stdio.h>

int left(int i);
int right(int i);
int parent(int i);
void max_heapify(int arr[], int heap_size, int i); // Complexity : O(log n)
void heap_print(int heap[], int heap_size);
void build_max_heap(int heap[], int heap_size);
void heap_sort_algorithm(int heap[], int heap_size); // Complexity : O(n log n)

int main(void)
{
    int H[] = {0, 2, 1, 7, 3, 19, 17, 10, 12, 5};
    int size = ((sizeof(H)/sizeof(H[0])) - 1);

    heap_print(H, size);
    printf("\n\n");

    build_max_heap(H, size);
    heap_print(H, size);
    printf("\n\n");

    // Sort Algo
    heap_sort_algorithm(H, size);
    heap_print(H, size);

    return 0;
}

// add left
int left(int i)
{
    return 2*i;
}

// add right
int right(int i)
{
    return 2*i+1;
}

// search parent
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
    }
}

// print heap
void heap_print(int heap[], int heap_size)
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

// Heap sort Algorithm
void heap_sort_algorithm(int heap[], int heap_size)
{
    int i, temp;

    for(i = heap_size; i > 1; i--)
    {
        temp = heap[1];
        heap[1] = heap[i];
        heap[i] = temp;

        heap_size -= 1;
        max_heapify(heap, heap_size, 1);
    }
}
