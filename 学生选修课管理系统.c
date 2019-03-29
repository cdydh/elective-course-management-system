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
	

struct subjects* read_list()           /* ��������*/
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
		printf("�ļ��򿪴���,����ֹ��������!");
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
 
void savefile(SUB student[])								 /*  ��¼�����Ϣ�������ļ��� */        
{
	FILE *fp;
	int i;
		if((fp=fopen("e:\\subjects.dat","wb"))==NULL)
		{
			printf("open fail!\n");
			exit(0);
		}
		printf("����ѡ�޿γ���Ϣ:\n");
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
	printf("���������Ϣ�ѷ���E�̸�Ŀ¼��\"subjects.dat\"�ļ���\n");
}
 
void savefileadd(SUB *head)								/* ����������Ϣ�������ļ��� */          
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
	printf("�޸ĺ����Ϣ�ѷ���E�̸�Ŀ¼��\"subjects.dat\"�ļ���\n");
}
 
void savefiledel(SUB *head)								/* ��ɾ������ļ��������ļ��� */                
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
	printf("�޸ĺ����Ϣ�ѷ���E�̸�Ŀ¼��\"subjects.dat\"�ļ���\n");
}
 
void savefilechange(SUB student[] , int count)								 /*  ��¼�����Ϣ�������ļ��� */        
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
	printf("���������Ϣ�ѷ���E�̸�Ŀ¼��\"subjects.dat\"�ļ���\n");
}


void Prin(struct subjects student[] ,int count)
{		
	int i=0 ;
	printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��  �Ͽ�ʱ��(������.����)\n");
		for(i=0;i<count;i++)
			printf("%5d%12s%9s%9d%9d%11d%11d%7d%12.1f\n",student[i].num,student[i].name,student[i].kind,student[i].stime,student[i].ttime,student[i].etime,student[i].score,student[i].term,student[i].shijian);
}

void search(SUB student[],int count)									/* ����¼������ */                       
{
	int a,num;
	int t=1;
	int i;
	char type[10];
	char ch='a',ch1;
 
	while(ch!='#')
	{
		printf("��Ҫ���γ����ʲ���������1����Ҫ��ѧ�ֲ���������2:\n");
		scanf("%d",&a);
		switch(a)
	{
		case 1:printf("������Ҫ���ҵĿγ̵�����:\n");
		scanf("%s",type);
		printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��  �Ͽ�ʱ��(������.����)\n");
			for(i=0;i<count;i++)
				if(strcmp(type,student[i].kind)==0)
					{
						printf("%5d%12s%9s%9d%9d%11d%11d%7d%7f\n",student[i].num,student[i].name,student[i].kind,student[i].stime,student[i].ttime,student[i].etime,student[i].score,student[i].term,student[i].shijian);
						t=0;
					}
						if(t) 
							printf("δ�ҵ�!\n");
							t=1;
							break;
		case 2:printf("����Ҫ���ҵĿγ̵�ѧ��\n");
				scanf("%d",&num);
				printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��  �Ͽ�ʱ��(������.����)\n");
		   for(i=0;i<count;i++)
				if(student[i].score==num)
				{
					printf("%5d%12s%9s%9d%9d%11d%11d%7d%7f\n",student[i].num,student[i].name,student[i].kind,student[i].stime,student[i].ttime,student[i].etime,student[i].score,student[i].term,student[i].shijian);
                    t=0;
				}
				if(t) printf("δ�ҵ�!\n");
					t=1;
   
	}
		printf("���������밴�س����������밴#:\n");
		ch1=getchar();                              
		ch=getchar();
	}
}
 

SUB *insert(SUB *head)									/*  ������Ϣ */  
{
	SUB *ptr,*ptr2,*subj;
	int size=sizeof(SUB);
	char ch='a',ch1;
	while(ch!='#')
	{
      subj=(SUB *)malloc(size);
      ptr=subj;
      printf("����Ҫ����Ŀγ���Ϣ:\n");
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
			printf("���������밴�س��������밴#:\n");
            ch1=getchar();                      
            ch=getchar();
    }
	return head;
}
  
 
 
 

