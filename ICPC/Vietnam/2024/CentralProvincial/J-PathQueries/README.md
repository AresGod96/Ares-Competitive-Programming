## Problem J - Path Queries <img src="../../../../../boj-icon/gold1.svg" alt="Gold 1" width="20" height="20">
Source: [ICPC Vietnam Central Provincial 2024](https://oj.vnoi.info/contest/icpc24_mt)

## [Statement](https://oj.vnoi.info/problem/icpc24_mt_j)

## Difficulty <img src="../../../../../boj-icon/gold1.svg" alt="Gold 1" width="20" height="20">

## Tags
- tree
- lowest common ancestor

## Solution
Given a tree, we are asked to answer if a node $z$ lies on the path between node $u$ and node $v$.

After building the **Lowest Common Ancestor (LCA)** structure for the given tree, we can compute the distance between node $u$ and $v$ using the formula $dist(u, v) = depth[u] + depth[v] - 2 * LCA(u, v)$ where $depth[u]$ denotes the depth level of node $u$, determined through a DFS with the tree rooted at node $1$.

To check if the path between node $u$ and node $v$ passes through node $z$, we verify if this conditition holds $dist(u, v) = dist(u, z) + dist(z, v)$.

**Complexity**: 
- **Preprocessing**: $O(N\log N)$
- **Each query**: $O(\log N)$
- **Overall**: $O(Q\log N)$
