## Problem COLOREC <img src="../../../../boj-icon/gold1.svg" alt="Gold 1" width="20" height="20">
Source: [Vietnamese Olympiad in Informatics 2011](https://drive.google.com/drive/folders/1iNVER-0ociKM34HPzGmb6vnBgF6NMw5V)

## [Statement](https://oj.vnoi.info/problem/colorec)

## Difficulty <img src="../../../../boj-icon/gold1.svg" alt="Gold 1" width="20" height="20">

## Tags
- bitmask
- combinatorics

## Solution

Given $N$ points in a 2D plane, each colored one of four colors {1, 2, 3, 4}, we are asked to count the number of 4-color rectangles that can be formed using four points, each with a distinct color.

For subtask with $50\%$ score, an $O(N^4)$ solution would work.

To achieve a $O(d^3)$ solution, where $d$ is the maximum absolute value of coordinates, we aim to count the 4-color rectangles by fixing two rows and sweeping through columns to count color combinations efficiently.

1. **Grid Mapping**:
   - Store each point’s color in a grid $rect[x][y]$, offsetting coordinates to handle negative values.

2. **Row Pairing and Column Sweep**:
   - For each pair of rows ($top$ and $bot$), we count color pairs by sweeping across columns between the selected rows.
   - For each column, we track two colors (if different) at $y_{top}$ and $y_{bot}$ and store them as a bitmask.

3. **Counting Valid Rectangles**:
   - After processing each column for a given pair of rows, we use bitwise combinations to count pairs of colors that together form all four colors.
   - For each color pair bitmask, calculate the number of valid rectangles that include all four colors, ensuring no duplicate counting.

4. **Result Adjustment**:
   - Each rectangle is counted twice, so we divide the result by 2 to get the final count.

**Complexity**:
- **Time Complexity**: $O(d^3)$, where $d$ is the maximum coordinate range (400).
- **Space Complexity**: $O(d^2)$ for the $rect$ grid.
