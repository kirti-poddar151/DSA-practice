#include<bits/stdc++.h>
using namespace std;

string lcs(string a, string b){
    int n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int len=dp[n][m];
    int i=n, j=m;
    int index=len-1;
    string ans="";
    for(int i=1;i<=len;i++) ans+="&";

    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans[index]=a[i-1];
            index--;
            i--;
            j--;
        }
        else if(a[i-1]>b[j-1]){ 
            i--;
        }else j--;
    }
    return ans;

}

int main(){
    string s1 = "abcde";
    string s2 = "bdgek";

    cout << "The Longest Common Subsequence is "<<lcs(s1, s2);
}