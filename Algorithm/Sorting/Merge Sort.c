#include<stdio.h>
#include<stdlib.h>

void merge(int A[], int L[], int R[], int len_L, int len_R)
{
    int i=0, j=0, k=0;

    while(i < len_L && j < len_R)
    {
        if(L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while(i < len_L)
    {
        A[k++] = L[i++];
    }

    while(j < len_R)
    {
        A[k++] = R[j++];
    }
}

void merge_sort(int A[], int n)
{
    int i, mid;

    if(n<2)
        return;

    mid = n/2;

    int* L = (int*)malloc(mid*sizeof(int));
    int* R = (int*)malloc((n-mid)*sizeof(int));

    for(i=0; i<mid; i++)
    {
        L[i] = A[i];
    }

    for(i=mid; i<n; i++)
    {
        R[i-mid] = A[i];
    }

    merge_sort(L, mid);
    merge_sort(R, n-mid);
    merge(A, L, R, mid, n-mid);

    free(L);
    free(R);
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

    merge_sort(A, n);

    printf("Sorted array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }

    return 0;
}

