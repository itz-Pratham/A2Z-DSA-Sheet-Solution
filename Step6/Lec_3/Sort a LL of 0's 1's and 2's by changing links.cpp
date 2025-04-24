class Solution {
    public:
      // Function to sort a linked list of 0s, 1s and 2s.
      Node* segregate(Node* head) {
  
          // Add code here
          Node* list_0 = new Node(-1);
          Node* zero_start = list_0;
          Node* list_1 = new Node(-1);
          Node* one_start = list_1;
          Node* list_2 = new Node(-1);
          Node* two_start = list_2;
          
          Node* cur = head;
          
          while(cur != NULL){
              if(cur->data == 0){
                  list_0->next = new Node(0);
                  list_0 = list_0->next;
              }
              else if(cur->data == 1){
                  list_1->next = new Node(1);
                  list_1 = list_1->next;
              }else{
                  list_2->next = new Node(2);
                  list_2 = list_2->next;
              }
              
              cur = cur->next;
          }
          
          list_0->next = (one_start->next) ? one_start->next : two_start->next;
          list_1->next = two_start->next;
          list_2->next = NULL;
          
          return zero_start->next;
          
      }
  };