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
     ListNode* Middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!= NULL && fast->next!= NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;     
    }   
     
    ListNode* reverseList(ListNode* head) 
     {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        
        while(head!=NULL)
        {
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
       
        return pre;
     }
    
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL)
        {
            return true;
        }
        
        ListNode* slow=Middle(head);
        ListNode* temp=head;
        
        slow=reverseList(slow);
        
        while(slow!=NULL)
        {
            if(slow->val!=temp->val)
            {
                return false;
            }
            
            slow=slow->next;
            temp=temp->next;
        }
        
        return true;
    }
};    