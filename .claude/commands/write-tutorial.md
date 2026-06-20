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
  behind Cloudflare and can't be fetched). If a statement/tags/difficulty are provided, use them. If a
  field is genuinely unknown, leave a clearly-marked placeholder rather than guessing.

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
this repo still borrows the solved.ac scale; use the difficulty the user gives, or `0.svg` ("Unrated")
if none is known. SPOJ/CSES problems reuse these BOJ badges.

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
2. Gather Judge / ID / Title / URL / difficulty / tags from the user-provided statement; flag anything
   missing rather than fabricating.
3. Compute the correct `<REL>` prefix and badge filename; verify the badge path resolves.
4. Write `README.md` in the problem directory using the template above.
5. Report the file written and flag any placeholder left for the user to fill.

## Notes
- If `$ARGUMENTS` is empty, ask for the problem path.
- Editorials are encouraged mainly for non-trivial problems; it's fine to write a short one for easy
  problems if asked.
- Never commit a compiled binary (the `pre-commit` hook guards this); don't create one here.
