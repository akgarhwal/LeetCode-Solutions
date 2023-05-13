/*
Problem Title: 2666 - Allow One Function Call
Lang: JavaScript
Runtime: 59 ms
Memory: 41.8 MB
Problem Url: https://leetcode.com/problems/allow-one-function-call
Submission Url: https://leetcode.com/problems/allow-one-function-call/submissions/948759558
*/

/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let hasBeenCalled = false;

    return function(...args){
        if (hasBeenCalled) {
            return undefined;
        }

        hasBeenCalled = true;
        return fn(...args);
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */