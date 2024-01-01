#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair <int, int> is_max_num() {
	vector<int> arr(9, 0);

	for (int i= 0; i < 9; ++i)
		cin >> arr[i];

	int max_num = arr[0];
	int cnt = 0;

	for (int i = 0; i < 9; ++i) {
		max_num = max(max_num, arr[i]);
		
		if (max_num == arr[i])
			cnt = i+1;
	}

	return { max_num, cnt };
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	auto [ max_num, cnt ] = is_max_num();
	cout << max_num << "\n";
	cout << cnt << "\n";

	return 0;
}