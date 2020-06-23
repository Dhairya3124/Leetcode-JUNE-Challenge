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
    int arr[100000];
    int x = 0;
    void solve(TreeNode* root)
    {
        if(root!=NULL)
        {
        arr[x++] = root->val;
        solve(root->left);
        solve(root->right);
    }
    }
    int countNodes(TreeNode* root) {
        x = 0;
        vector<int>ans;
        solve(root);
      //  for(int i = 0;i<x;i++)ans.push_back(arr[i]);
        
        return x;
        
    }
};
