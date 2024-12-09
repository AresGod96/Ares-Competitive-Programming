# Tutorial: Mo's Algorithm <img src="../../boj-icon/plat2.svg" alt="Platinum 2" width="20" height="20">

## Difficulty <img src="../../boj-icon/plat2.svg" alt="Platinum 2" width="20" height="20">

## Overview

Mo's algorithm is an efficient offline approach to solve range query problems on arrays. It is particularly useful when the array is static (doesn't change between queries) and the problem involves answering queries like sum, count, or distinct elements in a given range. By sorting queries strategically and processing them with a sliding window approach, Mo's algorithm achieves a time complexity of $O((N + Q)\sqrt{N})$, where $N$ is the array size, and $Q$ is the number of queries.

## Core Idea
Mo's algorithm relies on the following key principles:
1. **Query Sorting**: Queries are sorted based on the block number of their left endpoint $l$ and then by their right endpoint $r$ within the block. This minimizes unnecessary movements of the left and right pointers.
   - Block size is typically $\sqrt{N}$, ensuring that most queries have close ranges.

2. **Sliding Window**: Maintain a current range $[curL, curR]$ and efficiently expand or shrink it to match the desired range $[L, R]$. Update the results dynamically as the pointers move.

3. **Efficient Updates**: Add or remove elements from the range using data structures like frequency arrays, Fenwick Trees, or segment trees, depending on the problem.

## Steps to Implement
1. **Sort the Queries**:
   - Define a query structure with $(L, R, idx)$.
   - Sort the queries by block number $(L / block\_size)$, and for queries in the same block, sort by $R$.

2. **Process the Queries**:
   - Initialize `curL = 0` and `curR = -1`.
   - For each query, adjust `curL` and `curR` to match $L$ and $R$, updating the results accordingly.

3. **Output Results**:
   - Store results for each query in an array, indexed by the query's original position.

## Complexity
- Sorting Queries: $O(Q \log Q)$
- Processing Queries: $O((N + Q) \sqrt{N})$
- Total: $O((N + Q) \sqrt{N})$

## Example Problem
### Problem Statement
Given an array $A$ of size $N$ and $Q$ queries of the form $(L, R)$, answer the number of distinct elements in the subarray $(L, R)$.

### Solution
1. **Data Structure**:
   - Use a frequency array to track occurrences of elements in the current range.
   - Maintain a count of distinct elements.

2. **Algorithm**:
   ```cpp
   struct Query {
       int l, r, idx;
       bool operator<(const Query& other) const {
           if (l / blockSize != other.l / blockSize) {
               return l / blockSize < other.l / blockSize;
           }
           return (l / blockSize % 2) ? (r > other.r) : (r < other.r);
       }
   };

   void add(int pos, int& distinctCount, vector<int>& freq, vector<int>& arr) {
       if (++freq[arr[pos]] == 1) {
           ++distinctCount;
       }
   }

   void remove(int pos, int& distinctCount, vector<int>& freq, vector<int>& arr) {
       if (--freq[arr[pos]] == 0) {
           --distinctCount;
       }
   }

   void mosAlgorithm(vector<int>& arr, vector<Query>& queries, vector<int>& answers) {
       int blockSize = sqrt(arr.size());
       sort(queries.begin(), queries.end());

       vector<int> freq(1e6 + 1, 0); // Assuming elements <= 1e6
       int distinctCount = 0;
       int curL = 0, curR = -1;

       for (auto& q : queries) {
           while (curL > q.l) add(--curL, distinctCount, freq, arr);
           while (curR < q.r) add(++curR, distinctCount, freq, arr);
           while (curL < q.l) remove(curL++, distinctCount, freq, arr);
           while (curR > q.r) remove(curR--, distinctCount, freq, arr);

           answers[q.idx] = distinctCount;
       }
   }
   ```

### Complexity
- Sorting queries: $O(Q \log Q)$
- Processing queries: $O((N + Q) \sqrt{N})$

### Applications
1. Counting distinct elements in a range.
2. Finding range frequency.
3. Solving range sum problems with constraints.

---
## Practice problems
- [BOJ 13547 - 수열과 쿼리 5](../../boj/13547-수열과%20쿼리%205/)
- [BOJ 13548 - 수열과 쿼리 6](../../boj/13548-수열과%20쿼리%206/)