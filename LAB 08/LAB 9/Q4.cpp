//Implement Binary Search Tree with basic operations
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST() { root = NULL; }

    Node *insert(Node *node, int value)
    {
        if (!node)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    Node *findMin(Node *node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node *deleteNode(Node *node, int value)
    {
        if (!node)
            return node;
        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else
        {
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void deleteValue(int value)
    {
        root = deleteNode(root, value);
    }

    bool search(Node *node, int value)
    {
        if (!node)
            return false;
        if (node->data == value)
            return true;
        if (value < node->data)
            return search(node->left, value);
        return search(node->right, value);
    }

    bool search(int value)
    {
        return search(root, value);
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main()
{
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: "<<endl;
    tree.inorder(tree.root);
    cout << "Preorder: "<<endl;
    tree.preorder(tree.root);
    cout << "Postorder: "<<endl;
    tree.postorder(tree.root);

    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found")<<endl;
    cout << "Delete 20"<<endl;
    tree.deleteValue(20);

    cout << "Inorder after delete: "<<endl;
    tree.inorder(tree.root);
}
