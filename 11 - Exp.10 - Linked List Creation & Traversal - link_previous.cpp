#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *head = NULL;
    Node *temp, *newNode;

    // Creating linked list
    int a[] = {2, 4, 6, 8, 10};

    for (int i = 0; i < 5; i++)
    {
        newNode = new Node;
        newNode->data = a[i];
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Display original list
    cout << "Original list: ";

    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Take item to delete
    int item;
    cout << "\nEnter item to delete: ";
    cin >> item;

    // Delete item
    temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == item)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            delete temp;
            cout << "Item deleted." << endl;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Item not found." << endl;
    }

    // Display final list
    cout << "Final list: ";

    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}
