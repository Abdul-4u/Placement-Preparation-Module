class LRUCache {
public:
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int,Node*> mp;
    int Cap;

    LRUCache(int capacity) {
        Cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void insertNode(Node* nd){
       Node* nextHead=head->next;

       head->next=nd;
       nextHead->prev=nd;

       nd->prev=head;
       nd->next=nextHead;
    }

    void deleteNode(Node* nd){
        Node* prevNd=nd->prev;
        Node* nextNd=nd->next;

        prevNd->next=nextNd;
        nextNd->prev=prevNd;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* curr=mp[key];
            int ans=curr->val;
            
            mp.erase(key);
            deleteNode(curr);
            insertNode(curr);

            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* curr=mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if(mp.size()==Cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        insertNode(new Node(key,value));
        mp[key]=head->next;
    }
};