#include <iostream>
using namespace std;

class SafePtr {
    int* p;
public:
    SafePtr() { p = nullptr; }

    void setVal(int v) {
        if (!p) p = new int;
        *p = v;
    }

    int getVal() {
        return (p ? *p : 0);
    }

    void free() {
        delete p;
        p = nullptr;
    }

    ~SafePtr() { free(); }
};

int main() {
    SafePtr arr[5];

    for (int i = 0; i < 5; i++) {
        int m;
        cout << "Marks for student " << i+1 << ": ";
        cin >> m;
        arr[i].setVal(m);
    }

    cout << "\nStored Marks:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i+1 << " -> " << arr[i].getVal() << endl;
    }

    for (int i = 0; i < 5; i++) {
        arr[i].free();
    }

    return 0;
}





