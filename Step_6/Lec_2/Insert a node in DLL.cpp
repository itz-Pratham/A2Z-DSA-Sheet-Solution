class Solution {
    public:
      // Function to insert a new node at given position in doubly linked list.
      Node *addNode(Node *head, int pos, int data) {
          // code here
          Node* cur = head;
          int pos_rn = 0;
          bool flag = false;
          
          if(pos_rn == pos) flag = true;
          
          while(!flag && cur->next != NULL){
              cur = cur->next;
              pos_rn += 1;
              if(pos_rn == pos) break;
          }
          
          Node* temp = cur->next;
          
          Node* newNode = new Node(data);
          
          cur->next = newNode;
          newNode->next = temp;
          newNode->prev = cur;
          if(temp)
              temp->prev = newNode;
          
          return head;
      }
  };