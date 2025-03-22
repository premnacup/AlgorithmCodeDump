#include<iostream>
#include<vector>
using namespace std;
vector<int> mem;

void resetMem(int n){
	mem.assign(n+1, -1);
}

int fact(int n){
	if(n == 1){
		return 1;
	}
	return n * fact(n-1);
}

int fact_t(int n){
	if(n == 1){
		return 1;
	}
	if(mem[n] != -1){
		return mem[n];
	}
	mem[n] = n * fact_t(n-1);
	return mem[n];
}

int fact_d(int n){
	mem[1] = 1;
	for(int i = 2; i<=n; i++){
		mem[i] = i * mem[i-1];
	}
	return mem[n];
}

int main(){
	
	int n;
	cin >> n;
	
	cout << fact(n) << endl;
	resetMem(n);
	cout << fact_t(n) << endl;
	resetMem(n);
	cout << fact_d(n) << endl;
	
	for(auto i : mem){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
