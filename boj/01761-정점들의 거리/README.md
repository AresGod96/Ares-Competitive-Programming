## Problem BOJ 1761 - 정점들의 거리 <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">
Source: [Baekjoon OJ](https://www.acmicpc.net/problem/1761)

## [Statement](https://www.acmicpc.net/problem/1761)

## Difficulty <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">

## Tags
- tree
- [lowest common ancestor](../../library/lca)

## Solution

### Key Idea
After preprocessing the tree to compute the LCA, we can efficiently calculate the distance between any two nodes $u$ and $v$ using the formula:  

$\text{dist}(u, v) = dist[u] + dist[v] - 2 \cdot dist[\text{LCA}(u, v)]$

Here:
- $dist[u]$: The distance of node $u$ from the root, calculated during a Depth-First Search (DFS).
- $\text{LCA}(u, v)$: The lowest common ancestor of nodes $u$ and $v$.

### Steps
1. Root the tree at an arbitrary node (typically node 1).
2. Perform a DFS to calculate:
   - The depth of each node.
   - The distance of each node from the root.
3. Build the LCA structure using binary lifting for efficient ancestor queries.
4. For each query, compute the distance between the two nodes using the formula above.

### Complexity
- Binary lifting: $O(N \log N)$ preprocessing and $O(\log N)$ each query
- Sparse table: $O(N \log N)$ preprocessing and $O(1)$ each query
- Euler Tour: $O(N \log N)$ preprocessing and $O(\log N)$ each query
