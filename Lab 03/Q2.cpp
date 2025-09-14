#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    LinkedList(Node* ptr) : head(ptr) {}

    void Insertion(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << "[" << temp->data << "] ";   // ✅ values shown in brackets
            temp = temp->next;
        }
        cout << endl;
    }
};

// Merge two sorted linked lists (without creating new nodes)
Node* mergeList(Node* head1, Node* head2) {
    Node dummy(-1);         
    Node* tail = &dummy;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1) tail->next = head1;
    else       tail->next = head2;

    return dummy.next;
}

int main() {
    LinkedList l1, l2;

    l1.Insertion(1);
    l1.Insertion(10);
    l1.Insertion(15);

    l2.Insertion(20);
    l2.Insertion(25);
    l2.Insertion(30);

    cout << "List 1: ";
    l1.display();
    cout << "List 2: ";
    l2.display();

    Node* mergedHead = mergeList(l1.head, l2.head);
    LinkedList merged(mergedHead);

    cout << "Merged List: ";
    merged.display();

    return 0;
}
