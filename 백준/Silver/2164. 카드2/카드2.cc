#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int get_card_num(const int n) {
	queue<int> q;

	for (int i = 1; i <= n; ++i) {
		q.emplace(i);
	}

	while(q.size() != 1) {
		q.pop();
		q.emplace(q.front());
		q.pop();
	}

	return q.front();
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << get_card_num(n) << "\n";

	return 0;
}