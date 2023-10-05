struct ListNode* mergeNodes(struct ListNode* head){
    head=head->next;
    struct ListNode* start=head;
    while(start){
        struct ListNode* end= start;  
        int sum=0;
        while(end->val!=0)
        { 
            sum+= end->val; 
            end=end->next;
        }
        start->val=sum;   
        start->next=end->next;   
        start=start->next;   
	}
    return head;

}
