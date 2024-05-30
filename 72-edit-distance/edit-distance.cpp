#include<algorithm>
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>table(word1.size()+1,vector<int>(word2.size()+1));
        table[0][0]=0;
        for(int i=1;i<=word1.size();i++){
            table[i][0]=table[i-1][0]+1;
        }
        for(int j=1;j<=word2.size();j++){
            table[0][j]=table[0][j-1]+1;
        }
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    table[i][j]=table[i-1][j-1];
                }
                else{
                    table[i][j]=1+(min(table[i-1][j],min(table[i-1][j-1],table[i][j-1])));
                }
            }
        }
        return table[word1.size()][word2.size()];
    }
};