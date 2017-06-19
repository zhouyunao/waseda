#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*INF    起始承载量
 *check  标记是否已经访问，访问中为1，若子节点全部访问过则为0
 *path   存储起点到终点的路径
 *ans    更新的最大承载量 
 *Graph  邻接矩阵的结构体，方便作为变量传输


 *测试参数：
0 1 10
0 2 1
1 2 6
1 3 9
2 4 5
3 4 4
3 2 3
3 5 2
4 3 3
4 5 6
*/

int INF = 10000;
int check[6];
int path[10];
int ans = 0;
struct Graph{
	int adj[6][6];
};


/*再归DFS探索*/

/*到达终点时打印路径，更新最大承载量*/
void printpath(int path[], int len, int flow){
	for(int i = 0; i < len; i++){
		cout << path[i] <<" ";
		if(i!=len-1) cout << "--> ";
		else cout <<endl;
		ans = max(ans, flow);
	}
}


/*
 *des   终点编号
 *len   当前路径长度，主要来控制最后打印路径的停止变量，因为路径没有每次做初始化
 *c     check
 *a     邻接矩阵
 *v     当前节点编号
 *flow  承载量

*/
void dfs(int des, int len, int c[], Graph a, int v, int flow){
	/*再归停止条件：此点已被访问*/
	if(c[v]) return;


	/*添加路径*/
	path[len-1] = v;

	/*再归停止条件：到达终点，并打印路径，承载量*/
	if(v == des) {
		printpath(path, len, flow);
		cout << flow << endl;
		return;
	}
	/*否则对于v的邻接表所有邻接节点进行再归DFS探索*/
	else{
		/*标记已访问*/
		c[v] = 1;

		/*遍历邻接节点*/
		for(int i = 0; i < 6; i++){
			if(a.adj[v][i] != 0 && c[i] == 0){
				dfs(des, len + 1, check, a, i, min(flow, a.adj[v][i]));
			}

			
		}
		/*所有邻接节点都访问过后，解除访问标记并返回父节点*/
		c[v] = 0;
	}
	return;
}


int main(){
	/*初始化访问数组*/
	for(int i = 0; i < 6; i++){
		check[i] = 0;

	}
	
	Graph graph = {{0}};
	

	/*初始化邻接矩阵*/
	for(int i = 0; i < 10; i++){
		int x,y;
		cin >> x >> y; 
		cin >> graph.adj[x][y]; 
	}


	/*打印邻接矩阵*/
	for(int i = 0; i<6;i++){
		for(int j = 0;j<6;j++){
			cout << graph.adj[i][j] <<" ";

		}
		cout <<endl;
	}

	/*进入再归*/
	dfs(5, 1, check, graph, 0, INF);
	
	cout << "the answer is : "<<ans << endl;
}