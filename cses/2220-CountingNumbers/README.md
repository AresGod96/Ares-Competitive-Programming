## Problem CSES 2220 - Counting Numbers <img src="../../boj-icon/gold1.svg" alt="Gold 1" width="20" height="20">
Source: [CSES Problem Set](https://cses.fi/problemset/task/2220/)

## [Statement](https://cses.fi/problemset/task/2220/)

## Difficulty <img src="../../boj-icon/gold1.svg" alt="Gold 1" width="20" height="20">

## Tags
- digit DP
- combinatorics

## Solution

Count integers in $[a, b]$ where no two adjacent digits are the same.

We use the standard **digit DP** trick: define $\text{count}(n)$ as the number of valid integers in $[0, n]$, then the answer is $\text{count}(b) - \text{count}(a - 1)$.

### DP formulation

We process the number digit by digit from the most significant position. The recursive function is:

$$\text{calc}(\text{pos},\ \text{prev},\ \text{tight},\ \text{started})$$

| Parameter | Meaning |
|---|---|
| `pos` | Current digit position being filled |
| `prev` | Last digit placed (`10` = no digit placed yet) |
| `tight` | Whether the prefix so far matches the upper bound exactly |
| `started` | Whether a non-zero digit has been placed (handles leading zeros) |

**Transitions**: at each position, iterate over digits $d$ from $0$ to $\text{limit}$ (where $\text{limit} = 9$ if not tight, or the corresponding digit of $n$ if tight):
- Skip $d$ if `started && d == prev` — this would create two equal adjacent digits.
- Recurse with updated `tight` and `started` flags.

**Memoization**: the state `(pos, prev, started)` is memoized whenever `!tight`, since under the tight constraint the subproblem is unique and cannot be reused.

### Key observations

1. **Leading zeros** are tracked via the `started` flag. A leading zero does not count as a placed digit, so it does not constrain the next digit. Once the first non-zero digit is placed, `started = true` and the adjacent-equality rule kicks in.
2. The `prev` dimension ranges from $0$–$9$ plus the sentinel value $10$ (meaning "no previous digit"), giving $11$ possible values.
3. Numbers up to $10^{18}$ have at most $19$ digits, so the DP table is tiny: $20 \times 11 \times 2 = 440$ states.

### Complexity
- **DP states**: $O(D \times 10 \times 2)$ where $D \leq 19$ is the number of digits
- **Transitions per state**: $O(10)$
- **Overall**: $O(D \times 10^2) = O(D \times 100)$ — effectively $O(1)$ per query
