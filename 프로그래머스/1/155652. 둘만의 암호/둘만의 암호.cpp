#include <string>
#include <vector>

using namespace std;

bool check_skip(char ch, string skip) {
    for (int i = 0; i < skip.size(); ++i) {
        if (ch == skip[i])
            return true;
    }
    
    return false;
}

bool check_len(char ch) {
    if (ch > 'z')
        return true;
    else
        return false;
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (int i = 0; i < s.size(); ++i) {
        
        for (int j = 0; j < index; ++j) {
            s[i] += 1;
            
            if (check_len(s[i]))
                s[i] = 'a';
            
            while(check_skip(s[i], skip)) {
                s[i] += 1;
                if (check_len(s[i]))
                    s[i] = 'a';
            }
        }                        
        if (check_len(s[i]))
            s[i] = 'a';
        
        answer += s[i];
    }
    
    return answer;
}