class Solution {
public:
    int solve(int ind,int amount,vector<int> &coins){
        if(amount==0){
            return 0;
        }
        if(ind==0){
            if(coins[ind]<=amount){
                int val=amount%coins[ind];
                if(val==0){
                    return amount/coins[ind];
                }
                else{
                    return INT_MAX;
                }
            }
            if(coins[ind]>amount){
                return INT_MAX;
            }
        }
        else{
            if(coins[ind]<=amount){
                int not_take=0+solve(ind-1,amount,coins);
                int take=INT_MAX;
                if(coins[ind]<=amount){
                    int res=solve(ind,amount-coins[ind],coins);
                    if(res!=INT_MAX){
                        take=1+res;
                    }
                }
                return min(not_take,take);
            }
            else{
                return 0+solve(ind-1,amount,coins);
            }
        }
        return -1;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }

        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int not_take=dp[i-1][j];
                int take=INT_MAX;
                if(coins[i]<=j){
                    int res=dp[i][j-coins[i]];
                    if(res!=INT_MAX){
                        take=1+res;
                    }
                }
                dp[i][j]=min(take,not_take);
            }
        }
        int ans=dp[n-1][amount];
        return (ans==INT_MAX?-1:ans);
    }
};