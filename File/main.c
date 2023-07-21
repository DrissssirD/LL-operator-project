#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct tlpInfo
{
    long telNumber;
    char firstName[12];
    char lastName[12];
};

///-------------------------------------
typedef struct node
{
    struct tlpInfo info;
    struct node *link;
}*nodeptr;
///-------------------------------------


///getnode function---------------------
nodeptr getnode()
{
    nodeptr newnode=(nodeptr)malloc(sizeof(struct node));
    return newnode;

}
///-------------------------------------


///listing function--------------------///
int list(nodeptr head)
{
 nodeptr temp;
 struct tlpInfo p;
 int i=1,cnt=1;

for(temp=head;temp!=NULL;temp=temp->link)
 {

    p=temp->info;
    printf("%d_ %ld %s %s\n",cnt,p.telNumber,p.firstName,p.lastName);

    if(i==30)
    {
        getchar();
        i=1;
    }
    cnt++;
    i++;
 }
}
///------------------------------------///


///----------ascending-sort(by number)------------///
void Numberassort(nodeptr head)
{
nodeptr index=getnode(),x=getnode();
x=head;
struct tlpInfo save;
    while(x != NULL)
            {

                index = x->link;
                while(index != NULL)
                    {

                    if( x->info.telNumber>index->info.telNumber)
                        {
                        save=x->info;
                        x->info=index->info;
                        index->info=save;
                        }
                    index = index->link;
                    }
                x = x->link;
            }

}
///---------------------------------------------------------///


///------------------ascending order by name---------------///
void Nameassort(nodeptr head)
{
nodeptr index=getnode(),x=getnode();
x=head;
struct tlpInfo save;
while(x != NULL)
            {

                index = x->link;
                while(index != NULL)
                    {

                    if( strcmp(x->info.firstName,index->info.firstName)>0)
                        {
                        save=x->info;
                        x->info=index->info;
                        index->info=save;
                        }
                    index = index->link;
                    }
                x = x->link;
            }
x=head;
while(x != NULL)
            {

                index = x->link;
                while(index != NULL)
                    {

                    if( strcmp(x->info.firstName,index->info.firstName)==0&&strcmp(x->info.lastName,index->info.lastName)>0)
                        {
                        save=x->info;
                        x->info=index->info;
                        index->info=save;
                        }
                    index = index->link;
                    }
                        ///
                        ///&&strcmp(x->info.lastName,index->info.lastName)>0

                x = x->link;
            }
}
///---------------------------------------------------------------------///



///-------------------------insertion-function--------------------------///

nodeptr insertion(nodeptr head,struct tlpInfo n)
{
nodeptr x=head,before,after,temp=getnode();
temp->info=n;
Numberassort(head);
while(x!=NULL)
{
    before=x;
    after=x->link;
    if(x->info.telNumber<n.telNumber)
    {
     before->link=temp;
     temp->link=after;
     break;
    }
    if(x->info.telNumber>n.telNumber&& x==head)
    {
        head=temp;
        temp->link=x;
    }
    if(x->info.telNumber==n.telNumber)
    {
        printf("\nnumber already exists!");
        exit(1);
    }


    x=x->link;
}
list(head);

return head;
}
///---------------------------------------------------------------------///

///------------------------------search by full name---------------------------------///

nodeptr srchName(nodeptr head,struct tlpInfo n)
{
    nodeptr x=getnode();
    struct tlpInfo temp;
    x=head;
    int flag =0;


     while(x != NULL)
     {
         temp=x->info;

         if(strcmp(temp.firstName,n.firstName)==0 && strcmp(temp.lastName,n.lastName)==0)
         {
             flag=1;
             return x;
             break;
         }


        x=x->link;
     }
     if (flag==0)
     {
         printf("We couldn't find the member!\n");

     }
}
///---------------------------------------------------------------------///


