#include <iostream>
using namespace std;

int main() {
    int d;
    cout << "Enter number of departments: ";
    cin >> d;

    int* emp = new int[d];
    int** salary = new int*[d];

    for (int i = 0; i < d; i++) {
        cout << "Employees in department " << i+1 << ": ";
        cin >> emp[i];
        salary[i] = new int[emp[i]];

        cout << "Enter salaries for department " << i+1 << ":\n";
        for (int j = 0; j < emp[i]; j++) {
            cout<<"Employee "<<j+1<<endl;
            cin >> salary[i][j];
        }
    }

    double topAvg = 0.0;
    int topDept = -1;

    for (int i = 0; i < d; i++) {
        if (emp[i] == 0) {
            cout << "Dept " << i+1 << " has no employees.\n";
            continue;
        }

        int high = salary[i][0];
        double sum = salary[i][0];

        for (int j = 1; j < emp[i]; j++) {
            if (salary[i][j] > high) high = salary[i][j];
            sum += salary[i][j];
        }

        double avg = sum / emp[i];
        cout << "Dept " << i+1 << " -> Highest = " << high << ", Avg = " << avg << endl;

        if (avg > topAvg || topDept == -1) {
            topAvg = avg;
            topDept = i;
        }
    }

    if (topDept != -1) {
        cout << "\nDept " << topDept+1 << " has the highest avg salary = " << topAvg << endl;
    }

    for (int i = 0; i < d; i++) {
        delete[] salary[i];
    }
    delete[] salary;
    delete[] emp;

    return 0;
}


