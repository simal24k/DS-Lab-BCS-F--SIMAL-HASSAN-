#include <iostream>
using namespace std;

class Exam{
string *stname;
string *examdate;
float *marks;
public:
Exam(string name, string date, float m){
    stname = new string(name);
    examdate = new string(date);
    marks = new float(m);
  
}
void setname(string name){
    *stname = name;
}
void setdate(string d){
    *examdate = d;
}
void setmark(float mk){
    *marks = mk;
}
void display(){
    cout << "Student's name: "<< *stname <<endl;
    cout << "Exam date: "<< *examdate << endl;
    cout << "Marks scored: "<< *marks << "/100"<< endl;

}
~Exam(){
    delete stname;
    delete marks;
    delete examdate;
}
}
;
int main(){
    Exam st1("John","12/10/24",86.5);
    Exam st2("Shelby", "15/06/25", 94.25);
    st1.display();
    st2.display();
    st2 = st1;
    st2.display();
    st1.display();
// Conclusion: Without a user-defined copy constructor/assignment operator,
// a shallow copy is made. This means both objects point to the same memory,
// which causes problems like double deletion when destructors run.

}