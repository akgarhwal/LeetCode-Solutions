/*
Problem Title: 2623 - Memoize
Lang: JavaScript
Runtime: 340 ms
Memory: 107.1 MB
Problem Url: https://leetcode.com/problems/memoize
Submission Url: https://leetcode.com/problems/memoize/submissions/949322012
*/

/**
 * @param {Function} fn
 */
function memoize(fn) {
    const cache = {};
    
    return function(...args) {
        const key = JSON.stringify(args);

        if (key in cache) {
            return cache[key];
        }

        const functionOutput = fn(...args);
        cache[key] = functionOutput;
        
        return functionOutput;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */