# Recursion vs Iteration | C++ Comparative Study

## 📖 Problem Statement
Compare recursive and non-recursive implementations of common algorithms such as:
- **Factorial computation**
- **Fibonacci sequence generation**

Analyze:
- **Time Complexity**
- **Space Complexity**
- **Performance trade-offs**
- **Real-world scenarios** where recursion vs iteration matters

This project includes a C++ program demonstrating execution-time differences and theoretical analysis for both recursive & iterative solutions.

---

## 🚀 Features
- Factorial (Recursive & Iterative)
- Fibonacci (Recursive & Iterative)
- Performance comparison using high-resolution timestamps
- Menu-driven CLI program
- Well-documented code with explanations

---

## 📂 File Included
| File Name | Description |
|----------|-------------|
| `recursion_vs_iteration.cpp` | Contains the full comparison code with complexity analysis and examples |
| `README.md` | Documentation |
  
---

## 🧠 Theoretical Summary

| Concept | Recursive Approach | Iterative Approach |
|--------|------------------|------------------|
| Readability | Simple, closer to math logic | Sometimes more complex |
| Time Complexity | Can be worse (e.g., Fibonacci: O(2ⁿ)) | Usually optimal (e.g., O(n)) |
| Space Complexity | Uses call stack → O(n) | O(1) |
| Risk | Stack overflow for large n | Safe for large inputs |
| Best Use Cases | Trees, Divide & Conquer, Backtracking | Loops, Performance-critical systems |

---

## 🌍 Real-Life Applications
| Application Area | Preferred Approach |
|-----------------|------------------|
| File System Traversal | Recursion |
| Tree and graph algorithms (DFS) | Both |
| Factorial in statistics & ML | Iteration |
| Financial modelling with recurrence relations | Iteration |
| Compiler and parsing systems | Recursion |
| Competitive programming with high input limits | Iteration |

---

## 🛠️ How to Compile & Run

```sh
g++ recursion_vs_iteration.cpp -o compare
./compare
