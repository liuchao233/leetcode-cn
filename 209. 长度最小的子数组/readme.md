问题描述：

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

解题思路（滑动窗口）:

1. 定义 start 和 end 标识子数组的开始和结束位置，维护变量 sum 存储子数组的和。
2. 初始状态下，start 和 end 都指向下标 0，sum 的值为 0
3. 每一轮迭代，将 nums[end] 加到 sum, 如果 sum >= target, 循环减去 num[start]，并将 start 向后移动，直到 sum < target。每一轮迭代的最后，将 end 右移。