class Solution {
public:
    int rec(int i,string &s,int n,vector<int>&dp)
    {
        if(i==n)
        {
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        int cnt=0;
        //taking one digit
        if(s[i]!='0') cnt+=rec(i+1,s,n,dp);
        //taking 2 digits along with conditions
        if(i<n-1&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6'))) cnt+=rec(i+2,s,n,dp);
        return dp[i]=cnt;
        
    }
    
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        int ans=rec(0,s,n,dp);
        return ans;
    }
};