#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* insert(Node *root, int value)
{
    if (root == NULL)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
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

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
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

Node* findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
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
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    Node *root = NULL;

    int a[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};

    // Create BST
    for (int i = 0; i < 12; i++)
    {
        root = insert(root, a[i]);
    }

    int choice, value;

    while (true)
    {
        cout << "\n--- BST Menu ---" << endl;
        cout << "1. Inorder" << endl;
        cout << "2. Preorder" << endl;
        cout << "3. Postorder" << endl;
        cout << "4. Search" << endl;
        cout << "5. Delete" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
        }
        else if (choice == 4)
        {
            cout << "Enter key: ";
            cin >> value;

            if (search(root, value))
                cout << "Element found." << endl;
            else
                cout << "Element not found." << endl;
        }
        else if (choice == 5)
        {
            cout << "Enter element to delete: ";
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
        else if (choice == 6)
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
