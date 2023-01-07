/*
Problem Title: 89 - Gray Code
Lang: C++
Runtime: 440 ms
Memory: 95.3 MB
Problem Url: https://leetcode.com/problems/gray-code
Submission Url: https://leetcode.com/problems/gray-code/submissions/515847105
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        int st = 0 , end = (1<<n)-1;
        vector<int> ans(end+1);
        map<int,vector<int>> mp;
        for(int i = 0; i <= end; i++){
            for(int j = 0; j <= 16; j++){
                int num = 0;
                if( (i&(1<<j)) > 0 ){
                    num = i&(~(1<<j));
                }
                else{
                    num = i|(1<<j);
                }
                if(num >= st and num <= end){
                    mp[i].push_back(num);    
                }
            }
        }
        ans[0] = 0;
        vector<int> vis(end+1, 0);
        bool found = false;
        dfs(0, 1, ans, mp, vis, found);
        return ans;
    }
    void dfs(int num, int i, vector<int> &ans, map<int,vector<int>> &mp, vector<int> &vis, bool &found){
        vis[num] = 1;
        if(i == ans.size() or found){
            found = true;
            return;
        }
        for(int x : mp[num]){
            if(vis[x] == 0 and found == false){
                ans[i] = x;
                dfs(x, i+1, ans, mp, vis, found);
            }
        }
        vis[num] = 0;        
        
    }
};