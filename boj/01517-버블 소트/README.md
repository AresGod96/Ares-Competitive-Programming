## Problem BOJ 1517 -  버블 소트 <img src="https://github.com/AresGod96/Ares-Competitive-Programming/raw/master/boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">
Source: [Baekjoon OJ](https://www.acmicpc.net/problem/1517)

## [Statement](https://www.acmicpc.net/problem/1517)

## Difficulty <img src="https://github.com/AresGod96/Ares-Competitive-Programming/raw/master/boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">

## Tags
- sorting
- compression
- data structure
- binary indexed tree

## Solution
The problem asks for the number of swaps required by Bubble Sort to sort an array. This can be reformulated as counting the number of inversion pairs in the array. An inversion is a pair $(i, j)$ such that $i < j$ and $A[i] > A[j]$.

Since the elements in the array can be as large as $10^9$, directly counting inversions is inefficient. Instead, we can apply **coordinate compression** to reduce the range of array elements and then use a **Fenwick Tree (Binary Indexed Tree)** to efficiently count the inversions while sorting the array.

The approach can be broken down as follows:

1. **Compression**: We map the array values to a smaller range while preserving the order. This allows us to handle arrays with large values efficiently in a Fenwick Tree.
2. **Inversion Counting**: We traverse the array and use a Fenwick Tree to count how many elements larger than the current one have already been encountered. This gives the number of inversions for the current element.

### Complexity
- $O(N \log N)$ due to sorting and operations on Fenwick Tree