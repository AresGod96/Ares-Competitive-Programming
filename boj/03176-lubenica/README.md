## Problem BOJ 3176 - Lubenica <img src="../../boj-icon/plat4.svg" alt="Platinum 4" width="20" height="20">
Source: [Croatian Highschool Competitions in Informatics 2006 - Final Exam #2](https://www.acmicpc.net/problem/3176)

## [Statement](https://www.acmicpc.net/problem/3176)

## Difficulty <img src="../../boj-icon/plat4.svg" alt="Platinum 4" width="20" height="20">

## Tags
- tree
- [lowest common ancestor](../../library/lca)

## Solution
Given a tree, we need to efficiently find the maximum and minimum edge weights on the path between node $u$ and $v$ for multiple queries.

We preprocess the tree using **binary lifting** during a Depth First Search (DFS) to build three tables:
- `up[u][i]`: the $2^i$-th ancestor of node $u$
- `max_path[u][i]`: the maximum edge weight on the path from node $u$ to its $2^i$-th ancestor
- `min_path[u][i]`: the minimum edge weight on the path from node $u$ to its $2^i$-th ancestor

### Query handling
1. Use binary lifting to find the **Lowest Common Ancestor (LCA)** of nodes $u$ and $v$. Let the LCA be $w$.
2. Split the path between $u$ and $v$ into:
   - Path from $u$ to $w$
   - Path from $v$ to $w$
3. For each path segment, calculate the maximum and minimum edge weights using the precomputed binary lifting tables.
4. Combine the results to get the overall maximum and minimum weights for the path between $u$ and $v$.

### Complexity
- Per query: $O(\log N)$ due to binary lifting
- Overall: $O(Q \log N)$
