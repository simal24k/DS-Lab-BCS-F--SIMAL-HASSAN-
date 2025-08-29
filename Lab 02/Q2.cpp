#include<iostream>
using namespace std;

class Seats{
    int rows, cols;
    int **seating;
    public:
    //initialized
    Seats(int r, int c): rows(r), cols(c) {
         seating = new int*[rows];
        for (int i = 0; i < rows;i++)
            seating[i] = new int[cols];
    }
    
    void fill() {
    int input;
    cout << "Enter Occupied Seats: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
                cout << "Status of seating[" << i+1 << "][" << j+1 << "] :";
                cin >> input;
                if(input != 0 && input != 1) {
                    cout << "Invalid input! Please enter 0 (empty) or 1 (occupied).\n";
                }
                else{
                    seating[i][j] = input;
                }
            } 
            
        }
    }


    void printmatrix(){
        for(int i=0; i<rows;i++){
            for(int j=0; j<cols;j++){
                cout<<seating[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void freemem(){
    for(int i=0;i<rows;i++){
        delete seating[i];
    }
    delete[] seating;
    }
    
    
};
int main(){
    int rows, cols;
    cout << "Enter number of rows (benches): ";
    cin >> rows;
    cout << "Enter number of columns (seats per bench): ";
    cin >> cols;

    Seats s(rows, cols);
    s.fill();
    s.printmatrix();
    s.freemem();
}
