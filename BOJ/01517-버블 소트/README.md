## Problem BOJ 1517 -  버블 소트 <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">
Source: [Baekjoon OJ](https://www.acmicpc.net/problem/1517)

## [Statement](https://www.acmicpc.net/problem/1517)

## Tags
- sorting
- compression
- data structure

## Difficulty <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">

## Solution
The problem asks to count the number of swaps made in bubble sort, which is equivalent to counting the number of inversion pairs in the array. An inversion occurs when a larger element precedes a smaller one in the array.

Since the values in the array $A[i]$ can be as large as $10^9$, directly working with such large values would be inefficient. To handle this, we first compress the values in the array. After compressing, we can use a data structure such as a Fenwick Tree (Binary Indexed Tree) to efficiently count the number of inversions.

The approach can be broken down as follows:

1. **Compression**: We map the array values to a smaller range while preserving the order. This allows us to handle arrays with large values efficiently in a Fenwick Tree.
2. **Inversion Counting**: We traverse the array and use a Fenwick Tree to count how many elements larger than the current one have already been encountered. This gives the number of inversions for the current element.

**Complexity**: $O(NlogN)$ due to sorting and operations on Fenwick Tree