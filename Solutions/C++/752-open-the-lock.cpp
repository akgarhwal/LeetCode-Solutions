/*
Problem Title: 752 - Open the Lock
Lang: C++
Runtime: 652 ms
Memory: 53.2 MB
Problem Url: https://leetcode.com/problems/open-the-lock
Submission Url: https://leetcode.com/problems/open-the-lock/submissions/502841834
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans = -1;
        
        set<string> deadSet(deadends.begin(), deadends.end());        
        if(deadSet.find("0000") != deadSet.end()){
            return ans;
        }
        
        set<string> vis;
        queue<pair<string, int>> q;
        
        q.push({"0000", 0});
        vis.insert("0000");
        
        while(!q.empty()){
            
            pair<string, int> ele = q.front(); q.pop();
            
            if(ele.first == target){
                return ele.second;
            }
            vector<string> paths = findAllPaths(ele.first, vis, deadSet);
            
            for(string path : paths){
                vis.insert(path);
                q.push({path, ele.second+1});
            }
        }
        return ans;
    }
    
    vector<string> findAllPaths(string root, set<string> &vis, set<string> &deadSet){
        vector<string> paths;
        for(int i = 0; i < 4; i++){
            int digit = int(root[i] - '0');
            digit = (digit+1)%10;
            string new_path = root;
            new_path[i] = char(digit + '0');
            if(vis.find(new_path) == vis.end() and deadSet.find(new_path) == deadSet.end()){
                paths.push_back(new_path);
            }
            digit = int(root[i] - '0');
            digit = (10 + digit-1) % 10;
            new_path = root;
            new_path[i] = char(digit + '0');
            if(vis.find(new_path) == vis.end() and deadSet.find(new_path) == deadSet.end()){
                paths.push_back(new_path);
            }
        }
        return paths;
    }
    
};