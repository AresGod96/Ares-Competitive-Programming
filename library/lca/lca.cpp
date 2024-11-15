/* 
	- author: Ares
	- "Let's make it to ORANGE!"
	- Problem: Baekjoon OJ - 11438 - LCA 2
	- Problem link: https://www.acmicpc.net/problem/11438

	- Solution: Binary lifting
		- Preprocess: O(NlogN)
		- Query: O(logN) per query
*/
#define LOCAL
#undef LOCAL

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1e5 + 10;

vector<vector<int>> g;

class LCA {
	/*
		This LCA finds the lowest common ancestor of two nodes (u, v)
		Pre-process: O(NlogN)
		Query: O(logN)
	*/
	public:
		int n, LOG;
		int root;

		int depth[MAXN];
		// int d[MAXN];	// distance from root
		int up[MAXN][19];
		
		LCA(vector<vector<int>> g, int root) {
			n = g.size();
			LOG = log2(n) + 1;
			this->root = root;
			depth[root] = 0;
			dfs(root, root);
		}

		void dfs(int u, int p) {
			up[u][0] = p;
			for (int i = 1; i < LOG; ++i) {
				up[u][i] = up[up[u][i - 1]][i - 1];
			}

			for (auto v: g[u]) {
				if (v != p) {
					depth[v] = depth[u] + 1;
					dfs(v, u);
				}
			}
		}

		// lift node u up by 'k' levels
		int lift(int u, int k) {
			for (int i = 0; i < LOG; ++i) {
				if (k & (1 << i)) {
					u = up[u][i];
				}
			}
			return u;
		}

		int get_lca(int u, int v) {
			if (depth[u] < depth[v]) swap(u, v);
			u = lift(u, depth[u] - depth[v]);
			if (u == v) return u;

			for (int i = LOG - 1; i >= 0; --i) {
				if (up[u][i] != up[v][i]) {
					u = up[u][i];
					v = up[v][i];
				}
			}
			return up[u][0];
		}

		// get distance between two nodes (u, v)
		int get_dist(int u, int v) {
			return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
		}
};

int main()
{
	//freopen(".inp", "r", stdin);	freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	cin.tie(0), ios::sync_with_stdio(0);
	int n;
	cin >> n;
	g.resize(n + 1);

	for (int i = 0; i < n  - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}

	int root = 1;
	LCA lca(g, root);

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		printf("%d\n", lca.get_lca(u, v));
	}

	return 0;
}