#include <iostream>
using namespace std;
int partition(int A[], int lo, int hi)
{
    int pivot = A[hi];
    int i = lo - 1;
    for (int j = lo; j <= hi - 1; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i + 1];
    A[i + 1] = A[hi];
    A[hi] = temp;
    return i + 1;
}

void quickSort(int A[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = partition(A, lo, hi);
        quickSort(A, lo, p - 1);
        quickSort(A, p + 1, hi);
    }
}


int main()
{
    int A[] = {10, 7, 8, 9, 1, 5};

    int n = 6;

    cout << "Before sorting..." << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    quickSort(A, 0, n - 1);

    cout << "\nAfter sorting..." << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
