class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        auto it = v.begin();
        while(head!=nullptr){
            it = v.insert(it,head->val);
            head=head->next;
        }
        return v;
    }
};