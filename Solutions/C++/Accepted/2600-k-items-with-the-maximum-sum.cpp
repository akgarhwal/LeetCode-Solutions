/*
Problem Title: 2600 - K Items With the Maximum Sum
Lang: C++
Runtime: 2 ms
Memory: 5.9 MB
Problem Url: https://leetcode.com/problems/k-items-with-the-maximum-sum
Submission Url: https://leetcode.com/problems/k-items-with-the-maximum-sum/submissions/922210059
*/

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        
        if( k > (numOnes + numZeros)) {
            return (numOnes + numZeros) - (k-(numOnes));
        }
        
        return min(k, numOnes);
    }
};