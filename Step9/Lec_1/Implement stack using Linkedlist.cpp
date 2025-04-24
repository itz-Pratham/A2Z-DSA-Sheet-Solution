
class MyStack {
    private:
      StackNode *top;
  
    public:
      void push(int x) {
          // code here
          StackNode* node = new StackNode(x);
          node->next = top;
          top = node;
      }
  
      int pop() {
          // code here
          if(top == NULL) return -1;
          
          int popped = top->data;
          StackNode* temp = top;
          top = top->next;
          delete temp;
          return popped;
          
      }
  
      MyStack() { top = NULL; }
  };

  