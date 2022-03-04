#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Table = map<int, vi>;

vl delays;
Table table;
vl memo;

ll solve(int w) {
	if (memo[w] < 0) {
		auto mx = ll{ 0 };
		for (const auto& a : table[w]) {
			const auto d = solve(a);
			if (mx < d) {
				mx = d;
			}
		}

		memo[w] = mx + delays[w - 1];
	}

	return memo[w];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;

		memo = vl(n + 1, -1);

		delays = vl(n);
		for (int j = 0; j < n; ++j) {
			cin >> delays[j];
		}

		table = Table{};
		for (int j = 1; j <= n; ++j) {
			table.insert({ j, vi{} });
		}

		for (int j = 0; j < k; ++j) {
			int a, b;
			cin >> a >> b;

			table[b].push_back(a);
		}

		int w;
		cin >> w;

		cout << solve(w) << '\n';
	}

	return 0;
}