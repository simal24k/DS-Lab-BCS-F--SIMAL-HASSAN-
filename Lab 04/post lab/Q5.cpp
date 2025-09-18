#include<iostream>
using namespace std;

int IPsearch(int arr[], int n, int target) {
    int l=0, h=n-1;
    while (l <= h && target >= arr[l] && target <= arr[h]) {
        if (arr[h] == arr[l]) {
            if (arr[l] == target) return l;
            else break;
        }
        int pos = l + ((target - arr[l]) * (h- l)) / (arr[h] - arr[l]);
        if (arr[pos] == target)
         {  return pos;}
        else if (arr[pos] < target)
            {l = pos + 1;}
        else
       { h = pos - 1;}
    }
        return -1;
}

int main(){
    int n;
    cout << "Enter the number of elements in array : ";
    cin >> n;
    int* arr= new int[n];

    cout <<"Enter the number of elements in array in sorted form\n" << endl;
    for(int i = 0 ; i < n ; i++){
        cout << "Enter the element " << i + 1 << ":" ;
        cin >> arr[i]; 
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int index = IPsearch(arr , n , target);
    if(index != -1){
        cout << "ELement is found at index " << index << endl;     
    }
    else{
        cout << "Element not found." << endl;
    }
    delete[] arr;
    return 0;
}
