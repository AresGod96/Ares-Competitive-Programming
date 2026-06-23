---
argument-hint: <problem-path> (e.g. spoj/PT07Y or boj/01761-정점들의 거리/1761.cpp)
description: Write a README.md editorial/tutorial for a solved problem, following this repo's tutorial template
---

# /write-tutorial — editorial for a solved problem

Target: `$ARGUMENTS`

Write a `README.md` tutorial in the problem's directory, matching the exact format used by the
existing editorials in this repo (see `spoj/qtree2/README.md`, `cses/2220-CountingNumbers/README.md`,
`boj/01761-정점들의 거리/README.md` for reference). The tutorial explains *the approach used in the
solution file* — read the code, do not invent a different algorithm.

## Inputs

- `$ARGUMENTS` is the problem directory or its `.cpp`. Resolve the directory; the `README.md` goes there.
- **Read the solution `.cpp`** in that directory to determine the actual algorithm, complexity, and any
  implementation gotchas worth documenting.
- The problem statement / difficulty may be **pasted by the user** in the message (judges like SPOJ sit
  behind Cloudflare and can't be fetched). If a statement/tags/difficulty are provided, use them.
- **Difficulty**: if the user gives a tier, use it. If not, **estimate one** using the calibration
  strategy in [Estimating difficulty](#estimating-difficulty-when-the-user-gives-none) below — anchored
  to how sibling problems in *this* repo are rated — and tell the user it is an estimate so they can
  override. Only fall back to `0.svg` ("Unrated") if you truly cannot place it.

## Template (follow exactly)

```markdown
## Problem <Judge> <ID> - <Title> <BADGE>
Source: [<Judge full name>](<url>)

## [Statement](<url>)

## Difficulty <BADGE>

## Tags
- tag1
- [linked tag](<relative-path-to-library-module>)

## Solution

<prose explaining the approach, using LaTeX: inline $...$ and display $$...$$>

### <optional subsections as the problem needs>
<e.g. "Key Idea", "Steps", "DP formulation", "Implementation notes", "Key observations">

### Complexity
- Build: $O(...)$
- Query: $O(...)$ per query
- Overall: $O(...)$
```

### Header details — match the existing files precisely
- **`<Judge>` token** in the title line is the short form: `SPOJ`, `BOJ`, `CSES`.
- **Source link label** is the full name: `[SPOJ](...)`, `[Baekjoon OJ](...)`, `[CSES Problem Set](...)`.
- **`## [Statement](<url>)`** is a linked heading to the same problem URL.
- The **difficulty badge appears twice** — once on the `## Problem` title line and once after
  `## Difficulty` — as an inline `<img>`:
  ```html
  <img src="<REL>/boj-icon/<rank>.svg" alt="<Rank Name>" width="20" height="20">
  ```

### Badge: rank → filename
Badges live in `boj-icon/`. Files: `bronze1..5`, `silver1..5`, `gold1..5`, `plat1..5`, `dia1..5`,
`ruby1..5` (each `.svg`), plus `master.svg` and `0.svg` (unrated). Tier I = `1`, tier V = `5`
(e.g. *Platinum 5* → `plat5.svg`, alt text `"Platinum 5"`; *Gold 1* → `gold1.svg`). For non-BOJ judges
this repo still borrows the solved.ac scale. SPOJ/CSES/VNOJ problems reuse these BOJ badges.

> **solved.ac scale — 30 numeric levels, easiest → hardest.** Six tiers, each split into sub-levels
> **V, IV, III, II, I** where **V is the easy end and I the hard end** of that tier. solved.ac numbers
> them 1–30; this repo's badge **filename** uses the Roman-numeral digit (I = `1`, V = `5`), so a *lower*
> filename number is the *harder* problem within a tier.
>
> | Tier | solved.ac levels | Badge files (easy→hard) |
> |---|---|---|
> | Bronze | 1–5 | `bronze5` → `bronze1` |
> | Silver | 6–10 | `silver5` → `silver1` |
> | Gold | 11–15 | `gold5` → `gold1` |
> | Platinum | 16–20 | `plat5` → `plat1` |
> | Diamond | 21–25 | `dia5` → `dia1` |
> | Ruby | 26–30 | `ruby5` → `ruby1` |
>
> Global order: `bronze5 < … < bronze1 < silver5 < … < gold1 < plat5 < … < ruby1 < master`.
> Source: [solved.ac — Problem Level](https://help.solved.ac/en/problem/level).

### Estimating difficulty (when the user gives none)

Estimate the tier on the **solved.ac scale above**, then **sanity-check it against sibling problems
already rated in this repo** so the local set stays internally consistent.

**Procedure:**
1. Identify the problem's *dominant technique(s)* from the solution `.cpp` you just read (e.g. prefix
   sum, LCA, segment tree, digit DP, treap, Mo's) and the constraint weight ($N$, time limit, online).
2. Map them to a solved.ac band using the technique table below.
3. Pull the repo's current ratings as a cross-check — re-derive each run since it grows over time:
   ```bash
   for f in $(find . -name README.md -not -path ./README.md); do
     b=$(grep -m1 -oE 'boj-icon/[a-z0-9]+\.svg' "$f" | sed 's|boj-icon/||;s|\.svg||')
     t=$(awk '/^## Tags/{f=1;next} /^## /{f=0} f&&/^- /{gsub(/^- |\(.*|\[|\]/,"");printf "%s; ",$0}' "$f")
     printf '%-9s | %-40s | %s\n' "$b" "$(dirname "$f")" "$t"
   done | sort
   ```
   If a sibling uses the same core technique, land within one sub-level of it unless this problem is
   clearly heavier/lighter.
4. State in your report that the tier is an **estimate**, give the solved.ac band, and name the
   repo sibling(s) you anchored to.

**Technique → solved.ac band** (general solved.ac calibration; the *repo example* column is the
current in-repo anchor, which may sit at the harder end of the band):

| solved.ac band | Typical techniques | Repo example |
|---|---|---|
| **Bronze (1–5)** | implementation, simulation, basic math, single-pass prefix sum / difference array, basic DFS / connected components, ad-hoc | `vnoj/VOSSEVEN` (B1), `spoj/PT07Y` (B1), `…/G-SharedCells` (B2) |
| **Silver (6–10)** | sorting + greedy, two pointers, plain binary search, simple DP, BFS/DFS shortest path, hashing, basic number theory | `…/A-PassportChecking` (S5), `…/Aunction` (S4), `…/B-Random` (S3), `vnoj/PWALK` (S1) |
| **Gold (11–15)** | standard DP, Dijkstra / MST, **segment tree / BIT** (point update + range query), **binary-lifting LCA**, **Euler Tour** flattening, **hard / parametric binary search**, digit DP, bitmask + combinatorics, KMP | `boj/01275` segtree (G1), `cses/2220` digit DP (G1), `…/J-PathQueries` LCA (G1), `olympiads/VOI/2011/COLOREC` bitmask (G1), `boj/11437-LCA` (G3), `…/C-BinaryRoads` BFS+DP (G4) |
| **Platinum (16–20)** | lazy/merge-sort segment tree, HLD, persistent structures, Mo's algorithm, treap / balanced BST, sqrt decomposition, DP optimizations, LCA/Euler Tour as a *sub-routine* of a harder offline/path query | `library/MoAlgorithm` (P2), `library/MergeSortTree` (P3), `boj/03176-Lubenica` (P4), `…/E-Fish` treap (P4), `spoj/qtree2` (P5) |
| **Diamond (21–25)** | suffix automaton/array, FFT/NTT, flows, segment tree beats, link-cut tree, advanced math | not yet represented |
| **Ruby (26–30)** | research-level / very hard | not yet represented |

Within a band, pick the sub-level by implementation weight: textbook + short → easy end (V/IV); composes
several techniques, fiddly edge cases, or heavy constraints ($N \le 10^6$, tight time, overflow, online)
→ hard end (II/I). When in doubt, match the repo sibling's sub-level. If the problem genuinely fits no
band and no sibling, use `0.svg` ("Unrated").

### `<REL>` — relative path to repo root, computed by directory depth
Count the directory levels from the problem dir to the repo root and emit that many `../`:
- `spoj/PT07Y/` → 2 levels → `../..`
- `boj/11437-LCA/` → 2 levels → `../..`
- `olympiads/MCO/2014/A-PassportChecking/` → 4 levels → `../../../..`
- `icpc/Vietnam/2024/NorthernProvincial/L-Eqpair/` → 5 levels → `../../../../..`

Verify by checking that `<REL>/boj-icon/` actually resolves to the real `boj-icon/` directory.
The same `<REL>` prefix is used for any `[linked tag](<REL>/library/...)` links.

## Content guidance
- Explain *why* the approach works, not just *what* the code does. Use LaTeX for all math/complexity.
- Add a short **Implementation notes** / **Key observations** subsection when the solution has a subtle
  detail (off-by-one, 1- vs 0-indexing, input-termination token, overflow, recursion depth) — the
  existing editorials do this.
- Link recurring techniques to their `library/` module when one exists (LCA, Mo's, DSU, etc.).
- Always end with a `### Complexity` section.

## Steps
1. Resolve the problem directory and read its `.cpp` (and `input.txt` for sample I/O if helpful).
2. Gather Judge / ID / Title / URL / tags from the user-provided statement; flag anything missing
   rather than fabricating. For **difficulty**: use the user's tier if given, else estimate one via
   [Estimating difficulty](#estimating-difficulty-when-the-user-gives-none) and mark it as an estimate.
3. Compute the correct `<REL>` prefix and badge filename; verify the badge path resolves.
4. Write `README.md` in the problem directory using the template above.
5. Report the file written and flag any placeholder left for the user to fill.

## Notes
- If `$ARGUMENTS` is empty, ask for the problem path.
- Editorials are encouraged mainly for non-trivial problems; it's fine to write a short one for easy
  problems if asked.
- Never commit a compiled binary (the `pre-commit` hook guards this); don't create one here.
