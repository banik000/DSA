#include<stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void min_heap(int A[], int n, int i)
{
    int smallest = i;
    int l_child = 2*i + 1;
    int r_child = 2*i + 2;

    if (l_child < n && A[l_child] < A[smallest])
        smallest = l_child;

    if (r_child < n && A[r_child] < A[smallest])
        smallest = r_child;

    if (smallest != i)
    {
        swap(&A[i], &A[smallest]);
        min_heap(A, n, smallest);
    }
}

void heap_sort(int A[], int n)
{
    for (int i = (n/2)-1; i >= 0; i--)
    {
        min_heap(A, n, i);
    }

    for (int i = n-1; i >= 0; i--)
    {
        swap(&A[0], &A[i]);
        min_heap(A, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    int A[n];

    printf("Enter array: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }

    heap_sort(A, n);

    printf("Sorted array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }

    return 0;
}


