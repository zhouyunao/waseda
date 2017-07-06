#include <cstdio>
#include <iostream>
using namespace std;


/*find the root in array a*/
int find(int a[], int i){
	if(a[i] != i)
		return find(a, a[i]);
	return i;
}

/*func for check i & j is in the same tuple*/
int check_a(int a[], int i, int j){
	int t1 = find(a, i);
	int t2 = find(a, j);
	if(t1 == t2) return 1;
	else return 0;
}


int check_b(int b[], int i, int j){
	int flag = 0;
	int final = i;
	while(b[i]!= final){
		i = b[i];
		if(i == j) flag = 1;
	}

	return flag;
}

/*func for print checking result*/
void printout(int ans){
	if (ans == 1) cout << "yes" << endl;
	else cout << "no" << endl;
}


void merge(int a[], int b[], int i, int j){
	/*	
		merge a[]
		search for root
		bigger root link to smaller root
	*/
	int root_ai = find(a, i);
	int root_aj = find(a, j);
	if(root_ai <= root_aj) a[root_aj] = root_ai;
	else a[root_ai] = root_aj;

	/*
		merge b[]
		swap b[i] = b[j]
	*/
	int tmp = b[i];
	b[i] = b[j];
	b[j] = tmp;


}

int main(){
	int a[12] = {0,1,1,0,1,5,3,7,2,6,3,7};
	int b[12] = {9,2,8,0,1,5,3,11,4,10,6,7};
	
	/*check array a*/
	int ans = check_a(a, 4, 8);
	int ans1 = check_a(a, 10,8);
	printout(ans);
	printout(ans1);

	/*check array b*/
	int ans2 = check_b(b, 4, 8);
	printout(ans2);
	int ans3 = check_b(b, 10, 8);
	printout(ans3);

	/*merge 6 & 8 union and check the result*/
	merge(a, b, 6, 8);
	int ans4 = check_a(a, 6, 8);
	printout(ans4);
	int ans5 = check_b(b, 6, 8);
	printout(ans5);


}