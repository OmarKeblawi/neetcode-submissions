class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum = 0;
        for(int g : gas){
            gas_sum+=g;
        }
        int cost_sum = 0;
        for(int c : cost){
            cost_sum += c;
        }
        if(cost_sum > gas_sum ) return -1;

        int result = 0;
        int total = 0;
        int i = 0;
        while(i < gas.size()){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                result = i+1;
            }
            i++;
        }
        return result;
    }
};
