/*
Problem Title: 1900 - The Earliest and Latest Rounds Where Players Compete
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete
Submission Url: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/submissions/507743973
*/

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> vec(n);
        for(int i=1; i <= n;i++){
            vec[i-1] = i;
        }
        
        unordered_map<string, pair<int,int>> dp;
        auto res = solve(n, firstPlayer, secondPlayer, vec, 1);
        vector<int> ans(2,0);
        ans[0] = res.first;
        ans[1] = res.second;
        return ans;
    }
    
    pair<int,int> solve(int n, int f, int s, vector<int> vec, int r){
        
        int size = vec.size() / 2;
        if(vec.size() == 1) return {INT_MAX,INT_MIN};
        
        for(int i = 0; i < size; i++) {
            if(vec[i] == f && vec[vec.size() - i - 1] == s) {
                return {r,r};
            }
        }
        bool f1 = false, f2 = false;
        for(auto n : vec) {
            f1 |= n == f;
            f2 |= n == s;
        }
        if(!f1 || !f2) { 
            return {INT_MAX,INT_MIN};
        }
        
        int var = (1 << size) - 1;
        vector<int> vec2(size + (vec.size() % 2));
        pair<int,int> ans = {INT_MAX, INT_MIN};
        for(int i=0; i < var; i++){
            
            int x = 0, y = vec2.size()-1;
            for(int j = 0; j < size; j++) {
                if((1 << j) & i ) {
                    vec2[x++] = vec[j];
                }else { //right side player win.
                    vec2[y--] = vec[vec.size() - j - 1];
                }
            }
            if(vec.size() % 2) { //middle player go to the next round.
                vec2[x] = vec[vec.size() / 2];
            }
            auto res = solve(n,f,s,vec2,r+1);
            ans.first = min(ans.first, res.first);
            ans.second = max(ans.second, res.second);
        }
        return ans;
    }
    
};