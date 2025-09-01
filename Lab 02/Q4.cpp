#include <iostream>
using namespace std;

double* resize(double* arr, int osize, int nsize) {
    double* tmp = new double[nsize];
    int limit = (osize < nsize) ? osize : nsize;

    for (int i = 0; i < limit; i++) {
        tmp[i] = arr[i];
    }
    delete[] arr;
    return tmp;
}

int main() {
    int n;
    cout << "Enter months to track: ";
    cin >> n;

    double* exp = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Expense for month " << i + 1 << ": ";
        cin >> exp[i];
    }

    int m;
    cout << "Enter new size if you want to expand monthly tracking: ";
    cin >> m;
    exp = resize(exp, n, m);

    if (m > n) {
        for (int i = n; i < m; i++) {
            cout << "Expense for new month " << i + 1 << ": ";
            cin >> exp[i];
        }
    }

    double total = 0;
    for (int i = 0; i < m; i++) {
        total += exp[i];
    }

    cout << "\nTotal = " << total;
    cout << "\nAverage = " << (total / m) << endl;

    delete[] exp;
    return 0;
}
