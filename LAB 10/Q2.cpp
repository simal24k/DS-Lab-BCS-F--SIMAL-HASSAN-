#include <iostream>
using namespace std;

#define MAX 50

class Heap {
private:
    int array[MAX];
    int sarr = 0;

    int parent(int i){ return (i - 1) / 2; }
    int left(int i){ return 2 * i + 1; }
    int right(int i){ return 2 * i + 2; }

    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }

    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if(l < sarr && array[l] < array[smallest])
            smallest = l;
        if(r < sarr && array[r] < array[smallest])
            smallest = r;

        if(smallest != i){
            swap(array[i], array[smallest]);
            heapify(smallest);
        }
    }

public:
   
    void insert(int val){
        array[sarr] = val;
        int i = sarr;
        sarr++;

        while(i != 0 && array[parent(i)] > array[i]){
            swap(array[i], array[parent(i)]);
            i = parent(i);
        }
    }

    void updatekey(int i, int new_val){
        array[i] = new_val;

        while(i != 0 && array[parent(i)] > array[i]){
            swap(array[i], array[parent(i)]);
            i = parent(i);
        }

        heapify(i);
    }

    void delmin(int i){
        array[i] = array[sarr - 1];
        sarr--;

        heapify(i);
    }

    void printHeap(){
        for(int i = 0; i < sarr; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    bool isHeap(int arr[], int n){
        for(int i = 0; i <= (n - 2) / 2; i++){
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n && arr[i] > arr[l]) return false;
            if(r < n && arr[i] > arr[r]) return false;
        }
        return true;
    }

    
    void maxHeapify(int arr[], int n, int i){
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l < n && arr[l] > arr[largest]) largest = l;
        if(r < n && arr[r] > arr[largest]) largest = r;

        if(largest != i){
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

    
    void heapSortAsc(int arr[], int n){
    
        for(int i = n/2 - 1; i >= 0; i--)
            maxHeapify(arr, n, i);

    
        for(int i = n - 1; i >= 1; i--){
            swap(arr[0], arr[i]);
            maxHeapify(arr, i, 0);
        }
    }
};


int main(){
    Heap h;
    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);

    cout << "Initial Min Heap: ";
    h.printHeap();

    h.updatekey(2, 1);
    cout << "After update: ";
    h.printHeap();

    h.delmin(1);
    cout << "After delete: ";
    h.printHeap();
     int test[] = {3, 5, 9, 6, 8, 20, 10};
    int n = 7;

    cout << "Is Heap? " << h.isHeap(test, n) << endl;

    h.heapSortAsc(test, n);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) cout << test[i] << " ";
    cout << endl;
}

