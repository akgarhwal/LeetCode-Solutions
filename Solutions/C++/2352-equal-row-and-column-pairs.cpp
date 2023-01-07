/*
Problem Title: 2352 - Equal Row and Column Pairs
Lang: C++
Runtime: 394 ms
Memory: 42.7 MB
Problem Url: https://leetcode.com/problems/equal-row-and-column-pairs
Submission Url: https://leetcode.com/problems/equal-row-and-column-pairs/submissions/765509512
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> mp;
        
        for(int i=0; i< grid.size(); i++){
            string temp = "";
            for(int j = 0; j < grid.size(); j++){
                temp += to_string(grid[j][i]) + ",";                    
            }
            mp[temp] += 1;
        }
        
        int answer = 0;
        
        for(int i=0; i< grid.size(); i++){
            string temp = "";
            for(int j = 0; j < grid.size(); j++){
                temp += to_string(grid[i][j]) + ",";                 
            }
            
            if(mp.find(temp) != mp.end()) {
                answer += mp[temp];
            }
        }
        return answer;
    }
};