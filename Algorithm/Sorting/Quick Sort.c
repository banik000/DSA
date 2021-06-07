#include<stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int A[], int start, int end)
{
    int pivot = A[end];
    int pi = start;

    for(int i=start; i <= end-1; i++)
    {
        if(A[i] <= pivot)
        {
            swap(&A[i], &A[pi]);
            pi++;
        }
    }
    swap(&A[pi], &A[end]);

    return pi;
}

void quick_sort(int A[], int start, int end)
{
    if(start < end)
    {
        int pi = partition(A, start, end);

        quick_sort(A, start, pi-1);
        quick_sort(A, pi+1, end);
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

    quick_sort(A, 0, n-1);

    printf("Sorted array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }

    return 0;
}
