/*
题目描述
输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）。

输入
测试数据有多组，输入n(1<=n<=200)，接着输入n个数，然后输入x。

输出
对于每组输入,请输出结果。

样例输入
4
1 2 3 4
3
样例输出
2
*/
#include <cstdio>
#define MAX 201
 
int a[MAX];
int main(){
    int n;
    int x;
    while(scanf("%d",&n)!=EOF){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    int k=0;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            k=i;
            printf("%d\n",k);
            break;
        }
        if(i==n-1&&a[i]!=x){
            printf("-1\n");
        }
    }
}
    return 0;
     
}
