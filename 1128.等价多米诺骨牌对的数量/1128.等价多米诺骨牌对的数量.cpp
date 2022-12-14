/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 *
 * https://leetcode.cn/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (54.18%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    42K
 * Total Submissions: 77.5K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * 给你一个由一些多米诺骨牌组成的列表 dominoes。
 * 
 * 如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。
 * 
 * 形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且
 * b==c。
 * 
 * 在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对
 * (i, j) 的数量。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // 虽然不知道为什么在 Stack Tag 下  但是用 map 实现更加简单
        // 因为最大只是 99 手写数组可能更快？

        // map version
        // map<int, int> resultMap;
        // for(vector<int> sc : dominoes) {
        //     int index = 0;
        //     if(sc[0] > sc[1]) index = sc[0] * 10 + sc[1];
        //     else index = sc[1] * 10 + sc[0];

        //     resultMap[index] ++;
        // }

        // array version
        int resultMap[100] = {0};
        for(vector<int> sc : dominoes) {
            int index = 0;
            if(sc[0] > sc[1]) index = sc[0] * 10 + sc[1];
            else index = sc[1] * 10 + sc[0];

            resultMap[index] ++;
        }



        // 计算结果
        uint64_t ans = 0;
        for(int i = 11;i <= 99; i++) {
            // 由于从小到大排列  / 2
            // 组合数量 = A(2, n) / 2 = A(n - 2, n) / 2
            int n = resultMap[i];
            if(n <= 1) continue;
            ans += n * (n - 1) / 2;
        }
        return ans;
    }
};
// @lc code=end

