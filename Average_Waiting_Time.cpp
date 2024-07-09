class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_wait=0;
        double currt=0;

        for(auto& customer:customers){
            double arr=customer[0];
            double ser=customer[1];
            if(currt < arr){
                currt=arr;
            }
            int wait=currt-arr+ser;
            total_wait +=wait;
            currt +=ser;
        }
        return total_wait/customers.size();
    }
};