## Problem A - Passport Checking
Source: [Malaysian Computing Olympiad 2014](https://ioimalaysia.org/competition/mco/2014/)

## [Statement](https://www.acmicpc.net/problem/13211)

## Tags
- hash
- binary search

## Solution
For each query, we perform a binary search or use a map to check if a string exists in the dictionary in $O(logN)$ time.

**Complexity**: $O(Q * logN)$