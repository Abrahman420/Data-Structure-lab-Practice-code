#include <iostream>
using namespace std;

int main()
{
    int start, end;

    cout << "Enter starting number: ";
    cin >> start;

    cout << "Enter ending number: ";
    cin >> end;

    // Prime numbers
    cout << "\nPrime numbers: ";

    for (int n = start; n <= end; n++)
    {
        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                count++;
            }
        }

        if (count == 2)
        {
            cout << n << " ";
        }
    }

    // Fibonacci numbers
    cout << "\nFibonacci numbers: ";

    int a = 0, b = 1, c;

    while (a <= end)
    {
        if (a >= start)
        {
            cout << a << " ";
        }

        c = a + b;
        a = b;
        b = c;
    }

    cout << endl;

    return 0;
}
