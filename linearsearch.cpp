#include <iostream>
using namespace std;

// Function for Linear Search
bool linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return true;  // Student found
    }
    return false;  // Not found
}

int main() {
    int n;
    cout << "Enter number of students who attended the training: ";
    cin >> n;

    int rollNumbers[n];

    cout << "Enter roll numbers of students (in random order):\n";
    for (int i = 0; i < n; i++) {
        cin >> rollNumbers[i];
    }

    int key;
    cout << "Enter roll number to search: ";
    cin >> key;

    if (linearSearch(rollNumbers, n, key))
        cout << "✅ Student with roll number " << key << " attended the training program.\n";
    else
        cout << "❌ Student with roll number " << key << " did NOT attend the training program.\n";

    return 0;
}
