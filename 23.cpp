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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==nullptr||pHead->next==nullptr) return nullptr;
        int num = NumOfLoop(pHead);
        if(num==-1) return nullptr;
        ListNode* h2 = pHead;
        while(num>=1) {
            pHead=pHead->next;
            num--;
        }
        while(pHead!=h2){
            pHead=pHead->next;
            h2=h2->next;
        }
        return h2;
    }
    
    int NumOfLoop(ListNode* h){
        ListNode* h2 = h->next;
        while(h2!=nullptr&&h!=nullptr&&h!=h2){
            h=h->next;
            h2=h2->next;
            if(h2!=nullptr) h2=h2->next;
        }
        if(h==h2){
            int n=1;
            h=h->next;
            while(h!=h2){h=h->next;n++;}
            return n;
        }
        return -1;
    }
};