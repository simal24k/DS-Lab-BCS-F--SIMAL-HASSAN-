#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter number of elements: ";
    cin>>num;
    int *arr = new int[num];
    cout<<"Enter elements: ";
    for(int i = 0; i < num; i++){
        cin>>arr[i];
    }
    cout<<"Displaying array: ";
    for(int i = 0; i < num; i++){
        cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}
