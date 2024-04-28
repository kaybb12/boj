#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    
    for (const auto& ar : arr) {
        q.push(ar);
    }
    
    answer.emplace_back(q.front());
    q.pop();
    
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        if (temp != answer.back()) {
            answer.emplace_back(temp);
        }            
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}