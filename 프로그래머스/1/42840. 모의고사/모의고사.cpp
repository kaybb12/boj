#include <string>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> students(3);
    array<int, 5> answer_1 = {1, 2, 3, 4, 5};
    array<int, 8> answer_2 = {2, 1, 2, 3, 2, 4, 2, 5};
    array<int, 10> answer_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == answer_1[i % 5])
            ++students[0];
        if (answers[i] == answer_2[i % 8])
            ++students[1];
        if (answers[i] == answer_3[i % 10])
            ++students[2];
    }
    
    int max_score = students[0];
    
    for (const auto s : students) {
        max_score = max(max_score, s);
    }
    
    for (int i = 0; i < students.size(); ++i) {
        if (max_score == students[i])
            answer.emplace_back(i + 1);
    }
    
    return answer;
}