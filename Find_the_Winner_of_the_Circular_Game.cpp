class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> c;
        for(int i=1;i<=n;i++){
            c.push(i);
        }
        while(c.size()>1){
            for(int i=1;i<k;i++){
                c.push(c.front());
                c.pop();
            }
            c.pop();
        }
        return c.front();
    }
};