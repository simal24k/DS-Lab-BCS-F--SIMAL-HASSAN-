#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter readings per day: ";
    cin >> m;

    double** temp = new double*[n];
    for (int i = 0; i < n; i++) {
        temp[i] = new double[m];
        cout << "Day " << i+1 << " readings\n";
        for (int j = 0; j < m; j++) {
            cout<<"Reading "<<j+1<<endl;
            cin >> temp[i][j];
        }
    }

    double* avg = new double[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) sum += temp[i][j];
        avg[i] = sum / m;
        cout << "Day " << i+1 << " -> Avg temp = " << avg[i] << endl;
    }

    int hot = 0, cold = 0;
    for (int i = 1; i < n; i++) {
        if (avg[i] > avg[hot]) hot = i;
        if (avg[i] < avg[cold]) cold = i;
    }

    cout << "\nHottest day:\n Day " << hot+1 << " (Avg = " << avg[hot] << ")\n";
    cout << "Coldest day:\n Day " << cold+1 << " (Avg = " << avg[cold] << ")\n";

    for (int i = 0; i < n; i++) {
        delete[] temp[i];
    }
    delete[] temp;
    delete[] avg;

    return 0;
}
