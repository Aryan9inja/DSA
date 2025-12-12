#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return a;

    if (b == 0) return b;

    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two numbers to get GCD: ";
    cin >> a;
    cin >> b;

    int ans = gcd(a, b);

    cout << "GCD of " << a << " and " << b << " is:\n";
    cout << ans;

    return 0;
}