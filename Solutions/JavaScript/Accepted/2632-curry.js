/*
Problem Title: 2632 - Curry
Lang: JavaScript
Runtime: 84 ms
Memory: 48.6 MB
Problem Url: https://leetcode.com/problems/curry
Submission Url: https://leetcode.com/problems/curry/submissions/949896877
*/

/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    return function curried(...args) {
        if(args.length >= fn.length) {
            return fn(...args);
        }

        return (...nextArgs) => curried(...args, ...nextArgs);
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */