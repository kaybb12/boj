#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_triangle(const vector<int>& angles) {
	int sum = 0;
	
	for (auto angle : angles) {
		sum += angle;
	}

	if (sum != 180)
		return false;

	return true;
}

string determine_triangle(const vector<int>& angles) {
	int same_cnt = 0;

	for (int i = 0; i < angles.size(); ++i) {
		if (i < angles.size() - 1) {
			for (int j = i + 1; j < angles.size(); ++j) {
				if (angles[i] == angles[j])
					++same_cnt;
			}
		}
	}

	if (same_cnt == 0) {
		return "Scalene";
	}
	else if (same_cnt == 1) {
		return "Isosceles";
	}
	else {
		return "Equilateral";
	}
	
	return "0";
}

int main() {
	vector<int> angles(3);
	
	for (int i = 0; i < angles.size(); ++i) {
		cin >> angles[i];
	}

	if (!is_triangle(angles)) {
		cout << "Error" << "\n";
		return 0;
	}

	cout << determine_triangle(angles) << "\n";

	return 0;
}