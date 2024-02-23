#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool is_have(const vector<int>& in_cards, const int card) {
	int left = 0;
	int right = in_cards.size() - 1;

	while (left <= right) {
		int mid = (right + left) / 2;

		if (in_cards[mid] == card)
			return true;

		else if (in_cards[mid] > card)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return false;
}

void print_cards_have(vector<int>& in_cards, const vector<int>& out_cards) {
	sort(in_cards.begin(), in_cards.end());

	for (int i = 0; i < out_cards.size(); ++i) {
		cout << is_have(in_cards, out_cards[i]) << " ";
	}

	cout << "\n";
}

void comapre_card(vector<int>& in_cards, vector<int>& out_cards) {
	sort(in_cards.begin(), in_cards.end());
	vector<bool> had_card(out_cards.size());

	for (int i = 0; i < out_cards.size(); ++i) {
		int right = in_cards.size() - 1;
		int left = 0;
		while (left <= right) {
			int mid = (right + left) / 2;

			if (in_cards[mid] == out_cards[i]) {
				had_card[i] == true;
				break;
			}

			if (in_cards[mid] > out_cards[i])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	for (const auto is_had : had_card)
		cout << is_had << " ";

	cout << "\n";
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> in_cards(n);
	for (int i = 0; i < n; ++i)
		cin >> in_cards[i];

	int m;
	cin >> m;
	vector<int> out_cards(m);
	for (int i = 0; i < m; ++i) 
		cin >> out_cards[i];

	print_cards_have(in_cards, out_cards);
	//comapre_card(in_cards, out_cards);

	return 0;
}