#include <iostream>
using namespace std;//kth smallest

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

int h(Node *n) { return n ? n->height : 0; }

Node *fix(Node *n)
{
    n->height = 1 + max(h(n->left), h(n->right));
    return n;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    fix(y);
    fix(x);

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    fix(x);
    fix(y);

    return y;
}

int bal(Node *n) { return h(n->left) - h(n->right); }

Node *insertNode(Node *r, int key)
{
    if (!r)
        return new Node(key);

    if (key < r->key)
        r->left = insertNode(r->left, key);
    else
        r->right = insertNode(r->right, key);

    fix(r);

    int b = bal(r);

    if (b > 1 && key < r->left->key)
        return rightRotate(r);
    if (b < -1 && key > r->right->key)
        return leftRotate(r);

    if (b > 1 && key > r->left->key)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    if (b < -1 && key < r->right->key)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

Node *kthSmall(Node *root, int &k)
{
    if (!root)
        return NULL;

    Node *left = kthSmall(root->left, k);
    if (left)
        return left;

    k--;
    if (k == 0)
        return root;

    return kthSmall(root->right, k);
}

Node *kthLarge(Node *root, int &k)
{
    if (!root)
        return NULL;

    Node *right = kthLarge(root->right, k);
    if (right)
        return right;

    k--;
    if (k == 0)
        return root;

    return kthLarge(root->left, k);
}

int main()
{
    Node *root = NULL;
    int arr[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++)
        root = insertNode(root, arr[i]);

    int k1 = 3, k2 = 2;

    Node *s = kthSmall(root, k1);
    Node *l = kthLarge(root, k2);

    cout << "3rd Smallest: " << s->key << endl;
    cout << "2nd Largest: " << l->key << endl;

    cout << "Left Height from Root: " << h(root->left) << endl;
    cout << "Right Height from Root: " << h(root->right) << endl;

    return 0;
}
