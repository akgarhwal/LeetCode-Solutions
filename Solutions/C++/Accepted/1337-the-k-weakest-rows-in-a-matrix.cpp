/*
Problem Title: 1337 - The K Weakest Rows in a Matrix
Lang: C++
Runtime: 11 ms
Memory: 10.7 MB
Problem Url: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
Submission Url: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/submissions/890997225
*/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> st;
        int R = mat.size(), C = mat[0].size();

        for( int i = 0; i < R; i++ ) {
            int count = 0, lo = 0, hi = C-1, index = -1;
            // for( int j = 0; j < C; j++) {
            //     if(mat[i][j] == 1) {
            //         count++;
            //     } else {
            //         break;
            //     }
            // }
            while(lo <= hi){
                int mid = lo + ((hi - lo)>>1);
                if(mat[i][mid] == 1){
                    index = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            count = index == -1 ? 0 : index + 1;
            st.insert({count, i});
        }
        vector<int> ans;
        while(k--){
            ans.push_back( (*(st.begin())).second );
            st.erase(st.begin());
        }

        return ans;
    }
};