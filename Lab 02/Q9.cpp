#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows: ";
    cin >> r;
    cout << "Enter cols: ";
    cin >> c;

    int** mat = new int*[r];
    for (int i = 0; i < r; i++) {
        mat[i] = new int[c];
        for (int j = 0; j < c; j++) {
            cout << "Value at [" << i+1 << "][" << j+1 << "]: ";
            cin >> mat[i][j];
        }
    }

    cout << "\n--- Normal Matrix ---\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "\n--- Compressed (row col val) ---\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                cout << i+1 << "  " << j+1 << "  " << mat[i][j] << endl;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}
