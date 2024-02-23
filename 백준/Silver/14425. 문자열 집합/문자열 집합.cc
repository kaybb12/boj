#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_searching_word(const vector<string>& words, const string& str) {
	return binary_search(words.begin(), words.end(), str);
}

int get_corerct_word_count(vector<string>& words, const vector<string> test_words) {
	sort(words.begin(), words.end());

	int cnt = 0;
	for (const auto str : test_words) {
		if (is_searching_word(words, str))
			++cnt;
	}

	return cnt;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<string> words(n);
	for (int i = 0; i < n; ++i)
		cin >> words[i];

	vector<string> test_words(m);
	for (int i = 0; i < m; ++i) {
		cin >> test_words[i];
	}

	cout << get_corerct_word_count(words, test_words) << "\n";

	return 0;
}