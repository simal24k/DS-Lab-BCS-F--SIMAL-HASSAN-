#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter how many numbers you want to sort: ";
    cin >> size;

    int *nums = new int[size];

    for (int idx = 0; idx < size; idx++) {
        cout << "Enter number " << idx + 1 << ": ";
        cin >> nums[idx];
    }

    for (int pass = 0; pass < size; pass++) {
        for (int k = 0; k < size - pass - 1; k++) {
            if (nums[k] > nums[k + 1]) {
                int swap = nums[k];
                nums[k] = nums[k + 1];
                nums[k + 1] = swap;
            }
        }
    }

    cout << "\nNumbers after sorting:" << endl;
    for (int idx = 0; idx < size; idx++) {
        cout << nums[idx] << " ";
    }

    cout << endl;
    delete[] nums;
}