///----------------------------delete-by-number-------------------------------///
nodeptr dlt(nodeptr head,long n)
{
    nodeptr bnode,temp;
    char choice[3];
    int flag =0;
    temp = head;

     while(temp != NULL)
     {
         if(temp->info.telNumber==n)
         {
             printf("we found the user with the number: %ld, name: %s, surname: %s\n\n",temp->info.telNumber,temp->info.firstName,temp->info.lastName);
             printf("do you still want to delete it? 'yes/no'\n");scanf("%s",&choice);
             if(strcmp(choice,"yes")==0);
                    {
                        if (temp==head)
                        {
                            head=head->link;
                            printf("user has been deleted!\n\n");
                            free(temp);
                            flag=1;
                            break;
                        }
                        else
                        {
                            bnode->link=temp->link;
                            free(temp);
                            flag=1;
                            break;
                        }
                        printf("user has been deleted!\n\n");
                    }
             if(strcmp(choice,"no")==0)
                    printf("alright \4");
                    flag=1;
                    break;
             }
        bnode=temp;
        temp=temp->link;
    }
        if (flag==0)
            {
                printf("We couldn't find the number!\n");
            }
        return head;
}
///---------------------------------------------------------------------///




///------------------main-function------------------///
int main()
{
nodeptr head=getnode(),save,p;
head=NULL;
int choice=99;
long n;
struct tlpInfo temp;///the reason i didn't write a function for this operation is that i don't get the head address back
FILE *a=fopen("D:\\UNIV\\FIU\\3rd SEMESTER\\ALGORITHMS AND DATA STRUCTERS\\LABS\\ASSIGNMENTS\\assignment2\\telephone.txt","r");///declaring and opening a file

///reding file intoLL------------------------------///

while(fscanf(a,"%ld %s %s\n",&temp.telNumber, temp.firstName, temp.lastName)!=EOF)
{
    p=getnode();
    p->info=temp;

    if (head==NULL)
    {
        head=p;
        save=p;
    }
    else{
        save->link=p;
        save=p;
    }
}
p->link=NULL;

///---------------------------------------------------------------------///
list(head);
printf("%45s\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n%45s\4Welcome to LL-Operator\3\4\n%45s\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n"," "," "," ");

///---------------------------MENU--------------------------------------///
printf("\n\n%35s ------------------------------------------\n%35s| press any key to see the operations menu |\n%35s ------------------------------------------\n"," "," "," ");
getchar();
while(choice!=0)
{
printf("\n\n%40s\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n%40s\4 1_Ascending order(by number)   \4\n%40s\4 2_Ascending order(by full name)\4\n%40s\4 3_Insertion                    \4\n%40s\4 4_Search(Full Name)            \4\n%40s\4"," "," "," "," "," "," ");
printf(" 5_deletion                     \4\n%40s\4 0_Exit                         \4\n%40s\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4"," "," ");
printf("\n\nEnter Choice: ");scanf("%d",&choice);

struct tlpInfo neww;
neww.telNumber=0000000;
switch (choice)
    {
    case 1:
    ///--------------------------ascending-order(number)--------------------------///
        printf("\n\nAscending order done...\n\n");
        printf("press to list the content:\n\n");
        getchar();
        getchar();
        Numberassort(head);
        list(head);
        break;
    ///---------------------------------------------------------------------///
    case 2:
     ///--------------------------ascending-order(full name)--------------------------///
        printf("\n\nAscending order done...\n\n");
        printf("press to list the content:\n\n");
        getchar();
        Nameassort(head);
        list(head);
        break;
     ///---------------------------------------------------------------------///

    case 3:
     ///---------------------------Insertion--------------------------------///
        printf("\n\nEnter your informations(Num[6],Name[12],Surname[12]): ");scanf("%ld %s %s",&neww.telNumber,&neww.firstName,&neww.lastName);
        head = insertion(head,neww);
        break;
     ///--------------------------------------------------------------------///

    case 4:
     ///-------------------------------Search-------------------------------///
        printf("\n\nEnter Name & Surname(Name[12],Surname[12]): ");scanf("%s %s",&neww.firstName,&neww.lastName);
        save = srchName(head,neww);
        neww = save->info;
        printf("We found it!\n\nUser number: %ld\nUser name: %s\nUser surname: %s\n\n",neww.telNumber,neww.firstName,neww.lastName);
        Nameassort(head);
        break;
     ///--------------------------------------------------------------------///
    case 5:
     ///-------------------------------Delete-------------------------------///
        printf("\n\nEnter the number you want to delete: ");scanf("%ld",&n);
        head = dlt(head,n);
        list(head);

        break;
    ///--------------------------------------------------------------------///
    }
}


///how to assign a new address to the head after sortation????????????????

return 0;
}
