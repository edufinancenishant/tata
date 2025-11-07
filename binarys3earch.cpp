#include <iostream>
using namespace std;

// Function for Binary Search
bool binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return true;   // Student found
        else if (arr[mid] < key)
            low = mid + 1; // Search in right half
        else
            high = mid - 1; // Search in left half
    }
    return false; // Not found
}

int main() {
    int n;
    cout << "Enter number of students who attended the training: ";
    cin >> n;

    int rollNumbers[n];
    cout << "Enter roll numbers of students (in sorted order):\n";
    for (int i = 0; i < n; i++) {
        cin >> rollNumbers[i];
    }

    int key;
    cout << "Enter roll number to search: ";
    cin >> key;

    if (binarySearch(rollNumbers, n, key))
        cout << "✅ Student with roll number " << key << " attended the training program.\n";
    else
        cout << "❌ Student with roll number " << key << " did NOT attend the training program.\n";

    return 0;
}
