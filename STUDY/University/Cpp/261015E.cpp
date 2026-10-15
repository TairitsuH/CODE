#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int v = 0, Node* l = nullptr, Node* r = nullptr)
    {
        val = v;
        left = l;
        right = r;
    }

    Node* buildTree(vector<int>& Tree, int pos)
    {
        if(pos >= Tree.size() || Tree[pos] == 0) return nullptr;

        Node* node = new Node(Tree[pos]);
        node->left = buildTree(Tree, pos * 2 + 1);
        node->right = buildTree(Tree, pos * 2 + 2);
        return node;
    }
};

void preOrder(Node* root)
{
    if(!root) return;

    cout << root->val << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> Tree(n);
        for(int i=0; i<n; ++i) cin >> Tree[i];

        int pos = 0;
        Node* root = Node().buildTree(Tree, pos);

        preOrder(root);
        cout << endl;
    }
    return 0;
}