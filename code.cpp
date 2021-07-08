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
class Solution {
public:
    int ans;
    Solution()
    {
        ans=0;
    }
    int check(TreeNode *root)
    {
        if(root==NULL)return 0;
        int left=check(root->left);
        int right=check(root->right);
        ans+=abs(left)+abs(right);
        return root->val-1+left+right;// return extra coin or required coin 
                                      // if extra then extra coin tranfer one by
                                       //one which his move will count
                                        // if coin required then giving the coin to required node 
										//will step count
    }
    int distributeCoins(TreeNode* root) {
        check(root);
        return ans;
    }
};
