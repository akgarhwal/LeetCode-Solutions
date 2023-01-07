/*
Problem Title: 1912 - Design Movie Rental System
Lang: C++
Runtime: 976 ms
Memory: 324 MB
Problem Url: https://leetcode.com/problems/design-movie-rental-system
Submission Url: https://leetcode.com/problems/design-movie-rental-system/submissions/513790069
*/

class MovieRentingSystem {
public:
    struct cmp {
        int operator() (tuple<int,int,int> ff, tuple<int,int,int> ss) const {
            if(get<2>(ff) < get<2>(ss)){
                return 1;
            }
            if(get<0>(ff) < get<0>(ss)){
                return 1;
            }
             if(get<1>(ff) < get<1>(ss)){
                return 1;
            }
            return 0;
        }
    };
    unordered_map<long, int> mp;
    set<tuple<int,int,int>> rented;
    
    unordered_map<int, set<pair<int,int>>> store;
    
    int ZZ = 1000000;
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        
        for(auto ele : entries){
            store[ele[1]].insert({ele[2], ele[0]});
            long ke = ele[0] * 1LL * ZZ + ele[1];
            mp[ke] = ele[2];
        }
    }
    
    vector<int> search(int movie) {
        
        
        vector<int> ans;
        vector<pair<int,int>> bkp;
        int i =0 ;
        while( i < 5 and !store[movie].empty()){
            auto ele = *store[movie].begin();
            store[movie].erase(store[movie].begin());
            ans.push_back(ele.second);
            bkp.push_back(ele);
            i++;
        }
        for(auto ele : bkp){
            store[movie].insert(ele);
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = mp[shop * 1LL * ZZ + movie];
        auto it = store[movie].find({price, shop});
        store[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = mp[shop *1LL * ZZ + movie];
        store[movie].insert({price, shop});
        
        auto it = rented.find({price, shop, movie});
        rented.erase(it);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        vector<tuple<int,int,int>> bkp;
        int i =0 ; 
        while( i < 5 and !rented.empty()){
            vector<int> temp;
            auto ele = *rented.begin();
            rented.erase(rented.begin());
            temp.push_back(get<1>(ele));
            temp.push_back(get<2>(ele));
            bkp.push_back(ele);
            i++;
            ans.push_back(temp);
        }
        for(auto ele : bkp){
            rented.insert(ele);
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */