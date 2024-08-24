/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxLevelSum(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int mx = root.val;
        int level = 1;
        int temp = 0;
        while(q.size()!=0){
            int sz = q.size();
            temp++;
            int sum = 0;
            while(sz-->0){
                TreeNode front = q.remove();
                sum+= front.val;
                if(front.left!=null) q.add(front.left);
                if(front.right!=null) q.add(front.right);
                // sz--;
            }
            if(sum>mx){
                mx = Math.max(mx, sum);
                level = temp;
            }
        }
        return level;
    }
}