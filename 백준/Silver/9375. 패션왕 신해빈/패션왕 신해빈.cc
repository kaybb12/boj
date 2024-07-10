#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int count_case( map<string, int> closet) {
	int cnt = 1;

	for ( auto &cl : closet) {
		cnt *= (cl.second + 1);
	}
	--cnt;

	return cnt;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;
		map <string, int> closet;
		
		for (int i = 0; i < n; ++i) {
			string type, name;
			cin >> name >> type;
			if (closet.find(type) == closet.end()) {
				closet[type] = 1;
			}
			else
				closet[type] += 1;
		}

		cout << count_case(closet) << "\n";
	}

	return 0;
}