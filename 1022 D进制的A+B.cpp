/*
输入两个非负 10 进制整数 A 和 B (≤2
​30
​​ −1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103
*/
#include <cstdio>
#define MAX 100
int main(){
  int A,B,D;
  scanf("%d %d %d",&A,&B,&D);
  int sum=A+B;
  int a[MAX],num=0;
  do{
  a[num++]=sum%D;
  sum/=D;
  }while(sum!=0);
  for(int i=num-1;i>=0;i--){
    printf("%d",a[i]);
  }
  return 0;
}
