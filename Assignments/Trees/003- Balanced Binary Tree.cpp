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
 
 // Balanced Height mtlab - left binary tree aur right binary
 // tree ka absolute difference 1 se chota hona chaiye
 // 3 conditions
 //1.Height of Left Subtree - Height of right Subtree <=1
 //2. left subtreee balance
 //3. right subtree balance
 
 
class Solution {
public:

    int height(TreeNode* root){
       //base case
        if(root==NULL){
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int finalAns = max(leftHeight , rightHeight) + 1;
        return finalAns;
    }

    bool isBalanced(TreeNode* root) {
        //base case
        if(root==NULL){
            return true;
        }

        //currNode - Solve
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int difference = abs(leftHeight - rightHeight);

        bool currNodeAns = (difference <=1);

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if(currNodeAns && leftAns && rightAns){
            return true;
        }
        else{
            return false;
        }
        
    }
};