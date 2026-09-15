#include <iostream>
using namespace std;

int main()
{
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Bubble Sort
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(a[j] > a[j + 1])
        {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
        }
        }
    }

    cout << "Sorted elements: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
