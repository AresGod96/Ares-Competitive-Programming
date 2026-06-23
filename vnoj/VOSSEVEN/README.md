## Problem VNOJ VOSSEVEN - Bài toán số 7 <img src="../../boj-icon/bronze1.svg" alt="Bronze 1" width="20" height="20">
Source: [VNOI Online Judge](https://oj.vnoi.info/problem/vosseven)

## [Statement](https://oj.vnoi.info/problem/vosseven)

## Difficulty <img src="../../boj-icon/bronze1.svg" alt="Bronze 1" width="20" height="20">

## Tags
- prefix sum
- strings

## Solution

Given a string $s$ of $N$ digits (with $N \le 10^6$), for every length $i \ge 1$ we must report how many substrings consisting of **exactly $i$ consecutive `7`s** occur in $s$ — printing only the lengths whose count is non-zero, in increasing order.

### Reformulating with runs

A substring of $i$ consecutive `7`s can only live inside a *maximal run* of `7`s. If a maximal run has length $L$, then the number of windows of length $i$ that fit inside it is

$$\max(0,\ L - i + 1).$$

So the answer for a fixed length $i$ is

$$\text{ans}[i] = \sum_{\text{runs}} \max(0,\ L - i + 1).$$

A direct double loop over (length $i$) × (runs) is $O(N^2)$ in the worst case (e.g. a single run of a million `7`s), which is too slow. We need to accumulate all run contributions in linear time.

### The difference-array trick

Scan the string once, maintaining `cnt` = the length of the current run of `7`s ending at the position we are looking at (reset to $0$ on any non-`7`). When we are at a position whose running count is `cnt`, that position is the **right endpoint** of exactly one window of each length $1, 2, \dots, \text{cnt}$. In other words, this single character contributes $+1$ to $\text{ans}[1], \text{ans}[2], \dots, \text{ans}[\text{cnt}]$.

Adding $+1$ to the whole range $[1, \text{cnt}]$ for every character is again $O(N^2)$ if done naively, so we use a **difference array** $f$:

$$f[1] \mathrel{+}= 1, \qquad f[\text{cnt}+1] \mathrel{-}= 1.$$

After the scan, a single prefix sum turns $f$ into the answer:

$$f[i] \mathrel{+}= f[i-1].$$

Now $f[i]$ equals the number of positions whose running count was $\ge i$, which is exactly the number of length-$i$ windows of `7`s — i.e. $\text{ans}[i]$.

This works because, summed over one run of length $L$, the running counts take the values $1, 2, \dots, L$, and the number of positions with count $\ge i$ is $L - i + 1$, reproducing the formula above. Non-`7` characters set `cnt = 0`, so they contribute `f[1] += 1, f[1] -= 1`, a no-op — clean and branch-free.

### Why it's correct on the sample

For `72774777` the maximal runs are `7`, `77`, `777` (lengths $1, 2, 3$):
- length $1$: $1 + 2 + 3 = 6$
- length $2$: $0 + 1 + 2 = 3$
- length $3$: $0 + 0 + 1 = 1$

giving the expected output
```
1 6
2 3
3 1
```

### Implementation notes

- `len` tracks the longest run seen, so the final loop prints only lengths $1 \dots \text{len}$ — automatically skipping zero-count lengths beyond the longest run. (Interior lengths always have a positive count, since any length $i \le \text{len}$ fits inside the longest run.)
- The counts can be as large as $\approx N^2/2 \approx 5 \cdot 10^{11}$ for a single giant run, so the accumulator array `f[]` must be **64-bit** (`long long`); a 32-bit type would overflow.
- `f` is sized `MAXN = 1e6 + 100`, and `cnt + 1` reaches at most `len + 1 ≤ N + 1`, so the write `--f[cnt + 1]` stays in bounds.
- The statement guarantees at least one `7`, so `len ≥ 1` and there is always output.

### Complexity
- Scan + range updates: $O(N)$
- Prefix sum + output: $O(\text{len}) \le O(N)$
- **Overall**: $O(N)$ time, $O(N)$ memory
