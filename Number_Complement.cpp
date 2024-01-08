class Solution {
public:
    int findComplement(int num) {
        if(num==0) 
        return 1;
       vector<int> bits;

       while(num>0){
           bits.push_back(num%2);
           num/=2;
       } 

       int complement=0;
       int power=0;

       for(int i=0;i<bits.size();i++){
           int bit=(bits[i]==1)?0 :1;
           complement +=bit*(1<<power);
           power++;
       }
       return complement;
    }
};