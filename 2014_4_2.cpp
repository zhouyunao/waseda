#include <cstdio>
#include <iostream>
using namespace std;
int C[1000][1000];//not in here will bring error


/*阶乘函数*/
int Kaijo(int n){
	int total = 1;
	for(int i = 1; i <= n; i++){
		total *= i;
	}
	return total;
}


/*用阶乘计算路径数量*/
int Count1(int i, int j){
	int route;
	route = Kaijo(i+j)/Kaijo(i);
	route = route/Kaijo(j);
	return route;
}


/**/
int Count2(int i, int j){
	
	for(int m = 0; m <= j; m++){
		for(int n = 0; n <= i; n++){
			if(m == 0) C[m][n] = 1;
			else if(n == 0) C[m][n] = 1;
			else if(m > 0 && n > 0) C[m][n] = C[m-1][n] + C[m][n-1];
		}
	}
	return C[j][i];
}

int Count(int I, int J, int i0, int j0, int i1, int j1){

	for(int m = 1; m <= J; m++) C[m][0] = 1;
	for(int n = 0; n <= I; n++) C[0][n] = 1;

	C[j0][i0] = -1;
	C[j1][i1] = -1;

	for(int m = 1; m <= J; m++){
		for(int n = 1; n <= I; n++){
		    if(C[m][n] == -1) {}
			else if(C[m][n-1] == -1 && C[m-1][n] == -1) C[m][n] = 0;
			else if(C[m][n-1] == -1 && C[m-1][n] != -1) C[m][n] = C[m-1][n];
			else if(C[m-1][n] == -1 && C[m][n-1] != -1) C[m][n] = C[m][n-1];
			else C[m][n] = C[m-1][n] + C[m][n-1];
		}
	}

	return C[J][I];
}


/* update on 17.6.12 */
/* exception: 
              1.(0,n)or(m,0)
              2.(m-1,n)or(m,n-1) is not allowed to pass
              3.(m-1,n)and(m,n-1) are not allowed to pass  
              4.(m,n) is not allowed to pass */

int count(int I, int J, int i0, int j0, int i1, int j1){

	for(int m = 1; m <= J; m++) C[m][0] = 1;
	for(int n = 0; n <= I; n++) C[0][n] = 1;

	C[j0][i0] = -1;
	C[j1][i1] = -1;

	for(int m = 1; m <= J; m++){
		for(int n = 1; n <= I; n++){
		    if(C[m][n] == -1) {}
			else if(C[m][n-1] == -1) C[m][n] = C[m-1][n];
			else if(C[m-1][n] == -1) C[m][n] = C[m][n-1];
			else if(C[m-1][n] == -1 && C[m][n-1] == 1) C[m][n] = 0;
			else C[m][n] = C[m-1][n] + C[m][n-1];
		}
	}

	return C[J][I];
}


int main(){
    int result = Count(4,3,1,1,3,2);
    int r = count(4,3,1,1,3,2);


    cout << "1-1-2:"<<Count1(4,3) << endl;
    cout << "1-2:" << Count2(4,3) << endl;
	cout << "1-4:"<<result << endl;
	cout << "1-4:" << r < endl;

}
