## Tags
- policy-based data structure
- treap

## Solution
Let's count how many sub-segment ending at $i$ satisfied the condition $A[j..i] >= K$.

Reformulate the above inequality, if we fix one endpoint, say $i$, we are asked to count how many $j$ that satisfies $A[j-1] <= A[i] - K$.

Thus, a data structure that supports updating and counting number of elements less than or equal to $K$ would work. In this case, both GNU policy-based data structure and Treap work well.

**Complexity**: $O(NlogN)$, since we loop through $N$ endpoints, and in each loop we perform query and update prefix sum in $O(log N)$.