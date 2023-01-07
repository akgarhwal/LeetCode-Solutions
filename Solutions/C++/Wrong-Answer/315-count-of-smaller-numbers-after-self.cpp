/*
Problem Title: 315 - Count of Smaller Numbers After Self
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/count-of-smaller-numbers-after-self
Submission Url: https://leetcode.com/problems/count-of-smaller-numbers-after-self/submissions/484512099
*/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> index(nums.size(), 0);
        for(int i = 0; i < nums.size();i++){
            index[i] = i;
        }
        
        vector<int> ans(nums.size(), 0);
        
        mergeSort(index, nums, ans, 0, nums.size()-1);
        
        return ans;
    }
    
    void mergeSort(vector<int> &index, vector<int> &nums, vector<int> &ans, int start, int end) {
        
        if(start == end) {
            return;
        }
        
        
        int mid = start + (end-start)/2;
        
        mergeSort(index, nums, ans, start, mid);
        
        mergeSort(index, nums, ans, mid+1, end);
        
        
        merge(index, nums, ans, start, mid, end);
        
    }
    
    
    void merge(vector<int> &index, vector<int> &nums, vector<int> &ans, int start, int mid, int end) {
        
        int l = start, r = mid+1;
        int inv_count = 0;
        
        vector<int> ind;
        
        while( l <= mid && r <= end) {
            
            if(nums[index[l]] > nums[index[r]]) {
                inv_count++;
                ind.push_back(index[r]);
                r++;
            }
            else{
                ans[index[l]] += inv_count;
                ind.push_back(index[l]);
                l++;
            }
        }
        
        while( l <= mid) {
            ans[index[l]] += inv_count;
            ind.push_back(l++); 
        }
        
        while(r <= end) {
            ind.push_back(r++); 
        }
        
        for(int k=0,i=start;i<=end;i++){
            index[i] = ind[k++];
        }
        
        
    }
};