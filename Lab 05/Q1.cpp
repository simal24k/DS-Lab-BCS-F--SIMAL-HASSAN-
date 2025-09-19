#include <iostream>
using namespace std;
int factorial (int num){
    if(num==0 || num == 1){
        return num;
    }
    return num*factorial(num-1);
}
int main(){
    int n;
    cout<<"Enter number: "<<endl;
    cin>>n;
    int f = factorial(n);
    cout<<"Factorial for "<<n<<": \n"<<endl;
    cout<<f<<endl;
}
