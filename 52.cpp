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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr||pHead2==nullptr) return nullptr;
        int num1=1,num2=1;
        ListNode* node1=pHead1, * node2=pHead2;
        while(node1->next!=nullptr){
            node1=node1->next;num1++;
        }
        while(node2->next!=nullptr) {
            node2=node2->next;num2++;
        }
        if(node1==node2){
            node1=pHead1;
            node2=pHead2;
            int cost=abs(num1-num2);
            if(num1>num2){
                while(cost>0){
                    node1=node1->next;
                    cost--;
                }
            }else if(num1<num2){
                while(cost>0){
                    node2=node2->next;
                    cost--;
                }
            }
            while(node1!=node2){
                node1=node1->next;
                node2=node2->next;
            }
            return node1;
        }else return nullptr;
    }
};