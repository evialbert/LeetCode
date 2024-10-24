/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var flipEquiv = function(root1, root2) {
    const flipToEquivalentTree = (node1, node2) => {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;
        if (node1.val !== node2.val) return false;

        const { left, right } = node1;

        if (left?.val !== node2.left?.val) {
            node1.right = left;
            node1.left = right;
        }
        const isLeftEquivalent = flipToEquivalentTree(node1.left, node2.left);
        const isRightEquivalent = flipToEquivalentTree(node1.right, node2.right);

        return isLeftEquivalent && isRightEquivalent;
    };

    return flipToEquivalentTree(root1, root2);
};