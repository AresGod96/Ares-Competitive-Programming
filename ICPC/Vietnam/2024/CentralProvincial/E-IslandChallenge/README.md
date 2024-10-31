## Problem E - Island Challenge <img src="../../../../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">
Source: [ICPC Vietnam Central Provincial 2024](https://oj.vnoi.info/contest/icpc24_mt)

## [Statement](https://oj.vnoi.info/problem/icpc24_mt_e)

## Difficulty <img src="../../../../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">

## Tags
- bitmask dp
- bfs
- graph

## Solution
To solve this problem, we need to calculate the minimum time required to visit each shrine, starting from (1, 1). Given the constraints, we can utilize **BFS** and **Bitmask DP**:

1. **Shortest Path Calculation with BFS**:
   - Treat each shrine (and the start position) as a node.
   - Run BFS from each node to calculate the shortest distance to every other node, avoiding mountain cells. This forms a **distance matrix** where $d[i][j]$ gives the shortest path between shrine $i$ and shrine $j$.
   
2. **Bitmask Dynamic Programming**:
   - Since there are at most 15 shrines, we use a bitmask where each bit represents whether a shrine is visited or not.
   - Define $dp[i][mask]$ as the minimum time to visit all shrines in the subset represented by $mask$, ending at shrine $i$.
   - Transition: For each shrine $i$ in a subset $mask$, calculate the minimum time to reach an unvisited shrine $j$ and update the DP state:
   
     $
     dp[j][mask | (1 << j)] = \min(dp[j][mask | (1 << j)], dp[i][mask] + dist[i][j])
     $

3. **Extracting the Result**:
   - After filling the DP table, the result is the minimum value among $dp[(1 << N) - 1][i]$, representing the time to visit all shrines and end at any shrine.

**Complexity**: 
- **BFS**: $O(N \times R \times C)$ to compute distances from each shrine.
- **Bitmask DP**: $O(2^N \times N^2)$
