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
//     bool isSymmetric(TreeNode* root) {
//         if(root==NULL) return false;
        
//         TreeNode *L,*R;
//         queue<TreeNode*>q1;
//         queue<TreeNode*>q2;
//         q1.push(root->left);
//         q2.push(root->right);
//         while(!q1.empty() || !q2.empty()){
//             L = q1.front();
//             q1.pop();
//             R = q2.front();
//             q2.pop();
//             if(L && R ){
//                 continue;
//             }
//             if(L || R){
//                 false;
//             }
//             if(L->val!=R->val){
//                 false;
//             }
//             q1.push(L->left);
//             q1.push(R->right);
//             q2.push(L->left);
//             q2.push(R->right);
//         }
//         return true;
//    }
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        return helper(p->left,q->right) && helper(p->right, q->left); 
    }
};