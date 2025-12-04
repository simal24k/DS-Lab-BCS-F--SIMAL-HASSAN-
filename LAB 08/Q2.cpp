
//rotation method
#include <iostream>
using namespace std;

class Node
{
public:
    int key, height;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *n)
{
    return n ? n->height : 0;
}

int getBalance(Node *n)
{
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node *update(Node *n)
{
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    return n;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    update(y);
    update(x);

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    update(x);
    update(y);

    return y;
}

Node *insertNode(Node *root, int key)
{
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);

    update(root);

    int balance = getBalance(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printTree(Node *root)
{
    if (!root)
        return;
    printTree(root->left);
    cout << root->key << " ";
    printTree(root->right);
}

int main()
{
    Node *root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = insertNode(root, arr[i]);

    root = insertNode(root, 55);

    root = leftRotate(root);

    cout << "Tree after inserting 55 and left rotating root: ";
    printTree(root);

    return 0;
}
