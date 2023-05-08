/*
Problem Title: 2667 - Create Hello World Function
Lang: JavaScript
Runtime: 57 ms
Memory: 41.7 MB
Problem Url: https://leetcode.com/problems/create-hello-world-function
Submission Url: https://leetcode.com/problems/create-hello-world-function/submissions/944654047
*/

/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */