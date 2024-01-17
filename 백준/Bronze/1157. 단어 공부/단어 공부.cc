#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char check_word(const string word) {

	vector<int> count(word.length(), 0);
	vector<int> alpha_cnt(('Z' - 'A' + 1), 0);

	for (int i = 0; i < word.length(); ++i) {
		if (word[i] < 'a') {
			++alpha_cnt[word[i] - 'A'];
		}
		else {
			++alpha_cnt[word[i] - 'a'];
		}
	}

	/*
	for ( int i = 0; i < alpha_cnt.size(); ++i){
		cout << alpha_cnt[i];
	}
	*/
	//cout << "\n";

	/*
	for (int i = 0; i < word.length(); ++i) {
		for (int j = i; j < word.length(); ++j) {
			if (word[i] == word[j] || (word[i] - 32) == word[j] || (word[i] + 32) == word[j])
				++count[i];
		}
	}
	*/

	int max_num = 0;
	int max_idx = 0;

	for (int i = 0; i < alpha_cnt.size(); ++i) {
		max_num = max(max_num, alpha_cnt[i]);

		if (alpha_cnt[i] >= max_num)
			max_idx = i;
	}

	//cout << max_num << " " << max_idx << "\n";

	int cnt = 0;

	for (int i = 0; i < alpha_cnt.size(); ++i) {
		if (max_num == alpha_cnt[i])
			++cnt;
		if (cnt > 1)
			break;
	}

	//cout << cnt << "\n";

	//cout << max_idx + 'A';

	if (cnt > 1)
		return '?';
	else
		return (max_idx + 'A');

	return 0;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	/*
	char ch = check_word(str);

	if (ch != '?') {
		if (ch < 'a')
			cout << ch << "\n";
		else {
			ch -= 32;
			cout << ch << "\n";
		}
	}
	else
		cout << ch << "\n";
	*/

	cout << check_word(str) << "\n";

	return 0;
}