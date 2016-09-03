/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        string res = "[";
        map<TreeNode*, TreeNode*> mp;
        if(!root) return res;
        TreeNode* p = root;
        TreeNode* first = NULL;
        TreeNode* last = NULL; 
        while(p) {
            int x = p->val;
            string t;
            while(x) {
                t += ('0' + x % 10);
                x /= 10;
            }
            reverse(t.begin(), t.end());
            res += t; res += ",";
            if(!first) {
                if(p->left) first = p->left;
                if(p->right) first = p->right;
            }
            if(p->left) {
                if(last) {
                    mp[last] = p->left;
                }
                last = p->left;
            }
            if(p->right) {
                if(last) {
                    mp[last] = p->right;
                }
                last = p->right;
            } 
            if(mp[p]) {
                p = mp[p];
            }
            else {
                p = first;
                last = first = NULL;
            }
        }
        res[res.length() - 1] = ']';
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL, curr = NULL;
        queue <TreeNode*> q;
        string x;
        int count = 0;
        for(int i = 1; i < data.size(); ++i) {
            if(data[i] == ',' || data[i] == ']') {
                if(x == "null") {
                    count += 1;
                    if(count == 2) {
                        q.pop();
                        count = 0;
                    }
                    continue;
                }
                int d = 1, value = 0;
                for(int i = x.length() - 1; i >= 0; --i) {
                    value += d * (x[i] - '0');
                    d *= 10;
                }
                x = "";
                if(root == NULL) {
                    root = new TreeNode(value);
                    q.push(root);
                }
                else {
                    TreeNode* cu = q.front();
                    if(count == 0) {
                        cu->left = new TreeNode(value); 
                        q.push(cu->left);
                    }
                    else {
                        cu->right = new TreeNode(value);
                        q.push(cu->right);
                    }
                    count += 1;
                    if(count == 2) {
                        q.pop();
                        count = 0;
                    }
                }
            }
            else {
                x += data[i];
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));