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
    void inorder(vector<int> &v,TreeNode * root){
        if(root==NULL){
            return ;
        }
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
        return ;
    }
     set<int> s;
   bool method2(TreeNode * root,int k){
       if(root==NULL){
           return false;
       }
       if(s.find(k-root->val)!=s.end()){
           return true;
       }
       s.insert(root->val);
      if( method2(root->left,k)){
          return true;
      }
      if( method2(root->right,k)){
          return true;
      }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        
        return method2(root,k);
        vector<int> v;
        inorder(v,root);
        int i=0;
        int j=v.size()-1;
        while(i<j){
            if(v[i]+v[j]<k){
                i++;
            }
            else if(v[i]+v[j]>k){
                j--;
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};