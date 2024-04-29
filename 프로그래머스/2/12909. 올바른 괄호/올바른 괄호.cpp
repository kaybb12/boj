#include<string>
#include <iostream>

using namespace std;

bool solution(string str)
{
    int cnt = 0;
    
    for (const auto s : str) {
        if (cnt < 0)
            return false;
        
        if (s == '(')
            ++cnt;
        else if (s == ')')
            --cnt;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return (cnt == 0);
}