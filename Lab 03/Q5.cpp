#include <iostream>
using namespace std;

class SNode{
public:
    int val;
    SNode* next;
    SNode(int x){ val=x; next=NULL; }
};

class DNode{
public:
    int val;
    DNode* next;
    DNode* prev;
    DNode(int x){ val=x; next=NULL; prev=NULL; }
};

class Single{
public:
    SNode* head;
    Single(){ head=NULL; }

    void insert(int x){
        SNode* p=new SNode(x);
        if(!head){ head=p; return; }
        SNode* q=head;
        while(q->next) q=q->next;
        q->next=p;
    }

    void display(){
        SNode* t=head;
        while(t){ cout<<t->val<<" "; t=t->next; }
        cout<<endl;
    }

    DNode* toDouble(){
        if(!head) return NULL;
        SNode* a=head;
        DNode* dh=NULL; DNode* prev=NULL;
        while(a){
            DNode* dn=new DNode(a->val);
            if(!dh) dh=dn;
            dn->prev=prev;
            if(prev) prev->next=dn;
            prev=dn;
            a=a->next;
        }
        return dh;
    }

    SNode* toCircle(){
        if(!head) return NULL;
        SNode* r=head;
        while(r->next) r=r->next;
        r->next=head;
        return head;
    }
};

void showDouble(DNode* h){
    while(h){ cout<<h->val<<" "; h=h->next; }
    cout<<endl;
}

void showCircle(SNode* h,int n){
    SNode* t=h;
    for(int i=0;i<n;i++){
        cout<<t->val<<" ";
        t=t->next;
    }
    cout<<endl;
}

int main(){
    Single obj;
    obj.insert(5); obj.insert(15); obj.insert(25); obj.insert(35);

    cout<<"Singly: "; obj.display();

    DNode* d=obj.toDouble();
    cout<<"Doubly: "; showDouble(d);

    SNode* c=obj.toCircle();
    cout<<"Circular: "; showCircle(c,10);
}

