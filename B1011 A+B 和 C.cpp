/*
给定区间 [−2
​31
​​ ,2
​31
​​ ] 内的 3 个整数 A、B 和 C，请判断 A+B 是否大于 C。

输入格式：
输入第 1 行给出正整数 T (≤10)，是测试用例的个数。随后给出 T 组测试用例，每组占一行，顺序给出 A、B 和 C。整数间以空格分隔。

输出格式：
对每组测试用例，在一行中输出 Case #X: true 如果 A+B>C，否则输出 Case #X: false，其中 X 是测试用例的编号（从 1 开始）。

输入样例：
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
输出样例：
Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/
#include <cstdio>
#define MAX 10
int main(){
  long long A[MAX],B[MAX],C[MAX];
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;i++){
    scanf("%lld %lld %lld",&A[i-1],&B[i-1],&C[i-1]);
  }
  for(int i=1;i<=T;i++){
    if(A[i-1]+B[i-1]>C[i-1])printf("Case #%d: true\n",i);
    else printf("Case #%d: false\n",i);
  }
}
