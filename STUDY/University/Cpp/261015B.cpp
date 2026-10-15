#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

struct Node
{
    char val;
    Node* left;
    Node* right;

    Node(int v = 0, Node* l = nullptr, Node* r = nullptr)
    {
        val = v;
        left = l;
        right = r;
    }
    

    Node* BuildTree(const string& s, int& pos)
    {
        int n = s.size();

        if(pos >= n || s[pos] == '0')
        {
            ++pos;
            return nullptr;
        }

        Node* node = new Node(s[pos]);
        ++pos;
        node->left = BuildTree(s, pos);
        node->right = BuildTree(s, pos);
        return node;
    }
};

int TreeLeaves(Node* root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;

    int left = TreeLeaves(root->left);
    int right = TreeLeaves(root->right);
    return left + right;
}


int main()
{
    int t; cin >> t;
    while(t--)
    {
        string str; cin >> str;
        int pos = 0;
        Node* root = Node().BuildTree(str, pos);

        cout << TreeLeaves(root) << endl;

    }
    return 0;
}