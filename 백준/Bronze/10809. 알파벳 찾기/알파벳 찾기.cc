#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline string make_alphabet_set() {
	return "abcdefghijklmnopqrstuvwxyz";
}

vector<int> check_alphabet(const string word) {
	string alphabet = make_alphabet_set();
	vector<int> check_result(alphabet.size(), -1);

	for (int i = 0; i < word.size(); ++i) {
		for (int j = 0; j < alphabet.size(); ++j) {
			if (alphabet[j] == word[i]) {
				if (check_result[j] != -1)
					break;
				check_result[j] = i;	
			}
		}
	}

	return check_result;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string word;
	cin >> word;

	vector<int> check_result = check_alphabet(word);
	for (int i = 0; i < check_result.size(); ++i) {
		cout << check_result[i] << " ";
	}

	return 0;
}