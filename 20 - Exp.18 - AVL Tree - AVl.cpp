#include <iostream>
using namespace std;

struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;
};

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

Node* createNode(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node *x)
{
    Node *y = x->right;
    Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

Node* insert(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = max(height(root->left),
                       height(root->right)) + 1;

    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    // Right Right
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    // Left Right
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* findMin(Node *root)
{
    Node *temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

Node* deleteNode(Node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            Node *temp;

            if (root->left != NULL)
                temp = root->left;
            else
                temp = root->right;

            if (temp == NULL)
            {
                delete root;
                return NULL;
            }
            else
            {
                *root = *temp;
                delete temp;
            }
        }
        else
        {
            Node *temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    root->height = max(height(root->left),
                       height(root->right)) + 1;

    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    int choice, value;

    while (true)
    {
        cout << "\n--- AVL Tree Menu ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;

            root = insert(root, value);

            cout << "Element inserted." << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter value to delete: ";
            cin >> value;

            if (search(root, value))
            {
                root = deleteNode(root, value);
                cout << "Element deleted." << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Enter key to search: ";
            cin >> value;

            if (search(root, value))
                cout << "Element found." << endl;
            else
                cout << "Element not found." << endl;
        }
        else if (choice == 4)
        {
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
