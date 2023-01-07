/*
Problem Title: 307 - Range Sum Query - Mutable
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/range-sum-query-mutable
Submission Url: https://leetcode.com/problems/range-sum-query-mutable/submissions/509678440
*/

class NumArray {
    vector<int> tree;
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        tree.assign(nums.size()*4, 0);
        build(0,nums.size()-1, 1);
        // for(int x : tree){
        //     cout<<x<<" ";
        // }
    }
    
    int build(int s, int e, int node){
        if(s == e){
            return tree[node] = arr[s];
        }
        int m = s + (e-s)/2;
        int left = build(s,m,node*2);
        int right = build(m+1,e,node*2+1);
        return tree[node] = left+right;
    }
    
    void update(int index, int val) {
        update(index, val, 1, 0, arr.size()-1);
        // for(int x : tree){
        //     cout<<x<<" ";
        // }
    }
    
    int update(int ind, int val, int node, int st,int end){
        if(ind == st and st == end){
            return tree[node] = val;
        }
        if(st == end){
            return tree[node];
        }
        if(ind < st){
            return tree[node];
        }
        if(ind > end){
            return tree[node];
        }
        int mid = st + (end-st)/2;
        int left = update(ind, val, node*2, st,mid);
        int right = update(ind, val, node*2+1, mid+1, end);
        return tree[node] = left + right;
    }
    
    int sumRange(int left, int right) {
        return range(left,right,1,0,arr.size()-1);
    }
    
    int range(int l, int r, int node, int s, int e){
        if(s == l and e == r){
            return tree[node];
        }
        int m = s + (e-s)/2;
        int ans = 0;
        if( l < m or r <= m){
            ans += range(l,r,node*2,s,m);
        }
        if(l > m or r > m){
            ans += range(l,r,node*2+1,m+1,e);
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */