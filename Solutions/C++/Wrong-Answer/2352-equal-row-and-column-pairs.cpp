/*
Problem Title: 2352 - Equal Row and Column Pairs
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/equal-row-and-column-pairs
Submission Url: https://leetcode.com/problems/equal-row-and-column-pairs/submissions/765508295
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> mp;
        
        for(int i=0; i< grid.size(); i++){
            string temp = "";
            for(int j = 0; j < grid.size(); j++){
                temp += char(grid[j][i] + '0');                    
            }
            
            if(mp.find(temp) != mp.end()) {
                mp[temp] = mp[temp] + 1;
            }
            else{
                mp[temp] = 1;
            }
        }
        
        int answer = 0;
        
        for(int i=0; i< grid.size(); i++){
            string temp = "";
            for(int j = 0; j < grid.size(); j++){
                temp += char(grid[i][j] + '0');                    
            }
            
            if(mp.find(temp) != mp.end()) {
                answer += mp[temp];
            }
        }
        return answer;
    }
};