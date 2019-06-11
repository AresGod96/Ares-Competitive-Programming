// - Kruskal's Algorithm
// - Find minimum spanning tree of a graph using DSU
// - NOTE: GRAPH MUST CONNECTED
// - Complexity: O(|E|*logV)
// - submitted on vn.spoj.com/problems/QBMST
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5 + 100;

const int MAX_NODE = MAXN;
struct DisjointSet
{

	struct node
	{
		int parent, rank;
	} T[MAX_NODE];

	DisjointSet(int n)
	{
		for (int i = 0; i < n; ++i) make(i);
	}
	void make(int u) { T[u].parent = u, T[u].rank = 0;};

	int find(int u)
	{
		if (T[u].parent == u) return u;
		return T[u].parent = find(T[u].parent);
	}

	void merge(int u, int v)	// union by rank
	{
		u = find(u), v = find(v);
		if (u == v) return;
		if (T[u].rank < T[v].rank)
			T[u].parent = v;
		else if (T[u].rank > T[v].rank)
			T[v].parent = u;
		else
			T[v].parent = u, ++T[u].rank;
	}
};

struct edge {
	int u, v, w;
};
priority_queue<pair<int, pair<int, int>>> heap;
int n, m; //input vertices and edges
vector<edge> E; //MST

int main()
{
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		heap.push({-w, {u, v}});
	}
	// Kruskal
	DisjointSet dsu(n);
	int res = 0;
	while (!heap.empty())
	{
		int u = heap.top().se.fi, v = heap.top().se.se;
		int w = -heap.top().fi;
		heap.pop();
		if (dsu.find(u) == dsu.find(v)) continue;
		res += w;
		E.push_back({u, v, w});
		dsu.merge(u, v);
	}
	printf("Minimum Spanning Tree's weight = %d\n", res);
	for (auto x: E)
		printf("%d %d %d\n", x.u, x.v, x.w);
	return 0;
}
