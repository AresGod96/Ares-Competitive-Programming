## Problem L - Eqpair <img src="../../../../../boj-icon/silver1.svg" alt="Silver 1" width="20" height="20">
Source: [ICPC Vietnam Northern Provincial 2024](https://oj.vnoi.info/contest/icpc24_mb)

## [Statement](https://oj.vnoi.info/problem/icpc24_mb_l)

## Difficulty <img src="../../../../../boj-icon/silver1.svg" alt="Silver 1" width="20" height="20">

## Tags
- binary search
- data structure

## Solution
We are asked to count how many pairs of indices $(i, j)$ satisfied $a[i] = a[j]$ and $i < j$

This problem can be solved using a data structure such as **multiset** in C++.

We maintain a multiset $S$. Each time, we increase the result by the occurrences of the current element in $S$, and update $S$ by adding the new element to the multiset.

**Complexity**: $O(N \log N)$
