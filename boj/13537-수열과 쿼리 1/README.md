## Problem BOJ 13537 - 수열과 쿼리 1 <img src="../../boj-icon/plat3.svg" alt="Platinum 3" width="20" height="20">
Source: [Baekjoon OJ](https://www.acmicpc.net/problem/13537)

## [Statement](https://www.acmicpc.net/problem/13537)

## Difficulty <img src="../../boj-icon/plat3.svg" alt="Platinum 3" width="20" height="20">

## Tags
- data structure
- merge sort tree
- sqrt decomposition

## Solution
Given an array, we are asked to answer $Q$ queries of form $(l, r, k)$, where each query asks for the count of values greater than $k$ in the range $[l..r]$.

This problem is a common application of techniques like merge sort tree or sqrt-decomposition. In this editorial, we focus on the merge sort tree approach.

A merge sort tree is a type of segment tree that uses the divide-and-conquer approach of merge sort to maintain sorted subarrays at each node. This structure enables efficient solutions queries such as counting elements greater than or less than a given value, finding the $k$-th smallest element in a range, and similar tasks that involved range statistics.

Building a merge sort tree takes $O(N\log N)$, while each query requires an additional binary search on the sorted ranges, resulting in $O(\log^2 N)$ per query.


### Complexity
- Build tree: $O(N\log N)$
- Query: $O(\log^2 N)$ per query
- Overall: $O(Q\log^2 N)$
