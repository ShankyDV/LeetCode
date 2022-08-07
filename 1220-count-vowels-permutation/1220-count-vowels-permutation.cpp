class Solution {
public:
    string s = "aeiou";
    int mod = 1e9+7;
    int dp[20001][5];
    int func(int i,int n,int j){
        if(i==n) return 1;
        long long ans=0;
        if(j==-1){
            for(int k=0;k<5;k++){
                ans+=func(i+1,n,k);
                ans%=mod;
            }
            return ans;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==0){
            ans+=func(i+1,n,1);
        }
        else if(j==1){
            ans=(ans+func(i+1,n,0))%mod;
            ans=(ans+func(i+1,n,2))%mod;
        }
        else if(j==2){
            for(int k=0;k<5;k++){
                if(k==j) continue;
                ans=(ans+func(i+1,n,k))%mod;
            }
        }
        else if(j==3){
            ans=(ans+func(i+1,n,2))%mod;
            ans=(ans+func(i+1,n,4))%mod;
        }
        else ans=(ans+func(i+1,n,0))%mod;
        
        return dp[i][j] = ans;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return func(0,n,-1);
    }
};