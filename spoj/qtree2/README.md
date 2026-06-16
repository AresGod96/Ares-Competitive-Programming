## Problem SPOJ QTREE2 - Query on a tree II <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">
Source: [SPOJ](https://www.spoj.com/problems/QTREE2/)

## [Statement](https://www.spoj.com/problems/QTREE2/)

## Difficulty <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">

## Tags
- lowest common ancestor
- binary lifting
- trees

## Solution

Given a weighted tree of $N$ nodes, answer two types of queries online:
- **DIST u v**: sum of edge weights on the path from $u$ to $v$.
- **KTH u v k**: the $k$-th node (1-indexed) on the path from $u$ to $v$.

Both queries reduce to [binary lifting LCA](../../library/lca/).

### DIST query

Let $\text{dist}[u]$ be the total edge weight from the root to $u$, precomputed during the DFS. The path distance between $u$ and $v$ is:

$$\text{dist}(u, v) = \text{dist}[u] + \text{dist}[v] - 2 \cdot \text{dist}[\text{lca}(u, v)]$$

### KTH query

Let $\ell = \text{lca}(u, v)$, $d_u = \text{depth}[u] - \text{depth}[\ell]$, $d_v = \text{depth}[v] - \text{depth}[\ell]$.

The path from $u$ to $v$ passes through $\ell$: $u \to \cdots \to \ell \to \cdots \to v$, with $d_u + d_v + 1$ nodes total.

**Case 1** — the $k$-th node lies on the $u \to \ell$ segment ($k \leq d_u$):

$$\text{answer} = \text{kth\_parent}(u,\ k - 1)$$

**Case 2** — the $k$-th node lies at or below $\ell$ toward $v$ ($k > d_u$):

Let $k' = k - d_u - 1$ be the 0-indexed offset past $\ell$ along the $\ell \to v$ segment. The answer node is $k'$ steps from $v$ going upward:

$$\text{answer} = \text{kth\_parent}(v,\ d_v - k')$$

`kth_parent(u, k)` is implemented via binary lifting in $O(\log N)$.

### Implementation notes

- Each test case ends with `DONE` — the inner query loop must `break` on this token, otherwise subsequent test cases read corrupted input.
- $k$ is **1-indexed**: the first node on the path ($k = 1$) is $u$ itself, so Case 1 uses $k - 1$ hops, not $k$.

### Complexity
- Build: $O(N \log N)$
- Query: $O(\log N)$ per query
- Overall: $O((N + Q) \log N)$ per test case
