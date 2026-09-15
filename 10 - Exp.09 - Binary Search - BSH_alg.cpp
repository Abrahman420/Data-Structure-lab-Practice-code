#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Array Size: ";
    cin >> n;

    int a[n];

    cout << "Enter elements in sorted order: ";
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int x;
    cout << "Search Element: ";
    cin >> x;

    int left = 0;
    int right = n - 1;
    int found = 0;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(a[mid] == x)
        {
            cout << "Element found at position: " << mid + 1;
            found = 1;
            break;
        }
        else if(a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if(found == 0)
    {
        cout << "Element not found";
    }

    return 0;
}
