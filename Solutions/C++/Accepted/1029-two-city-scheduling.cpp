/*
Problem Title: 1029 - Two City Scheduling
Lang: C++
Runtime: 20 ms
Memory: 10.3 MB
Problem Url: https://leetcode.com/problems/two-city-scheduling
Submission Url: https://leetcode.com/problems/two-city-scheduling/submissions/348784573
*/

bool mysort(vector<int> a, vector<int> b){
    // if(a[0] == b[0]){
    //     return a[1] > b[1];
    // }
    // return a[0] < b[0]; 
    if( (a[0]-a[1]) <= (b[0]-b[1])){
        return true;
    }
    else{
        return false;
    }
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), mysort);
        int ans = 0;
        for(int i = 0 ;i<costs.size();i++){
            if( i < costs.size()/2){
                ans += costs[i][0];
            }
            else{
                ans += costs[i][1];
            }
        }
        return ans;
    }
};