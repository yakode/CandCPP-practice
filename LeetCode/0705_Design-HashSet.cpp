class MyHashSet{
private:
    bool isContained[1000001] = {0};
public:
    MyHashSet(){
    }
    
    void add(int key){
        isContained[key] = true;
    }
    
    void remove(int key){
        isContained[key] = false;
    }
    
    bool contains(int key){
        return isContained[key];
    }
};
