class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto convert=[&](int num)->long long{
            if(num==0) return mapping[0];
            long long mp=0,place=1;
            while(num>0){
                int dig=num%10;
                mp=mapping[dig]*place+mp;
                place *=10;
                num /=10;
            }
            return mp;
        };

        vector<pair<long long,int>> mp;
        for(int num:nums){
            mp.emplace_back(convert(num),num);
        }
        sort(mp.begin(),mp.end(),[](const pair<long long,int>& a,const pair<long long,int>& b){
            return a.first<b.first;
        });
        vector<int> res;
        for(const auto& z:mp){
            res.push_back(z.second);
        }
        return res;
    }
};