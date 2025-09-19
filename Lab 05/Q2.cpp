#include<iostream>
using namespace std;

void printNumbers(int n) {
    if (n < 1) {
        
        return;
    }

    cout << n << " \n ";

    printNumbers(n - 1);
}
void functionB(int n);
void functionA(int n){
        if (n < 1) {
        
        return;
    }

    cout << n << " \n ";

    functionB(n - 1);
}
void functionB(int n){        
    if (n < 1) {
        
        return;
    }

    cout << n << " \n ";

    functionA(n - 1);
}
int main() {
    int nums;
    cout<<"Enter number: "<<endl;
    cin>>nums; 
    printNumbers(nums);
    cout<<"Function A: "<<endl;
    functionA(nums);
    cout<<"Function B: "<<endl;
    functionB(nums);
    return 0;
}
