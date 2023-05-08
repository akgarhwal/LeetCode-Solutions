/*
Problem Title: 2665 - Counter II
Lang: JavaScript
Runtime: 68 ms
Memory: 44.7 MB
Problem Url: https://leetcode.com/problems/counter-ii
Submission Url: https://leetcode.com/problems/counter-ii/submissions/945806382
*/

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var n = init, increment;

    return {
        increment: function() {
            return ++n;
        },
        decrement: function() {
            return --n;
        },
        reset: function() {
            return n = init;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */