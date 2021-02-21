/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    public String tree2str(TreeNode t) {

        StringBuilder ans = new StringBuilder();

        dfs(ans, t);

        return ans.toString();

    }



    private void dfs(StringBuilder ans, TreeNode t) {

        if (t == null) {

            return;

        }

        ans.append(t.val);

        if (t.right != null) {

            // if the right child isn't empty, we still need to append '()' although the left child is empty

            dfs(ans.append('('), t.left);

            ans.append(')');

            dfs(ans.append('('), t.right);

            ans.append(')');

        } else if (t.left != null) {

            dfs(ans.append('('), t.left);

            ans.append(')');

        }

    }

}