#include <iostream>
using namespace std;

int main()
{
    int a[] = {18, 25, 75, 3, 90};
    int n = 5;
    int temp;

    cout << "Before sorting: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    // Bubble Sort
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
        {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
     }
     }
     }
    cout << "\nAfter sorting: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
    }
