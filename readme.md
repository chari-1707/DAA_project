# Recursion vs Iteration – Fibonacci & Factorial

## Problem Statement
Compare recursive and non-recursive implementations of Fibonacci and factorial. Analyze time and space complexities and discuss the trade-offs in different contexts. Include real-time scenarios where this comparison is applicable.

---

## Algorithms Implemented

### Factorial
| Method | Time Complexity | Space Complexity |
|--------|----------------|-----------------|
| Recursive | O(n) | O(n) |
| Iterative | O(n) | O(1) |

### Fibonacci
| Method | Time Complexity | Space Complexity |
|--------|----------------|-----------------|
| Recursive | O(2^n) | O(n) |
| Iterative | O(n) | O(1) |

---

## Trade-offs

| Recursion | Iteration |
|----------|-----------|
| Cleaner & closer to mathematical definitions | Faster and memory efficient |
| Useful for tree/graph problems | No stack overflow risk |
| Shorter code | Better for large inputs |

---

## Real-Time Applications

- Optimizing performance in embedded systems, servers, and critical applications
- Graph/tree traversal algorithms (DFS recursion vs stack-based DFS)
- Backtracking techniques vs iterative search
- Interview and educational demonstrations

---

## How to Compile & Run

```bash
g++ -std=c++17 main.cpp -o run
./run
