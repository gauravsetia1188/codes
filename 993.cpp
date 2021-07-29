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
    
    // bfs/ level order, if same level bnoth yes 
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            int count = 0;
            for(int i=0;i<n;i++) {
                TreeNode* tmp = q.front(); q.pop();
                TreeNode* left = tmp->left;
                TreeNode* right = tmp->right;
                
                if(left!=NULL and right!=NULL) {
                    if((left->val == x && right->val == y) or (right->val == x && left->val == y)) {
                        return false;
                    }
                        
                }
                
                if(left!=NULL) {
                    q.push(left);
                    if(left->val == x || left->val == y)
                        count++;
                }
                
                if(right!=NULL) {
                    q.push(right);
                    if(right->val == x || right->val == y)
                        count++;
                }
                    
            }
            if(count==2)
                return true;
            
        }
        return false;
    }
    
};
