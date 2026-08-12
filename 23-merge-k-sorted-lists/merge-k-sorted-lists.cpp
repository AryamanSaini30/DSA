/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return solve(lists,0,lists.size()-1);
    }
    ListNode* solve(vector<ListNode*>& lists,int l,int r){
        if(l==r){
            return lists[l];
        }
        if(l>r){
            return NULL;
        }
        int mid=l+(r-l)/2;
        ListNode*  left=solve(lists,l,mid);
        ListNode* right=solve(lists,mid+1,r);
        return merge(lists,left,right);
    }
    ListNode* merge(vector<ListNode*>& lists,ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(l1 && l2){
            if(l1->val<=l2->val){
                dummy->next=l1;
                l1=l1->next;
            }
            else if(l2->val<l1->val){
                dummy->next=l2;
                l2=l2->next;
            }
            dummy=dummy->next;
        }
        if(l1){
            dummy->next=l1;
        }
        if(l2){
            dummy->next=l2;
        }
        return temp->next;
    }
};