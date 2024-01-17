#include <iostream>

using namespace std;

int count_integer(const int num){
	int integer[num] = { 0, };

	for(int i = 0; i < num; ++i){
		cin >> integer[i];
	}

	int find_num, cnt = 0;
	cin >> find_num;

	for(int i = 0; i < num; ++i){
		if(integer[i]==find_num)
			++cnt;
	}

	return cnt;
}

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;

	cout << count_integer(num) << "\n";

	return 0;
}