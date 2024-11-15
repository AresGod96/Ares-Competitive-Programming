## Problem G - Corner-Shared Cells <img src="../../../../../boj-icon/bronze2.svg" alt="Bronze 2" width="20" height="20">
Source: [ICPC Vietnam Central Provincial 2024](https://oj.vnoi.info/contest/icpc24_mt)

## [Statement](https://oj.vnoi.info/problem/icpc24_mt_g)

## Difficulty <img src="../../../../../boj-icon/bronze2.svg" alt="Bronze 2" width="20" height="20">

## Tags
- ad-hoc

## Solution
There are 3 cases to be considered
- Corner $(1,1)$ or $(1,n)$ or $(m,1)$ or $(m,n)$: 3 shared-cells
- Boundary cells that are not corners: 5 shared-cells
- Interior cells (cells that do not lie on the boundaries): 8 shared-cells

**Complexity**: 
- $O(1)$
