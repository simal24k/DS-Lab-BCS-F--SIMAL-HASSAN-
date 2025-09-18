#include <iostream>
using namespace std;

void selection(int arr[], int n){
    for(int i=0;i<n;i++){
        int index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[index]){
                index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
}

int main(){
    int sz;
    cout<<"Enter size of array: ";
    cin>>sz;

    int *nums = new int[sz];
    for(int i=0;i<sz;i++){
        cout<<"Value "<<i+1<<": ";
        cin>>nums[i];
    }

    selection(nums,sz);

    cout<<"Selection sorted array: ";
    for(int i=0;i<sz;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    delete[] nums;
    return 0;
}
