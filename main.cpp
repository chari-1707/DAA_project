#include <bits/stdc++.h>
using namespace std;

long long factorialRecursive(int n) {
    if (n < 0) throw invalid_argument("Factorial is not defined for negative numbers.");
    if (n == 0 || n == 1) return 1;
    return 1LL * n * factorialRecursive(n - 1);
}

long long factorialIterative(int n) {
    if (n < 0) throw invalid_argument("Factorial is not defined for negative numbers.");
    long long result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

long long fibonacciRecursive(int n) {
    if (n < 0) throw invalid_argument("Fibonacci is not defined for negative index.");
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

long long fibonacciIterative(int n) {
    if (n < 0) throw invalid_argument("Fibonacci is not defined for negative index.");
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

void printFibonacciSequenceIterative(int k) {
    if (k <= 0) {
        cout << "No terms to display.\n";
        return;
    }
    cout << "Fibonacci sequence for first " << k << " terms:\n";
    long long prev2 = 0, prev1 = 1;
    for (int i = 0; i < k; i++) {
        if (i == 0) cout << 0 << " ";
        else if (i == 1) cout << 1 << " ";
        else {
            long long curr = prev1 + prev2;
            cout << curr << " ";
            prev2 = prev1;
            prev1 = curr;
        }
    }
    cout << "\n";
}

void showMenu() {
    cout << "\n============================\n";
    cout << "RECURSION VS ITERATION MENU\n";
    cout << "============================\n";
    cout << "1. Factorial (Recursive)\n";
    cout << "2. Factorial (Iterative)\n";
    cout << "3. Fibonacci (Recursive)\n";
    cout << "4. Fibonacci (Iterative)\n";
    cout << "5. Fibonacci (sequence)\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
   

    while (true) {
        showMenu();
        int choice;
        cin >> choice;

        if (!cin) break;
        if (choice == 0) {
            cout << "Exiting program.\n";
            break;
        }

        try {
            int n;
            switch (choice) {
                case 1:
                    cout << "Enter n: ";
                    cin >> n;
                    cout << "Factorial (Recursive) = " << factorialRecursive(n) << "\n";
                    break;
                case 2:
                    cout << "Enter n: ";
                    cin >> n;
                    cout << "Factorial (Iterative) = " << factorialIterative(n) << "\n";
                    break;
                case 3:
                    cout << "Enter n: ";
                    cin >> n;
                    cout << "Fib (Recursive) = " << fibonacciRecursive(n) << "\n";
                    break;
                case 4:
                    cout << "Enter n: ";
                    cin >> n;
                    cout << "Fib (Iterative) = " << fibonacciIterative(n) << "\n";
                    break;
                case 5:
                    cout << "Enter k: ";
                    cin >> n;
                    printFibonacciSequenceIterative(n);
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
        } catch (const exception& ex) {
            cout << "Error: " << ex.what() << "\n";
        }
    }
    return 0;
}
