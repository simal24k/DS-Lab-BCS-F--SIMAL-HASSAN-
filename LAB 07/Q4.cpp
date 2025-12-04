#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* getTail(Node* head) {
    while (head && head->next)
        head = head->next;
    return head;
}

void swapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (!*newHead)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (!*newHead)
        *newHead = pivot;

    *newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node* newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(Node** headRef, int data) {
    Node* newNode = new Node{data, nullptr};
    if (!*headRef) {
        *headRef = newNode;
        return;
    }
    Node* temp = *headRef;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;

    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    for (int i = 0; i < 7; i++)
        append(&head, arr[i]);

    quickSort(&head);
    printList(head);

    return 0;
}
