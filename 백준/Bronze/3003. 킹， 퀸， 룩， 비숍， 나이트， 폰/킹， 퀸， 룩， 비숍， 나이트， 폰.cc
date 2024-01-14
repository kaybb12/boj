#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int> arr) {
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " " ;
	}
	cout << "\n";
}

vector<int> find_chess_piece (const vector<int> chess_pieces) {
	vector<int> origin_pieces = {1, 1, 2, 2, 2, 8};	

	for (int i = 0; i < chess_pieces.size(); ++i) {
		origin_pieces[i] -= chess_pieces[i];
	}

	return origin_pieces;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	
	vector<int> chess_pieces(6);

	for (int i = 0; i < chess_pieces.size(); ++i) {		
		cin >> chess_pieces[i];	
	}

	chess_pieces = find_chess_piece(chess_pieces);
	print_arr(chess_pieces);

	return 0;
}