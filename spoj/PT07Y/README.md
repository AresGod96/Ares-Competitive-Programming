## Problem SPOJ PT07Y - Is it a tree <img src="../../boj-icon/bronze1.svg" alt="Bronze 1" width="20" height="20">
Source: [SPOJ](https://www.spoj.com/problems/PT07Y/)

## [Statement](https://www.spoj.com/problems/PT07Y/)

## Difficulty <img src="../../boj-icon/bronze1.svg" alt="Bronze 1" width="20" height="20">

## Tags
- graph theory
- tree
- depth-first search
- connected components

## Solution

Given an undirected graph with $N$ nodes and $M$ edges, decide whether it is a **tree**.

### Key Idea

For a graph on $N$ vertices, the three properties

1. connected,
2. acyclic,
3. having exactly $N - 1$ edges,

are linked: **any two of them imply the third.** So a graph is a tree **iff** it is connected *and*
has exactly $N - 1$ edges — that pair already forces acyclicity, so no explicit cycle check is needed.

The solution checks exactly those two conditions:

$$\text{tree} \iff (M = N - 1) \ \wedge\ (\text{the graph is connected})$$

### Steps

1. **Edge count.** If $M \neq N - 1$ the graph cannot be a tree — print `NO` and stop immediately.
2. **Connectivity.** Build the adjacency list and run a DFS from an unvisited node, counting how many
   connected components the graph has. The `par[]` array doubles as the visited marker
   (`par[v] == -1` means unvisited; roots are seeded with `par[u] = u`).
3. If there is exactly **one** component the graph is connected, so with $M = N - 1$ it is a tree →
   print `YES`; otherwise `NO`.

When $M = N - 1$ but the graph is disconnected, some component must contain a cycle (it has more edges
than a spanning tree of its size), which is why the component count alone settles it.

### Implementation notes

- **Early return after the edge-count check is mandatory.** PT07Y expects a single line of output, so
  the `M \neq N - 1` branch must `return` after printing `NO`; otherwise the DFS below runs and prints a
  second line, causing Wrong Answer.
- Nodes are **1-indexed** ($1 \ldots N$); the component scan loops over `FOR(u, 1, n)`.
- The DFS is recursive. With $N \le 10^4$ a degenerate path graph gives recursion depth $\approx N$,
  which is well within the stack limit, so no iterative rewrite is needed.
- A single node ($N = 1, M = 0$) satisfies $M = N - 1$ and forms one component → `YES`.

### Complexity
- Build (read edges + adjacency): $O(N + M)$
- Connectivity DFS: $O(N + M)$
- Overall: $O(N + M) = O(N)$, since the answered branch has $M = N - 1$
