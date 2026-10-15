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

void PrintLeaves(Node* node)
{
    if(!node) return;
    if(!node->left && !node->right)
    {
        cout << node->val << ' ';
    }

    PrintLeaves(node->left);
    PrintLeaves(node->right);
}

void PrintParent(Node* node, Node* parent)
{
    if(!node) return;
    if(!node->left && !node->right)
    {
        cout << parent->val << ' ';
    }

    PrintParent(node->left, node);
    PrintParent(node->right, node);
}


int main()
{
    int t; cin >> t;
    while(t--)
    {
        string str; cin >> str;
        int pos = 0;
        Node* root = Node().BuildTree(str, pos);

        PrintLeaves(root);
        cout << endl;
        PrintParent(root, root);
        cout << endl;

    }
    return 0;
}