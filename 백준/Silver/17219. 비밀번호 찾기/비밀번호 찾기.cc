#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void print_password(const int M, unordered_map<string, string> um) {
    for (int i = 0; i < M; ++i) {
        string site;
        cin >> site;
        
        cout << um[site] << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> passwords;
    
    for (int i = 0; i < N; ++i) {
        string site, password;
        cin >> site >> password;

        passwords[site] = password;
    }

    print_password(M, passwords);

    return 0;
}