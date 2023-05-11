/*
Problem Title: 2626 - Array Reduce Transformation
Lang: JavaScript
Runtime: 65 ms
Memory: 44.7 MB
Problem Url: https://leetcode.com/problems/array-reduce-transformation
Submission Url: https://leetcode.com/problems/array-reduce-transformation/submissions/947554534
*/

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let accumulator = init;

    for (const element of nums) {
        accumulator = fn(accumulator, element);
    }
    
    return accumulator;
};