/*
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10^5），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/
#include <cstdio>
int change(char c){
  if(c=='B')return 0;
  if(c=='C')return 1;
  if(c=='J')return 2;
}
int win(int a,int b,int A1[],int B1[],int A2[],int B2[]){
  if((a+1)%3==b){
    A1[0]++;
    B1[2]++;
    A2[a]++;
  }
  else if((b+1)%3==a){
    A1[2]++;
    B1[0]++;
    B2[b]++;
  }else
  {
      A1[1]++;
      B1[1]++;
  }
}
char change(int a){
   if(a==0)return 'B';
   if(a==1)return 'C';
   else return 'J';
}
int main(){
int N;
int A1[3]={0},B1[3]={0};
int A2[3]={0},B2[3]={0};
char mp[3]={'B','C','J'};
scanf("%d",&N);
char a,b;
int k1,k2;
for(int i=0;i<N;i++){
    getchar();
    scanf("%c %c",&a,&b);
    k1=change(a);
    k2=change(b);
    win(k1,k2,A1,B1,A2,B2);
}
printf("%d %d %d\n",A1[0],A1[1],A1[2]);
printf("%d %d %d\n",B1[0],B1[1],B1[2]);
int max=0;
int temp=0;
for(int i=0;i<3;i++){
    if(A2[i]>max){temp=i;max=A2[i];}
}
printf("%c",change(temp));
max=0;
temp=0;
for(int i=0;i<3;i++){
    if(B2[i]>max){temp=i;max=B2[i];}
}
printf(" %c",change(temp));
return 0;
}
