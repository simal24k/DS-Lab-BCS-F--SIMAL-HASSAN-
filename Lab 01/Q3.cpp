#include <iostream>
using namespace std;

class Box{
int *num;
public:
Box(int n=0){
    num = new int(n);
}
//copy constructor - deep copy
Box(const Box& other){
    num = new int(*other.num);
}
 // Copy assignment operator -deep copy
Box& operator=(const Box& other) {
        if (this != &other) { 
            delete num;       
            num = new int(*other.num); 
        }
        return *this;
    }
void setValue(int n) {
        *num = n;
    }

    int getValue() const {
        return *num;
    }
~Box(){
    delete num;
}
};

int main(){
    //copy constructor
    Box b1(10);
    Box b2 = b1;
    cout << "Copy constructor\n"<<endl;
    cout <<"b1 = "<< b1.getValue() << "\nb2 = " << b2.getValue() << endl;
    b2.setValue(14);
    cout <<"After b2 changed\n b1 = "<< b1.getValue() << "\nb2 = " << b2.getValue() << endl;

    //Copy assignment operator 
    Box b3(45);
    b3 = b1;
    cout << "b3 after assignment = " << b3.getValue() << endl;
    return 0;
}
// Rule of Three applied:
// 1. Copy constructor → creates deep copy (new memory).
// 2. Copy assignment operator → deletes old memory, copies new value safely.
// 3. Destructor → frees memory. 