/*
Problem Title: 2629 - Function Composition
Lang: JavaScript
Runtime: 64 ms
Memory: 43.4 MB
Problem Url: https://leetcode.com/problems/function-composition
Submission Url: https://leetcode.com/problems/function-composition/submissions/948146098
*/

/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        if (functions.length === 0) {
            return x;
        }

        let input = x;

        for (let i = functions.length - 1; i >= 0; i--) {
            const currFunc = functions[i];
            input = currFunc(input);
        }

        return input;
    };
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */