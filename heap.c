#include <stdio.h>

int left(int i);
int right(int i);
int parent(int i);

int main(void)
{


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
