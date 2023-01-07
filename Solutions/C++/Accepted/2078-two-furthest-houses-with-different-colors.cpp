/*
Problem Title: 2078 - Two Furthest Houses With Different Colors
Lang: C++
Runtime: 4 ms
Memory: 9 MB
Problem Url: https://leetcode.com/problems/two-furthest-houses-with-different-colors
Submission Url: https://leetcode.com/problems/two-furthest-houses-with-different-colors/submissions/592297376
*/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDist = 0;
        for(int i=0;i<colors.size();i++){
            int tempMaxDist = 0;
            for(int j=colors.size()-1;  j > i; j--){
                
                if(colors[i] != colors[j]){
                    tempMaxDist = (j-i);
                    break;
                }
                
            }
            maxDist = max(maxDist, tempMaxDist);
        }
        return maxDist;
    }
};