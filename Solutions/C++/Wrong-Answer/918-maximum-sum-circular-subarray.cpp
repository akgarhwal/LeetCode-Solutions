/*
Problem Title: 918 - Maximum Sum Circular Subarray
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximum-sum-circular-subarray
Submission Url: https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/339933610
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ans1 = INT_MIN, st = 0, sum = 0;
        for(int i = 0; i < 2*A.size();i++){
            if( i-st >= A.size()){
                sum -= A[st++];
                while(st <= i  && A[st%A.size()] <= 0){
                    sum -= A[st%A.size()];
                    st++;
                }
            }
            sum += A[i%A.size()];
            ans1 = max(ans1, sum);
            if(sum < 0){
                sum = 0;
                st = i+1;
            }
        }
        
        return ans1;
    }
};