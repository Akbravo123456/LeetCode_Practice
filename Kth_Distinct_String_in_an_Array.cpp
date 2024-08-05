class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,bool> map;
        int count=0;
        for(const string& i:arr){
            if(map.find(i)!=map.end()){
                map[i]=false;
            }else{
                map[i]=true;
            }
        }
        for(const string& i:arr){
            if(map[i]){
                count++;
                if(count==k){
                    return i;
                }
            }
        }
        return "";
    }
};