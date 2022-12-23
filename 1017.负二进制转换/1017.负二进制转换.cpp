/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 *
 * https://leetcode.cn/problems/convert-to-base-2/description/
 *
 * algorithms
 * Medium (56.95%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 8.6K
 * Testcase Example:  '2'
 *
 * 给你一个整数 n ，以二进制字符串的形式返回该整数的 负二进制（base -2）表示。
 * 
 * 注意，除非字符串就是 "0"，否则返回的字符串中不能含有前导零。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出："110"
 * 解释：(-2)^2 + (-2)^1 = 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3
 * 输出："111"
 * 解释：(-2)^2 + (-2)^1 + (-2)^0 = 3
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 4
 * 输出："100"
 * 解释：(-2)^2 = 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 10^9
 * 
 * 
 */
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    string baseNeg2(int n) {
        // 处理 0
        if(n==0) return "0";

        int64_t mins[32], maxs[32], vals[32];

        mins[0] = 0;
        maxs[0] = 1;
        vals[0] = 1;

        // 构建列表
        for(int i = 1;i < 32;i++) {
            vals[i] = vals[i-1] * -2;
            if(vals[i] > 0) {
                maxs[i] = maxs[i-1] + vals[i];
                mins[i] = mins[i-1];
            } else {
                mins[i] = mins[i-1] + vals[i];
                maxs[i] = maxs[i-1];
            }
        }

        string ans = "";

        // 判断结果
        for(int i = 31; i > 0; i--) {
            // cout << n << endl;
            if(n == 0) {
                ans += "0";
                continue;
            }
            if(n > 0) {
                if(n <= maxs[i] && n > maxs[i-1]) {
                    ans += "1";
                    n -= vals[i];
                }
                else ans += '0';
            } else {
                if(n >= mins[i] && n < mins[i-1]) {
                    ans += "1";
                    n -= vals[i];
                }
                else ans += '0';
            }
        }

        if(n == 0) ans += '0';
        else ans += '1';

        int i;
        
        for(i = 0;i < 32 && ans[i] == '0';i++);

        return ans.substr(i);
    }
};
// @lc code=end

