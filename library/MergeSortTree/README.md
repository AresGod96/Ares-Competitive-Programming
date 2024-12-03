# Tutorial: Merge Sort Tree <img src="../../boj-icon/plat3.svg" alt="Platinum 3" width="20" height="20">

## Difficulty <img src="../../boj-icon/plat3.svg" alt="Platinum 3" width="20" height="20">

## Overview

A merge sort tree is a data structure that combines the divide-and-conquer approach of merge sort with the structure of a segment tree. Each node of the tree stores a sorted list of the elements in the corresponding segment of the array. This allows us to efficiently perform range-based queries involving sorted data.

## Problem Statement
[BOJ 13544](../../boj/13544-수열과%20쿼리%203/)

Given an array, we are asked to answer $Q$ queries of form $(l, r, k)$, where each query asks for the count of values greater than $k$ in the range $[l..r]$.

### How to build Merge Sort Tree?

Each node in the merge sort tree corresponds to a segment of the array. The node stores a sorted list of all elements within that segment, constructed using the **merge step of merge sort**. Building the tree requires merging sorted segments at every level, resulting in a complexity of $O(N \log N)$.

### Querying
The key advantage of a merge sort tree lies in its ability to perform range queries efficiently:
- **Example Queries**:
  - Count number of elements less than or greater than $k$ in a range.
  - $k$-th smallest element in a range.
  - Count number of elements within a specific range $[a, b]$ in a segment.

For each query:
1. Decompose the range into $O(\log N)$ segments.
2. Use binary search within the sorted arrays at these segments to compute the result.

---

### Complexity
- Build merge sort tree: $O(N \log N)$
- Query: $O(\log^2 N)$ due to binary searches on $\log N$ nodes
- Space complexity: $O(N \log N)$

--- 
### Merge Sort Tree and Updates

### Overview
Merge Sort Tree is primarily designed for **static arrays**, making updates (whether point or interval) **not natively efficient** with this structure.

### Point Updates in Merge Sort Tree
To update a single element in the array:
1. **What happens?**  
   A point update requires modifying all nodes in the merge sort tree corresponding to the updated element, which involves rebuilding the sorted arrays at each level.
2. **Time Complexity**  
   Rebuilding the sorted arrays requires $O(\log N)$ merges per level and $O(N)$ time per merge, leading to a total complexity of **$O(N \log N)$ for a single update**.
3. **Conclusion**  
   This is inefficient for frequent dynamic point updates.

---

### Practice problems
- [BOJ 13537 - 수열과 쿼리 1](../../boj/13537-수열과%20쿼리%201/)
- [BOJ 13544 - 수열과 쿼리 3](../../boj/13544-수열과%20쿼리%203/)

