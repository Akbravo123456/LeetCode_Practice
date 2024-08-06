class Solution {
public:
    int minimumPushes(string word){
        vector<int> letter(26,0);
        for(char c:word){
            letter[c-'a']++;
        }
        sort(letter.rbegin(),letter.rend());
        int total=0;
        for(int i=0;i<26;i++){
            if(letter[i]==0) break;
            total +=(i/8+1)*letter[i];
        }
        return total;
    }
};