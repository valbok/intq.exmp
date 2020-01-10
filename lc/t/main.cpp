Given a binary tree, find its maximum depth.

***
Given a binary tree, determine if it is a valid binary search tree (BST).

***
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
***
Given a binary tree, return the level order traversal of its nodes values. (ie, from left to right, level by level).

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (!root) return r;        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        int n = 1, i = 0, inserted = 0;
        while (!q.empty()) {            
            auto node = q.front();q.pop();            
            v.push_back(node->val);
           
            if (node->left) {
                q.push(node->left); ++inserted;
            }
            if (node->right) {
                q.push(node->right); ++inserted;
            }          
            if (++i == n) {
                r.push_back(v);
                v.clear();
                n = inserted;
                inserted = 0;
                i = 0;
            }
        }
        return r;
    }
***
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int n = nums.size()/2;
        auto node = new TreeNode(nums[n]);
        vector<int> ll(nums.begin(),nums.begin()+n);        
        node->left = sortedArrayToBST(ll);

        vector<int> rr(nums.begin()+n+1,nums.end());        
        node->right = sortedArrayToBST(rr);

        return node;
    }
