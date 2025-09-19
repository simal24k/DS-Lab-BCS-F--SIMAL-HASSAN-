#include <iostream>
using namespace std;

int sumTail(int n, int total) {
    if (n == 0) {
        
        return total;
    }
   
    return sumTail(n - 1, total + n);
}


int sumNonTail(int n) {
    if (n == 0) {
        
        return 0;
    }
   
    return sumNonTail(n - 1) + n;
}

int main() {
    int n = 7; 

   
    int tailResult = sumTail(n, 0);
    cout << "Sum (Tail Recursion) from 1 to " << n << ": " << tailResult << endl;

  
    int nonTailResult = sumNonTail(n);  
    cout << "Sum (Non-Tail Recursion) from 1 to " << n << ": " << nonTailResult << endl;

    return 0;
}
