class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int s=target.size();
        sort(begin(target),end(target));
        sort(begin(arr),end(arr));
        for(int i=0;i<s;i++){
            if(target[i]!=arr[i])
            return false;
        }
        return true;
    }
};