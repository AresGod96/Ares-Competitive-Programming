## Problem B - Random
Source: [Malaysian Computing Olympiad 2014](https://ioimalaysia.org/competition/mco/2014/)

## [Statement](https://www.acmicpc.net/problem/13212)

## Tags
- string
- math

## Solution
We must handle with care since number $N$ can be as large as $2^{32}$, which should be stored in either **unsigned int** or **long long** type.

A number is considered random when it satisfies the following conditions:
- it contains at most 3 consecutive repeated digits
- all factors of the number (except 1) must be greater than a given value $K$

The first condition can be checked easily by iterating through the string representation of the number, but the second condition is a bit trickier.

The second condition is equivalent to checking if the smallest prime factor of $N$ is greater than $K$. Since we only need to check up to $\sqrt{N}$, we can generate all primes less than $\sqrt{2^{32}}$, which is $2^{16}$. Using prime sieve, we can find that there are around 6000 primes less than $2^{16}$ (more exactly, 6542).

For each number $N$, we iterate through these 6542 generated primes. If there is a prime $p <= K$ that is also a factor of $N$, then $N$ is not a random number.


**Complexity**: $O(N * C)$ where $C$ is the number of prime numbers less than $2^{16}$