class node{
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int a,int b){
            key=a;
            val=b;
        }
};

class LRUCache {
private:
    void addNode(node *newNode){
        node* nextNode=head->next;
        newNode->next=nextNode;
        nextNode->prev=newNode;
        head->next=newNode;
        newNode->prev=head;
    }
    void deleteNode(node *delNode){
        node* nextNode=delNode->next;
        node* prevNode=delNode->prev;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
public:
    int cap;
    unordered_map<int,node*> mp;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* resNode=mp[key];
            int resVal=resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key]=head->next;
            return resVal;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* delNode=mp[key];
            mp.erase(key);
            deleteNode(delNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */