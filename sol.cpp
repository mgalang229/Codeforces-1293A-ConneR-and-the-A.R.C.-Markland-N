#include <bits/stdc++.h>

using namespace std;

//int x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
//int y[8] = {0, 1, 0, -1, 1, -1, 1, -1};

//int x[4] = {1, 0, -1, 0};
//int y[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, s, k;
		cin >> n >> s >> k;
		bool checker = true;
		vector<int> a(k);
		set<int> st;
		for (int i = 0; i < k; i++) {
			cin >> a[i];
			checker &= (a[i] != s);
			st.insert(a[i]);
		}
		if (checker) {
			cout << 0 << '\n';
			continue;
		}
		if (st.find(s + 1) == st.end() && s + 1 <= n) {
			cout << 1 << '\n';
			continue;
		}
		if(st.find(s - 1) == st.end() && s - 1 > 0) {
			cout << 1 << '\n';
			continue;
		}
		int mn = INT_MAX;
		for (int i = 0; i < k; i++) {
			if (a[i] == s) {
				continue;
			}
			if (a[i] - 1 > 0 && st.find(a[i] - 1) == st.end()) {
				mn = min(mn, abs((a[i] - 1) - s));
			}
			if (st.find(a[i] + 1) == st.end() && a[i] + 1 <= n) {
				mn = min(mn, abs((a[i] + 1) - s));
			}
		}
		cout << mn << '\n';
	}
}
