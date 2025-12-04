#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;
};

void appendStudent(Student*& head, const string& name, int score) {
    Student* newNode = new Student{name, score, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Student* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

int getMaxScore(Student* head) {
    int maxScore = 0;
    while (head) {
        if (head->score > maxScore) maxScore = head->score;
        head = head->next;
    }
    return maxScore;
}

void countingSort(Student*& head, int exp) {
    Student* output[10000];
    int count[10] = {0};
    Student* temp = head;
    int idx = 0;
    Student* nodes[10000];
    while (temp) {
        nodes[idx++] = temp;
        count[(temp->score / exp) % 10]++;
        temp = temp->next;
    }
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = idx - 1; i >= 0; i--) {
        int index = (nodes[i]->score / exp) % 10;
        output[count[index] - 1] = nodes[i];
        count[index]--;
    }
    head = output[0];
    temp = head;
    for (int i = 1; i < idx; i++) {
        temp->next = output[i];
        temp = temp->next;
    }
    temp->next = nullptr;
}

void radixSort(Student*& head) {
    int maxScore = getMaxScore(head);
    for (int exp = 1; maxScore / exp > 0; exp *= 10)
        countingSort(head, exp);
}

void displayList(Student* head) {
    while (head) {
        cout << head->name << " - " << head->score << endl;
        head = head->next;
    }
}

Student* binarySearch(Student* head, const string& name, int score) {
    Student* nodes[10000];
    int idx = 0;
    while (head) {
        nodes[idx++] = head;
        head = head->next;
    }
    int low = 0, high = idx - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nodes[mid]->score == score && nodes[mid]->name == name)
            return nodes[mid];
        else if (nodes[mid]->score < score ||
                (nodes[mid]->score == score && nodes[mid]->name < name))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return nullptr;
}

void deleteNode(Student*& head, Student* nodeToDelete) {
    if (!head || !nodeToDelete) return;
    if (head == nodeToDelete) {
        Student* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Student* temp = head;
    while (temp->next && temp->next != nodeToDelete)
        temp = temp->next;
    if (temp->next == nodeToDelete) {
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}

int main() {
    Student* head = nullptr;

    appendStudent(head, "Alice", 75);
    appendStudent(head, "Bob", 50);
    appendStudent(head, "Charlie", 90);
    appendStudent(head, "David", 65);
    appendStudent(head, "Eve", 85);

    cout << "Before sorting:\n";
    displayList(head);

    radixSort(head);

    cout << "\nAfter sorting:\n";
    displayList(head);

    string name;
    int score;
    cout << "\nEnter name to delete: ";
    cin >> name;
    cout << "Enter score: ";
    cin >> score;

    Student* found = binarySearch(head, name, score);
    if (found) {
        deleteNode(head, found);
        cout << "\nRecord deleted. Updated list:\n";
        displayList(head);
    } else {
        cout << "\nRecord not found. List unchanged.\n";
    }

    return 0;
}
