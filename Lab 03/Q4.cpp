#include <iostream>
using namespace std;

class Person{
public:
    int id;
    Person* link;
    Person(int v){ id=v; link=NULL; }
};

class Circle{
public:
    Person* head;
    Circle(){ head=NULL; }

    void insert(int v){
        Person* p=new Person(v);
        if(!head){
            head=p;
            p->link=head;
            return;
        }
        Person* q=head;
        while(q->link!=head) q=q->link;
        q->link=p;
        p->link=head;
    }

    void remove(Person* prev){
        Person* del=prev->link;
        prev->link=del->link;
        delete del;
    }
};

int josephus(int n,int k){
    Circle obj;
    for(int i=1;i<=n;i++) obj.insert(i);

    Person* cur=obj.head;
    Person* prev=NULL;

    while(cur->link!=cur){
        for(int step=1;step<k;step++){
            prev=cur;
            cur=cur->link;
        }
        obj.remove(prev);
        cur=prev->link;
    }
    return cur->id;
}

int main(){
    int people,skip;
    cout<<"Enter total people: ";
    cin>>people;
    cout<<"Enter k: ";
    cin>>skip;
    cout<<"Survivor position: "<<josephus(people,skip)<<endl;
    return 0;
}

