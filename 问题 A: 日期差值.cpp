/*
题目描述
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。

输入
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD

输出
每组数据输出一行，即日期差值

样例输入
20130101
20130105
样例输出
5
*/
#include <cstdio>
int month[13][2]={
    {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};
bool isLeap(int year){
    return(year%4==0&&year%100!=0)||(year%400==0);
}
int main(){
    int time1,y1,m1,d1;
    int time2,y2,m2,d2;
    while(scanf("%d%d",&time1,&time2)!=EOF){
        if(time1>time2){
            int temp=time1;
            time1=time2;
            time2=temp;
        }
    y1=time1/10000,m1=time1%10000/100,d1=time1%100;
    y2=time2/10000,m2=time2%10000/100,d2=time2%100;
    int ans=1;
    while(y1<y2||m1<m2||d1<d2){
        d1++;
        if(d1==month[m1][isLeap(y1)]+1){
            m1++;
            d1=1;
        }
        if(m1==13){
            y1++;
            m1=1;
        }
        ans++;
    }
        printf("%d\n",ans);
    }
    return 0;
}
