class Solution {
public:
    int max(int a,int b){
        return ((a>=b)?a:b);
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>table(s.size(),vector<int>(s.size()));
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                if(i>j){
                    table[i][j]=0;
                }
            }
        }
        int end;
        for(int i=1;i<=s.size();i++){
            for(int start=0;start<=s.size()-i;start++){
                end=start+i-1;
                if(start==end){
                    table[start][end]=1;
                }
                else if(s[start]==s[end]){
                    table[start][end]=2+table[start+1][end-1];
                }
                else{
                    table[start][end]=max(table[start][end-1],table[start+1][end]);
                }

            }
        }
        return table[0][s.size()-1];
    }
};