/* Question: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 * Lang: cpp
 * Runtime: 88 ms
 * Memory: 32.3 MB
 * Question Url:
 * https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts
 * Submission Url:
 * https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/submissions/736243520
 */

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        verticalCuts.push_back(w);
        horizontalCuts.push_back(h);
        
        int ans = 0;
        
        int h_max = horizontalCuts[0], v_max = verticalCuts[0];
        for(int i = 1; i < horizontalCuts.size(); i++){
            h_max = max(h_max, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        for(int i = 1; i < verticalCuts.size(); i++){
            v_max = max(v_max, verticalCuts[i] - verticalCuts[i-1]);
        }
        return (h_max * 1LL* v_max) % 1000000007;
    }
};
