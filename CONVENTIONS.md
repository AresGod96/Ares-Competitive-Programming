# Codebase Conventions

Conventions observed across this competitive-programming repository.

---

## Folder Structure

| Top-level folder | Purpose |
|---|---|
| `boj/` | Baekjoon Online Judge solutions |
| `codeforces/` | Codeforces contest solutions |
| `gym/` | Codeforces Gym / other team contest solutions |
| `icpc/` | ICPC regional/national solutions |
| `olympiads/` | National olympiad solutions (USACO, MCO, VOI, …) |
| `spoj/` | SPOJ solutions |
| `vnoj/` | VNOJ (vnoi.info) solutions |
| `free-contest/` | Free Contest solutions |
| `gcj/` | Google Code Jam solutions |
| `library/` | Reusable algorithm / data-structure implementations |
| `boj-icon/` | SVG badge assets for BOJ difficulty icons used in READMEs |

### Problem directory naming

```
<zero-padded-id>-<problem-title>/
    <id>.cpp        ← main solution
    input.txt       ← local test input (redirected via freopen)
    README.md       ← editorial (optional but encouraged for hard problems)
```

Multiple solutions in one folder use suffixes that describe the approach:

```
13547.cpp                  ← primary solution
13547_gpt.cpp              ← experimental / alternative approach
F-ArrayPartition-Nlog^2N.cpp
F-ArrayPartition-linear.cpp
```

---

## Solution Template

Every `.cpp` file begins with the **Ares template** (`~190 lines`).  Key sections:

### Header block
```cpp
/*
    - author: Ares
    - "Let's make it to ORANGE!"
    - Problem: <Judge> - <ID> - <Title>
    - Problem link: <URL>
    - Tags
        - <tag1>
        - <tag2>
*/
```

### Compile pragmas
```cpp
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
```

### Macro cheat-sheet
| Macro | Expands to |
|---|---|
| `FOR(i,a,b)` | inclusive for-loop `[a, b]` |
| `FORD(i,a,b)` | descending inclusive for-loop |
| `REP(i,a)` | zero-based for-loop `[0, a)` |
| `REPD(i,a)` | descending zero-based for-loop |
| `fi` / `se` | `first` / `second` of a pair |
| `SZ(x)` | `(int)(x).size()` |
| `sqr(x)` | `(x)*(x)` |
| `unify(x)` | sort + unique erase |
| `IOS` | fast I/O (`sync_with_stdio(0), cin.tie(0)`) |

Names `prev`, `next`, `left`, `right`, `y0`, `y1` are **redefined** to custom names to avoid STL/system conflicts.

### Debug helpers (tourist-style)
```cpp
#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
    #define debug(...) 42;
#endif
```
Enable debug mode by keeping `#define LOCAL` un-commented and removing `#undef LOCAL`.

### Common typedefs
```cpp
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll>   pll;
```

### Constants (adjust per problem)
```cpp
const int MAXN  = 1e5 + 10;
const int MOD   = 1e9 + 7;   // or 1e6, varies
const ll  MAXV  = 1e9;
const double eps = 1e-12;
const int INF   = 2e9 + 100;
const ll  INF_LL = 1e16;
```

### Entry point
```cpp
int Ares_KN()   // main — all problem logic lives here
{
    // ...
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    IOS
    Ares_KN();
    return 0;
}
```

> `input.txt` is read automatically during local runs; the redirect is stripped on the online judge.

---

## Build Configuration

VS Code task (`.vscode/tasks.json`):
```
g++ -std=c++17 -march=x86-64 -o <basename> <file>
```

Compilation is file-scoped — each `.cpp` is self-contained; there are no shared headers.

---

## Git Hygiene — Compiled Binaries Never Get Committed

Compiled binaries are produced beside their source by the build command
(`g++ ... -o <basename> <file>`), so they are **extensionless and named after the `.cpp`**
(e.g. `spoj/PT07Y/PT07Y`). They must never be committed.

A `pre-commit` hook (`.git/hooks/pre-commit`) enforces this. It unstages any compiled
artifact from the commit, detecting them two ways:

1. **By extension** — `.exe .o .out .obj .bin .dll .so .dylib .a .class .pyc`
2. **By content** — ELF / Mach-O / PE / object files via `file --mime-type` (this is what
   catches the extensionless artifacts above)

It only **unstages** (`git rm --cached`); it never deletes files from disk. The hook is POSIX
`sh`/dash-safe and preserves paths containing spaces (e.g. `library/Disjoint Set - Union Find/`).

> `.git/hooks/` is **not** version-controlled, so the hook lives only in each local clone.
> If you re-clone, reinstall it. (`.vscode/`, `.serena/`, `.claude/` are git-ignored.)

---

## GitNexus Index Auto-Refresh

The GitNexus knowledge graph (`.gitnexus/`, git-ignored) is re-indexed automatically
after each repository update by two hooks that share `.git/hooks/gitnexus-analyze.sh`:

- **`post-commit`** — refresh after every commit (and amend)
- **`post-merge`** — refresh after every `pull`/`merge`

The shared script runs `node .gitnexus/run.cjs analyze` (falling back to `npx gitnexus
analyze`) in a **detached background process**, so it never blocks git. A directory lock
(`.gitnexus/.analyze.lock`) skips a new run while one is in flight — rapid commits don't
pile up overlapping re-indexes of the large `.gitnexus/lbug`. Output is written to
`.gitnexus/analyze.log`. POSIX `sh`/dash-safe.

> Like the binary guard, these hooks are local-only — reinstall after a re-clone.

---

## Editorial / README Convention

Each README follows this template:

```markdown
## Problem <Judge> <ID> - <Title>  <difficulty-badge>
Source: [<Judge>](<url>)

## Difficulty  <badge>

## Tags
- tag1
- tag2

## Solution
<editorial prose with LaTeX complexity notation>

### Complexity
- Build: O(N log N)
- Query: O(log² N) per query
- Overall: O(Q log² N)
```

Difficulty badges reference SVG icons in `boj-icon/` (Bronze V → Ruby I scale from solved.ac).

---

## Library Catalogue

| Module | Location | Algorithm |
|---|---|---|
| Merge Sort Tree | `library/MergeSortTree/` | Segment tree with sorted node arrays; range-count queries in O(log² N) |
| LCA (Binary Lifting) | `library/lca/` | Sparse table ancestor; O(N log N) build, O(log N) query |
| Dijkstra (SSSP) | `library/SSSP-Dijkstra/` | Priority-queue Dijkstra |
| Disjoint Set (DSU) | `library/Disjoint Set - Union Find/` | Union by rank + path compression |
| Matrix Multiplication | `library/Matrix Multiplication/` | Fast matrix exponentiation |
| Mo's Algorithm | `library/MoAlgorithm/` | Offline range queries in O((N+Q)√N) |
| Minimum Spanning Tree | `library/Minimum Spanning Tree/` | Kruskal |
| Hash Function | `library/Hash Function/` | Polynomial rolling hash |

---

## Common Patterns

- **Offline vs online queries**: offline problems use Mo's Algorithm or sort-based tricks; online problems (with XOR-encoding of previous answer) use persistent / mergeable data structures.
- **Multiple solutions**: exploration files use suffixes like `_slow`, `_brute`, `_gpt` to distinguish approach variants.
- **Stress tests**: test generators are named `test_generator.cpp` beside the main solution (e.g., `vnoj/LCS2X/`).
- **Random utilities**: `mt19937 RNG` seeded with `chrono` is included in the template for randomised algorithms.
