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

        if(pos >= n || s[pos] == '#')
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

void preOrder(Node* node)
{
    if(node == nullptr) return;

    cout << node->val;
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node* node)
{
    if(node == nullptr) return;

    inOrder(node->left);
    cout << node->val;
    inOrder(node->right);
}

void postOrder(Node* node)
{
    if(node == nullptr) return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->val;
}



int main()
{
    int t; cin >> t;
    while(t--)
    {
        string str; cin >> str;
        int pos = 0;
        Node* root = Node().BuildTree(str, pos);

        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
    }
    return 0;
}