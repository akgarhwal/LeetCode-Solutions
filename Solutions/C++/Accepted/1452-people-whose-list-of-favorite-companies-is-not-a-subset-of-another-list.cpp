/*
Problem Title: 1452 - People Whose List of Favorite Companies Is Not a Subset of Another List
Lang: C++
Runtime: 1012 ms
Memory: 385.6 MB
Problem Url: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list
Submission Url: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/submissions/340508819
*/

class Solution {
public:
    
    bool MATCH(vector<int> s, vector<int> S){
        vector<int> arr(10000, 0);
        for(int ch:S){
            arr[ch]++;
        }
        for(int ch: s){
            if(arr[ch] == 0){
                return false;
            }
            arr[ch]--;
        }
        return true;
    }
    
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> mp;
        int co = 1;
        vector<vector<int>> comList;
        for(auto list : favoriteCompanies){
            vector<int> co_li;
            for(string str : list){
                if(mp.find(str) == mp.end()){
                    co_li.push_back(co);
                    //cout<<str<<" --> "<<co<<endl;
                    mp[str] = co++;
                    //cout<<str<<" --> "<<mp[str]<<endl;
                }
                else{
                    co_li.push_back(mp[str]);
                }
            }
            comList.push_back(co_li);
        }
        vector<int> ans;
        for(int i =0;i<comList.size();i++){
            vector<int> temp = comList[i];
            
            
            
            bool found = false;
            for(int j = 0; j< comList.size(); j++){
                if(i != j and temp.size() < comList[j].size() and MATCH(temp, comList[j]) == true){
                    found = true;
                    break;
                }
            }
            if(!found){
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};