#include <iostream>
#include <vector>

using namespace std;

vector<int> change_basket(vector<int>& baskets, const int from, const int to) {
	int j = to;

	for (int i = from; i < j; ++i) {
		swap(baskets[i], baskets[j]);
		--j;
	}

	vector<int> final_baskets(baskets.size());
	final_baskets = baskets;

	return final_baskets;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> baskets(N+1);
	for (int i = 1; i < baskets.size(); ++i) {
		baskets[i] = i;
	}

	vector<int> final_baskets(baskets.size());
	for (int i = 1; i <= M; ++i) {
		int from, to;
		cin >> from >> to;
		final_baskets = change_basket(baskets, from, to);
	}

	for (int i = 1; i < baskets.size(); ++i) {
		cout << final_baskets[i] << " ";
	}

	return 0;
}