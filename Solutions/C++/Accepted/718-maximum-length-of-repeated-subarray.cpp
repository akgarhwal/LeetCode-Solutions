/*
Problem Title: 718 - Maximum Length of Repeated Subarray
Lang: C++
Runtime: 156 ms
Memory: 11.7 MB
Problem Url: https://leetcode.com/problems/maximum-length-of-repeated-subarray
Submission Url: https://leetcode.com/problems/maximum-length-of-repeated-subarray/submissions/519669337
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
    int m=nums2.size();
     int dp[2][m+1];
    int ans=0;
    for(int i=0;i<=m;i++){
        dp[1][i]=0;
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nums1[i-1]==nums2[j-1]){
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
            }
            else{
                dp[i%2][j]=0;
            }
            ans=max(ans, dp[i%2][j]);
        }
    }
    return ans;
    }
};