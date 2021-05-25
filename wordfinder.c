#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
struct node
{
char data[30];
char m[10][20];
int count;
struct node *link;
};
struct node *find[30];
void addfind(char *);
int search(char *);
void showfind();
void delfind();
void main()
{
char word[20];
int ch;
int i;
while(1)
{
printf("word finder \n");
printf("ENTER YOUR CHOICE \n");
printf("1 add the word \n 2 search the word \n 3 show the list of the word finder\n 4 delete the word \n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter the word \n");
scanf("%s",&word);
addfind(word);
break;
case 2:
printf("enter the word to be search \n");
scanf("%s",&word);
i=search(word);
if(!i)
printf("word does not exist \n ");
getch();
break;
case 3:
showfind();
getch();
break;
case 4:
printf("The wordfinder is deleted create a new word finder or prees 5 to go bac \n");
delfind();
break;
case 5:
break;
default:
printf("invalid choice \n");
}
}
}
void addfind(char *str)
{
int i,j=toupper(str[0])-65;
struct node *r,*temp=find[j],*q;
char meaning[5][20],ch='y';
i=search(str);
if(i)
{
printf("word already exists \n");
getch();
return;
}
q=(struct node*)malloc(sizeof(struct node));
strcpy(q->data,str);
q->link=NULL;
for(i=0;tolower(ch)=='y'&&i<3;i++)
{
printf("  add the meanings \n");
scanf("%s",&meaning[i]);
strcpy(q->m[i],meaning[i]);
if(i!=2)
printf(" do you want to add more meanings yes(Y)/no(n) \n");
else
printf("sorry you cannot enter more than 3 meanings\n");
ch=getche();
}
q->count=i;
if(find[j]==NULL||strcmp(find[j]->data,str)>0)
{
r=find[j];
find[j]=q;
q->link=r;
return;
}
else
{
while(temp!=NULL)
{
if((strcmp(temp->data,str)<0)&&((strcmp(temp->link->data,str)>0)||temp->link==NULL))
{
q->link=temp->link;
temp->link=q;
return;
}
temp=temp->link;
}
}
}
int search(char *str)
{
struct node *n;
char temp1[20];
char temp2[20];
int i;
n =find[toupper(str[0])-65];
strcpy(temp2,str);
strupr(temp2);
while(n!=NULL)
{
strcpy(temp1, n->data);
if(strcmp(strupr(temp1),temp2)==0)
{            printf("\n%s\t\t%s",n->data,n->m[0]);
for(i=1;i<n->count;i++)
printf("\n\t\t%s",n->m[i]);
return 1;
}
n=n->link;
}
return 0;
}
void showfind()
{
struct node *n;
int i,j;
printf("word\t\tmeaning\n");
for(i=0;i<=30;i++)
printf("-");
for(i=0;i<=25;i++)
{
n=find[i];
while(n!=NULL)
{
printf("\n%s\t\t%s",n->data,n->m[0]);
for(j=1;j<n->count;j++)
printf("\n\t\t%s",n->m[j]);
n=n->link;
}
}
}
void delfind()
{
struct node *n,*t;
int i;
for(i=0;i<=25;i++)
{
n=find[i];
while(n!=NULL)
{
t=n->link;
free(n);
n=t;
}
}
}
