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

int TreelEFTLeaves(Node* node, Node* parent)
{
    if(!node) return 0;
    if(!node->left && !node->right && parent->left == node) return 1;

    int left = TreelEFTLeaves(node->left, node);
    int right = TreelEFTLeaves(node->right, node);
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

        cout << TreelEFTLeaves(root, root) << endl;

    }
    return 0;
}