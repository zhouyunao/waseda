#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;



void power(char A[], int n)
{   /*plus 进位 初始时0*/
    int plus = 0;
    for(int i = 0; i < n; i++){
        for(int j = 100000; j > 0; j--){
            /*乘2 取个位+进位*/
            int tmp = (A[j] - '0')*2%10 + plus;
            /*乘2 取十位更新进位plus*/
            plus = (A[j] - '0') * 2 /10;
            /*更新 字符数组*/
            A[j] = (char)(tmp + '0');
        }
    }
}

int main()
{   
    int n;
    cin >> n;
    char A[100001];
    for(int j = 0; j < 100001; j++){
        A[j] = '0';
    }
    A[100000] = '1';
    /*数组最后一位开始进行运算方便最后加0*/
    power(A, n);


    /*补全非0部分*/
    int i = 0;

    for(; i < 100001; i++){
        if(A[i] != '0') break;
    }
    int right = 100000 - i + 1;
    cout << "0.";
    int zero = n-right;
    for(int t = 0; t < zero; t++) cout << 0;
    for(;i<100001;i++){
        cout << A[i];
    }
}