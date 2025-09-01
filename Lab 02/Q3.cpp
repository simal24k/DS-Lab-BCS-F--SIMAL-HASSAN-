#include <iostream>
using namespace std;

int main() {
    int st;
    cout << "Enter number of students: ";
    cin >> st;

    int* crs = new int[st];         
    int** marks = new int*[st];      
    
    for (int i = 0; i < st; i++) {
        cout << "Enter number of courses for student " << i + 1 << ": ";
        cin >> crs[i];
        marks[i] = new int[crs[i]];

        cout << "Enter marks for student " << i + 1 << ": " << endl;
        for (int j = 0; j < crs[i]; j++) {
            cout << "Course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\n--- Student Averages ---" << endl;
    for (int i = 0; i < st; i++) {
        int sum = 0;
        for (int j = 0; j < crs[i]; j++) {
            sum += marks[i][j];
        }
        double avg = (double) sum / crs[i];
        cout << "Student " << i + 1 << " average = " << avg << endl;
    }

    // free memory
    for (int i = 0; i < st; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] crs;

    return 0;
}

