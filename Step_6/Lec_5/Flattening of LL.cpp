class Solution {
    public:
      // Function which returns the  root of the flattened linked list.
      Node *flatten(Node *root) {
          // Your code here
          Node* head = root;
          
          if(!head || head->next == NULL && head->bottom == NULL) return root;
          
          vector<int> v;
          v.push_back(head->data);
          
          while(head != NULL){
              Node* cur = head->bottom;
              Node* temp = head->next;
              
              while(cur != NULL){
                  v.push_back(cur->data);
                  cur = cur->bottom;
              }
              
              // cur->bottom = temp;
              cur = temp;
              if(cur) v.push_back(cur->data);
              head = head->next;
          }
          
          sort(v.begin(),v.end());
          
          Node* start = new Node(-1);
          Node* c = start;
          
          for(int i=0;i<v.size();i++){
              c->bottom = new Node(v[i]);
              c = c->bottom;
          }
          
          return start->bottom;
      }
  };
  