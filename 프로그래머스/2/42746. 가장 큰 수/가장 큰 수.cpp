#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> temps;
    
    for (const auto num : numbers) {
        temps.emplace_back(to_string(num));
    }
    
    sort(temps.begin(), temps.end(), cmp);
    
    for (const auto temp : temps) {
        answer += temp;
    }
    
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}