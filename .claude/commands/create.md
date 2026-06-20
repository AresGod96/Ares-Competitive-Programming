---
argument-hint: <target-path> (e.g. spoj/qtree3/qtree3.cpp or boj/1234-Title)
description: Initialize a new solution .cpp from template.cpp, filling the header from the problem source + statement HTML
---

# /create — scaffold a new solution from the Ares template

Target: `$ARGUMENTS`

The user will provide the **problem source** (judge + URL) and the **problem statement HTML**
in this message or the surrounding conversation. Use them to fill in the template header.

## Steps

1. **Resolve the target path** from `$ARGUMENTS`:
   - If it ends in `.cpp`, that is the solution file; its parent is the problem directory.
   - If it is a directory (no `.cpp`), follow the repo convention
     `<zero-padded-id>-<problem-title>/<id>.cpp` and name the `.cpp` after the problem id.
   - The top-level folder (`spoj/`, `boj/`, `codeforces/`, `cses/`, `vnoj/`, …) tells you the judge.
   - Create the problem directory if it does not exist.

2. **Extract metadata** from the provided source + statement HTML:
   - `Judge`   — from the source URL / top-level folder (SPOJ, BOJ, Codeforces, CSES, VNOJ, …).
   - `ID`      — problem id / code (e.g. `QTREE3`, `1234`, `1759F`).
   - `Title`   — the problem title (strip HTML tags).
   - `URL`     — the canonical problem link.
   - `Tags`    — algorithm tags if present in the statement or inferable; otherwise leave one
     placeholder `- <tag1>`.
   - If any field is genuinely unknown and not inferable, leave the template placeholder
     (`<Judge>`, `<ID>`, `<Title>`, `<URL>`) rather than guessing.

3. **Copy `template.cpp`** (at the repo root) to the target `.cpp` path. Do NOT hand-rewrite the
   template body — copy it verbatim so the macros/debug block stays identical. Then edit ONLY the
   header comment block (lines 1–9) to fill in the extracted metadata:

   ```cpp
   /*
       - author: Ares
       - "Let's make it to ORANGE!"
       - Problem: <Judge> - <ID> - <Title>
       - Problem link: <URL>

       - Tags:
           - <tag1>
   */
   ```

4. **Create an empty `input.txt`** in the problem directory (the template's `freopen("input.txt", ...)`
   reads it on local runs). If the statement includes a sample input, paste the first sample into it;
   otherwise leave it empty.

5. **Do not** add a README — editorials are written separately and only for hard problems.

6. Report what was created: the resolved paths and the metadata you filled in (flag any field left
   as a placeholder so the user can fill it).

## Notes
- Keep tabs for indentation to match the existing files.
- Never modify `template.cpp` itself.
- If `$ARGUMENTS` is empty, ask the user for the target path before proceeding.
