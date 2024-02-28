#include <iostream>
#include <deque>
#include <vector>

using namespace std;

constexpr static int Queue = 0;
constexpr static int Stack = 1;

void get_queue_stack(const vector<int>& conditions, const int n) {
	deque<int> deq;

	for (const auto cond : conditions) {
		int x;
		cin >> x;
		if (cond == Queue)
			deq.emplace_back(x);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		deq.emplace_front(x);
		cout << deq.back() << " ";
		deq.pop_back();
	}

	cout << "\n";
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> conditons(n);
	for (int i = 0; i < n; ++i) {
		cin >> conditons[i];
	} 

	get_queue_stack(conditons, n);

	return 0;
}