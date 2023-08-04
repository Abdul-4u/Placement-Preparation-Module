class Node{
    public:
    int val;
    Node* next;

    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

//Using Scratch

class MyQueue {
public:
    Node* front;
    Node* rear;
    MyQueue() {
        front = NULL;
        rear = NULL;
    }
    
    void push(int x){
        Node* temp = new Node(x);
        if(front == NULL)   //No node
        {
            front = temp;
            rear = temp;
            return;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }

    }
    
    int pop(){
        if(front==NULL) return -1;

        int frontData = front->val;
        if(front==rear)
        {            
            front = NULL;
            rear = NULL;
            return frontData;
        }
        front = front->next;
        return frontData   ;    
    }
    
    int peek(){
        return front->val;
                
    }
    
    bool empty(){
        return front==NULL;
        
    }
};