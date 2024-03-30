#include <iostream>
using namespace std;

void move(int n, char A, char B, char C) {
    if (n == 1) {
        cout << A << " ==> " << C << "\n";
    } else {
        move(n - 1, A, C, B);
        cout << A << " ==> " << C << "\n";
        move(n - 1, B, A, C);
    }
}

int main() {
    int n; // S? dia
    cout << "Nh?p s? dia: ";
    cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}
