#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void count_people(vector<string>& names) {
	sort(names.begin(), names.end());

	cout << names.size() << "\n";
	for (const auto name : names)
		cout << name << "\n";
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	map<string, int> people;
	vector<string> names;

	for (int i = 0; i < n; ++i) {
		string name;
		cin >> name;
		++people[name];
	}

	for (int i = 0; i < m; ++i) {
		string name;
		cin >> name;
		++people[name];
		if (people[name] == 2)
			names.emplace_back(name);
	}

	count_people(names);

	return 0;
}