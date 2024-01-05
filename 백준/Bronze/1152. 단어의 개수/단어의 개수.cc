#include <iostream>
#include <vector>

using namespace std;

int count_num_of_word(const string& str) {
	int count = 0;
	for (const auto& ch : str) {
		if(ch == ' ' && ch )
			++count;
	}

	return count;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string str;
	int count = 0;
	while(cin >> str) {
		++count;
	}

	cout << count << "\n"; 

	return 0;
}