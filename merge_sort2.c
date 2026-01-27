#include <stdio.h>
#include <limits.h>
long count=0;

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;

    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i++];
            count++;
        }
        else
        {
            A[k] = R[j++];
            count++;
        }
    }
}

void merge_sort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int A[] = {23, 76, 89, 3, 8, 0, 789, 123, 889, 25};
    int n = sizeof(A) / sizeof(A[0]);

    merge_sort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    
    printf("\n%d",count);

    return 0;
}
