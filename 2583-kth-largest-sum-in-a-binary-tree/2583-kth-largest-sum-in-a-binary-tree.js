/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthLargestLevelSum = function(root, k) {
    function dfs (node, level = 0, levels = []) {
        if (!node) return;

        if (levels[level]) {
            levels[level] += node.val;
        } else {
            levels[level] = node.val;
        }

        dfs (node.left, level + 1, levels);
        dfs (node.right, level + 1, levels);

        return levels;
    }

    const levels = dfs (root);

    if (levels.length < k) return -1;

    return levels.sort((a, b) => b - a)[k - 1];
};