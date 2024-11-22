## Problem BOJ 2261 - 가장 가까운 두 점 <img src="../../boj-icon/plat2.svg" alt="Platinum 2" width="20" height="20">
Source: [Baekjoon OJ](https://www.acmicpc.net/problem/2261)

## [Statement](https://www.acmicpc.net/problem/2261)

## Difficulty <img src="../../boj-icon/plat2.svg" alt="Platinum 2" width="20" height="20">

## Tags
- sweep line
- divide and conquer

## Solution
Given $N$ points on 2D plane, we are asked to find the square of distance between the two nearest points.

This well-known problem can be solved using either **Divide and Conquer** approach or **sweep line** technique. More details can be found at https://cp-algorithms.com/geometry/nearest_points.html

Step-by-step algorithm

1. **Sorting**: 
   - First, sort the points based on their $x$-coordinates. This allows us to efficiently divide the points into two halves.

2. **Recursive Dividing**: 
   - The algorithm recursively divides the set of points into two halves and calculates the minimum distance in each half. If the set is small enough (e.g., fewer than 3 points), a brute-force approach calculates the distance between every pair of points.

3. **Merging Step**:
   - During the merge step, we focus on points near the vertical line dividing the two halves. A "strip" of points within the current minimum distance `res` is created. Only points that are close in the $y$-direction (less than `res` apart) are compared.

4. **Efficient Checking in the Strip**:
   - To efficiently check distances of points in the strip, the points are sorted by their $y$-coordinates. For each point in the strip, we check a limited number of nearby points to find any closer pairs.

### Complexity
- $O(N\log N)$
