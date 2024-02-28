#include <iostream>
#include <string>
#include <queue>

using namespace std;

void get_order(queue<int>& q, const string order) {
	
	if (order == "push") {
		int x;
		cin >> x;
		q.emplace(x);
	}
	else if (order == "pop") {
		if (!q.empty()) {		
			cout << q.front() << "\n";
			q.pop();
		}
		else
			cout << -1 << "\n";
	}
	else if (order == "size") {
		cout << (q.empty() ? 0 : q.size()) << "\n";
	}
	else if (order == "empty") {
		cout << (q.empty() ? 1 : 0) << "\n";
	}
	else if (order == "front") {
		cout << (q.empty() ? -1 : q.front()) << "\n";
	}
	else if (order == "back") {
		cout << (q.empty() ? -1 : q.back()) << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	queue<int> q;

	while(n--) {
		string order;
		cin >> order;
		get_order(q, order);
	}
	
	return 0;
}
