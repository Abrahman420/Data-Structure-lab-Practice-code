#include <iostream>
using namespace std;

#define SIZE 5

char queue[SIZE];
int front = -1;
int rear = -1;

void insert()
{
    char item;

    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue Overflow!" << endl;
        return;
    }

    cout << "Enter character: ";
    cin >> item;

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = item;

    cout << "Element inserted successfully." << endl;
}

void deleteElement()
{
    char item;

    if (front == -1)
    {
        cout << "Queue Underflow!" << endl;
        return;
    }

    item = queue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }

    cout << "Deleted element: " << item << endl;
}

void display()
{
    int i;

    if (front == -1)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Circular Queue: ";

    i = front;

    while (true)
    {
        cout << queue[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n--- Circular Queue Menu ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            insert();
        }
        else if (choice == 2)
        {
            deleteElement();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            cout << "Program ended." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
