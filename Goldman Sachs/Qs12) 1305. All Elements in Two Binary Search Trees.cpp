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
    void inOrderTraversal(TreeNode* tree,vector<int> &vec)
    {
        if(tree)
        {
            inOrderTraversal(tree->left,vec);
            vec.push_back(tree->val);
            inOrderTraversal(tree->right,vec);
        }
    }
    void mergeVector(vector<int> &tree1,vector<int> &tree2,vector<int> &ans)
    {
        int i=0,j=0,k=0;

        while(i<tree1.size() && j<tree2.size())
        {
            if(tree1[i] < tree2[j])
            {
                ans[k]=tree1[i];
                k++;
                i++;
            }
            else
            {
                ans[k]=tree2[j];
                k++;
                j++;
            }
        }
        while(i<tree1.size())
        {
            ans[k]=tree1[i];
            k++;
            i++;
        }
        while(j<tree2.size())
        {
            ans[k]=tree2[j];
            k++;
            j++;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1,tree2;
        inOrderTraversal(root1,tree1);
        inOrderTraversal(root2,tree2);

        vector<int> ans(tree1.size()+tree2.size());
        mergeVector(tree1,tree2,ans);
        return ans; 
    }
};
