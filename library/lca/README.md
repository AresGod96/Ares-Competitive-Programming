## Lowest Common Ancestor <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">

## Difficulty <img src="../../boj-icon/plat5.svg" alt="Platinum 5" width="20" height="20">

## Tutorial: Lowest Common Ancestor (LCA)

The **Lowest Common Ancestor (LCA)** of two nodes in a tree is the deepest node that is an ancestor of both nodes. The LCA problem is fundamental for many tree-based queries, such as calculating the distance between nodes or verifying if one node is an ancestor of another. Here’s a concise guide on solving the LCA efficiently.

### Problem Statement
Given a tree with $N$ nodes, answer multiple queries of the form: "What is the LCA of nodes $u$ and $v$?"

### Common Techniques

1. **Binary Lifting (Sparse Table)**:
   - **Description**: Binary lifting precomputes answers to the question, "What is the 2^k-th ancestor of each node?" for various values of $k$.
   - **Complexity**: Requires $O(N \log N)$ preprocessing time and answers each query in $O(\log N)$.

2. **Euler Tour + Segment Tree (RMQ)**:
   - **Description**: Perform a Depth-First Search (DFS) to record the first visit of each node and the order of visits (Euler tour). Using this tour, the LCA problem reduces to a Range Minimum Query (RMQ) on node depths.
   - **Complexity**: Takes $O(N \log N)$ for preprocessing and $O(1)$ or $O(\log N)$ per query depending on the RMQ data structure.

### Example Solution Outline Using Binary Lifting

#### Steps

1. **DFS to Calculate Depths**:
   - Perform a DFS from the root to assign a depth to each node.

2. **Build Sparse Table for Binary Lifting**:
   - For each node, compute its $2^k$-th ancestors up to the highest power of two less than $N$.

3. **Answer Queries**:
   - Use the sparse table to "lift" both nodes up to the same depth, then continue lifting both nodes up until reaching the LCA.


### Complexity
- Binary lifting: $O(N \log N)$ preprocessing and $O(\log N)$ each query
- Sparse table: $O(N \log N)$ preprocessing and $O(1)$ each query
- Euler Tour: $O(N \log N)$ preprocessing and $O(\log N)$ each query

### Practice problems
- [USACO Oct '08 Gold - Pasture Walking](../../olympiads/USACO/Oct08-Gold/PastureWalking/)
- [BOJ 11437 - LCA](../../boj/11437-LCA/)
- [BOJ 11438 - LCA 2](../../boj/11438-LCA%202/)
- [BOJ 03176 - Lubenica](../../boj/03176-Lubenica/)



