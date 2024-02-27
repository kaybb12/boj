#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool is_eating(int n) {
	stack<int> st;
	int cnt = 1;

	while(n--) {
		int k;
		cin >> k;

		if (cnt == k)
			++cnt;
		else
			st.emplace(k);

		while(!st.empty() && st.top() == cnt) {
			st.pop();
			++cnt;
		}
	}

	if (!st.empty())
		return false;

	return true;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << (is_eating(n) ? "Nice" : "Sad") << "\n";

	return 0;
}