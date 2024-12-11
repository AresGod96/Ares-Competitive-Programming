## Problem BOJ 13547 - 수열과 쿼리 5 <img src="../../boj-icon/plat2.svg" alt="Platinum 2" width="20" height="20">
Source: [Baekjoon OJ](https://www.acmicpc.net/problem/13547)

## [Statement](https://www.acmicpc.net/problem/13547)

## Difficulty <img src="../../boj-icon/plat2.svg" alt="Platinum 2" width="20" height="20">

## Tags
- Mo's algorithm


## Solution
This problem can be solved efficiently by [Mo's algorithm](../../library/MoAlgorithm/) with offline queries.

Mo's algorithm relies on the following key principles:
1. **Query Sorting**: Queries are sorted based on the block number of their left endpoint $l$ and then by their right endpoint $r$ within the block. This minimizes unnecessary movements of the left and right pointers.
   - Block size is typically $\sqrt{N}$, ensuring that most queries have close ranges.

2. **Sliding Window**: Maintain a current range $[curL, curR]$ and efficiently expand or shrink it to match the desired range $[L, R]$. Update the results dynamically as the pointers move.

3. **Efficient Updates**: Add or remove elements from the range using data structures like frequency arrays, Fenwick Trees, or segment trees, depending on the problem.

### Steps to Implement
1. **Sort the Queries**:
   - Define a query structure with $(L, R, idx)$.
   - Sort the queries by block number $(L / block\_size)$, and for queries in the same block, sort by $R$.

2. **Process the Queries**:
   - Initialize `curL = 0` and `curR = -1`.
   - For each query, adjust `curL` and `curR` to match $L$ and $R$, updating the results accordingly.

3. **Output Results**:
   - Store results for each query in an array, indexed by the query's original position.

### Complexity
- Sorting Queries: $O(Q \log Q)$
- Processing Queries: $O((N + Q) \sqrt{N})$
- Total: $O((N + Q) \sqrt{N})$
