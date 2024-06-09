#include<unordered_set>
#include<string>
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordset(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++)//Always consider the length of the string for substr() sue to the parameters
        {
            for(int j=0;j<i;j++){
                if(dp[j]&&wordset.find(s.substr(j,i-j))!=wordset.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};