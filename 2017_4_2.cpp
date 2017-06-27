#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
  
struct POINT   
{  
    double x,y;  
}point[10010],temp[10010];  
  
double dis(struct POINT p1, struct POINT p2)  
{  
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));  
}  



/*用于基于x的排序*/  
int cmp(const void * a, const void * b)  
{  
    struct POINT * c = (struct POINT *)a;  
    struct POINT * d = (struct POINT *)b;  
    if (c->x != d->x)  
    {  
        return c->x > d->x;  
    }  
    else  
        return c->y > d->y;  
}  
/*用于基于y的排序*/
int cmp1(const void * a, const void * b)  
{  
    struct POINT * c = (struct  POINT *)a;  
    struct POINT * d = (struct  POINT *)b;  
    if (c->y != d->y)  
    {  
        return c->y > d->y;  
    }  
    else  
        return c->x > d->x;  
}  
  
double findMin(int l, int r)  
{  
    if (l == r)  
    {  
        return 10010;  
    }  
    if (l == r - 1)  
    {  
        return dis(point[l], point[r]);  
    }  

    /**/
    double tmp1 = findMin(l,(l + r) >> 1);  
    double tmp2 = findMin(((l + r) >> 1) + 1, r);  
    double Mindis,tmp, mid;  
    mid = point[(l + r) >> 1].x;  
    /*mid = (point[l].x + point[r].x) / 2.0;*/  
    int i,j,cnt = 0;  


    if (tmp1 < tmp2)  
    {  
        Mindis = tmp1;  
    }  
    else  
        Mindis = tmp2;


    /*取最小值中间值mid前后最小值d的范围，将这个范围内所有点存入新的数组*/      
    for (i = l; i <= r; ++ i)  
    {  
        if (fabs(point[i].x - mid) < Mindis)  
        {  
            temp[cnt ++] = point[i];  
        }  
    }  
    qsort(temp, cnt, sizeof(temp[0]), cmp1);  
    for (i = 0; i < cnt - 1; ++ i)  
    {  
        /*for (j = i + 1; j < cnt; ++ j)*/  
        /*only 6 is possible*/
        for (j = i + 1; j < i + 7 && j < cnt; ++ j)  
        {  
            tmp = dis(temp[i], temp[j]);  
            if (tmp < Mindis)  
            {  
                Mindis = tmp;  
            }  
        }  
    }  
    return Mindis;  
  
}  
int main()  
{  
    int n,i,j;  
    double minDis;  
    while (scanf("%d", &n)==1 && n)  
    {  
        for (i = 0; i < n; ++ i)  
        {  
            scanf("%lf%lf", &point[i].x, &point[i].y);  
        }  
        qsort(point, n, sizeof(point[0]), cmp);  
        minDis = findMin(0, n-1);  
        if (minDis > 10000)  
        {  
            printf("INFINITY\n");  
        }  
        else  
            printf("%.4lf\n", minDis);  
    }  
    return 0;  
}  
