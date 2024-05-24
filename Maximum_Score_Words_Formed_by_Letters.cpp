class Solution {
public:
int helper(vector<string> words,int start,vector<int> letterCounts,vector<int> score){
    if(start==words.size())
    return 0;
    int currScore=0;
    int wordScore=0;
    vector<int> nextCounts=letterCounts;
    for(int i=0;i<words[start].size();i++){
        int index=words[start][i]-'a';
        if(nextCounts[index]==0){
            wordScore=-1;
            break;
        }
        wordScore += score[index];
        nextCounts[index]--;
    }
    if(wordScore>0)
    currScore=helper(words,start+1,nextCounts,score)+wordScore;
    currScore=max(currScore,helper(words,start+1,letterCounts,score));

    return currScore;
}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letterCounts(26,0);
        for(char letter:letters)
        letterCounts[letter-'a']++;

        return helper(words,0,letterCounts,score);
    }
};