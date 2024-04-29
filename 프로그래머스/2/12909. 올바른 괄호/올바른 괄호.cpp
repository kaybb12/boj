#include<string>
#include <iostream>

using namespace std;

bool solution(string str)
{
    bool answer = true;
    
    if (str.front() == ')' || str.back() == '(')
        return false;
    
    int left_cnt = 0;
    int right_cnt = 0;
    
    for (const auto& s : str) {
        if (s == '(')
            ++left_cnt;
        else if (s == ')')
            ++right_cnt;
        
        if (right_cnt > left_cnt)
            return false;
    }
    
    if (left_cnt != right_cnt)
        return false;  

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}