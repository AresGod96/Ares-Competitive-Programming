## Problem USACO - Going Once, Going Twice, Gone! <img src="../../../../boj-icon/silver4.svg" alt="Silver 4" width="20" height="20">
Source: [USACO November 2008 Bronze](https://www.acmicpc.net/problem/1246)

## [Statement](https://www.acmicpc.net/problem/1246)

## Difficulty <img src="../../../../boj-icon/silver4.svg" alt="Silver 4" width="20" height="20">

## Tags
- greedy
- sorting

## Solution
This problem involves a simulation of an auction where Farmer John has $N$ identical lots of hay, and $M$ bidders, each with a specific budget. The goal is to maximize the total profit from selling the hay.

### Steps:
1. Sort the bidders based on their budgets in ascending order.
2. For each bidder $i$ (starting from the lowest budget), calculate the total profit using the formula $profit[i] = a[i] * min(N, M - i)$ where
- $N$ is the maximum number of hay lots Farmer John has to sell
- $(M - i)$ represents the number of bidders still remaining whose budgets are larger than current bidder with budget $a[i]$.

**Complexity**: $O(N\log N)$
