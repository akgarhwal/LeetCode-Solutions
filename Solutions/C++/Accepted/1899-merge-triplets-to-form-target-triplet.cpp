/*
Problem Title: 1899 - Merge Triplets to Form Target Triplet
Lang: C++
Runtime: 716 ms
Memory: 169 MB
Problem Url: https://leetcode.com/problems/merge-triplets-to-form-target-triplet
Submission Url: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/submissions/507096007
*/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        set<int> del_ind;
        
        for(int i =0 ; i < triplets.size(); i++){
            if(triplets[i][0] > target[0]){
                del_ind.insert(i);
            }
            if(triplets[i][1] > target[1]){
                del_ind.insert(i);
            }
            if(triplets[i][2] > target[2]){
                del_ind.insert(i);
            }
        }
        vector<int> mx(3, 0);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < triplets.size(); j++){
                if(del_ind.find(j) == del_ind.end()){
                    mx[i] = max(mx[i], triplets[j][i]);
                }
            }
        }
        
        return (mx[0] == target[0] and mx[1] == target[1] and mx[2] == target[2]);
    }
};