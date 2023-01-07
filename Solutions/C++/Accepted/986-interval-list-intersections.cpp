/*
Problem Title: 986 - Interval List Intersections
Lang: C++
Runtime: 84 ms
Memory: 21.8 MB
Problem Url: https://leetcode.com/problems/interval-list-intersections
Submission Url: https://leetcode.com/problems/interval-list-intersections/submissions/343551461
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        
        if(A.size() == 0 or B.size() == 0){
            return ans;            
        }
        
        
        int i =0, j=0, last = -1;
        while(i < A.size() and j < B.size()){
            
            auto pa = A[i], pb = B[j];
            
            int smx = max(pa[0], pb[0]);
            int emi = min(pa[1], pb[1]);
            
            if(smx <= emi ){
                vector<int> temp;
                temp.push_back(smx);
                temp.push_back(emi);
                ans.push_back(temp);
                last = temp[1];
            }
            
            if(pa[1] < pb[1]){
                i++;
            }
            else{
                j++;
            }
            
        }
        
        return ans;
    }
};