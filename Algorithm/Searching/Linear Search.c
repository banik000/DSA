#include<stdio.h>

int main()
{
    int n, i, key, flag = 0;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    int a[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter search element: ");
    scanf("%d", &key);

    for(i=0; i<n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            break;
        }
    }

    if(flag)
        printf("Element found at location %d", i+1);
    else
        printf("Element not found");

    return 0;
}
