class node{
    public:
        int key,val;
        node *prev,*next;
        node(int a,int b){
            key=a;
            val=b;
        }
        
};

class LRUCache {
    node *head=new node(-1,-1),*tail=new node(-1,-1);
    map<int,node*> mp;
    int cap;
    void addNode(node *n){
        node *nextNode=head->next;
        n->next=nextNode;
        nextNode->prev=n;
        head->next=n;
        n->prev=head;
        
    }
    void deleteNode(node *n){
        node *prevNode=n->prev,*nextNode=n->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        node *n=mp[key];
        mp.erase(key);
        deleteNode(n);
        addNode(n);
        mp[key]=head->next;
        return n->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *n=mp[key];
            mp.erase(key);
            deleteNode(n);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node *newNode=new node(key,value);
        addNode(newNode);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */