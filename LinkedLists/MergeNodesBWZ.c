struct ListNode* mergeNodes(struct ListNode* head){
    head=head->next;
    struct ListNode* start=head;
    while(start){
        struct ListNode* end= start;   /* Point to first node of current part for getting sum */
        int sum=0;
        while(end->val!=0) sum+= end->val , end=end->next;
        start->val=sum;   /*assign sum to first node between two 0*/
        start->next=end->next;   /*make this connect to first node of next part*/
        start=start->next;    /*go..to..next..part*/
	}
    return head;

}
