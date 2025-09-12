#include <iostream>
using namespace std;

int main() {
    int CEO = 0;
    int CTO = 1;
    int CFO = 2;
    int VP  = 3;
    int MGR = 4;
    int EMP = 5;

    int len = 8;
    int roles[8] = {EMP, CFO, MGR, EMP, VP, CTO, MGR, CEO};

    for (int i = 1; i < len; i++) {
        int hold = roles[i];
        int j = i - 1;

        while (j >= 0 && roles[j] > hold) {
            roles[j + 1] = roles[j];
            j--;
        }
        roles[j + 1] = hold;
    }

    cout << "After sorting:" << endl;
    for (int i = 0; i < len; i++) {
        string title = (roles[i] == 0) ? "CEO" :
                       (roles[i] == 1) ? "CTO" :
                       (roles[i] == 2) ? "CFO" :
                       (roles[i] == 3) ? "VP"  :
                       (roles[i] == 4) ? "MGR" : "EMP";
        cout << title << endl;
    }

    return 0;
}
