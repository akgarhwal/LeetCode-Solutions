/*
Problem Title: 649 - Dota2 Senate
Lang: C++
Runtime: 680 ms
Memory: 6.8 MB
Problem Url: https://leetcode.com/problems/dota2-senate
Submission Url: https://leetcode.com/problems/dota2-senate/submissions/944113506
*/

class Solution {
public:
    string predictPartyVictory(string senate) {

        int rCount = count(senate.begin(), senate.end(), 'R');
        int dCount = senate.size() - rCount;

        vector<bool> banned(senate.size(), false);

        auto ban = [&](char toBan, int startAt) {
            while (true) {
            if (senate[startAt] == toBan && !banned[startAt]) {
                banned[startAt] = true;
                break;
            }
            startAt = (startAt + 1) % senate.size();
            }
        };

        int turn = 0;

        while (rCount > 0 && dCount > 0) {

            if (!banned[turn]) {
            if (senate[turn] == 'R') {
                ban('D', (turn + 1) % senate.size());
                dCount--;
            } else {
                ban('R', (turn + 1) % senate.size());
                rCount--;
            }
            }

            turn = (turn + 1) % senate.size();
        }

        return dCount == 0 ? "Radiant" : "Dire";
    }
};