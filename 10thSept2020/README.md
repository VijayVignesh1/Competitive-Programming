# Questions
--------------------------
## Count Good Triplets (October LeetCode Challenge: Day 10)

Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets. <br>

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true: <br>

0 <= i < j < k < arr.length <br>
|arr[i] - arr[j]| <= a <br>
|arr[j] - arr[k]| <= b <br>
|arr[i] - arr[k]| <= c <br>
Where |x| denotes the absolute value of x.<br>

Return the number of good triplets.<br>

### Example 1
Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3 <br>
Output: 4 <br>
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)]. <br>

### Example 2
Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1 <br>
Output: 0 <br>
Explanation: No triplet satisfies all conditions. <br>

### Constraints
3 <= arr.length <= 100 <br>
0 <= arr[i] <= 1000 <br>
0 <= a, b, c <= 1000 <br>

-------------------------------
