/*
Problem Title: 85 - Maximal Rectangle
Lang: C++
Runtime: 32 ms
Memory: 13.2 MB
Problem Url: https://leetcode.com/problems/maximal-rectangle
Submission Url: https://leetcode.com/problems/maximal-rectangle/submissions/594732305
*/

class Solution {
public:
    
    int findMaxRectArea(vector<int> arr){
        int ans = 0, ind = 0;
        stack<int> st;
        while(ind < arr.size()){
            while(!st.empty() and arr[st.top()] >= arr[ind]){
                int top = st.top();
                st.pop();
                ans = max(ans, ( st.empty() ? ind : ind-st.top()-1 ) * arr[top]);
            }
            st.push(ind++);
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            ans = max(ans, ( st.empty() ? ind : ind-st.top()-1 ) * arr[top]);
        }
        return ans;        
    }
    
    
    int maximalRectangle(vector<vector<char>>& arr) {
        
        if(arr.size() == 0){
            return 0;
        }
        
        vector<vector<int>> matrix(arr.size(), vector<int>(arr[0].size()));
        
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[0].size(); j++){
                
                matrix[i][j] = arr[i][j] == '0' ? 0 : 1;
            }
        }
        
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < matrix.size();i++){
            ans = max(ans, findMaxRectArea(matrix[i]));
        }        
        
        
        return ans;
    }
};