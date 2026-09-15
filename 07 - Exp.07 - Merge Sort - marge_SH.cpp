#include <iostream>
using namespace std;
void merge(int A[], int lo, int mid, int hi)
{
    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[lo + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = lo;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int lo, int hi)
{
    if (lo >= hi)
        return;

    int mid = lo + (hi - lo) / 2;

    mergeSort(A, lo, mid);
    mergeSort(A, mid + 1, hi);

    merge(A, lo, mid, hi);
}


int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10};

    int n = 7;

    cout << "Before sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    mergeSort(A, 0, n - 1);

    cout << "\nAfter sorting:  " << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
