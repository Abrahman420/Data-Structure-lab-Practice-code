#include <iostream>
using namespace std;

int main()
{
    int a[100], n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    // Selection Sort
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
            min = j;
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    cout << "Sorted elements: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
