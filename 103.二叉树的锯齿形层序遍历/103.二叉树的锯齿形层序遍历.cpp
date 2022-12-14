/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.42%)
 * Likes:    721
 * Dislikes: 0
 * Total Accepted:    280.1K
 * Total Submissions: 487.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[20,9],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define swap(a, b) a=a^b; b=a^b;a=a^b
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(TreeNode* node, int depth) {
        if(node == nullptr) return;
        if(ans.size() <= depth) {
            vector<int> vec;
            ans.push_back(vec);
        }

        ans[depth].push_back(node->val);

        // 遍历 左右节点
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);

        // 进行翻转 其实还有其他的解法 
        for(int i = 1; i < ans.size(); i+=2) 
            std::reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};
// @lc code=end

