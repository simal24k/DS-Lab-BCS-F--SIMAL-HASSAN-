#include <iostream>
using namespace std;

int binSearch(int ids[], int count, int key, int &pos) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ids[mid] == key) {
            return mid + 1;
        } else if (ids[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    pos = left;
    return -1;
}

int main() {
    int count;
    cout << "How many employee IDs? ";
    cin >> count;

    int *ids = new int[count + 1];
    for (int i = 0; i < count; i++) {
        cout << "Enter ID " << i + 1 << ": ";
        cin >> ids[i];
    }

    int roll;
    cout << "Enter your roll number: ";
    cin >> roll;
    int key = roll % 100;

    int pos = 0;
    int res = binSearch(ids, count, key, pos);

    if (res != -1) {
        cout << "ID found at position " << res << endl;
    } else {
        for (int i = count; i > pos; i--) {
            ids[i] = ids[i - 1];
        }
        ids[pos] = key;
        count++;

        cout << "ID " << key << " not found." << endl;
        cout << "Inserted at position " << pos << endl;
        cout << "Updated list: ";
        for (int i = 0; i < count; i++) {
            cout << ids[i] << " ";
        }
        cout << endl;
    }

    delete[] ids;
    return 0;
}
