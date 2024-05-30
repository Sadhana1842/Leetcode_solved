class Solution {
public:
    bool solve(int n,int m,vector<vector<char>> &board,string word,int i,int j,int ind){
        if(ind==word.size()){
            return true;
        }
        if(i==-1||j==-1||i==n||j==m||board[i][j]!=word[ind]||board[i][j]=='*'){
            return false;
        }
        else{
            char temp=board[i][j];
            board[i][j]='*';
            bool a=solve(n,m,board,word,i-1,j,ind+1);
            bool b=solve(n,m,board,word,i,j-1,ind+1);
            bool c=solve(n,m,board,word,i+1,j,ind+1);
            bool d=solve(n,m,board,word,i,j+1,ind+1);
            board[i][j]=temp;
            return(a||b||c||d);
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        bool val=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(n,m,board,word,i,j,0)){
                    val=true;
                    break;
                }
            }
        }
        
        return val;
    }
};