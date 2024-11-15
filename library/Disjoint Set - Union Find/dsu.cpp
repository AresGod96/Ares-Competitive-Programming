// - Disjoint Set - Union Find data structure
// - Using heuristic Union by rank
// - Complexity: makeSet O(1), findSet O(logN), merge O(logN)
// - Please try problem vn.spoj.com/problems/PBCGANGS
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 100;

// Disjoint-Set data structure
const int MAX_NODE = MAXN;
struct DisjointSet {

	struct node	{
		int parent, rank;
		int child;
	} T[MAX_NODE];

	DisjointSet() {
		for (int i = 0; i < MAX_NODE; ++i) make(i);
	}
	DisjointSet(int n) {
		for (int i = 0; i < n; ++i) make(i);
	}
	void make(int u) { T[u].parent = u, T[u].rank = 0; T[u].child = 1;}

	int get_child(int u)
	{
		return T[find(u)].child;
	}

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
		{
			T[u].parent = v;
			T[v].child += T[u].child;
		}
		else if (T[u].rank > T[v].rank)
		{
			T[v].parent = u;
			T[u].child += T[v].child;
		}
		else
		{

			T[v].parent = u;
			T[u].child += T[v].child;
			++T[u].rank;
		}
	}
};

DisjointSet DSU;

int main()
{
	// INPUT: N elements representing N sets
	int N = 10; 
	for (int i = 1; i <= N; ++i) DSU.make(i);
	printf("3 is in set %d\n", DSU.find(3));
	// 3 is in set 3	
	printf("5 is in set %d\n", DSU.find(5));
	// 5 is in set 5

	DSU.merge(3, 5);
	printf("3 is in set %d\n", DSU.find(3));
	// 3 is in set 3
	printf("5 is in set %d\n", DSU.find(5));
	// 5 is in set 3
}
