#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subjects
{
	int num;                 
	char name[20];         
	char kind[8];          
	int stime;               
	int ttime;               
	int etime;               
	int score;               
	int term;
	float shijian ;
	struct subjects *next;
}SUB;
	

struct subjects* read_list()           /* 读入链表*/
{
	FILE *fp;
	struct subjects *head,*p1,*p2;
	head=NULL;
	p1=p2=(struct subjects *)malloc(sizeof(struct subjects));
			{
				p1->num=0 ;
				p1->name[0]='\0';
				p1->kind[0]='\0';
				p1->stime=0 ;
				p1->ttime=0 ;
				p1->etime=0 ;
				p1->score=0 ;
				p1->term=0  ;
				p1->shijian=0 ;
			}
	if((fp=fopen("e:\\subjects.dat","rb"))==NULL)
	{
		printf("文件打开错误,请终止程序运行!");
		exit(0);
	}
	while(!feof(fp))
	{
			if(head==NULL)
			{
				head=p1;
			}
			else
			{
				p2->next=p1;
			}
		p2=p1;
		p1=(struct subjects *)malloc(sizeof(struct subjects));
			{
				p1->num=0 ;
				p1->name[0]='\0';
				p1->kind[0]='\0';
				p1->stime=0 ;
				p1->ttime=0 ;
				p1->etime=0 ;
				p1->score=0 ;
				p1->term=0  ;
				p1->shijian=0 ;
			}
			fread(p1,56,1,fp) ;
	}
	p2->next=NULL;
		if(fclose(fp))
		{
			printf("close fail!\n");
			exit(0);
		}
	return head;
}
 
void savefile(SUB student[])								 /*  将录入的信息保存至文件中 */        
{
	FILE *fp;
	int i;
		if((fp=fopen("e:\\subjects.dat","wb"))==NULL)
		{
			printf("open fail!\n");
			exit(0);
		}
		printf("输入选修课程信息:\n");
		for(i=0;;i++)
		{
			scanf("%d%s%s%d%d%d%d%d%f",&student[i].num,student[i].name,student[i].kind,&student[i].stime,&student[i].ttime,&student[i].etime,&student[i].score,&student[i].term,&student[i].shijian);
			if(student[i].num==0)
			{
				break;
			}
			fwrite(&student[i],56,1,fp);
		}
		if(fclose(fp))
		{
			printf("close fail!\n");
			exit(0);
		}
	printf("创建后的信息已放入E盘根目录的\"subjects.dat\"文件中\n");
}
 
void savefileadd(SUB *head)								/* 将插入后的信息保存至文件中 */          
{
	SUB *p;
	FILE *fp;
		if((fp=fopen("e:\\subjects.dat","wb"))==NULL)
		{
			printf("open fail!\n");
			exit(0);
		}
		for(p=head->next;p;p=p->next)
			fwrite(p,56,1,fp);
		if(fclose(fp))
		{
			printf("close fail!\n");
			exit(0);
		}
	printf("修改后的信息已放入E盘根目录的\"subjects.dat\"文件中\n");
}
 
void savefiledel(SUB *head)								/* 将删除后的文件保存至文件中 */                
{
	SUB *p;
	FILE *fp;
		if((fp=fopen("e:\\subjects.dat","wb"))==NULL)
		{
			printf("open fail\n");
			exit(0);
		}

		for(p=head->next;p;p=p->next)
			fwrite(p,56,1,fp);
		if(fclose(fp))
		{
			printf("close fail!\n");
			exit(0);
		}
	printf("修改后的信息已放入E盘根目录的\"subjects.dat\"文件中\n");
}
 
void savefilechange(SUB student[] , int count)								 /*  将录入的信息保存至文件中 */        
{
	FILE *fp;
	int i;
		if((fp=fopen("e:\\subjects.dat","wb"))==NULL)
		{
			printf("open fail!\n");
			exit(0);
		}
		for(i=0;i<count;i++)
		{
			fwrite(&student[i],56,1,fp);
		}
		if(fclose(fp))
		{
			printf("close fail!\n");
			exit(0);
		}
	printf("创建后的信息已放入E盘根目录的\"subjects.dat\"文件中\n");
}


