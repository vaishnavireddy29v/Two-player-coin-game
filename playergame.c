#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
struct players
{
   char First_Name[20];
   char Last_Name[20];
   char Gender;
   char Email;
   char nickname[20];
};
struct players p1,p2;
int max(int x, int y)
{
    int max=0;
    if(x>y)
     { max=x;}
     else {max=y;}
     return max;
}
int min(int x,int y)
{
    int min=0;
    if(x<y){
        min=x;
    }
    else {
        min=y;
    }
}
void Welcomescreen(void)
{
    printf("\n\n\n\n\t\t\t##############################");
    printf("\n\t\t\t #########***   Welcome To    *****#######\t\t");
    printf("\n\n\n\t\t ////////**   TWO COIN GAME   **//// ");
  printf("\n\n\n\t\t$$$$$      GO        $$$$\t\t");
  printf("\n\n\n\n\n\t\t\t ########   let's play    #######");
  printf("\n\t\t\tenter any key to continue");
  getchar();
  system("clear");
}
void title(void)
{
    printf("\n\n\n\n\n\t\t\t ######## enter details to signup #######");
    printf("\n\n\n\t\t\n****enter to go**");
    getchar();
    system("clear");
}
void signup(void)
{
    int b,valid,L=0;
    A:
    printf("\n\n\n enter first_name");
    //scanf("%s",p1.First_name);
     scanf("%s",p1.First_Name);
  
  if(strlen(p1.First_Name)>20||strlen(p1.First_Name)<2)
  {
    printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
    goto A;
  }
  else
  {
    for (b=0;b<strlen(p1.First_Name);b++)
    {
      if (isalpha(p1.First_Name[b]))
    {
        valid=1;
      }
     else
      {
        valid=0;
        break;
   } 
    if(!valid)
    {
      printf("\n\t\t First name contain Invalid character :(  Enter again :)");
      goto A;
    }
  }
  }
 B: 
  printf("\n\t\t\tLast Name: ");
  scanf("%s",p1.Last_Name);
  
    
    if(strlen(p1.Last_Name)>20||strlen(p1.Last_Name)<2)
  {
    printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
    goto B;
  }
  else
  {
    for (b=0;b<strlen(p1.Last_Name);b++)
    {
      if (isalpha(p1.Last_Name[b]))
      {
        valid=1;
      }
      else
      {
        valid=0;
        break;
      }
    }
    if(!valid)
    {
      printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
      goto B;
    }
  }
 
    getchar();
    system("clear");
      
  }
  /*  else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
    */
   



int main(void)

{
    Welcomescreen();
    title();
    signup();

 int n;
printf("start the game enter number of coins");
 scanf("%d",&n);

 int a[n];

 for(int i=0;i<n;i++)

 scanf("%d",&a[i]);
 char s1[20],s2[20];
 printf("enter player1 name");
 scanf("%s",s1);
 printf("enter player2 name");
 scanf("%s",s2);

 int table[n][n];

 for(int i=0;i<n;i++)

 {

 table[i][i]=a[i];

 if(i != n-1)

 table[i][i+1]=max(a[i],a[i+1]);

 }

 int x,y,z,r,c;

 bool flag = true;

 for(int i=2;i<n;i++)

 {

 for(int j=0;j+i<n;j++)

 {

 r=j;

 c=j+i;

 x=table[r+2][c];

 y=table[r+1][c-1];

 z=table[r][c-2];

 if(r == 0 && c == n-1)

 {

 if(max(a[r]+min(x,y),a[c]+min(y,z)) == a[r]+min(x,y))

 flag=true;

 else

 flag= false;

 }

 table[r][c]=max(a[r]+min(x,y),a[c]+min(y,z));

 }

 }

 int player1,player2;

 /*

 cout<<table[0][n-1]<<endl;

 if(flag)

 cout<<table[1][n-1];

 else

 cout<<table[0][n-2]<<endl;

 */

 player1=table[0][n-1];

 player2=(flag)?table[1][n-1]:table[0][n-2];

 if(player1 > player2)

 printf("%s  1 WINS",s1);

 else if(player2 > player1)

 printf("%s  WINS",s2);

 else

 printf("DRAW");

}