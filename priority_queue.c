#include <stdio.h>

int left(int i);
int right(int i);
void max_heapify(int heap[], int heap_size, int i);
int extract_max(int heap[], int heap_size);
void print_heap(int heap[], int heap_size);
void build_max_heap(int heap[], int heap_size);
int parent(int i);
int insert_node(int heap[], int heap_size, int node);

int main(void)
{
    int root, node;

    int H[] = {0, 2, 1, 7, 3, 19, 17, 10, 12, 5};
    int size = ((sizeof(H)/sizeof(H[0])) - 1);

    print_heap(H, size);
    printf("\n\n");

    build_max_heap(H, size);
    print_heap(H, size);
    printf("\n\n");

    root = extract_max(H, size);
    printf("%d \n\n", root);
    print_heap(H, size);

    printf("\n\n");
    node = insert_node(H, size, 76);
    print_heap(H, size);

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
void max_heapify(int heap[], int heap_size, int i)
{
    int l, r, largest, temp;

    l = left(i);
    r = right(i);

    if(l <= heap_size && heap[l] > heap[i])
        largest = l;
    else
        largest = i;

    if(r <= heap_size && heap[r] > heap[largest])
        largest = r;

    if(largest == i)
        return;
    else
    {
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        max_heapify(heap, heap_size, largest);
    }
}

// extract max
int extract_max(int heap[], int heap_size)
{
    int max_item = heap[1];

    heap[1] = heap[heap_size];
    heap_size -= 1;

    max_heapify(heap, heap_size, 1);

    return max_item;
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

// insert
int insert_node(int heap[], int heap_size, int node)
{
    int i, p, temp;

    heap_size += 1;
    heap[heap_size] = node;

    i = heap_size;
    while(i > 1 && heap[i] > heap[parent(i)])
    {
        p = parent(i);

        temp = heap[p];
        heap[p] = heap[i];
        heap[i] = temp;

        i = p;
    }

    return heap_size;
}
