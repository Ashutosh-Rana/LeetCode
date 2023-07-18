class node{
public:
    int key,val;
    node *next,*prev;
    node(int a,int b){
        key=a,val=b;
    }
};

class LRUCache {
    void addNode(node* newNode){
        node* nextNode=head->next;
        newNode->next=nextNode;
        nextNode->prev=newNode;
        head->next=newNode;
        newNode->prev=head;
    }
    void deleteNode(node* n){
        node *prevNode=n->prev;
        node *nextNode=n->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
public:
    int cap;
    node *head=new node(-1,-1),*tail=new node(-1,-1);
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node *resNode=mp[key];
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
            node *dNode=mp[key];
            mp.erase(key);
            deleteNode(dNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node* tmp=new node(key,value);
        addNode(tmp);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */