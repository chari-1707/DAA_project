/*
    
    Problem Statement:
    Compare recursive and non-recursive implementations of algorithms
    (e.g., Fibonacci sequence, factorial calculation). Analyze their time
    and space complexities and discuss the trade-offs of using recursion
    versus iteration in different contexts. Also provide real-time
    scenarios where this comparison is applicable.

    ---------------------------------------------------------------------
    REAL-TIME / PRACTICAL SCENARIOS

    1. Combinations & Permutations in Statistics and ML
       - Factorial is used in nCr and nPr.
       - Example: calculating probabilities in quality control, data
         sampling, and risk analysis.
       - Implementations need to be efficient and safe from overflow,
         so an iterative factorial is typically preferred.

    2. Financial & Scientific Simulations
       - Fibonacci-like recurrences appear in certain models, such as
         simplified population growth, interest approximations, or
         discretized dynamic systems.
       - Recursive formulas are mathematically elegant; iterative
         versions are usually used in production systems due to better
         performance and memory usage.

    3. System Utilities (File System Traversal)
       - Recursive: depth-first search through directories (each folder
         calls the function on its subfolders).
       - Iterative: explicit stack/queue used instead of call stack.
       - Trade-off: recursion is simpler to write and read; iteration is
         safer for very deep directory trees (avoids stack overflow).

    4. Tree and Graph Traversals
       - Recursive DFS vs iterative DFS using an explicit stack.
       - In compilers, parsers, search engines, and AI (state-space
         search), engineers must choose between recursive clarity and
         iterative control (e.g., limits, custom stack, memory control).

    5. Competitive Programming & System Design
       - For small constraints, recursive solutions may be fine and easy
         to code under time pressure.
       - For large constraints, iterative implementations are preferred
         to avoid stack overflow and reduce overhead.

    ---------------------------------------------------------------------
    HIGH-LEVEL TRADE-OFFS: RECURSION vs ITERATION

    Recursion:
      - Pros:
        * Code is often shorter and more expressive, closer to the
          mathematical definition (especially for divide & conquer).
        * Easier to reason about for tree-like or recursively-defined problems.
      - Cons:
        * Function call overhead (parameters, return address, etc.).
        * Uses call stack -> risk of stack overflow for large input.
        * Sometimes more complex to debug (deep call stacks).

    Iteration:
      - Pros:
        * Typically more efficient in terms of time (no call overhead)
          and space (O(1) extra space in many cases).
        * No risk of stack overflow due to deep recursion.
      - Cons:
        * Code can become more verbose and less intuitive, especially
          for naturally recursive problems (like tree traversals).

    This program demonstrates both approaches using:
      1. Factorial (n!)
      2. Fibonacci numbers (F(n))

    It also prints both results and explains their time/space complexity.
*/

#include <iostream>
#include <chrono>
#include <limits>

using namespace std;

// ========================== FACTORIAL ==========================

// Recursive factorial
// Time Complexity  : O(n)
// Space Complexity : O(n) due to recursion call stack
long long factorialRecursive(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorialRecursive(n - 1);
}

// Iterative factorial
// Time Complexity  : O(n)
// Space Complexity : O(1)
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// ========================== FIBONACCI ==========================

