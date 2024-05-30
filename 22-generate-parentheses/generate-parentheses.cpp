class Solution {
public:
    void solve(int n,vector<string> &ans_fin,string ans,int open,int close){
        if(close==n){
            ans_fin.push_back(ans);
            return;
        }
        if(open<n){
            solve(n,ans_fin,ans+"(",open+1,close);
        }
        if(open>close){
            solve(n,ans_fin,ans+")",open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
       string ans="";
       vector<string>ans_fin;
       int open=0;
       int close=0;
       solve(n,ans_fin,ans,open,close);
       return ans_fin;
 
    }
};