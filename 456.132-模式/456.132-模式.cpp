/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 *
 * https://leetcode.cn/problems/132-pattern/description/
 *
 * algorithms
 * Medium (36.41%)
 * Likes:    719
 * Dislikes: 0
 * Total Accepted:    72.6K
 * Total Submissions: 199.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k]
 * 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。
 * 
 * 如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：false
 * 解释：序列中不存在 132 模式的子序列。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,1,4,2]
 * 输出：true
 * 解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [-1,3,2,0]
 * 输出：true
 * 解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * -10^9 
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 类似波峰波谷 只需要找到端点即可
        // 或者用两个栈 最大值 栈和最小值栈
        // 首先用一个循环找到 最小值和 最小值之后的最大值
        // 或者分三段？ 第一段 是最小值栈 第二段是最大值栈(需要根据位置修改) 第三段遍历

        // 单调栈
        // 单调空间
    }
};
// @lc code=end

