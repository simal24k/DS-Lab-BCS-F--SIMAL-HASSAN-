#include <iostream>
#include <string>
using namespace std;

int main() {
    int cgs;
    cout << "Enter number of categories: ";
    cin >> cgs;

    string* names = new string[cgs];  
    int* count = new int[cgs];         
    int** books = new int*[cgs];       

    for (int i = 0; i < cgs; i++) {
        cout << "Name of category " << i + 1 << ": ";
        cin >> names[i];

        cout << "Enter number of books in " << names[i] << ": ";
        cin >> count[i];

        books[i] = new int[count[i]];
        cout << "Enter book IDs for " << names[i] << ": " << endl;
        for (int j = 0; j < count[i]; j++) {
            cin >> books[i][j];
        }
    }

    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < cgs; i++) {
        for (int j = 0; j < count[i]; j++) {
            if (books[i][j] == id) {
                cout << "Book found in " << names[i] << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "Book not available in library." << endl;
    }

   
    for (int i = 0; i < cgs; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] count;
    delete[] names;

    return 0;
}
