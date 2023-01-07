/*
Problem Title: 1452 - People Whose List of Favorite Companies Is Not a Subset of Another List
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list
Submission Url: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/submissions/340502533
*/

class Solution {
public:
    
    bool MATCH(string s, string S){
        cout<<s<<" == "<<S<<endl;
        vector<int> arr(10, 0);
        for(char ch:S){
            arr[ch-'0']++;
        }
        for(char ch: s){
            if(arr[ch-'0'] == 0){
                return false;
            }
        }
        return true;
    }
    
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> mp;
        int co = 1;
        vector<string> comList;
        for(auto list : favoriteCompanies){
            string co_li = "";
            for(string str : list){
                if(mp.find(str) == mp.end()){
                    co_li += to_string(co);
                    mp[str] = co++;
                }
                else{
                    co_li += to_string(mp[str]);
                }
            }
            sort(co_li.begin(), co_li.end());
            comList.push_back(co_li);
        }
        vector<int> ans;
        for(int i =0;i<comList.size();i++){
            
            string temp = comList[i];
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