SUB *del(SUB *head)                                      /*  ɾ��¼����Ϣ  */                                     
{
	SUB *p1,*p2;
	char ch='a',ch1;
	int num;
	while(ch!=' ')
	{
		printf("������Ҫɾ���Ŀγ̱��:\n");
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
			printf("����ɾ���밴�س��������밴�ո�:\n");
			ch1=getchar();                      
			ch=getchar();
	}
	return head;
}

void change(SUB student[],int count)    /* �޸���Ϣ */
{
	int i , num , t = 0 ;
	printf("��������Ҫ�޸ĵĵĿγ̱�ţ�") ;
	scanf("%d",&num) ;
	for(i=0;i<count;i++)
		{
			if(num==student[i].num)
			{	
				printf("�������޸ĺ���Ϣ") ;
				printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��  �Ͽ�ʱ��(������.����)\n");
				scanf("%d%s%s%d%d%d%d%d%f",&student[i].num,student[i].name,student[i].kind,&student[i].stime,&student[i].ttime,&student[i].etime,&student[i].score,&student[i].term,&student[i].shijian);
				t = 1 ;	
			}
		}
	if(t==0)
	{
		printf("�޴˿γ�") ;
	}
}
 
void choose(SUB student[],int count)                                      /*  ����ѡ��  */                     
{
	int a[10];
	float b[10] ;
	int num,total=0,i=0,j,t,time,m=0,n=0;
	printf("������ѡ��ѧ�ڣ�") ;
	scanf("%d",&time) ;
	printf("����Ҫѡ�޵Ŀγ̵ı�ţ����֮���Կո�ֿ����������0����\n");
	scanf("%d",&num);
		while(num!=0)
		{
			for(t=0;t<count;t++)	 
				if(student[t].num==num)
					{	
						if(student[t].term != time)
							{
								printf("�Բ��𣡣��γ�%d��ѧ��δ����\n",student[t].num) ;
							}
						else{	
								for(m=0;m<i;m++)
								{
									if(b[m]==student[t].shijian)
									{
										printf("�γ�%d�Ϳγ�%dʱ���ͻ\n",student[m].num,student[t].num) ;
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
		if(total<60) printf("ѡ����ѧ��δ�ﵽ60,ѡ��ʧ��!\n");
		if(total>80) printf("ѡ����ѧ�ֽ�ֹ����80,ѡ��ʧ��!\n");
		else 
		{
			printf("ѡ�޳ɹ�!\n");
			printf("��ѡ�޵Ŀγ�Ϊ:\n");
			printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��  �Ͽ�ʱ��(������.����)\n");
		for(j=0;j<i;j++)
			for(t=0;t<count;t++)
				if(student[t].num==a[j])
					printf("%5d%12s%9s%9d%9d%11d%11d%7d%16.1f\n",student[t].num,student[t].name,student[t].kind,student[t].stime,student[t].ttime,student[t].etime,student[t].score,student[t].term,student[t].shijian);
					printf("��ѧ��Ϊ��%d",total) ;
					printf("\n");
		}
}
 
int readfile(struct subjects student[])    /* �������� */
{
	int count=0;
	FILE *fp;
	if((fp=fopen("e:\\subjects.dat","rb"))==NULL)
	{
		printf("�ļ��򿪴���,����ֹ��������!");
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
			printf("                            *   ѡ�޿ι���ϵͳ	 *                               \n");
			printf("                            **********************                               \n");
			printf("                                                                                 \n");
			printf("                       1.�γ���Ϣ¼��        2.�γ���Ϣ���                      \n");
			printf("                       3.�γ���Ϣ����        4.�γ���Ϣ����                      \n");
			printf("                       5.�γ���Ϣɾ��        6.�γ�ѡ��                          \n");
			printf("                       7.�γ���Ϣ�޸�        0.�˳�ϵͳ                          \n");
			printf("����������Ҫִ�еĲ�����");
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
						printf("***************************************************лл����ʹ��********************************************************\n");
						exit(0) ;
				   }
		}
	printf("����ʹ���밴�س����������밴*:\n");
	ch1=getchar();                              
	ch=getchar();
	}
}

		void main()
	{
		menu() ;
		    printf("***************************************************лл����ʹ��********************************************************\n");  
	}