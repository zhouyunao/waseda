#include <cstdio>
#include <iostream>
using namespace std;
int d[100][100];
/*
	test input:
	4 7
	1 10
	3 20
	2 15
	4 25

	answer:
	45
	50

	table d[][]
	      *  0  1  2  3  4  5  6  7
	      0  0  0  0  0  0  0  0  0
	1  10 1  0  10 10 10 10 10 10 10
	3  20 2  0  10 10 20 30 30 30 30
	2  15 3  0  10 15 25 30 30 30 30
	4  25 4  0  10 15 25 30 35 40 50

*/


// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

void s_sort(int a[], int b[], int n){
	for(int i = 1; i <= n-1; i++){
		for(int j = n; j > i; j--){
			float score1 = (float) b[j]/a[j];
			float score2 = (float) b[j-1]/a[j-1];
			if(score1 > score2){
				int s = b[j];
				int t = a[j];
				b[j] = b[j-1];
				a[j] = a[j-1];
				b[j-1] = s;
				a[j-1] = t;
			}
		}
	}
}

int calc_greedy(int w[], int v[], int N, int U){
	s_sort(w, v , N);
	int ans = 0;
	int i= 1;
	int n = 0;
	for(; i <= N && n <= U; i++, n+=w[i]){
		ans += v[i];
	}
	return ans;
}

int calc_dynamic(int w[], int v[], int N, int U){
	for(int i = 0; i <=N; i++ ){
		for(int j = 0; j <= U; j++){
			if(i == 0 || j == 0) d[i][j] = 0;
			else if(w[i] <= j){
				d[i][j] = max(d[i-1][j-w[i]] + v[i], d[i-1][j]);
			}

			else
				d[i][j] = d[i-1][j];
		}
	}

	return d[N][U];
}

int main(){
	int N, U;
	cin >> N >> U;
	int w[10];
	int v[10];
	for(int t = 1; t <= N; t++){
		cin >> w[t] >> v[t];
	}
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= U; j++){
			d[i][j] = 0;
		}
	}
	int ans0 = calc_greedy(w, v, N, U);
	int ans = calc_dynamic(w, v, N, U);


	cout << "calc_greedy :  "<< ans0 << endl;
	cout << "calc_dynamic:  "<< ans << endl;
}