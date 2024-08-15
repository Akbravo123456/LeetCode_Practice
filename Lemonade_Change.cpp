class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        stack<int> f,t;
        for(auto x:bills){
            if (x==5){
            f.push(x);
            }
        else if(x==10){
            if(f.empty()){
                return false;
            }
            f.pop();
            t.push(x);
        }
        else if(x==20){
            if(!t.empty() && !f.empty()){
                t.pop();
                f.pop();
            }   
        else if(f.size()>=3){
            f.pop();
            f.pop();
            f.pop();
        }
        else{
            return false;
        }
    }
    }    
    return true;
    }
};