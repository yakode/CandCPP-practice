/*
	doubt: complexity of count and [] of unorder_map is not O(1)?
 */
class RandomizedSet{
    vector<int> nums;
    unordered_map<int, int> pos;

public:
    RandomizedSet(){   
    }
    
    bool insert(int val){
        if(pos.count(val) != 0)
            return false;
        
        nums.push_back(val);
        pos[val] = nums.size() - 1;

        return true;
    }
    
    bool remove(int val){
        if(pos.count(val) == 0)
            return false;
        
        nums[pos[val]] = nums[nums.size() - 1];
        pos[nums[nums.size() - 1]] = pos[val];
        nums.pop_back();
        pos.erase(val);

        return true;
    }
    
    int getRandom(){
        return nums[rand() % nums.size()];
    }
};
