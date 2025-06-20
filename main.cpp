#include <iostream>
using namespace std;

int main() {
    int n;
    // keep reading “n” until EOF (e.g. user hits Ctrl+D/Ctrl+Z)
    while (cin >> n) {
        int a = 1, b = 1, c;

        if (n >= 1) cout << a;
        if (n >= 2) cout << " " << b;

        for (int i = 2; i < n; ++i) {
            c = a + b;
            cout << " " << c;
            a = b;
            b = c;
        }
        cout << "\n";    // newline after each sequence
    }
    return 0;
}
