## Problem C - Binary Roads
Source: [Malaysian Computing Olympiad 2014](https://ioimalaysia.org/competition/mco/2014/)

## [Statement](https://www.acmicpc.net/problem/13213)

## Tags
- BFS
- dynamic programming
- graph

## Solution

The problem can be solved using Breadth-First Search (BFS) approach.

Let $f(v, value)$ denote the minimum time for Ali to reach vertex $v$ with his current status being $value$. Initially, since Ali starts at vertex $0$, and he can choose to start with either value $0$ or $1$, the first two states in the queue are $f(0, 0)$ and $f(0, 1)$.

**State transition**: from $f(v, value)$, we can calculate $f(u, value')$ if there is an edge between $u-v$ with weight equal to $value$. For simplicity, we can build $g[u][value]$ meaning the adjacent list of vertex $u$ with weight equals to $value$.

The answer is the minimum of $f(N - 1, 0)$ and $f(N - 1, 1)$.

**Complexity**: $O(V + E)$