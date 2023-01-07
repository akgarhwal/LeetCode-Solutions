/*
Problem Title: 1757 - Recyclable and Low Fat Products
Lang: MS SQL Server
Runtime: 857 ms
Memory: 0B
Problem Url: https://leetcode.com/problems/recyclable-and-low-fat-products
Submission Url: https://leetcode.com/problems/recyclable-and-low-fat-products/submissions/848656537
*/

SELECT product_id FROM Products WHERE low_fats = 'Y' AND recyclable = 'Y';