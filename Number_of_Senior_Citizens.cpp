class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(auto& x:details){
            int age=stoi(x.substr(11,2));
            res +=age>60;
        }
        return res;
    }
};