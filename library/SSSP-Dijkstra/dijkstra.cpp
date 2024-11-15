/*
	Algorithm: Single Source Shortest Path - Dijkstra with binary heap

	Usage: find shortest distance from source S to all vertices
	Complexity: O((|E| + |V|)log|V|)

	Input: Undirected/Directed graph with set of vertices V and set of edges E
	Output: N-element 'dist' array with dist[u] = shortest path from S to u

	Submitted to problem BOJ 1753 at https://www.acmicpc.net/problem/1753
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2e9 + 100;

struct Edge {
	int u, v, w;
};

class Graph {
	public:
		vector<Edge> edge_list;
		int n_vertices, n_edges;
		int directed = 0;

		vector<vector<pair<int, int> > > g;

		// input parser
		Graph(int node) {
			(*this).n_vertices = node;
			(*this).g.resize(node + 1);
		}

		Graph(int node, vector<Edge> list) {
			(*this).n_vertices = node;
			(*this).g.resize(node + 1);
			(*this).n_edges = list.size();
			(*this).edge_list = list;
			for (auto [u, v, w]: edge_list) {
				(*this).add_edge(u, v, w);
			}
		}

		void add_edge(int u, int v, int k) {
			g[u].emplace_back(v, k);
		}
};

class Dijkstra {
	public:
		int src;
		vector<int> dist;

		Dijkstra(Graph G, int src) {
			(*this).src = src;
			run(G, src);
		}

		Dijkstra(int node, vector<Edge> edge_list, int src) {
			(*this).src = src;
			Graph G(node, edge_list);
			run(G, src);
		}

		void run(Graph G, int src) {
			int n = G.n_vertices;
			dist.resize(n + 1);
			for (int u = 1; u <= n; ++u) dist[u] = INF;
			
			dist[src] = 0;
			priority_queue<pair<int, int> > heap;
			heap.push({-dist[src], src});
			while (!heap.empty()) {
				int u = heap.top().second;
				heap.pop();
				for (auto [v, w]: G.g[u])
					if (dist[v] > dist[u] + w) {
						dist[v] = dist[u] + w;
						heap.push({-dist[v], v});
					}
			}
		}

		int to(int vertex) {
			return dist[vertex];
		}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, src;
	cin >> n >> m >> src;

	// in this problem, graph is directed
	Graph G(n);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		G.add_edge(u, v, w);
	}

	Dijkstra D(G, src);
	for (int u = 1; u <= n; ++u)
		if (D.to(u) == INF) {
			puts("INF");
		}
		else {
			printf("%d\n", D.to(u));
		}

	return 0;
}