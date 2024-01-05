#include <iostream>
#include <string>

using namespace std;

void print(const int re_num, const string word) {
	for (int i = 0; i < word.size(); ++i) {
		for (int j = 0; j < re_num; ++j)
			cout << word[i];
	}
	cout << "\n";
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {
		int re_num;
		string word;
		cin >> re_num >> word;
		print(re_num, word);
	}

	return 0;
}