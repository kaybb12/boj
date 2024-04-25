#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    //bool answer = true;
    unordered_map<string, bool> hash;
    
    for (const auto& phone_number : phone_book)
        hash[phone_number] = true;
    
    for (const auto& phone_number : phone_book) {
        for (int i = 0; i < phone_number.length() - 1; ++i) {
            string number = phone_number.substr(0, i + 1);
            if (hash[number])
                return false;
        }
    }
    return true;
    
    //return answer;
}