#include<bits/stdc++.h>
#include<string>
using namespace std;

int ok; int n, a[1001];
void ktao(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		a[i] = 0;
	}
}
void sinh(){
	int i = n;
	while(i >= 1 && a[i] == 1){ 
		a[i] = 0;
		i--;
	}
	if(i == 0){
		ok = 0;
	}
	else{
		 a[i] = 1;
		}
}


int main(){
	int t; cin >> t;
	while(t--){
		ok = 1;
		ktao();
		while(ok){
		for(int i = 1; i <= n; i++){
			if(a[i]){
			cout << 'B';
			}
			else cout <<'A';
		}
			cout << " ";
		sinh();
		}
		cout << "\n";
	}
}
  
