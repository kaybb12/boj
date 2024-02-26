#include <algorithm>
#include <iostream>
#include <vector>
#include <vector>
#include <map>

using namespace std;

inline int count_card(map<int, int>& cards, const int card) {
	return cards[card];
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<int, int> cards;
	for (int i = 0; i < n; ++i) {
		int card;
		cin >> card;
		++cards[card];
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int card;
		cin >> card;
		cout << count_card(cards, card) << " ";
	}
	cout << "\n";

	return 0;
}