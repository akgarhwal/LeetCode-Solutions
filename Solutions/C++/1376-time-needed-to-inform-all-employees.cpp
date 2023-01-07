/*
Problem Title: 1376 - Time Needed to Inform All Employees
Lang: C++
Runtime: 1432 ms
Memory: 72.4 MB
Problem Url: https://leetcode.com/problems/time-needed-to-inform-all-employees
Submission Url: https://leetcode.com/problems/time-needed-to-inform-all-employees/submissions/310362183
*/

class Solution {
public:
    int helper(map<int,vector<int>>& tree, int node, vector<int>& info){
        
        if(tree.count(node) == 0){
            return 0;
        }
        int ans = 0;
        
        for(auto child : tree[node]){
            
            ans = max(ans, helper(tree, child, info) + info[node]);
            
        }
        
        return ans;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int, vector<int>> tree;
        
        for(int i=0;i<manager.size();i++){
            if(tree.count(manager[i]) == 0){
                vector<int> temp;
                tree[manager[i]] = temp;
            }
            tree[manager[i]].push_back(i);
        }
        
        int ans = 0;
        
        ans = helper(tree, headID, informTime);
        
        return ans;
    }
};