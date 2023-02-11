struct ListNode* sortList(struct ListNode* head){
      struct ListNode*num=head;//用链表遍历，计算链表长度
      int count;
      while(num->next!=NULL){
          num=num->next;
          count++;
      }
      int i;
      struct ListNode*newhead=NULL;
      struct ListNode*tail=NULL;
      for(i=0;i<count;i++){
          struct ListNode*p=head->next;
          //struct ListNode*temp=NULL
          struct ListNode*connect=NULL;
          while(p!=NULL&&p->next!=NULL){
             if(p->val>p->next->val){
                connect=p->next;
             }else connect=p;
             p=p->next;
          }if(newhead==NULL){
              newhead=tail=connect;
              //newhead->next=connection;
          }else{
              struct ListNode*connection=connect;
              tail->next=connection;
          }
      }return newhead;
}
