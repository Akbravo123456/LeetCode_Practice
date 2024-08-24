class Solution {
public:
    string nearestPalindromic(string n) {
        vector<long> can;
        int s=n.length();
        int mid=(s+1)/2;
        if(s==1)
        return to_string(stoi(n)-1);

        can.push_back(pow(10,s)+1);
        can.push_back(pow(10,s-1)-1);

        long pre=stol(n.substr(0,mid));
        vector<long> temp={pre,pre+1,pre-1};

        for(int i:temp){
            string res=to_string(i);
            string rev=res;
            reverse(rev.begin(),rev.end());
            if(s%2==1){
                res.pop_back();   
            }
            can.push_back(stol(res+rev)); 
        }
        long minDiff=LONG_MAX,result=-1,tip=stol(n);
        for(long candidate:can){
            if(candidate!=tip){
                long diff=abs(candidate-tip);
                    if(diff<minDiff || (diff==minDiff && candidate<result)){
                        minDiff=diff;
                        result=candidate;
                    }
            }
        }
            return to_string(result);
    }
};