/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==nullptr) return nullptr;
        //先新建连到后方
        RandomListNode* n = pHead;
        while(n!=nullptr){
            RandomListNode* newNode = new RandomListNode(n->label);
            newNode->next=n->next;
            n->next=newNode;
            n=newNode->next;
        }
        n=pHead;
        //再连random
        while(n!=nullptr){
            if(n->random!=nullptr)
                n->next->random=n->random->next;
            n=n->next->next;
        }
        //拆开
        n=pHead->next;
        RandomListNode* newHead = n;
        while(n->next!=nullptr){
            pHead->next=pHead->next->next;
            pHead=pHead->next;
            n->next=n->next->next;
            n=n->next;
        }
        pHead->next=nullptr;
        return newHead;
    }
};