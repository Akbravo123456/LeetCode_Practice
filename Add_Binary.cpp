class Solution {
public:
    string addBinary(string a, string b) {
        int c=a.length();
        int d=b.length();
        int i=0;
        int carry=0;
        string res="";
        while(i<c||i<d|| carry!=0){
            int x=0;
            if(i<c && a[c-i-1]=='1'){
                x=1;
            }
            int y=0;
            if(i<d && b[d-i-1]=='1'){
                y=1;
            }
            res=to_string((x+y+carry)%2)+res;
            carry=(x+y+carry)/2;
            i+=1;
        }
        return res;
    }
};