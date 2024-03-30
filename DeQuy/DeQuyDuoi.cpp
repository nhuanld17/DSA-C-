#include <iostream>
using namespace std;

int gcd(int m, int n) {
    if (n == 0) {
        return m;
    }
    int r = m % n;
    return gcd(n, r);
}

int main() {
    int m, n;
    cout << "Nhập hai số m và n: ";
    cin >> m >> n;
    cout << "Ước chung lớn nhất của " << m << " và " << n << " là: " << gcd(m, n);
    return 0;
}
