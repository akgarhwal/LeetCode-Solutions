/*
Problem Title: 2620 - Counter
Lang: JavaScript
Runtime: 59 ms
Memory: 42.1 MB
Problem Url: https://leetcode.com/problems/counter
Submission Url: https://leetcode.com/problems/counter/submissions/945247177
*/

/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {

    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */