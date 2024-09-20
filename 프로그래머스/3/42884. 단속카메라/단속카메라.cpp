#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const vector<int>& a, const vector<int>& b) {
    if (a[0] > b[0]) {
        return true;
    }
    else if (a[0] == b[0]) {
        if (a[1] > b[1])
            return true;
    }
    
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end(), cmp);
    int cur = routes[0][0];
    
    for (auto& route : routes) {
        if (cur >= route[0] && cur <= route[1])
            continue;
        cur = route[0];
        answer++;
    }
    
    
    return answer;
}