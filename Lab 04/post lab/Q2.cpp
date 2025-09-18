#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int pass=0; pass<n; pass++){
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}

void showArr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int sz;
    cout<<"Enter array size: ";
    cin>>sz;

    int *nums=new int[sz];
    for(int i=0;i<sz;i++){
        cout<<"Value "<<i+1<<": ";
        cin>>nums[i];
    }

    cout<<"Before sorting:"<<endl;
    showArr(nums,sz);

    bubbleSort(nums,sz);

    cout<<"After sorting:"<<endl;
    showArr(nums,sz);

    delete[] nums;
    return 0;
}
