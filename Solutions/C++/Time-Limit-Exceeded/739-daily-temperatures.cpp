/*
Problem Title: 739 - Daily Temperatures
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/daily-temperatures
Submission Url: https://leetcode.com/problems/daily-temperatures/submissions/308652521
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        map<int, vector<int>> temp;
        
        for(int ind = 0; ind < T.size(); ind++){
            if(temp.count(T[ind]) > 0){
                temp[T[ind]].push_back(ind);
            }
            else{
                vector<int> te;
                te.push_back(ind);
                temp.insert({T[ind], te});
            }
        }
        vector<int> ans(T.size(), 0);
        
        for(int ind = 0; ind < T.size(); ind++){
            int cur_temp = T[ind] + 1;
            int min_index = INT_MAX;
            while(cur_temp <= 100){
                if(temp.count(cur_temp) > 0){
                    for(auto t_ind : temp[cur_temp]) {
                        if(t_ind > ind && t_ind < min_index){
                            min_index = t_ind;
                            break;
                        }
                    }
                }
                cur_temp += 1;
            }
            ans[ind] = min_index == INT_MAX ? 0 : min_index - ind;
        }
        
        return ans;
    }
};