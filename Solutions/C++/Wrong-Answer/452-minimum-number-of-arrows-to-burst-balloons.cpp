/*
Problem Title: 452 - Minimum Number of Arrows to Burst Balloons
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
Submission Url: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/872077869
*/

class Solution {
public:
    static bool sortBy(vector<int> first, vector<int> second){
        if(first[1] < second[1]) {
            return true;
        }
        if(first[0] < second[0]){
            return true;
        }
        return first[0] <= second[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), sortBy);

        for(auto point : points) {
            cout<<"("<<point[0]<<", "<<point[1]<<")  ";
        }

        int ans = 0;
        long last = (long)INT_MIN - 1LL;
        cout<<last<<endl;
        for(auto point : points) {
            
            if((long)point[0] > last) {
                ans += 1;
                last = point[1];
            }

        }

        return ans;
    }
};