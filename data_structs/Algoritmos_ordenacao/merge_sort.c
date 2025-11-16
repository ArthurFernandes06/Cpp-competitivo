#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r-q;

    int L[n1];
    int R[n2];


    for(int i = 0; i < n1; ++i)
    {
        L[i] = A[i + p];

    }

    for(int i = 0; i < n2; ++i)
    {
        R[i] = A[i+ q + 1];
    }

    int i = 0, j = 0,k = p;
    while(i < n1 && j <n2)
    {
        if(L[i] < R[j])
        {
            A[k] = L[i];
            i++;
            k++;
        }else
        {
            A[k] = R[j];
            j++;
            k++;
        }
    }
    while(j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }

    while(i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
}

void merge_sort(int A[], int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

int main()
{
    int n = 6;
    int A[6] = {1,100,150,2,1,200};
    merge_sort(A,0,5);


    for(int i =0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    return EXIT_SUCCESS;
}