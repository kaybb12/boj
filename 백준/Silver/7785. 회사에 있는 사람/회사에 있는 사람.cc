#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void get_enter_person(const map<string, string, greater<>>& company) {

	for (auto m : company) {
		if (m.second == "enter")
			cout << m.first << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, string, greater<>> company;
	for (int i = 0; i < n; ++i) {
		string name, stat;
		cin >> name >> stat;
		company[name] = stat;
	}

	get_enter_person(company);

	return 0;
}