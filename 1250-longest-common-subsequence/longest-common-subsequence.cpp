class Solution {
public:
    int max(int a,int b){
        return ((a>=b)?a:b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.size();
        int len2=text2.size();
        vector<vector<int>> table( len1+1 , vector<int> (len2+1));
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                if(i==0||j==0){
                    table[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1]){
                    table[i][j]=1+table[i-1][j-1];
                }
                else{
                    table[i][j]=max(table[i-1][j],table[i][j-1]);
                }

            }
        }
        return table[len1][len2];
    }
};