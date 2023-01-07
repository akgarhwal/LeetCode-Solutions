/*
Problem Title: 1889 - Minimum Space Wasted From Packaging
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-space-wasted-from-packaging
Submission Url: https://leetcode.com/problems/minimum-space-wasted-from-packaging/submissions/503678716
*/

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        long long ans = INT_MAX;
        for(int i =0 ; i < boxes.size(); i++){
            
            long long temp = 0;
            
            int pi = packages.size()-1;
            
            sort(boxes[i].begin(), boxes[i].end());
            
            int bi = boxes[i].size()-1;
            
            while( pi >= 0){
                while(bi >= 0 and boxes[i][bi] >= packages[pi]){
                    bi--;
                }
                
                int nbi = bi == (boxes[i].size()-1) ? bi : bi+1;
                temp += long(boxes[i][nbi] - packages[pi]);
                if(boxes[i][nbi] - packages[pi] < 0){
                    temp = -1;
                    break;
                }
                pi--;
            }
            if(temp != -1)
                ans = min(ans, temp);
        }
        ans = ans == INT_MAX ? -1 : ans;
        return ans%1000000007;
    }
};