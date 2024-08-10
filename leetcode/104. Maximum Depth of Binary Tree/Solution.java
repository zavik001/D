// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);

        return Math.max(leftDepth, rightDepth) + 1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test 1: Empty tree
        TreeNode root1 = null;
        System.out.println("Test 1: " + (solution.maxDepth(root1) == 0 ? "Passed" : "Failed"));

        // Test 2: Tree with one node
        TreeNode root2 = new TreeNode(1);
        System.out.println("Test 2: " + (solution.maxDepth(root2) == 1 ? "Passed" : "Failed"));

        // Test 3: Tree with two levels
        TreeNode root3 = new TreeNode(1);
        root3.left = new TreeNode(2);
        root3.right = new TreeNode(3);
        System.out.println("Test 3: " + (solution.maxDepth(root3) == 2 ? "Passed" : "Failed"));

        // Test 4: Tree with three levels
        TreeNode root4 = new TreeNode(1);
        root4.left = new TreeNode(2);
        root4.right = new TreeNode(3);
        root4.left.left = new TreeNode(4);
        root4.left.right = new TreeNode(5);
        System.out.println("Test 4: " + (solution.maxDepth(root4) == 3 ? "Passed" : "Failed"));

        // Test 5: Unbalanced tree
        TreeNode root5 = new TreeNode(1);
        root5.left = new TreeNode(2);
        root5.left.left = new TreeNode(3);
        System.out.println("Test 5: " + (solution.maxDepth(root5) == 3 ? "Passed" : "Failed"));
    }
}
