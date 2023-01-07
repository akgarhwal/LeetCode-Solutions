/*
Problem Title: 1458 - Max Dot Product of Two Subsequences
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/max-dot-product-of-two-subsequences
Submission Url: https://leetcode.com/problems/max-dot-product-of-two-subsequences/submissions/344205234
*/

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int  r = nums1.size(), c = nums2.size();
        vector<vector<int>> mat(r, vector<int>(c,0));
        int mx = INT_MIN;
        for(int i = 0; i< c ; i++){
            
            mat[0][i] = max(mx , nums2[i] * nums1[0]);
            mx = max(mx , mat[0][i]);
            
        }
        mx = mat[0][0];
        for(int i = 1; i< r ; i++){
            
            mat[i][0] = max(mx, nums1[i] * nums2[0]);
            mx = max(mx , mat[i][0]);
        }
        
        for(int i = 1; i< r ; i++){
            for(int j = 1; j < c ; j++){
                
                int t1 = nums1[i] * nums2[j] + mat[i-1][j-1];
                
                mat[i][j] =  max({t1, mat[i][j-1], mat[i-1][j]});
            }
        }
        
        return mat[r-1][c-1];
    }
};