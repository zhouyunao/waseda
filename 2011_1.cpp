#include <cstdio>
#include <iostream>
#include <string.h> //for strlen
#include <cmath>
using namespace std;


/*坐标结构体
 *坐标
 *tan值
*/
struct n
{
	int x;
	int y;
	float tan;
	
};

/*坐标二维数组*/
n nd[251][251];



/*寻找下一个坐标的函数
 *输入为 横坐标 纵坐标 杆子长
 */
void find_next_node(int Ax, int Ay, int l){
	

	/*搜索范围内最大的正切值*/
	float tan_big = 0.0;
	
	int result_x;
	int result_y;

    /*纵坐标搜索范围*/
	int ymax;
	ymax = (int) Ay*l/sqrt(Ax*Ax + Ay*Ay);
	

	//cout << ymax <<endl;

	/*输入坐标的tan值*/
	float s_tan = (float)Ay/Ax;
	//cout << s_tan << endl;



	for(int j = 1; j <= ymax; j++){
		for(int i = 1; i <= l; i++){
			/*斜边长*/
			int ln = nd[j][i].x * nd[j][i].x + nd[j][i].y*nd[j][i].y;
			/*搜索满足要求的坐标
			  1.tan值大于输入坐标tan值s_tan
			  2.tan值大于最大tan值tan_big
			  3.坐标与0，0的距离平方小于输入坐标斜边平方
			 */
			if(nd[j][i].tan < s_tan && nd[j][i].tan > tan_big && ln <= l*l){
				tan_big = nd[j][i].tan;
				result_x = i;
				result_y = j;
				cout << result_x <<" " << result_y << endl;
			}

		}
	}
	cout << result_x <<" " << result_y << endl;

}


int main(){
	int l;
	int a,b;
	cin >> l >> a >> b;

	/*初始化坐标二维数组*/
	for(int i = 1; i <= 251; i++){
		for(int j = 1; j <= 251; j++){
		nd[i][j].x = j;
		nd[i][j].y = i;
		nd[i][j].tan = (float)i/j;
	}

}
	find_next_node(a,b,l);
}