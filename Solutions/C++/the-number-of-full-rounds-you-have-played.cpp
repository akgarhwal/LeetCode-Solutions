/* Question: The Number of Full Rounds You Have Played
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 6 MB
 * Question Url:
 * https://leetcode.com/problems/the-number-of-full-rounds-you-have-played
 * Submission Url:
 * https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/submissions/510402308
 */

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int sh = int(startTime[0]-'0') * 10 + int(startTime[1]-'0');
        int sm = int(startTime[3]-'0') * 10 + int(startTime[4]-'0');
        int fh = int(finishTime[0]-'0') * 10 + int(finishTime[1]-'0');
        int fm = int(finishTime[3]-'0') * 10 + int(finishTime[4]-'0');
        int sms = 0, fms = 0;
        if(fh < sh or (fh == sh and fm <sm)){
            sms = sh * 60;
            fms = fh*60 + 24*60;
        }
        else{
            sms = sh * 60;
            fms = fh * 60;
        }
        
        sms += sm;
        fms += fm;
        int start = 0;
        int ans = 0;
        while(start <= fms){
            if(start>=sms and (start+15) <= fms){
                ans++;
            }
            start += 15;
        }
        return ans;
    }
};
