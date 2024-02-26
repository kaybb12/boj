#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int count_set_num(const string& word) {
	set<string> words;
	for (int i = 0; i < word.size(); ++i)
		for (int j = i; j < word.size(); ++j)
			words.insert(word.substr(i, j - i + 1));

	return words.size();
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	cout << count_set_num(str) << "\n";

	return 0;
}
