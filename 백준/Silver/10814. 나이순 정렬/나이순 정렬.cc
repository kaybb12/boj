#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using Point = pair<int, string>;

bool compare_with(Point a, Point b) {
	return a.first < b.first;
}

void sort_ascending(vector<Point>& people) {
	stable_sort(people.begin(), people.end(), compare_with);
}

void print(const vector<Point>& people) {
	for (const auto& person : people) {
		auto [ age, name ] = person;
		cout << age << " " << name <<"\n";
	}
}

int main() {
	int n;
	cin >> n;
	vector<Point> people;

	for (int i = 0; i < n; ++i) {
		int age; 
		string name;
		cin >> age >> name;
		people.emplace_back(age, name);
	}

	sort_ascending(people);
	print(people);

	return 0;
}