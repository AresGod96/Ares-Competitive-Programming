## Problem E - Fish <img src="https://github.com/AresGod96/Ares-Competitive-Programming/raw/master/boj-icon/plat4.svg" alt="Platinum 4" width="20" height="20">
Source: [Malaysian Computing Olympiad 2014](https://ioimalaysia.org/competition/mco/2014/)

## [Statement](https://www.acmicpc.net/problem/13215)

## Difficulty <img src="https://github.com/AresGod96/Ares-Competitive-Programming/raw/master/boj-icon/plat4.svg" alt="Platinum 4" width="20" height="20">

## Tags
- data structure
- treap

## Solution
Let's count how many sub-segments ending at $i$ satisfy the condition $sum(A[j..i]) >= K$. With prefix sum, this is equal to $A[i] - A[j - 1] >= K$.

Reformulating the above inequality, if we fix one endpoint, say $i$, we are asked to count how many $j$ such that $A[j-1] <= A[i] - K$.

By looping through each endpoint, we also need to update the prefix sum ending at $i$.

Thus, a data structure that supports updating and counting number of elements less than or equal to a given value $K$ would work. In this case, both GNU policy-based data structure and Treap work well.

**Complexity**: $O(N \log N)$, since we loop through $N$ endpoints, and in each loop we perform a single query and update prefix sum in $O(\log N)$.