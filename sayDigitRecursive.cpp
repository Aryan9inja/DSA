#include <iostream>
using namespace std;

void sayDigit(int n, string arr[]) {


    if (n == 0) {
        return;
    }

    int temp = n % 10;
    n = n / 10;

    sayDigit(n, arr);
    cout << arr[temp] << " ";
}

int main() {
    string arr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int n;
    cin >> n;

    sayDigit(n, arr);

    return 0;
}