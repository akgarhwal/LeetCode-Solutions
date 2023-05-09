/*
Problem Title: 2635 - Apply Transform Over Each Element in Array
Lang: JavaScript
Runtime: 57 ms
Memory: 41.8 MB
Problem Url: https://leetcode.com/problems/apply-transform-over-each-element-in-array
Submission Url: https://leetcode.com/problems/apply-transform-over-each-element-in-array/submissions/946592111
*/

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    return  arr.map(fn);
};