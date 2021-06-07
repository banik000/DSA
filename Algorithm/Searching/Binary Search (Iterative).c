#include<stdio.h>

int binary_search(int A[], int l, int h, int key)
{
    while(l <= h)
    {
        int mid = l + (h-l)/2;

        if(key == A[mid])
            return mid;

        if(key < A[mid])
        {
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return -1; //element is not present if l > h, i.e. after coincide point is crossed
}

int main()
{
    int n, key;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    int A[n];

    printf("Enter array in sorted order: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }

    //assume array to be sorted

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binary_search(A,0,n-1,key);

    if(result == -1)
        printf("Element not found");
    else
        printf("Element found at location %d", result+1);

    return 0;
}
