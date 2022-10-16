class Solution {
public:
    long long int dp[1001][1001];
   long long int solve(vector<int>& jobDifficulty, int d,int i,int n){
        if(d==0 && i==n){
            return 0;
        }
        if(i>=n || (d<0 && i<n)){
            return INT_MAX;
        }
       if(dp[i][d]!=-1){
           return dp[i][d];
       }
        long long int ans=INT_MAX;
        int k=INT_MIN;
        for(int j=i;j<n;j++){
            k=max(k,jobDifficulty[j]);
            long long int p=solve(jobDifficulty,d-1,j+1,n);
            if(p+k < ans){
                ans=p+k;
            }
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size()){
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        
        long long int p= solve(jobDifficulty,d,0,jobDifficulty.size());
        if(p>=INT_MAX){
            return -1;
        }
        return p;
    }
};