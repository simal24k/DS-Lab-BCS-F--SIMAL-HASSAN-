#include <iostream>
using namespace std;

int main() {
    int r1, c1;
    int r2, c2;

    while (true) {
        cout<<"First Matrix:\n";
        cout << "Rows: ";
        cin >> r1;
        cout << "Cols: ";
        cin >> c1;
        cout<<"Second Matrix:\n";
        cout << "Rows: ";
        cin >> r2;
        cout << "Cols: ";
        cin >> c2;

        if (r1 == r2 && c1 == c2) break;
        cout << "ERROR\n Both matrices must have same size!\n";
    }

    int** m1 = new int*[r1];
    int** m2 = new int*[r1];
    for (int i = 0; i < r1; i++) {
        m1[i] = new int[c1];
        m2[i] = new int[c1];
    }

    cout << "\nEnter values for Matrix 1:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "[" << i+1 << "][" << j+1 << "]: ";
            cin >> m1[i][j];
        }
    }

    cout << "\nEnter values for Matrix 2:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "[" << i+1 << "][" << j+1 << "]: ";
            cin >> m2[i][j];
        }
    }

    int** sum = new int*[r1];
    int** diff = new int*[r1];
    for (int i = 0; i < r1; i++) {
        sum[i] = new int[c1];
        diff[i] = new int[c1];
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            sum[i][j] = m1[i][j] + m2[i][j];
            diff[i][j] = m1[i][j] - m2[i][j];
        }
    }

    cout << "\n--- Addition ---\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) cout << sum[i][j] << " ";
        cout << endl;
    }

    cout << "\n--- Subtraction ---\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) cout << diff[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < r1; i++) {
        delete[] m1[i];
        delete[] m2[i];
        delete[] sum[i];
        delete[] diff[i];
    }
    delete[] m1;
    delete[] m2;
    delete[] sum;
    delete[] diff;

    return 0;
}
