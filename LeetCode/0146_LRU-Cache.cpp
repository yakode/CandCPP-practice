class LRUCache{
private:
    struct Node{
        int key;
        int value;
        struct Node *prev, *next;
    };
    struct Node *head, *tail;
    int capacity;
    int nr_key;
    struct Node *hash[10000 + 1] = {0};

public:
    LRUCache(int capacity){
        this->head = nullptr;
        this->tail = nullptr;
        this->capacity = capacity;
        this->nr_key = 0;
    }
    
    int get(int key){
        if(hash[key]){
            if(hash[key] == head)
                return head->value;

            if(hash[key]->prev)
                hash[key]->prev->next = hash[key]->next;
            if(hash[key]->next)
                hash[key]->next->prev = hash[key]->prev;
            if(tail == hash[key] && hash[key]->prev)
                tail = hash[key]->prev;
            hash[key]->next = head;
            head->prev = hash[key];
            hash[key]->prev = nullptr;
            head = hash[key];

            return hash[key]->value;
        }

        return -1;
    }
    
    void put(int key, int value){
        struct Node *tmp;
        if(hash[key]){
            tmp = hash[key];
            if(head == tmp && nr_key == 1){
                head->value = value;
                return;
            }

            if(head == tmp && tmp->next)
                head = head->next;
            if(tail == tmp && tmp->prev)
                tail = tail->prev;

            if(tmp->next)
                tmp->next->prev = tmp->prev;
            if(tmp->prev)
                tmp->prev->next = tmp->next;

            --nr_key;
        }else{
            tmp = new struct Node();
            hash[key] = tmp;
        }
        tmp->prev = nullptr;
        tmp->next = nullptr;
        tmp->key = key;
        tmp->value = value;
        
        if(nr_key == capacity){
            hash[tail->key] = nullptr;
            if(tail->prev)
                tail->prev->next = nullptr;
            tail = tail->prev;
            if(!tail)
                head = nullptr;
            --nr_key;
        }

        if(head){
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
        }else{
            head = tmp;
            tail = tmp;
        }

        ++nr_key;
    }
};
