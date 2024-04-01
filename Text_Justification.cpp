class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n=words.size();
        for (int i=0;i<n;) {
            int width=words[i].size(); 
            int j=i+1; 
            while (j<n && width+words[j].size()+(j - i)<= maxWidth) {
                width+= words[j].size();
                j++;
            }
            int numWords=j-i; 
            int totalSpaces=maxWidth-width; 
            int numGaps=numWords-1;
            stringstream line;
            line << words[i];
            if (j<n && numWords>1) {
                int regularSpaces = totalSpaces / numGaps;
                int extraSpaces = totalSpaces % numGaps;
                for (int k=i+1;k<j;k++) {
                    line << string(regularSpaces, ' ');
                    if (extraSpaces > 0) {
                        line << ' ';
                        extraSpaces--;
                    }
                    line << words[k]; 
                }
            }
            else { 
                for (int k=i+1;k<j;k++) {
                    line << ' '; 
                    line << words[k]; 
                }
                line << string(maxWidth - width - numWords + 1, ' ');
            }
            result.push_back(line.str());
            i=j; 
        }
        return result;
    }
};