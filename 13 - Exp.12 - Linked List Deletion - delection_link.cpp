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
    tail = tail->next;
}

void deleteItem(Node* &head, int idx)
{
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    if(idx == 1)
    {
        Node* delNode = head;
        head = head->next;
        delete delNode;
        return;
    }

    Node* tmp = head;

    for(int i=1; i<idx-1; i++)
    {
        tmp = tmp->next;
    }

    if(tmp->next == NULL)
    {
        cout << "Invalid position";
        return;
    }

    Node* delNode = tmp->next;
    tmp->next = delNode->next;
    delete delNode;
}

void traverse(Node* head)
{
    Node* tmp = head;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
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

    cout << "Delete Position: ";
    int idx;
    cin >> idx;

    deleteItem(head, idx);

    cout << "Linked List: ";
    traverse(head);

    return 0;
}
