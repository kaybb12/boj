#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

static map<string, int> hash_x = {
    { "add", 0 },
    { "remove", 1 },
    { "check", 2 },
    { "toggle", 3 },
    { "all", 4 },
    { "empty", 5 }
};

void get_progress_result(const string& progress, int num, vector<int>& vec_s) {
    switch (hash_x[progress]) {
    case 0: // add
        vec_s[num] = 1;
        break;
    case 1: // remove
        vec_s[num] = 0;
        break;
    case 2: // check
        if (vec_s[num] == 1)
            cout << "1\n";
        else
            cout << "0\n";
        break;
    case 3: // toggle
        vec_s[num] = !vec_s[num];
        break;
    case 4: // all
        fill(vec_s.begin(), vec_s.end(), 1);
        break;
    case 5: // empty
        fill(vec_s.begin(), vec_s.end(), 0);
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;
    vector<int> vec_s(21, 0);

    while (M--) {
        string progress;
        int num = 0; // num 초기값 설정
        cin >> progress;

        if (progress != "all" && progress != "empty") {
            cin >> num;
        }

        get_progress_result(progress, num, vec_s);
    }

    return 0;
}