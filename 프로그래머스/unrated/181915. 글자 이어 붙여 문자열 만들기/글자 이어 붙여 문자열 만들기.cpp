#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    string answer = "";
    
    for (const auto index : index_list) {
        answer += my_string[index];
    }
    
    return answer;
}