#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> album;
    map<string, map<int, int>> albumlist;
    
    for (int i = 0; i < genres.size(); ++i) {
        album[genres[i]] += plays[i];
        albumlist[genres[i]][i] = plays[i];
    }
    
    while (album.size() > 0) {
        string genre;
        int max = 0;
    
        for (const auto& al : album) {
            if (max < al.second) {
                max = al.second;
                genre = al.first;
            }
        }
    
        for (int i = 0; i < 2; ++i) {
            int temp = 0;
            int num = -1;
        
            for (const auto& al : albumlist[genre]) {
                if (temp < al.second) {
                    temp = al.second;
                    num = al.first;
                }
            }
            
            if (num == -1)
                break;
        
            answer.emplace_back(num);
            albumlist[genre].erase(num);
        }
        
        album.erase(genre);
    }
    
    return answer;
}