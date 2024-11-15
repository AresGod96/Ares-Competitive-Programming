## Problem D - Swaps <img src="https://github.com/AresGod96/Ares-Competitive-Programming/raw/master/boj-icon/gold4.svg" alt="Gold 4" width="20" height="20">
Source: [Malaysian Computing Olympiad 2014](https://ioimalaysia.org/competition/mco/2014/)

## [Statement](https://www.acmicpc.net/problem/13214)

## Difficulty <img src="https://github.com/AresGod96/Ares-Competitive-Programming/raw/master/boj-icon/gold4.svg" alt="Gold 4" width="20" height="20">

## Tags
- BFS
- graph theory

## Solution
Consider an example of $A = [1, 2, 3]$ and $B = [2, 3, 1]$.

We need $2$ swaps to transform $A$ to $B$. In general, to transform a cycle permutation of $N$ elements, we need $N - 1$ swap operations.

The problem breaks down to finding the number of swap operations in each cycle. This can be done easily by a simple loop or BFS.

For example, $A = [1, 4, 2, 5, 3, 6, 9, 8, 7]$ and $B = [2, 5, 3, 6, 1, 4, 9, 7, 8]$, there are $3$ cycles:
- $[1, 2, 3]$ and $[2, 3, 1]$, which require 2 swap operations
- $[4, 5, 6]$ and $[5, 6, 4]$, which require 2 swap operations
- $[9]$ and $[9]$, which require 0 swap operations
- $[8, 7]$ and $[7, 8]$, which require 1 swap operations

In total, we need 5 swap operations.


**Complexity**: $O(N)$ since we iterate through each element exactly once