## Problem BOJ 1761 - 정점들의 거리 <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">
Source: [Baekjoon OJ](https://www.acmicpc.net/problem/1761)

## [Statement](https://www.acmicpc.net/problem/1761)

## Difficulty <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">

## Tags
- tree
- [lowest common ancestor]((../../library/lca))

## Solution
After building the **Lowest Common Ancestor (LCA)** structure for the given tree, we can compute the distance between node $u$ and $v$ using the formula $dist(u, v) = d[u] + d[v] - 2 * LCA(u, v)$ where $d[u]$ denotes the distance of node $u$ from $root$, determined through a DFS with the tree rooted at node $1$.

### Complexity
- Binary lifting: $O(N \log N)$ preprocessing and $O(\log N)$ each query
- Sparse table: $O(N \log N)$ preprocessing and $O(1)$ each query
- Euler Tour: $O(N \log N)$ preprocessing and $O(\log N)$ each query
