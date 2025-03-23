#include<bits/stdc++.h>
using namespace std;




int C(int n,int k , vector<vector<int>> &mem2){
	if(k == 0 || k == n  ){
		return 1 ;
	}
	if (mem2[n][k] != -1){
		return mem2[n][k];
	}
	mem2[n][k]= C(n-1,k-1,mem2)+C(n-1,k,mem2);
	return mem2[n][k];
}
int main (){
    
	int n ,k ;
	cin >> n >> k;
    vector<vector<int>> mem2(n+1, vector<int>(k+1, -1));
	int ans = C(n,k,mem2);
	cout<< ans;
}