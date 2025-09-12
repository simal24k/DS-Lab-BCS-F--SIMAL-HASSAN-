#include <iostream>
using namespace std;

int interpSearch(int nums[], int count, int key) {
    int low = 0, high = count - 1;
    while (low <= high && key >= nums[low] && key <= nums[high]) {
        if (nums[high] == nums[low]) {
            if (nums[low] == key) return low;
            else break;
        }
        int pos = low + ((key - nums[low]) * (high - low)) / (nums[high] - nums[low]);
        if (nums[pos] == key) return pos;
        else if (nums[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

bool checkUniform(int nums[], int count) {
    int gap = nums[1] - nums[0];
    for (int i = 2; i < count; i++) {
        if (nums[i] - nums[i - 1] != gap) return false;
    }
    return true;
}

void sortBubble(int nums[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int swap = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = swap;
            }
        }
    }
}

int main() {
    int count, key;
    cout << "How many balances? ";
    cin >> count;

    int nums[100];
    cout << "Enter balances: ";
    for (int i = 0; i < count; i++) {
        cin >> nums[i];
    }

    sortBubble(nums, count);

    if (!checkUniform(nums, count)) {
        cout << "Data isn’t uniformly spaced." << endl;
        return 0;
    }

    cout << "Balance to find: ";
    cin >> key;

    int res = interpSearch(nums, count, key);
    if (res != -1)
        cout << "Found " << key << " at position " << res << endl;
    else
        cout << "Balance not found" << endl;

    return 0;
}
