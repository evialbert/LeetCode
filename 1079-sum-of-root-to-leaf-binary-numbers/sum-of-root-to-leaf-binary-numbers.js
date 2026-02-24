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
 * @return {number}
 */
var sumRootToLeaf = function(root) {
    let res = 0;
    // DFS function
    var traverse = (curNode, value = root.val) => {
        // leaf node
        if(curNode.left === null && curNode.right === null){
            res += value;
            return;
        }
        // traverse left child
        if(curNode.left !== null){
            traverse(curNode.left, value * 2 + curNode.left.val);
        }
        // traverse right child
        if(curNode.right !== null){
            traverse(curNode.right, value * 2 + curNode.right.val);
        }
    };
    traverse(root);
    return res;
};