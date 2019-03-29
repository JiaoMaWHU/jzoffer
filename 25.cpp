//solution1-loop
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr&&pHead2==nullptr) return nullptr;
        ListNode* head = nullptr;
        ListNode* node = nullptr;
        while(pHead1!=nullptr||pHead2!=nullptr){
            if(pHead1==nullptr){
                if(head==nullptr) {head=pHead2;break;}
                node->next=pHead2;
                break;
            }
            else if(pHead2==nullptr){
                if(head==nullptr) {head=pHead1;break;}
                node->next=pHead1;
                break;
            }else{
                if(pHead1->val<pHead2->val){
                    if(head==nullptr) {
                        head=pHead1;
                        node=pHead1;
                        pHead1=pHead1->next;
                    }else{
                        node->next=pHead1;
                        node=node->next;
                        pHead1=pHead1->next;
                    }
                }else{
                    if(head==nullptr) {
                        head=pHead2;
                        node=pHead2;
                        pHead2=pHead2->next;
                    }else{
                        node->next=pHead2;
                        node=node->next;
                        pHead2=pHead2->next;
                    }
                }
            }
        }
        return head;
    }
};
//solution2-recursive
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr) return pHead2;
        else if(pHead2==nullptr) return pHead1;
        ListNode* node=nullptr;
        if(pHead1->val<pHead2->val){
            node=pHead1;
            node->next=Merge(pHead1->next,pHead2);
        }else{
            node=pHead2;
            node->next=Merge(pHead1,pHead2->next);
        }
        return node;
    }
};