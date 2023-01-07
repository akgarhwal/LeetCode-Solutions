/*
Problem Title: 1640 - Check Array Formation Through Concatenation
Lang: C++
Runtime: 36 ms
Memory: 14 MB
Problem Url: https://leetcode.com/problems/check-array-formation-through-concatenation
Submission Url: https://leetcode.com/problems/check-array-formation-through-concatenation/submissions/437084183
*/

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        bool res = true;
        int count = 0;
        for(int i=0; i< arr.size(); i++){
            //cout<<i<<" - "<<endl;
            for(auto p : pieces){
                if(arr[i] == p[0] and i+p.size() <= arr.size()){ 
                    bool temp = true;
                    for(int y=0; y<p.size();y++){
                        if(arr[i+y] != p[y]){
                            temp=false;
                            break;
                        }
                        
                    }
                    if(temp){
                        i+=p.size()-1;
                        count += p.size();
                    }
                }
                if(i >= arr.size()){
                    break;
                }
            }
            //cout<<count<<endl;
        }
        // cout<<count<<endl;
        return (count == arr.size());
    }
};