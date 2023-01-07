/*
Problem Title: 1833 - Maximum Ice Cream Bars
Lang: Go
Runtime: 972 ms
Memory: 8.6 MB
Problem Url: https://leetcode.com/problems/maximum-ice-cream-bars
Submission Url: https://leetcode.com/problems/maximum-ice-cream-bars/submissions/872289581
*/

func maxIceCream(costs []int, coins int) int {
    sort.Sort(sort.IntSlice(costs))

    var answer int = 0
    for _, cost := range costs {
        fmt.Println(cost)
        if cost <= coins {
            answer += 1
            coins -= cost
        }
    }

    return answer;
}