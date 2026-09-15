#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertTail(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);

    if(tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void searchElement(Node* head, int x)
{
    Node* tmp = head;
    int pos = 1;

    while(tmp != NULL)
    {
        if(tmp->val == x)
        {
            cout << "Element found at position: " << pos << endl;
            return;
        }

        tmp = tmp->next;
        pos++;
    }

    cout << "Element not found" << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    cout << "List Size: ";
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        insertTail(head, tail, x);
    }

    cout << "Search Element: ";
    int x;
    cin >> x;

    searchElement(head, x);

    return 0;
}
