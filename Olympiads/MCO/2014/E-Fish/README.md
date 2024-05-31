## Tags
- policy-based data structure
- treap

## Solution
Let's count how many sub-segment ending at $i$ satisfied the condition $A[j..i] >= K$.
Reformulate the above inequality, if we fix one end $i$, we are asked to count how many $j$ that satisfies $A[j-1] <= A[i] - K$.

A data structure that supports updating and counting number of elements less than or equal to $K$ would work.

Since we loop through $N$ elements as endpoint, in each loop we perform query and update prefix sum in $O(log N)$, total complexity would be $O(NlogN)$.