/*
Problem Title: 2087 - Minimum Cost Homecoming of a Robot in a Grid
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid
Submission Url: https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/submissions/593457273
*/

class Solution {
public:
    bool inLimit(int x, int y, int r, int c){
        if (x >= 0 and y >= 0 and x < r and y < c){
            return true;
        }
        return false;
    }
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
            priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
            
            pq.push({0, {startPos[0], startPos[1]}});
        
            int X[4] = {0,1,0,-1};
            int Y[4] = {1,0,-1,0};
            
            vector<vector<int>> cost(rowCosts.size(), vector<int>(colCosts.size(), INT_MAX));
            cost[startPos[0]][startPos[1]] = 0;
        
            int ans = INT_MAX;
        
            int r = rowCosts.size();
            int c = colCosts.size(); 
        
            while(!pq.empty()) {
                auto ele = pq.top(); pq.pop();
                if(ele.second.first == homePos[0] and ele.second.second == homePos[1]){
                    return ele.first;
                }
                if(cost[ele.second.first][ele.second.second] < ele.first){
                    continue;
                }
                for(int i =0 ; i < 4; i++){
                    int newX = X[i] + ele.second.first;
                    int newY = Y[i] + ele.second.second;
                    
                    
                    if(!inLimit(newX, newY, r,c)){
                        continue;
                    }
                
                    int tempCost = 0;
                    if(i%2 == 0){
                       tempCost = ele.first + colCosts[newY];
                    }
                    else{
                        tempCost = ele.first + rowCosts[newX];
                    }
                    
                    if(cost[newX][newY] > tempCost ){
                        cost[newX][newY] = tempCost;
                        pq.push({tempCost, {newX, newY}});
                         
                    }
                }
            }
        return ans;
    }
};