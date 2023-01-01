/* Question: Number of Days Between Two Dates
 * Lang: javascript
 * Runtime: 48 ms
 * Memory: 33.7 MB
 * Question Url: https://leetcode.com/problems/number-of-days-between-two-dates
 * Submission Url:
 * https://leetcode.com/problems/number-of-days-between-two-dates/submissions/305933364
 */

/**
 * @param {string} date1
 * @param {string} date2
 * @return {number}
 */
var daysBetweenDates = function(date1, date2) {
    
    let d1 = new Date(date1);
    
    let d2 = new Date(date2);
    
    let res = d2.getTime() - d1.getTime();
    
    if(res < 0){
        res = -res;
    }
    
    return res /  (1000 * 3600 * 24);
    
};