void Prin(struct subjects student[] ,int count)
{		
	int i=0 ;
	printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期  上课时间(星期数.节数)\n");
		for(i=0;i<count;i++)
			printf("%5d%12s%9s%9d%9d%11d%11d%7d%12.1f\n",student[i].num,student[i].name,student[i].kind,student[i].stime,student[i].ttime,student[i].etime,student[i].score,student[i].term,student[i].shijian);
}

void search(SUB student[],int count)									/* 查找录入内容 */                       
{
	int a,num;
	int t=1;
	int i;
	char type[10];
	char ch='a',ch1;
 
	while(ch!='#')
	{
		printf("若要按课程性质查找请输入1，若要按学分查找请输入2:\n");
		scanf("%d",&a);
		switch(a)
	{
		case 1:printf("请输入要查找的课程的性质:\n");
		scanf("%s",type);
		printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期  上课时间(星期数.节数)\n");
			for(i=0;i<count;i++)
				if(strcmp(type,student[i].kind)==0)
					{
						printf("%5d%12s%9s%9d%9d%11d%11d%7d%7f\n",student[i].num,student[i].name,student[i].kind,student[i].stime,student[i].ttime,student[i].etime,student[i].score,student[i].term,student[i].shijian);
						t=0;
					}
						if(t) 
							printf("未找到!\n");
							t=1;
							break;
		case 2:printf("输入要查找的课程的学分\n");
				scanf("%d",&num);
				printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期  上课时间(星期数.节数)\n");
		   for(i=0;i<count;i++)
				if(student[i].score==num)
				{
					printf("%5d%12s%9s%9d%9d%11d%11d%7d%7f\n",student[i].num,student[i].name,student[i].kind,student[i].stime,student[i].ttime,student[i].etime,student[i].score,student[i].term,student[i].shijian);
                    t=0;
				}
				if(t) printf("未找到!\n");
					t=1;
   
	}
		printf("继续查找请按回车键，结束请按#:\n");
		ch1=getchar();                              
		ch=getchar();
	}
}
 

SUB *insert(SUB *head)									/*  插入信息 */  
{
	SUB *ptr,*ptr2,*subj;
	int size=sizeof(SUB);
	char ch='a',ch1;
	while(ch!='#')
	{
      subj=(SUB *)malloc(size);
      ptr=subj;
      printf("输入要插入的课程信息:\n");
      scanf("%d%s%s%d%d%d%d%d%f",&subj->num,subj->name,subj->kind,&subj->stime,&subj->ttime,&subj->etime,&subj->score,&subj->term,&subj->shijian);
       if(head==NULL)
	   {
         head=ptr;
         head->next=NULL;
	   }
       else
	   {
          for(ptr2=head;ptr2;ptr2=ptr2->next)
             if(ptr2->next==NULL)
			 {
				ptr2->next=subj;
				subj->next=NULL;
				break;
			 }
	   }
			printf("继续插入请按回车，结束请按#:\n");
            ch1=getchar();                      
            ch=getchar();
    }
	return head;
}
  
 
 
 

SUB *del(SUB *head)                                      /*  删除录入信息  */                                     
{
	SUB *p1,*p2;
	char ch='a',ch1;
	int num;
	while(ch!=' ')
	{
		printf("输入想要删除的课程编号:\n");
		scanf("%d",&num);
		if(head->num==num)
		{
			p2=head;
			head=head->next;
			free(p2);
		}
		if(head==NULL)
			return NULL;
			p1=head;
			p2=head->next;
     while(p2)
		{
			if(p2->num==num)
			{
				p1->next=p2->next;
				free(p2);
			}
			else p1=p2;
			p2=p1->next;
		}
			printf("继续删除请按回车，结束请按空格:\n");
			ch1=getchar();                      
			ch=getchar();
	}
	return head;
}

void change(SUB student[],int count)    /* 修改信息 */
{
	int i , num , t = 0 ;
	printf("请输入想要修改的的课程编号：") ;
	scanf("%d",&num) ;
	for(i=0;i<count;i++)
		{
			if(num==student[i].num)
			{	
				printf("请输入修改后信息") ;
				printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期  上课时间(星期数.节数)\n");
				scanf("%d%s%s%d%d%d%d%d%f",&student[i].num,student[i].name,student[i].kind,&student[i].stime,&student[i].ttime,&student[i].etime,&student[i].score,&student[i].term,&student[i].shijian);
				t = 1 ;	
			}
		}
	if(t==0)
	{
		printf("无此课程") ;
	}
}
 
