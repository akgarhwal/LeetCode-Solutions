/*
Problem Title: 986 - Interval List Intersections
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/interval-list-intersections
Submission Url: https://leetcode.com/problems/interval-list-intersections/submissions/343550168
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        
        if(A.size() == 0 or B.size() == 0){
            return ans;            
        }
        
        
        int i =0, j=0, last = 0;
        
        while(i < A.size() and j < B.size()){
            
            auto pa = A[i], pb = B[j];
            
            int smx = max(pa[0], pb[0]);
            int emi = min(pa[1], pb[1]);
            
            if(last < smx and  smx <= emi and smx >= pa[0] and smx <= pa[1] ){
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
        
        while(i < A.size()){
            auto pa = A[i], pb = B[j-1];
            int smx = max(pa[0], pb[0]);
            int emi = min(pa[1], pb[1]);
            
            if(last < smx and  smx <= emi and smx >= pa[0] and smx <= pa[1]){
                vector<int> temp;
                temp.push_back(smx);
                temp.push_back(emi);
                ans.push_back(temp);
                last = temp[1];
            }
            i++;
        }
        
        while(j < B.size()){
            auto pa = A[i-1], pb = B[j];
            int smx = max(pa[0], pb[0]);
            int emi = min(pa[1], pb[1]);
            
            if(last < smx and  smx <= emi and smx >= pa[0] and smx <= pa[1]){
                vector<int> temp;
                temp.push_back(smx);
                temp.push_back(emi);
                ans.push_back(temp);
                last = temp[1];
            }
            j++;
        }
        return ans;
    }
};