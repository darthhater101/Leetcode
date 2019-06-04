/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or 
memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized 
to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Result: Runtime: 32 ms, faster than 88.17% of C++ online submissions for Serialize and Deserialize BST.
        Memory Usage: 24.4 MB, less than 47.50% of C++ online submissions for Serialize and Deserialize BST.
*/

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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream str;
        serialize(root, str);
        return str.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream str(data);
        return deserialize(str);
    }
    
private:
    
    void serialize(TreeNode* root, ostringstream& data) {
        if(root == nullptr) data << "# ";
        else {
            data << root->val << " ";
            serialize(root->left, data);
            serialize(root->right, data);
        }
    }
    
    TreeNode* deserialize(istringstream& data) {
        string val;
        data >> val;
        
        if(val == "#") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        
        node->left = deserialize(data);
        node->right = deserialize(data);
        
        return node;
    }
    
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
