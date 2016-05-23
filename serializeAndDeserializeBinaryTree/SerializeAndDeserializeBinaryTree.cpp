

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serialize02(root);
        return serialize01(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserialize02(data);
        return deserialize01(data);
    }      
    

public:
    // Encodes a tree to a single string.
    string serialize01(TreeNode* root) {
         string result;
         vector<TreeNode*> v;
         serializeHelper(root, v);
         for(int i=0; i<v.size(); i++){
             result = result + (v[i]==NULL ? "#" : to_string(v[i]->val)) + " ";
         }
         return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize01(string data) {
        vector<TreeNode*> v;
        split(data, ' ', v);

        int index = 0;
        return deserializeHelper(v, index);

    }    

private:

    void serializeHelper(TreeNode* root, vector<TreeNode*>& v) {
        if (root==NULL) {
            v.push_back(NULL);
        }else{
            v.push_back(root);
            serializeHelper(root->left, v);
            serializeHelper(root->right, v);
        }
    }
   

    TreeNode* deserializeHelper(vector<TreeNode*> &v, int& index) {

        if (index >= v.size() ) return NULL;

        TreeNode* root = v[index++];
        if (root) {
            root->left = deserializeHelper(v, index);
            root->right = deserializeHelper(v, index);
        }
        return root;
    }


   void split(const string &s, char delim, vector<TreeNode*> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            TreeNode* node =  (item=="#" ? NULL : new TreeNode( stoi(item)) );
            elems.push_back(node);
        }

    }
    


public:
    // Encodes a tree to a single string.
    string serialize02(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize02(string data) {
        istringstream in(data);
        return deserialize(in);
    } 
    
private:
   void serialize(TreeNode* root, ostringstream& out) {
        if (root==NULL) {
            out << "# ";
            return;
        }
        out << root->val << " ";
        serialize(root->left, out);
        serialize(root->right, out);
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#" || val.empty() ) return NULL;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserialize(in);
        node->right = deserialize(in);
        return node;
    }
};



int main(int argc, char** argv) 
{
    string s = "1 2 3 # # 4 5";
    if (argc>1){
        s = argv[1];
    }
    cout << s << endl;
    Codec codec;
    cout << codec.serialize(codec.deserialize(s)) << endl;
    
    return 0;
    
}
