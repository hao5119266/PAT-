/*
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (≤100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (≤300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/
#include <cstdio>
#include<algorithm>

using namespace std;

struct Student{
  int registration_number;
  int final_rank;
  int location_number;
  int local_rank;
  int score;
}stu[30010];
//排序判断函数
//要求按rank从小到大排序(分数从高到低)，分数相同则按编号从小到大
bool cmp(Student a,Student b){
   if(a.score!=b.score){
     return a.score>b.score;
   }
   else return a.registration_number<b.registration_number;
}

int main(){
  int N;
  scanf("%d",&N);//输入N为多少组数据
  int num;//每个考场人数
  int total=0;//总人数
  
  for(int i=0;i<N;i++){
    scanf("%d",&num);
    
    for(int j=0;j<num;j++){
      scanf("%d %d",&stu[total].registration_number,&stu[total].score);
      stu[total].location_number=i+1;//记录考场
      total++;
    }
    //0-n，即[0,n]代表n+1个人,
    sort(stu+total-num,stu+total,cmp);
    stu[total-num].local_rank=1;
    for(int i=total-num+1;i<total;i++){
        if(stu[i].score==stu[i-1].score){
          stu[i].local_rank=stu[i-1].local_rank;
        }else{
          stu[i].local_rank=i+1-(total-num);
        }
    }
  }
  printf("%d\n",total);
  sort(stu,stu+total,cmp);
  int r=1;
  for(int i=0;i<total;i++){
    if(i>0&&stu[i].score!=stu[i-1].score){
      r=i+1;
    }
      printf("%d ",stu[i].registration_number);
      printf("%d %d %d\n",r,stu[i].location_number,stu[i].local_rank);
  }
  return 0;
}
