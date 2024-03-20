class Solution {
public:
    bool isScramble(string s1, string s2) {
        int length=s1.size();
        int scrambleStates[length][length][length + 1];
        memset(scrambleStates,-1,sizeof(scrambleStates));

        function<bool(int,int,int)> checkScramble = [&](int index1,int index2,int len){
        if(scrambleStates[index1][index2][len]!= -1){
            return scrambleStates[index1][index2][len] == 1;
        }
        if (len == 1){
            return s1[index1] == s2[index2];
        }
        for(int split = 1;split<len;split++){
            if(checkScramble(index1,index2,split) && checkScramble(index1 + split,index2 + split,len -split)){
                scrambleStates[index1][index2][len] = 1;
                return true;
            }   
            if(checkScramble(index1+ split,index2,len - split) && checkScramble(index1,index2 + len - split,split)){
                scrambleStates[index1][index2][len] = 1;
                return true;
            }
         }
         scrambleStates[index1][index2][len] = 0;
         return false;
    };
    return checkScramble(0, 0, length);
    }
};