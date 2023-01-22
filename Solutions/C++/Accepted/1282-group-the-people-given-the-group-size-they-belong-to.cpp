/*
Problem Title: 1282 - Group the People Given the Group Size They Belong To
Lang: C++
Runtime: 12 ms
Memory: 13.4 MB
Problem Url: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to
Submission Url: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/submissions/882118923
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < groupSizes.size(); i++) {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;

        for(auto pair : mp) {

            int gs = pair.first;
            vector<int> arr = pair.second;
            vector<int> temp;

            for(int i = 0; i < arr.size(); i++) {
                if(i > 0  and (i%gs) == 0){
                    ans.push_back(temp);
                    temp.resize(0);
                }
                temp.push_back(arr[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};