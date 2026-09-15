#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void PUSH(int value)
{
    if (top == SIZE - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void POP()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Deleted element: " << stack[top] << endl;
        top--;
    }
}

void Display()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n1. PUSH";
        cout << "\n2. POP";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            PUSH(value);
            break;

        case 2:
            POP();
            break;

        case 3:
            Display();
            break;

        case 4:
            cout << "Exit";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}
