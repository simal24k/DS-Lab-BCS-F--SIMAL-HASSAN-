#include <iostream>
using namespace std;

void Linear(int arr[], int x, int n){
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            cout<<"Found at index "<<i+1<<endl;
            flag=true;
        }
    }
    if(!flag){
        cout<<"Not found"<<endl;
    }
}

int main(){
    int sz;
    cout<<"Size of array: ";
    cin>>sz;

    int *data=new int[sz];
    for(int i=0;i<sz;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>data[i];
    }

    int val;
    cout<<"Enter value to search: ";
    cin>>val;

    Linear(data,val,sz);

    delete[] data;
    return 0;
}
