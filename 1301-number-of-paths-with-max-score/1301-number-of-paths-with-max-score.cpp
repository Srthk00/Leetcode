class Solution {
public:
    const int MOD=1e9+7;
    int maxi,paths,n;
    vector<vector<int>> dp;
    vector<vector<vector<int>>> dp2;

    bool issafe(vector<string>& board,int i,int j){
        if(i<0 || j<0 || i>=n || j>=n || board[i][j]=='X'){
            return false;
        }
        return true;
    }

    int findmax(vector<string>& grid,int i,int j){
        if(i==0 && j==0){
            return 0;
        }
        if(!issafe(grid,i,j)){
            return -1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int temp=0;
        if(i!=n-1 || j!=n-1){
            temp=grid[i][j]-'0';
        }
        int top=temp+findmax(grid,i-1,j);
        int left=temp+findmax(grid,i,j-1);
        int diag=temp+findmax(grid,i-1,j-1);
        return dp[i][j]=max({top,diag,left});
    }

    int findpaths(vector<string>& grid,int i,int j,int sum){
        if(!issafe(grid,i,j)){
            return 0;
        }
        int temp=0;
        if(grid[i][j]!='S' && grid[i][j]!='E'){
            temp=grid[i][j]-'0';
        }
        sum+=temp;
        if(i==0 && j==0){
            return (sum==maxi)?1:0;
        }
        if(dp2[i][j][sum]!=-1){
            return dp2[i][j][sum];
        }
        long long result=0;
        result+=findpaths(grid,i-1,j,sum);
        result %= MOD;
        result+=findpaths(grid,i,j-1,sum);
        result %= MOD;
        result+=findpaths(grid,i-1,j-1,sum);
        result %= MOD;
        return dp2[i][j][sum]=result%MOD;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        dp=vector<vector<int>>(n,vector<int>(n,-1));
        maxi=findmax(board,n-1,n-1);
        if(maxi<0){
            return {0,0};
        }
        dp2=vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(maxi+1,-1)));
        paths=findpaths(board,n-1,n-1,0);
        return {maxi,paths};
    }
};