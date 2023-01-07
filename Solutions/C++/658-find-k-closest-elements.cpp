/*
Problem Title: 658 - Find K Closest Elements
Lang: C++
Runtime: 36 ms
Memory: 31.6 MB
Problem Url: https://leetcode.com/problems/find-k-closest-elements
Submission Url: https://leetcode.com/problems/find-k-closest-elements/submissions/516608530
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int idx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        vector<int> ans;

        int i = idx - 1;
        int j = idx;

        while(k--){
            
            if(i >= 0 and j < arr.size()){
                if(abs(arr[i] - x) <= abs(arr[j]-x)){
                    ans.push_back(arr[i]);
                    i--;
                }
                else{
                    ans.push_back(arr[j]);
                    j++;
                }
                continue;
            }
            
            if( i >= 0){
                ans.push_back(arr[i]);
                i--;
            }
            else{
                ans.push_back(arr[j]);
                j++;
            }
           
        }
        sort(ans.begin(), ans.end());
        return ans;        
    }
};