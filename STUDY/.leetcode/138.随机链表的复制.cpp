/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        Node* cur = head;
        if(cur == nullptr)
        {
            return nullptr;
        }

        map<Node*, Node*> m;
        Node* copyhead = nullptr;
        Node* copytail = nullptr;
        while(cur)
        {
            if(copyhead == nullptr)
            {
                copyhead = new Node(cur->val);
                copytail = copyhead;
                m[cur] = copyhead;
            }
            else
            {
                copytail->next = new Node(cur->val);
                copytail = copytail->next;
                m[cur] = copytail;
            }

            cur = cur->next;
        }

        //处理random
        cur = head;
        Node* copycur = copyhead;
        while(cur)
        {
            if(cur->random == nullptr)
            {
                copycur->random = nullptr;
            }
            else
            {
                copycur->random = m[cur->random];
            }

            copycur = copycur->next;
            cur = cur->next;
        }

        return copyhead;
    }
};
// @lc code=end
//一刷：用C++的map试着做了一下。先遍历链表并创建节点，然后用map建立原链表节点和复制链表的关系
//需要注意栈和堆的区别！需要分配空间必须用new！