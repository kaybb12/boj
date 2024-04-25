#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participants, vector<string> completions) {
    string answer = "";
    
    unordered_map<string, int> hash;
    
    for (auto participant : participants) {
        hash[participant] += 1;
    }
    
    for (auto completion : completions) {
        hash[completion] -= 1;
    }
    
    for (auto participant : participants) {
        if (hash[participant] == 1)
            answer = participant;
    }
    
    return answer;
}