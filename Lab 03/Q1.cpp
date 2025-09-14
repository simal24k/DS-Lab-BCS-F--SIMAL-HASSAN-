#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void insert(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = n;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

bool checkPalindrome(LinkedList& L){
    if(L.head == NULL || L.head->next == NULL){
        return true;
    }
    Node* slow = L.head;
    Node* fast = L.head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second = reverse(slow->next);
    Node* first = L.head;
    Node* sec = second;
    bool ok = true;
    while(sec != NULL){
        if(first->data != sec->data){
            ok = false;
            break;
        }
        first = first->next;
        sec = sec->next;
    }
    slow->next = reverse(second); // restoring list
    return ok;
}

int main(){
    LinkedList L1;
    int n,val;
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter value: ";
        cin >> val;
        L1.insert(val);
    }
    if(checkPalindrome(L1)){
        cout << "It is a palindrome" << endl;
    }
    else{
        cout << "It is NOT a palindrome" << endl;
    }
    return 0;
}
