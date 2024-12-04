## Problem BOJ 15681 - 트리와 쿼리 <img src="../../boj-icon/gold5.svg" alt="Gold 5" width="20" height="20">
Source: [Yonsei Programming Contest 2018 - Practice Session](https://www.acmicpc.net/category/detail/1860)

## [Statement](https://www.acmicpc.net/problem/15681)

## Difficulty <img src="../../boj-icon/gold5.svg" alt="Gold 5" width="20" height="20">

## Tags
- dfs
- dynamic programming

## Solution
Given a tree rooted at $R$, and $Q$ queries. For each query, we need to answer the number of nodes in subtree rooted at $u$.

While performing dfs, we also calculate $sub[u]$ indicating the number of nodes in subtree rooted at $u$, including $u$.
```c++
void dfs(int u, int p) {
	for (auto v: g[u]) {
		if (v != p) {
			par[v] = u;
			dfs(v, u);
			sub[u] += sub[v];
		}
	}
	++sub[u];
}
``` 

### Complexity: $O(N)$
