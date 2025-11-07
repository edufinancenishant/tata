#include <iostream>
using namespace std;

struct Seat {
    int seatNo;
    bool booked;
    Seat *next, *prev;
    Seat(int n) { seatNo = n; booked = false; next = prev = NULL; }
};

class Cinemax {
    Seat* rows[10]; // 10 rows
public:
    Cinemax() {
        for (int i = 0; i < 10; i++) {
            rows[i] = NULL;
            Seat* prev = NULL;
            for (int j = 1; j <= 7; j++) {
                Seat* s = new Seat(j);
                if (!rows[i]) rows[i] = s;
                if (prev) { prev->next = s; s->prev = prev; }
                prev = s;
            }
        }
        // Random initial bookings
        rows[0]->booked = true;
        rows[2]->next->booked = true;
        rows[5]->next->next->booked = true;
    }

    void display() {
        cout << "\nAvailable Seats (0=Free, 1=Booked):\n";
        for (int i = 0; i < 10; i++) {
            cout << "Row " << i + 1 << ": ";
            Seat* t = rows[i];
            while (t) { cout << (t->booked ? "[1]" : "[0]"); t = t->next; }
            cout << endl;
        }
    }

    void book(int r, int s) {
        if (r < 1 || r > 10 || s < 1 || s > 7) { cout << "Invalid seat!\n"; return; }
        Seat* t = rows[r - 1];
        for (int i = 1; i < s; i++) t = t->next;
        if (t->booked) cout << "Seat already booked!\n";
        else { t->booked = true; cout << "Seat booked successfully!\n"; }
    }

    void cancel(int r, int s) {
        if (r < 1 || r > 10 || s < 1 || s > 7) { cout << "Invalid seat!\n"; return; }
        Seat* t = rows[r - 1];
        for (int i = 1; i < s; i++) t = t->next;
        if (!t->booked) cout << "Seat is not booked!\n";
        else { t->booked = false; cout << "Booking cancelled!\n"; }
    }
};

int main() {
    Cinemax c;
    int ch, r, s;
    cout << "\n1.Display 2.Book 3.Cancel 4.Exit\n";
    do {
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: c.display(); break;
            case 2: cout << "Enter row & seat to book: "; cin >> r >> s; c.book(r, s); break;
            case 3: cout << "Enter row & seat to cancel: "; cin >> r >> s; c.cancel(r, s); break;
        }
    } while (ch != 4);
    return 0;
}
