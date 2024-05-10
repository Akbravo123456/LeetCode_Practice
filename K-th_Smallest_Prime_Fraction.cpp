class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        double low=0,high=1;
        while(low<high){
            double mid=low+(high-low)/2;
            vector<int> count =f(arr,mid);
            if(k<count[0]){
                high=mid;
            }else if(k>count[0]){
                low=mid;
            }
            else{
                return {count[1], count[2]};
            }
        }
        return {};
    }
    vector<int> f(vector<int>& arr, double target){
        int count=0;
        int i=0;
        int n=arr.size();
        int num=0,deno=1;

        for(int j=1;j<n;j++){
            while(i<j && arr[i]<=arr[j]*target){
                i++;
            }
            count +=i;
            if(i>0 && num*arr[j]<arr[i-1]*deno){
                num=arr[i-1];
                deno=arr[j];
            }
        }
        return {count,num,deno};
    }
};