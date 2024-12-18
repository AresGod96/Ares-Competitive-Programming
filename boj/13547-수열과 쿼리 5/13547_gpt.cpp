// generated by ChatGPT-4.0

#include <bits/stdc++.h>
using namespace std;

struct Query {
	int l, r, idx;
	bool operator<(const Query &other) const {
		return r < other.r; // Sort queries by R
	}
};

const int MAXN = 1e5 + 5;
int BIT[MAXN], result[MAXN];
int last_position[MAXN]; // Stores the last position of each element

void update(int idx, int value, int n) {
	for (; idx <= n; idx += idx & -idx)
		BIT[idx] += value;
}

int query(int idx) {
	int sum = 0;
	for (; idx > 0; idx -= idx & -idx)
		sum += BIT[idx];
	return sum;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	cin >> q;
	vector<Query> queries(q);
	for (int i = 0; i < q; i++) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].idx = i;
	}

	// Compress the array values
	vector<int> sorted_arr = arr;
	sort(sorted_arr.begin(), sorted_arr.end());
	sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
	for (int i = 1; i <= n; i++) {
		arr[i] = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin() + 1;
	}

	// Sort queries by R
	sort(queries.begin(), queries.end());

	// Process the array and answer queries
	memset(BIT, 0, sizeof(BIT));
	memset(last_position, 0, sizeof(last_position));
	int current_r = 0;

	for (const auto &q : queries) {
		while (current_r < q.r) {
			current_r++;
			int element = arr[current_r];
			if (last_position[element]) {
				update(last_position[element], -1, n);
			}
			update(current_r, 1, n);
			last_position[element] = current_r;
		}
		result[q.idx] = query(q.r) - query(q.l - 1);
	}

	// Output the results
	for (int i = 0; i < q; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
