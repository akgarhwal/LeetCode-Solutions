/*
Problem Title: 729 - My Calendar I
Lang: C++
Runtime: 140 ms
Memory: 37.6 MB
Problem Url: https://leetcode.com/problems/my-calendar-i
Submission Url: https://leetcode.com/problems/my-calendar-i/submissions/505873333
*/

class MyCalendar {
public:
    vector<pair<int,int>> events;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        bool res = true;
        end = max(end-1, start);
        
        for(pair<int,int> event : events){
            if(event.first <= start and start <= event.second){
                res = false;
                break;
            }
            if(event.first <= end and end <= event.second){
                res = false;
                break;
            }
            if(event.first >= start and end >= event.second){
                res = false;
                break;
            }
        }
        if(res){
            events.push_back({start, end});
        }
        return res;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */