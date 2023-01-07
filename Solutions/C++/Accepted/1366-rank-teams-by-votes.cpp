/*
Problem Title: 1366 - Rank Teams by Votes
Lang: C++
Runtime: 140 ms
Memory: 105.1 MB
Problem Url: https://leetcode.com/problems/rank-teams-by-votes
Submission Url: https://leetcode.com/problems/rank-teams-by-votes/submissions/308158902
*/

bool my_sort(pair<int, vector<int>> first, pair<int, vector<int>> second){
    
    for(int i=0; i < 26;i++){
        if(first.second[i] < second.second[i]){
            return false;
        }
        if(first.second[i] > second.second[i]){
            return true;
        }
    }
    return first.first < second.first;
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        
        vector<pair<int, vector<int>>> mat(26, {0, vector<int>(26,0)});
        
        for(int i=0;i<votes.size();i++){
            string temp = votes[i];
            for(int j=0;j<temp.size();j++){
                char x = temp[j];
                vector<int> t2 = mat[x-'A'].second;
                t2[j] += 1;
                mat[x-'A'] = {x - 'A', t2};
            }
        }
        
        sort(mat.begin(), mat.end(), my_sort);
        
        string ans = "";
        
        for(int i = 0;i < votes[0].size();i++){
            ans += (mat[i].first + 'A'); 
        }
        
        return ans;
        
    }
};