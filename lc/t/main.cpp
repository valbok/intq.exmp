Given a binary tree, find its maximum depth.

int maxDepth(Node * root)
{
  // Root being null means tree doesn't exist.
  if (root == NULL)
    return 0;

  // Get the depth of the left and right subtree
  // using recursion.
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);

  // Choose the larger one and add the root to it.
  if (leftDepth > rightDepth)
    return leftDepth + 1;
  else
    return rightDepth + 1;
}
***
Given a binary tree, determine if it is a valid binary search tree (BST).

 bool rec(TreeNode* root, long &min, long &max) {
        if (!root)return true;
        if (root->val < min)
            min = root->val;
        if (root->val > max)
            max = root->val;

        long mmin = LONG_MAX, mmax = LONG_MIN;
        if (!rec(root->left, mmin, mmax)) return false;
        if (root->val <= mmax) return false;
        if (mmin < min) min = mmin;
        if (mmax > max) max = mmax;

        mmin = LONG_MAX;
        if (!rec(root->right,mmin, mmax)) return false;
        if (root->val >= mmin) return false;
        if (mmin < min) min = mmin;
        if (mmax > max) max = mmax;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        long min = LONG_MAX, max = LONG_MIN;
        return rec(root, min, max);
    }

***
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*>s;
        s.push(root->left);
        s.push(root->right);
        while (s.size()) {
            auto right = s.top();s.pop();
            auto left = s.top();s.pop();
            if (!left && right) return false;
            if (left && !right) return false;
            if (!left && !right) continue;
            if (left->val != right->val) return false;

            s.push(left->left);
            s.push(right->right);
            s.push(left->right);
            s.push(right->left);
        }

        return true;

    }
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
