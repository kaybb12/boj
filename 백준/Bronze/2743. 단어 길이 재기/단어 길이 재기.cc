#include <iostream>
#include <string>

using namespace std;

inline int is_word_length(string word) {
	return word.size();
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string word;
	cin >> word;

	cout << is_word_length(word) << "\n";

	return 0;
}