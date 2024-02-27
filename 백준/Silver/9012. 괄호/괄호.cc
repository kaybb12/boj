#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reckon_VPS(const string& str) {
	stack<char> st;

	for (const auto s : str) {
		if (st.empty())
			if (s == ')')
				return "NO";

		if (s == '(') {
			st.emplace(s);
		}

		if (!st.empty())
			if (s == ')')
				st.pop();
	}

	if (!st.empty())
		return "NO";

	return "YES";
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		cout << reckon_VPS(str) << "\n";
	}

	return 0;
}