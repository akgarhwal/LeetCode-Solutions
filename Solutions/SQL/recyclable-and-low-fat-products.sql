/* Question: Recyclable and Low Fat Products
 * Lang: mssql
 * Runtime: 857 ms
 * Memory: 0B
 * Question Url: https://leetcode.com/problems/recyclable-and-low-fat-products
 * Submission Url:
 * https://leetcode.com/problems/recyclable-and-low-fat-products/submissions/848656537
 */

SELECT product_id FROM Products WHERE low_fats = 'Y' AND recyclable = 'Y';
