/*
Problem Title: 352 - Data Stream as Disjoint Intervals
Lang: C++
Runtime: 129 ms
Memory: 33.5 MB
Problem Url: https://leetcode.com/problems/data-stream-as-disjoint-intervals
Submission Url: https://leetcode.com/problems/data-stream-as-disjoint-intervals/submissions/886563956
*/

class SummaryRanges {
    set<int> st;
public:
    SummaryRanges() {
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if(st.empty()) {
            return ans;
        }

        int start = -1, end = -1;
        for(int num : st) {
            if(start < 0){
                start = end = num;
            } else if(num == end +1) {
                end = num;
            } else {
                ans.push_back({start, end});
                start = end = num;
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */