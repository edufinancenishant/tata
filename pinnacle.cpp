#include <iostream>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
    Node(int p, string n) { prn = p; name = n; next = NULL; }
};

class Club {
    Node* head;
public:
    Club() { head = NULL; }

    // Add president at beginning
    void addPresident(int prn, string name) {
        Node* temp = new Node(prn, name);
        temp->next = head;
        head = temp;
    }

    // Add secretary at end
    void addSecretary(int prn, string name) {
        Node* temp = new Node(prn, name);
        if (!head) { head = temp; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = temp;
    }

    // Add member in between (after president)
    void addMember(int prn, string name) {
        if (!head) { cout << "Add president first!\n"; return; }
        Node* temp = new Node(prn, name);
        Node* t = head;
        while (t->next && t->next->next) t = t->next;
        temp->next = t->next;
        t->next = temp;
    }

    // Delete president
    void deletePresident() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete secretary
    void deleteSecretary() {
        if (!head) return;
        Node* t = head;
        if (!t->next) { delete t; head = NULL; return; }
        while (t->next->next) t = t->next;
        delete t->next;
        t->next = NULL;
    }

    // Delete member by PRN
    void deleteMember(int prn) {
        Node* t = head;
        Node* prev = NULL;
        while (t && t->prn != prn) { prev = t; t = t->next; }
        if (!t) { cout << "Member not found!\n"; return; }
        prev->next = t->next;
        delete t;
    }

    // Display members
    void display() {
        Node* t = head;
        cout << "\nClub Members:\n";
        while (t) {
            cout << t->prn << " - " << t->name << endl;
            t = t->next;
        }
    }

    // Count total members
    int count() {
        int c = 0; Node* t = head;
        while (t) { c++; t = t->next; }
        return c;
    }

    // Concatenate two club lists
    void concatenate(Club& c2) {
        if (!head) { head = c2.head; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = c2.head;
    }
};

int main() {
    Club A, B;
    int ch, prn;
    string name;
    cout << "1.Add Pres 2.Add Sec 3.Add Mem 4.Del Pres 5.Del Sec 6.Del Mem 7.Display 8.Count 9.Concat 10.Exit\n";
    do {
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter PRN & Name: "; cin >> prn >> name; A.addPresident(prn, name); break;
            case 2: cout << "Enter PRN & Name: "; cin >> prn >> name; A.addSecretary(prn, name); break;
            case 3: cout << "Enter PRN & Name: "; cin >> prn >> name; A.addMember(prn, name); break;
            case 4: A.deletePresident(); break;
            case 5: A.deleteSecretary(); break;
            case 6: cout << "Enter PRN to delete: "; cin >> prn; A.deleteMember(prn); break;
            case 7: A.display(); break;
            case 8: cout << "Total members: " << A.count() << endl; break;
            case 9: cout << "Enter another club list details:\n"; 
                    B.addPresident(111, "DummyP"); B.addSecretary(999, "DummyS");
                    A.concatenate(B); cout << "Lists concatenated!\n"; break;
        }
    } while (ch != 10);
    return 0;
}
