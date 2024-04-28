#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

void print(const vector<int>& vecs) {
    cout << "벡터 ";
    for (const auto v : vecs) {
        cout << v << " ";
    }
    cout << "\n";
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> durations;
    queue<int> q;
    
    for (int i = 0; i < progresses.size(); ++i) {
        int space = 100 - progresses[i];
        if (space % speeds[i] == 0)
            durations.emplace_back(space / speeds[i]);
        else
            durations.emplace_back(space / speeds[i] + 1);
    }    
    
    for (int i = 1; i < durations.size(); ++i) {
        if (durations[i] < durations[i - 1])
            durations[i] = durations[i - 1];
    }
    
    
    unordered_map<int, int> days;
    
    for (const auto& duration : durations) {
        days[duration] += 1;
    }
    
    durations.erase(unique(durations.begin(), durations.end()),durations.end());
    
    for (const auto& duration : durations) {
        answer.emplace_back(days[duration]);
    }
    
    return answer;
}