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
    void Binarytreee(TreeNode*root, int n, vector<int> &res){
        if(root == NULL) return;
        if( n == res.size()) res.push_back(root->val);
        Binarytreee(root->right,n+1,res);
        Binarytreee(root->left,n+1,res);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
     
        Binarytreee(root,0,res);
        return res;
        
    }
};