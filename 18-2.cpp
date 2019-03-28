/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr) return nullptr;
        ListNode* pre=nullptr;
        ListNode* p=pHead;
        ListNode* q=nullptr;
        while(p!=nullptr){
            if(p->next!= nullptr&&p->val==p->next->val){
                q=p->next;
                while(q!=nullptr&&q->val==p->val){
                    q=q->next;
                }
                if(p==pHead){
                    pHead=q;
                    p=q;
                }else{
                    pre->next=q;
                    p=pre;
                }
            }else{
                pre=p;
                p=p->next;
            }
        }
        return pHead;
    }
};