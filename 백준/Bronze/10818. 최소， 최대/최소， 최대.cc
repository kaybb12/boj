#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

pair<ll, ll> compare_size(const ll cnt) {
	vector<ll> arr(cnt, 0);

	for (int i = 0; i < cnt; ++i) {
		cin >> arr[i];
	}

	ll max_num = arr[0]; 
	ll min_num = arr[0];

	for (int i = 0; i < cnt; ++i) {
		min_num = min(min_num, arr[i]);
		max_num = max(max_num, arr[i]);
	}

	return { min_num, max_num };
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	ll cnt;
	cin >> cnt;

	auto [ min_num, max_num ] = compare_size(cnt);
	cout << min_num << " " << max_num << "\n";

	return 0;
}