## Problem BOJ 11437 - LCA <img src="../../boj-icon/gold3.svg" alt="Gold 3" width="20" height="20">
Source: [Baekjoon OJ](https://www.acmicpc.net/problem/11437)

## [Statement](https://www.acmicpc.net/problem/11437)

## Difficulty <img src="../../boj-icon/gold3.svg" alt="Gold 3" width="20" height="20">

## Tags
- tree
- [lowest common ancestor](../../library/lca)

## Solution
This is an educational problem that focuses on finding the [**Lowest Common Ancestor (LCA)**](https://cp-algorithms.com/graph/lca.html) of nodes in a tree. We can solve this problem using one of three common methods: Binary Lifting, Sparse Table, or Euler Tour with Segment Tree. Each method has unique trade-offs in terms of preprocessing and query efficiency.

### Complexity
- Binary lifting: $O(N \log N)$ preprocessing and $O(\log N)$ each query
- Sparse table: $O(N \log N)$ preprocessing and $O(1)$ each query
- Euler Tour: $O(N \log N)$ preprocessing and $O(\log N)$ each query
