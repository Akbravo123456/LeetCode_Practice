class Solution {
public:
    string numberToWords(int num){
        if (num==0)
            return "Zero";

        string lessThan20[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string tens[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string thousands[]= {"","Thousand","Million","Billion"};
        string result ="";
        int i=0;
        
        while(num>0){
            if (num%1000!=0) {
                result=helper(num%1000,lessThan20,tens)+thousands[i]+" "+result;
            }
            num/=1000;
            i++;
        }
        while(result.back()==' ') result.pop_back(); 
        return result;
    }
    string helper(int num,string lessThan20[],string tens[]) {
        if (num == 0)
            return "";
        else if(num<20)
            return lessThan20[num]+" ";
        else if (num<100)
            return tens[num/10] +" "+helper(num%10,lessThan20,tens);
        else
            return lessThan20[num/100]+" Hundred "+ helper(num % 100,lessThan20,tens);
    }
};
