class LRUCache {
public:
    int cap;
    typedef struct node{
        node *prev,*next;
        int key,value;
    }node;
    unordered_map<int,node*> mp;
    node *make(int key,int value){
        node* temp=new node();
        temp->prev=nullptr;temp->next=nullptr;
        temp->key=key;temp->value=value;
        return temp;
    }
    node *head=nullptr;
    node *last=nullptr;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            node *temp=mp[key];
            if(temp==last){
                return temp->value;
            }
            if(head==temp){
                head=head->next;
                if(head!=nullptr){
                    head->prev=nullptr;
                }
            }
            else{
                if(temp->prev!=nullptr){
                    temp->prev->next=temp->next;
                }
                if(temp->next!=nullptr){
                    temp->next->prev=temp->prev;
                }
            }
            temp->prev=last;
            temp->next=nullptr;
            if(last!=nullptr){
                last->next=temp;
            }
            last=temp;
            if(head==nullptr){
                head=temp;
            }
            return temp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            node *temp=mp[key];
            temp->value=value;
            get(temp->key);
            return;
        }
        if(mp.size()==cap){
            node *temp=head;
            head=head->next;
            mp.erase(temp->key);
            if(head!=nullptr){
                head->prev=nullptr;
            }
            else{
                last=nullptr;
            }
            delete temp;
        }
        node *n=make(key,value);
        if(head==nullptr){
            head=n;
            last=n;
        }
        else{
            n->prev=last;
            last->next=n;
            last=n;
        }
        mp[key]=n;
    }  
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */