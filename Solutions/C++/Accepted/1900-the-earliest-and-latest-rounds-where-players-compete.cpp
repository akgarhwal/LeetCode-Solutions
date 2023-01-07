/*
Problem Title: 1900 - The Earliest and Latest Rounds Where Players Compete
Lang: C++
Runtime: 1888 ms
Memory: 525.6 MB
Problem Url: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete
Submission Url: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/submissions/507745205
*/

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> vec(n+1,0);
        for(int i= 1;i<=n;i++){
            vec[i]=1;
        }
        unordered_map<string, pair<int,int>> dp;
        auto res = solve(n, firstPlayer, secondPlayer, vec, 1, dp);
        vector<int> ans(2,0);
        ans[0] = res.first;
        ans[1] = res.second;
        return ans;
    }
    
    pair<int,int> solve(int n, int f, int s, vector<int> &vec, int r, unordered_map<string, pair<int,int>> &dp){
        
        
        string key = "";
        for(int x : vec){
            key += char(x - '0');
        }
        if(dp.find(key) != dp.end()){
            return dp[key];
        } 
        
        vector<vector<int>> vec2;
        
        int x = 1, y = n;
        while( x < y) {
            while(x < n and vec[x]==0) {
                x++;
            }
            if(x == n) break;
            while(y > 0 and vec[y]==0){
                y--;
            }
            
            if(y==0) break;
            if(x>=y){
                break;
            }
            if( x==f and y == s){
                // for(int x : vec){
                //     cout<<x<<" ";
                // }
                // cout<<" -> "<<r<<endl;
                return dp[key] = {r,r};
            }
            if(x == f or x == s){
                // x will win
                vec[x] = 1;
                vec[y] = 0;
                if(vec2.size()==0){
                    vec2.push_back(vec);
                }
                else{
                    for(auto &new_vec : vec2){
                        new_vec[x] = 1;
                        new_vec[y] = 0;
                    }
                }
            }
            else if(y == f or y == s){
                // y will win
                vec[x] = 0;
                vec[y] = 1;
                if(vec2.size()==0){
                    vec2.push_back(vec);
                }
                else{
                    for(auto &new_vec : vec2){
                        new_vec[x] = 0;
                        new_vec[y] = 1;
                    }
                }
            }
            else {
                
                if(vec2.size()==0){
                    vec[x] = 1;
                    vec[y] = 0;
                    vec2.push_back(vec);
                    vec[x] = 0;
                    vec[y] = 1;
                    vec2.push_back(vec);
                }
                else{
                    int ts = vec2.size();
                    for(int i=0;i<ts;i++){
                        vec2[i][y] = 0;
                        vector<int> new_vec(vec2[i].begin(), vec2[i].end());
                        new_vec[y]=1;
                        new_vec[x]=0;
                        vec2.push_back(new_vec);
                    }
                }
            }
            x++;y--;
        }
       
        pair<int,int> ans = {INT_MAX, INT_MIN};
        for(auto arr : vec2){
            // for(int x : arr){
            //     cout<<x<<" ";
            // }
            // cout<<" -> "<<r+1<<endl;
            auto res = solve(n,f,s,arr,r+1, dp);
            ans.first = min(ans.first, res.first);
            ans.second = max(ans.second, res.second);
        }
        return dp[key] = ans;
    }
    
};