// Naive recursive Fibonacci
// Time Complexity  : O(2^n)  (exponential)
// Space Complexity : O(n)    (max depth of recursion tree)
long long fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative Fibonacci (bottom-up)
// Time Complexity  : O(n)
// Space Complexity : O(1)
long long fibonacciIterative(int n) {
    if (n <= 1) return n;
    long long prev2 = 0; // F(0)
    long long prev1 = 1; // F(1)
    long long curr   = 0;

    for (int i = 2; i <= n; ++i) {
        curr  = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// ========================== UTILITIES ==========================

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printTimeSpaceInfoFactorial() {
    cout << "\n--- Factorial Complexity & Trade-offs ---\n";
    cout << "Recursive Factorial:\n";
    cout << "  Time Complexity  : O(n)\n";
    cout << "  Space Complexity : O(n) due to call stack\n";
    cout << "  Notes            : Simpler to understand but risky for very large n.\n\n";

    cout << "Iterative Factorial:\n";
    cout << "  Time Complexity  : O(n)\n";
    cout << "  Space Complexity : O(1)\n";
    cout << "  Notes            : No stack overflow risk, better for production.\n\n";
}

void printTimeSpaceInfoFibonacci() {
    cout << "\n--- Fibonacci Complexity & Trade-offs ---\n";
    cout << "Naive Recursive Fibonacci:\n";
    cout << "  Time Complexity  : O(2^n) (exponential)\n";
    cout << "  Space Complexity : O(n) due to recursion depth\n";
    cout << "  Notes            : Matches mathematical definition, but very slow\n";
    cout << "                     and not suitable for large n.\n\n";

    cout << "Iterative Fibonacci:\n";
    cout << "  Time Complexity  : O(n)\n";
    cout << "  Space Complexity : O(1)\n";
    cout << "  Notes            : Efficient and safe for large n, good for real use.\n\n";
}

// ========================== MAIN MENU ==========================

void factorialMenu() {
    int n;
    cout << "\nEnter a non-negative integer for factorial (e.g., 0 to 20): ";
    while (!(cin >> n) || n < 0) {
        cout << "Invalid input. Please enter a non-negative integer: ";
        clearInputBuffer();
    }

    // Recursive calculation with timing
    auto startRec = chrono::high_resolution_clock::now();
    long long facRec = factorialRecursive(n);
    auto endRec = chrono::high_resolution_clock::now();
    auto durRec = chrono::duration_cast<chrono::nanoseconds>(endRec - startRec).count();

    // Iterative calculation with timing
    auto startIter = chrono::high_resolution_clock::now();
    long long facIter = factorialIterative(n);
    auto endIter = chrono::high_resolution_clock::now();
    auto durIter = chrono::duration_cast<chrono::nanoseconds>(endIter - startIter).count();

    cout << "\n===== FACTORIAL RESULTS =====\n";
    cout << "n              : " << n << "\n";
    cout << "Recursive      : " << facRec  << " (" << durRec  << " ns)\n";
    cout << "Iterative      : " << facIter << " (" << durIter << " ns)\n";

    if (facRec == facIter) {
        cout << "Status         : Both implementations match ✅\n";
    } else {
        cout << "Status         : Mismatch ❌ (check implementation)\n";
    }

    printTimeSpaceInfoFactorial();
}

void fibonacciMenu() {
    int n;
    cout << "\nEnter n for Fibonacci (recommend <= 40 for recursive): ";
    while (!(cin >> n) || n < 0) {
        cout << "Invalid input. Please enter a non-negative integer: ";
        clearInputBuffer();
    }

    cout << "\n===== FIBONACCI RESULTS =====\n";
    cout << "n              : " << n << "\n";

    // Recursive calculation with timing (only if n not too large)
    if (n <= 40) {
        auto startRec = chrono::high_resolution_clock::now();
        long long fibRec = fibonacciRecursive(n);
        auto endRec = chrono::high_resolution_clock::now();
        auto durRec = chrono::duration_cast<chrono::microseconds>(endRec - startRec).count();

        cout << "Recursive      : " << fibRec << " (" << durRec << " microseconds)\n";
    } else {
        cout << "Recursive      : Skipped (n too large; would be very slow)\n";
    }

    // Iterative calculation with timing
    auto startIter = chrono::high_resolution_clock::now();
    long long fibIter = fibonacciIterative(n);
    auto endIter = chrono::high_resolution_clock::now();
    auto durIter = chrono::duration_cast<chrono::microseconds>(endIter - startIter).count();

    cout << "Iterative      : " << fibIter << " (" << durIter << " microseconds)\n";

    printTimeSpaceInfoFibonacci();
}

int main() {
    int choice;

    while (true) {
        cout << "\n=============================================\n";
        cout << "  RECURSION vs ITERATION DEMO (C++)\n";
        cout << "=============================================\n";
        cout << "1. Compare Factorial (Recursive vs Iterative)\n";
        cout << "2. Compare Fibonacci (Recursive vs Iterative)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input. Please enter a number from 1 to 3.\n";
            continue;
        }

        switch (choice) {
            case 1:
                factorialMenu();
                break;
            case 2:
                fibonacciMenu();
                break;
            case 3:
                cout << "Exiting. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }
    }

    return 0;
}
