#include <iostream>
#include <vector>

using namespace std;

int is_area(const vector<vector<bool>>& arr) {
	int area = 0;

	for (int i = 1; i < 101; ++i) {
		for (int j = 1; j < 101; ++j) {
			if(arr[i][j])
				++area;
		}
	}

	return area;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	vector<vector<bool>> arr(101, vector<bool> (101, 0));

	for (int i = 1; i < 101; ++i) {
		for (int j = 1; j < 101; ++j) {
			
			int width, height;
			cin >> width >> height;

			for (int k = height; k < height + 10; ++k) {
				for (int l = width; l < width + 10; ++l) {
					arr[k][l] = true;
				}
			}
		}
	}

	cout << is_area(arr) << "\n";

	return 0;
}