void choose(SUB student[],int count)                                      /*  进行选课  */                     
{
	int a[10];
	float b[10] ;
	int num,total=0,i=0,j,t,time,m=0,n=0;
	printf("请输入选课学期：") ;
	scanf("%d",&time) ;
	printf("输入要选修的课程的编号，编号之间以空格分开，输完后以0结束\n");
	scanf("%d",&num);
		while(num!=0)
		{
			for(t=0;t<count;t++)	 
				if(student[t].num==num)
					{	
						if(student[t].term != time)
							{
								printf("对不起！，课程%d本学期未开课\n",student[t].num) ;
							}
						else{	
								for(m=0;m<i;m++)
								{
									if(b[m]==student[t].shijian)
									{
										printf("课程%d和课程%d时间冲突\n",student[m].num,student[t].num) ;
										n=1 ;
										break ;
									}
								}
								if(n==0)
								{
									total=total+student[t].score;
									a[i]=num;
									b[i]=student[t].shijian ;
									i++;
								}
							}
					}
				scanf("%d",&num);
		}
		if(total<60) printf("选修总学分未达到60,选修失败!\n");
		if(total>80) printf("选修总学分禁止超过80,选修失败!\n");
		else 
		{
			printf("选修成功!\n");
			printf("您选修的课程为:\n");
			printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期  上课时间(星期数.节数)\n");
		for(j=0;j<i;j++)
			for(t=0;t<count;t++)
				if(student[t].num==a[j])
					printf("%5d%12s%9s%9d%9d%11d%11d%7d%16.1f\n",student[t].num,student[t].name,student[t].kind,student[t].stime,student[t].ttime,student[t].etime,student[t].score,student[t].term,student[t].shijian);
					printf("总学分为：%d",total) ;
					printf("\n");
		}
}
 
int readfile(struct subjects student[])    /* 读入数组 */
{
	int count=0;
	FILE *fp;
	if((fp=fopen("e:\\subjects.dat","rb"))==NULL)
	{
		printf("文件打开错误,请终止程序运行!");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&student[count],56,1,fp);
		count++;
	}
	count--;
	fclose(fp);
	return count;
}

void menu()
{	
	SUB *head;
	SUB student[10];
	char ch='a',ch1;
	int a ;
	int count=0;
	while(ch!='*')
	{	
			system("cls") ;
		{
			printf("                            **********************                               \n");
			printf("                            *   选修课管理系统	 *                               \n");
			printf("                            **********************                               \n");
			printf("                                                                                 \n");
			printf("                       1.课程信息录入        2.课程信息输出                      \n");
			printf("                       3.课程信息查找        4.课程信息插入                      \n");
			printf("                       5.课程信息删除        6.课程选修                          \n");
			printf("                       7.课程信息修改        0.退出系统                          \n");
			printf("请输入您想要执行的操作：");
		}
		scanf("%d",&a);
		switch(a)
		{	
			case 1:	{
						savefile(student);
						break ;
					}
			case 2:		count=readfile(student) ;
						Prin(student,count); break ;
			case 3:	{	
						count=readfile(student) ;
						search(student,count); 
						break ;
					}
			case 4: 
					{	head=read_list() ;
						head=insert(head);
						savefileadd(head);
						break ;
					}
			case 5:	
					{	head=read_list() ;
						head=del(head);                           
						savefiledel(head);
						break ;
					}
			case 6:	{	
						count=readfile(student) ;
						choose(student,count); 
						break ;
					}
			case 7: {	
						count=readfile(student) ;
						change(student,count) ;
						savefilechange(student,count) ;
						break ;
					}
			case 0:{	
						printf("***************************************************谢谢您的使用********************************************************\n");
						exit(0) ;
				   }
		}
	printf("继续使用请按回车键，结束请按*:\n");
	ch1=getchar();                              
	ch=getchar();
	}
}

		void main()
	{
		menu() ;
		    printf("***************************************************谢谢您的使用********************************************************\n");  
	}