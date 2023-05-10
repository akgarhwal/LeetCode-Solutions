/*
Problem Title: 2634 - Filter Elements from Array
Lang: JavaScript
Runtime: 55 ms
Memory: 42.3 MB
Problem Url: https://leetcode.com/problems/filter-elements-from-array
Submission Url: https://leetcode.com/problems/filter-elements-from-array/submissions/946958967
*/

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    return arr.filter(fn);
};