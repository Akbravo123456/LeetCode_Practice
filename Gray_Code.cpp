class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0)
        return {0};
        if(n == 1)
        return{0,1};
        vector<int> Rans = grayCode(n-1);
        vector<int> Mans;
        for(int i=0;i<Rans.size();i++){
            int s=Rans[i];
            Mans.push_back(0 * (1 << (n - 1)) + s);
        }
        for(int i=Rans.size()-1;i>=0;i--){
            int s=Rans[i];
            Mans.push_back(1 * (1 << (n - 1)) + s);
        }
        return Mans;
    }
};