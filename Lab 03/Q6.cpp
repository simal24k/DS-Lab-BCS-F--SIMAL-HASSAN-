#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* nxt;
    Node* down;
    Node(int x){ val=x; nxt=NULL; down=NULL; }
};

class MultiList {
public:
    Node* head;
    MultiList(){ head=NULL; }

    void add(int x){
        Node* n=new Node(x);
        if(!head){ head=n; return; }
        Node* t=head;
        while(t->nxt) t=t->nxt;
        t->nxt=n;
    }

    void attachChild(int key, Node* c){
        Node* t=head;
        while(t && t->val!=key) t=t->nxt;
        if(t) t->down=c;
    }
};

Node* flatten(Node* head){
    Node* cur=head;
    while(cur){
        if(cur->down){
            Node* nxt=cur->nxt;
            cur->nxt=cur->down;
            Node* tmp=cur->down;
            while(tmp->nxt) tmp=tmp->nxt;
            tmp->nxt=nxt;
            cur->down=NULL;
        }
        cur=cur->nxt;
    }
    return head;
}

void display(Node* h){
    while(h){
        cout<<h->val<<" ";
        h=h->nxt;
    }
    cout<<endl;
}

int main(){
    MultiList ml;
    ml.add(18); 
    ml.add(9); 
    ml.add(18);

    MultiList child;
    child.add(40); 
    child.add(25);

    ml.attachChild(3, child.head);

    Node* res  = flatten(ml.head);
    display(res);
}

