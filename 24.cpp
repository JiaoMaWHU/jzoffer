/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr) return nullptr;
        ListNode* n=pHead->next;
        ListNode* n1=nullptr;
        if(n!=nullptr){
            pHead->next=nullptr;
            n1=n->next;
            n->next=pHead;
            pHead=n;
            n=n1;
        }
        while(n!=nullptr){
            n1=n->next;
            n->next=pHead;
            pHead=n;
            n=n1;
        }
        return pHead;
    }
};