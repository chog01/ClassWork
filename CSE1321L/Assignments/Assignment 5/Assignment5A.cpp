#include <iostream>
using namespace std;

int main() {
    int n, term1 = 0, term2 = 1, nextTerm = 0;
    bool underZero = false;

    cout << "[Fibonacci Sequence Generator]" << endl;
    while (underZero == false) {
        n = 1;
        cout << "How long should the Fibonacci Sequence be?: ";
        cin >> n;
        if (n > 0) {
            for (int i = 1; i <= n; ++i) {
                if (i == 1) {
                    cout << term1 << ", ";
                    continue;
                }
                if (i == 2) {
                    cout << term2 << ", ";
                    continue;
                }
                nextTerm = term1 + term2;
                term1 = term2;
                term2 = nextTerm;

                cout << nextTerm << ", ";
            }
            underZero = true;
        }
        else cout << "Sequences must be larger than 0!" << endl;
    }
}