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
    string st(int value) {
        int c = 0;
        if(value < 0) c = 1, value *= -1;;
        string res; if(c == 1) res += '-';
        while(value) {
            res += (value % 10 + '0');
            value /= 10;
        }
        reverse(res.begin() + c, res.end());
        return res;
    }
    string serialize(TreeNode* root) {
        string res = "[";
        vector <string> ans;
        if(root == NULL) return "[]";
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* t = q.front();
            string x; 
            if(t == NULL) x = "null", q.pop();
            else {
                x = st(t->val);
                q.push(t->left), q.push(t->right);
                q.pop();
            }
            ans.push_back(x);
        }
        for(int i = ans.size() - 1; i >= 0; --i) {
            if(ans[i] != "null") break;
            ans.pop_back();
        }
        for(int i = 0; i < ans.size(); ++i) res += ans[i] + ",";
        res[res.length() - 1] = ']';
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL, curr = NULL;
        queue <TreeNode*> q;
        string x;
        int count = 0;
        if(data == "[]") return root;
        for(int i = 1; i < data.size(); ++i) {
            if(data[i] == ',' || data[i] == ']') {
                if(x == "null") {
                    TreeNode* cu = q.front();
                    if(count == 0) cu->left = NULL; 
                    else cu->right = NULL;
                    count += 1;
                    if(count == 2) q.pop(), count = 0;
                    x = "";
                    continue;
                }
                int d = 1, value = 0, cx = 0;
                if(x[0] == '-') cx = 1;
                for(int i = x.length() - 1; i >= cx; --i) {
                    value += d * (x[i] - '0');
                    d *= 10;
                }
                if(cx) value *= -1; x = "";
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
                    if(count == 2) q.pop(), count = 0;
                }
            }
            else x += data[i];
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));