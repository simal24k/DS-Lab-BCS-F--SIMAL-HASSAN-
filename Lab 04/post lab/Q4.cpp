#include<iostream>
using namespace std;

void insert(int a[], int n){
    for(int i=1;i<n;i++){
        int cur=a[i];
        int j=i-1;
        while(j>=0 && a[j]>cur){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=cur;
    }
}

void binSearch(int a[], int n, int key){
    int low=0, high=n-1;
    bool flag=false;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            cout<<"Found at index "<<mid+1<<endl;
            flag=true;
            break;
        }
        else if(key<a[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(!flag) cout<<"Value not found"<<endl;
}

int main(){
    int sz;
    cout<<"Enter size of array: ";
    cin>>sz;

    int *nums=new int[sz];
    for(int i=0;i<sz;i++){
        cout<<"Value "<<i+1<<": ";
        cin>>nums[i];
    }

    int x;
    cout<<"Enter number to search: ";
    cin>>x;

    insert(nums,sz);

    cout<<"Insertion - Sorted array: ";
    for(int i=0;i<sz;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    binSearch(nums,sz,x);

    delete[] nums;
    return 0;
}
