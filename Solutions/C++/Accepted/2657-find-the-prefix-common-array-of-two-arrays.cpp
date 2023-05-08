/*
Problem Title: 2657 - Find the Prefix Common Array of Two Arrays
Lang: C++
Runtime: 50 ms
Memory: 81 MB
Problem Url: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays
Submission Url: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/submissions/942970298
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq(A.size()+1, 0);
        vector<int> C(A.size(), 0);
        
        for(int i = 0; i < A.size(); i++) {
            
            freq[A[i]] += 1;
            freq[B[i]] += 1;
            
            int count = 0;
            
            for(int x = 1; x < freq.size(); x++) {
                count += (freq[x] == 2);
            }
            
            C[i] = count;
        }
        
        return C;
    }
};