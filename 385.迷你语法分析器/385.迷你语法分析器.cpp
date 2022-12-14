/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 *
 * https://leetcode.cn/problems/mini-parser/description/
 *
 * algorithms
 * Medium (54.87%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    30.5K
 * Total Submissions: 55.5K
 * Testcase Example:  '"324"'
 *
 * 给定一个字符串 s 表示一个整数嵌套列表，实现一个解析它的语法分析器并返回解析的结果 NestedInteger 。
 * 
 * 列表中的每个元素只可能是整数或整数嵌套列表
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "324",
 * 输出：324
 * 解释：你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "[123,[456,[789]]]",
 * 输出：[123,[456,[789]]]
 * 解释：返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
 * 1. 一个 integer 包含值 123
 * 2. 一个包含两个元素的嵌套列表：
 * ⁠   i.  一个 integer 包含值 456
 * ⁠   ii. 一个包含一个元素的嵌套列表
 * ⁠        a. 一个 integer 包含值 789
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s 由数字、方括号 "[]"、负号 '-' 、逗号 ','组成
 * 用例保证 s 是可解析的 NestedInteger
 * 输入中的所有值的范围是 [-10^6, 10^6]
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int getInteger(string &s, int &i) {
        int v = 0;
        bool sign = false;
        for(;;i++) {
            if(s[i] == '-') sign = true;
            else if(s[i] >= '0' && s[i] <= '9') v= v*10 + s[i] - '0';
            else {
                i--;
                break;
            }
        }
        return sign ? -v : v;
    }

    NestedInteger dfs(string &s, int &i) {
        if(s[i] == '[') {
            NestedInteger list;
            i++;
            for(;i < s.size() && s[i] != ']';i++) {
                if(s[i] == '[') {
                    list.add(dfs(s, i));
                } else if(s[i] == ',') {

                } else {
                    list.add(getInteger(s, i));
                }
            }
            // i++;
            return list;
        } else {
            return NestedInteger(getInteger(s, i));
        }
    }

    NestedInteger deserialize(string s) {
        int i = 0;
        return dfs(s, i);
    }
};
// @lc code=end

int main() {
    Solution s;
    s.deserialize("[123,[456,[789]]]");
}
