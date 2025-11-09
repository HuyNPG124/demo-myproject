#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[15];// mảng lưu chỉ số của phần tử trong mảng b
int b[15];
void in(){
	for(int i = 1; i <= k; i++){
		cout << b[a[i]] << " ";
	}
	cout <<  endl;
}
void backtrack(int i){
	for(int j = a[i-1] + 1; j <= n-k+i; j++){
		a[i] = j; 
		if(i == k) in();
		else backtrack(i+1);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> b[i];
		}
		sort(b+1, b+n+1);
		backtrack(1);
	}
}
