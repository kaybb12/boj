#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void get_ballon_num(const int n) {
	deque<pair<int, int>> deq;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x; 
		deq.emplace_back(x, i+1);
	}

	while(!deq.empty()) {
		int cnt = deq.front().first;
		cout << deq.front().second << " ";
		deq.pop_front();
		if (cnt > 0) {
			for (int i = 1; i < cnt; ++i) {
				deq.emplace_back(deq.front());
				deq.pop_front();
			}
		}
		else {
			for (int i = cnt; i < 0; ++i) {
				deq.emplace_front(deq.back());
				deq.pop_back();
			}
		}
	}

	cout << "\n";
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	get_ballon_num(n);

	return 0;
}