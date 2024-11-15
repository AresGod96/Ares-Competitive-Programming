## Problem A - Subtree Queries <img src="../../../boj-icon/plat4.svg" alt="Platinum 4" width="20" height="20">
Source: [VNOJ Educational Eulter Tour and HLD Contest](https://oj.vnoi.info/contest/euler_tour)

## [Statement](https://oj.vnoi.info/problem/euler_a)

## Difficulty <img src="../../../boj-icon/plat4.svg" alt="Platinum 4" width="20" height="20">

## Tags
- tree
- euler tour
- segment tree

## Solution
Given a tree, we are asked to perform two operations.
1. Change the value of node $s$ to $x$
2. Query the sum of all nodes in subtree rooted at node $s$

After constructing the **Euler Tour Tree (ETT)** for the given tree via DFS, we build a segment tree based on the resulting **ETT**. Using two vectors, $euler_{in}[u]$ and $euler_{out}[u]$, which represent the entry and exit positions of $u$ in **ETT**, we can query the sum of subtree rooted at node $u$ in $O(\log N)$ per query.

**Complexity**: 
- **DFS and building ETT**: $O(N)$
- **Each query**: $O(\log N)$
- **Overall**: $O(Q\log N)$
