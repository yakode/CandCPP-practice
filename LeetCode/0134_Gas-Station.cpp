class Solution{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
        vector<int> net(gas.size());
        int sum = 0;

        for(int i = 0; i < gas.size(); ++i){
            net[i] = gas[i] - cost[i];
            sum += net[i];
        }

        if(sum < 0)
            return -1;

        int start = 0;
        sum = 0;
        for(int i = 0; i < net.size(); ++i){
            sum += net[i];
            if(sum < 0){
                sum = 0;
                start = i + 1;
            }
        }

        return start;
    }
};
