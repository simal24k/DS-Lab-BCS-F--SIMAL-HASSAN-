#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int v){ data=v; next=NULL; }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){ head=NULL; }

    void insert(int v){
        Node* p=new Node(v);
        if(!head){ head=p; return; }
        Node* q=head;
        while(q->next) q=q->next;
        q->next=p;
    }
    void display(){
        Node* r=head;
        while(r){ cout<<r->data<<" "; r=r->next; }
        cout<<endl;
    }
    static Node* reverseK(Node* start,int k){
        if(!start) return NULL;
        Node* a=start; Node* b=NULL; Node* c=NULL; int cnt=0;
        while(a && cnt<k){
            c=a->next;
            a->next=b;
            b=a;
            a=c;
            cnt++;
        }
        if(c) start->next=reverseK(c,k);
        return b;
    }
};

int main(){
    LinkedList obj;
    for(int i=1;i<=8;i++) obj.insert(i);

    cout<<"Before: "; obj.display();
    obj.head = LinkedList::reverseK(obj.head,14);
    cout<<"After: "; obj.display();
}
