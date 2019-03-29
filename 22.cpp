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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr || k==0) return nullptr;
        ListNode* f = pListHead;
        ListNode* s = nullptr;
        while(f!=nullptr&&k>1){
            f=f->next;
            k--;
        }
        if(f==nullptr) return nullptr;
        s=pListHead;
        while(f->next!=nullptr){
            f=f->next; s=s->next;
        }
        return s;
    }
};