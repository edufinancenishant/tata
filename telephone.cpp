#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

struct Client {
    string name;
    long long phone;
    bool occupied;
    Client() { name = ""; phone = 0; occupied = false; }
};

class HashTable {
    Client table[SIZE];

    int hash1(string key) {      // Simple hash function
        int sum = 0;
        for (char c : key) sum += c;
        return sum % SIZE;
    }
    int hash2(string key) {      // For double hashing
        int sum = 0;
        for (char c : key) sum += c;
        return 7 - (sum % 7);
    }

public:
    void insert(string name, long long phone, int method) {
        int h1 = hash1(name), index = h1, i = 0;
        while (table[index].occupied && i < SIZE) {
            if (method == 1)          // Linear Probing
                index = (h1 + i) % SIZE;
            else if (method == 2)     // Quadratic Probing
                index = (h1 + i * i) % SIZE;
            else                      // Double Hashing
                index = (h1 + i * hash2(name)) % SIZE;
            i++;
        }
        if (!table[index].occupied) {
            table[index].name = name;
            table[index].phone = phone;
            table[index].occupied = true;
        } else
            cout << "Hash table full, cannot insert!\n";
    }

    void search(string name, int method) {
        int h1 = hash1(name), index = h1, i = 0;
        while (i < SIZE) {
            if (table[index].occupied && table[index].name == name) {
                cout << "Found! Phone: " << table[index].phone << endl;
                return;
            }
            if (method == 1)
                index = (h1 + i) % SIZE;
            else if (method == 2)
                index = (h1 + i * i) % SIZE;
            else
                index = (h1 + i * hash2(name)) % SIZE;
            i++;
        }
        cout << "Client not found!\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            if (table[i].occupied)
                cout << table[i].name << " - " << table[i].phone;
            cout << endl;
        }
    }
};

int main() {
    HashTable h;
    int n, method;
    cout << "Enter number of clients: ";
    cin >> n;
    cout << "Choose Collision Method:\n1. Linear Probing\n2. Quadratic Probing\n3. Double Hashing\n";
    cin >> method;

    for (int i = 0; i < n; i++) {
        string name; long long phone;
        cout << "Enter name and phone: ";
        cin >> name >> phone;
        h.insert(name, phone, method);
    }

    h.display();

    string key;
    cout << "\nEnter name to search: ";
    cin >> key;
    h.search(key, method);

    return 0;
}
