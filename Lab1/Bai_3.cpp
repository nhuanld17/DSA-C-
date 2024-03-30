#include<iostream>
using namespace std;

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

int BCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}

int main() {
    int a, b;
    cout << "Nhap so thu nhat: ";
    cin >> a;
    cout << "Nhap so thu hai: ";
    cin >> b;

    cout << "UCLN cua " << a << " va " << b << " la: " << UCLN(a, b) << endl;
    cout << "BCNN cua " << a << " va " << b << " la: " << BCNN(a, b) << endl;

    return 0;
}
