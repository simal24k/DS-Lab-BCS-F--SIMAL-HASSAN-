#include <iostream>
#include <string>//Implement merge sort for runner finish times
using namespace std;

struct Runner {
    string name;
    int finishTime;
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Runner L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].finishTime <= R[j].finishTime)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int n = 10;
    Runner runners[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name of participant " << i + 1 << ": ";
        cin >> runners[i].name;
        cout << "Enter finish time in seconds: ";
        cin >> runners[i].finishTime;
    }

    mergeSort(runners, 0, n - 1);

    cout << "\nTop 5 fastest runners:\n";
    for (int i = 0; i < 5; i++)
        cout << runners[i].name << " - " << runners[i].finishTime << " seconds\n";

    return 0;
}
