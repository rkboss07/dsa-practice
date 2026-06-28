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

class Codec {
   public:
    string data = "";
    void DFS(TreeNode* root) {
        if (!root) {
            data += "N,";
            return;
        }
        data += to_string(root->val) + ",";
        DFS(root->left);
        DFS(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        DFS(root);
        return data;
    }
    // Decodes your encoded data to tree.
    vector<string> vals;
    int i = 0;
    TreeNode* dfsCreate() {
        if (vals[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsCreate();
        node->right = dfsCreate();
        return node;
    }
    TreeNode* deserialize(string data) {
        vals.clear();
        i = 0;

        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            if (!token.empty()) {  // Ignore the empty string after the last comma
                vals.push_back(token);
            }
        }

        return dfsCreate();
    }
};
