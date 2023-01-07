/*
Problem Title: 973 - K Closest Points to Origin
Lang: C++
Runtime: 1464 ms
Memory: 201.9 MB
Problem Url: https://leetcode.com/problems/k-closest-points-to-origin
Submission Url: https://leetcode.com/problems/k-closest-points-to-origin/submissions/346749172
*/

bool myfun(vector<int> f, vector<int> s){
    
    double df = sqrt( (f[0]*f[0] + f[1]*f[1]));
    double ds = sqrt( (s[0]*s[0] + s[1]*s[1]));
    
    return df <= ds;
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), myfun);
        vector<vector<int>> ans(points.begin(), points.begin()+K);
        return ans;
    }
};