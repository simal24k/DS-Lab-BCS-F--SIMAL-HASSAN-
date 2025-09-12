#include <iostream>
using namespace std;

void findLinear(int nums[], int look, int len) {
    bool found = false;
    for (int i = 0; i < len; i++) {
        if (nums[i] == look) {
            cout << "Found at position " << i + 1 << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Not found" << endl;
    }
}

int main() {
    int len;
    cout << "How many numbers? ";
    cin >> len;

    int *nums = new int[len];
    for (int i = 0; i < len; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> nums[i];
    }

    int look;
    cout << "Number to search: ";
    cin >> look;

    findLinear(nums, look, len);

    delete[] nums;
    return 0;
}
