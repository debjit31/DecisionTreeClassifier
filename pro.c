#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
		char  *data;
		struct Node *left, *mid, *right;
}node;
node *age, *youth, *middle, *senior, *stu_yes, *stu_no, *mid_yes, *cr_fair, *cr_excellent;
void decision_tree_construction()
{
			age = (node*)malloc(sizeof(node));				/*Manual assignment of data to the various*/
			youth = (node*)malloc(sizeof(node));			/*nodes and linking of the different nodes of*/
			middle = (node*)malloc(sizeof(node));			/*as per the predicted decision tree model. */
			senior = (node*)malloc(sizeof(node));			/*Concepts of Entropy and information gain is used*/
			stu_yes = (node*)malloc(sizeof(node));			/*to predict the model decision tree.*/		
			stu_no = (node*)malloc(sizeof(node));			/*All decisions in the program are made on the basis of*/
			mid_yes = (node*)malloc(sizeof(node));			/*the pre-defined model.*/
			cr_fair = (node*)malloc(sizeof(node));
			cr_excellent = (node*)malloc(sizeof(node));
			age->data="age";
			youth->data="youth";
			middle->data="middle";
			senior->data="senior";
			stu_yes->data="yes";
			stu_no->data="no";
			mid_yes->data="yes";
			cr_fair->data="yes";
			cr_excellent->data="no";
			age->left=youth;
			age->mid=middle;
			age->right=senior;
			youth->left=stu_yes;
			youth->mid=stu_no;
			youth->right=NULL;
			middle->left=mid_yes;
			middle->mid=NULL;
			middle->right=NULL;
			senior->left=cr_fair;
			senior->mid=cr_excellent;
			senior->right=NULL;
			stu_yes->left=NULL;
			stu_yes->mid=NULL;
			stu_yes->right=NULL;
			stu_no->left=NULL;
			stu_no->mid=NULL;
			stu_no->right=NULL;
			mid_yes->left=NULL;
			mid_yes->mid=NULL;
			mid_yes->right=NULL;
			cr_fair->left=NULL;
			cr_fair->mid=NULL;
			cr_fair->right=NULL;
			cr_excellent->left=NULL;
			cr_excellent->mid=NULL;
			cr_excellent->right=NULL;
}
void decision_making(char in_age[10],char in_income[10],char in_student[10],char in_creditrating[10])
{
	node *ptr, *ptr1;
	while(1)
	{
		ptr=age;
		ptr1=age;
		if(strcmp(in_age,"youth")==0)
		{
			ptr1=ptr;
			ptr=ptr->left;
			if(strcmp(in_student,"yes")==0)
			{
				ptr1=ptr;
				ptr = ptr->left;
				if(ptr->left == NULL && ptr->mid == NULL && ptr->right == NULL)
				{
					printf("\n%s is the final predicted class",ptr->data);
					printf("\nYou will buy a computer.");
					break;
				}
			}
			else if(strcmp(in_student,"no")==0)
			{
				ptr1=ptr;
				ptr = ptr->mid;
				if(ptr->left == NULL && ptr->mid == NULL && ptr->right == NULL)
				{
					printf("\n%s is the final predicted class",ptr->data);
					printf("\nYou will not buy a computer.");
					break;
				}
			}
		}
		else if(strcmp(in_age,"middle")==0)
		{
			ptr1=ptr;
			ptr = ptr->mid;
			printf("\n%s is the final predicted class",ptr->left->data);
			printf("\nYou will buy a computer");
			break;
		}
		else if(strcmp(in_age,"senior")==0)
		{
			ptr1=ptr;
			ptr=ptr->right;
			if(strcmp(in_creditrating,"fair")==0)
			{
				ptr1=ptr;
				ptr=ptr->left;
				if(ptr->left == NULL && ptr->mid == NULL && ptr->right == NULL)
				{
					printf("\n%s is the final predicted class",ptr->data);
					printf("\nYou will buy a computer.");
					break;
				}
			}
			else if(strcmp(in_creditrating,"excellent")==0)
			{
				ptr1=ptr;
				ptr=ptr->mid;
				if(ptr->left == NULL && ptr->mid == NULL && ptr->right == NULL)
				{
					printf("\n%s is the final predicted class",ptr->data);
					printf("\nYou will not buy a computer.");
					break;
				}
			}
		}
	}
	
}
int main()
{
	

	decision_tree_construction();
	char in_age[10],in_income[10], in_student[10], in_creditrating[10];
	int ch;
	printf("\t---------------------------Welcome to the Decision Tree Classifier-------------------------------\n\n");
	while(1)
	{
		
		printf("\nDo you want to do the prediction ? Press 1 for yes and 0 for no :- ");
		scanf("%d",&ch);
		if(ch == 1)
		{
			fflush(stdin);
			printf("\nIn which age group do you belong ? Youth, middle or senior ? ");
			gets(in_age);
			if(strcmp(in_age,"youth")!=0&&strcmp(in_age,"middle")!=0&&strcmp(in_age,"senior")!=0)
			{
				printf("\nWrong Innput!!!!");
				fflush(stdin);
				printf("\nIn which age group do you belong ? Youth, middle or senior ? ");
				gets(in_age);
			}
			fflush(stdin);
			printf("\nIs your income high, medium or low ?");
			gets(in_income);
			if(strcmp(in_income,"high")!=0&&strcmp(in_income,"medium")!=0&&strcmp(in_income,"low")!=0)
			{
				printf("\nWrong Innput!!!!");
				fflush(stdin);
				printf("\nIs your income high, medium or low ?");
				gets(in_income);
			}
			fflush(stdin);
			printf("\nAre you a student ? Write Yes or No :- ");
			gets(in_student);
			if(strcmp(in_student,"yes")!=0&&strcmp(in_student,"no")!=0)
			{
				printf("\nWrong Innput!!!!");
				fflush(stdin);
				printf("\nAre you a student ? Write Yes or No :- ");
				gets(in_student);
			}
			fflush(stdin);
			printf("\nIs your credit rating fair or excellent ? ");
			gets(in_creditrating);
			if(strcmp(in_creditrating,"fair")!=0&&strcmp(in_creditrating,"excellent")!=0)
			{
				printf("\nWrong Innput!!!!");
				fflush(stdin);
				printf("\nIs your credit rating fair or excellent ? ");
				gets(in_creditrating);
			}
			decision_making(in_age,in_income,in_student,in_creditrating);
		}
		else if(ch == 0)
		{
			printf("\nThank You!!!!");
			break;
			exit(0);
		}
		else if(ch != 1 && ch != 0)
		{
			printf("\nWrong Input!!!!!");
			continue;
		}
	}
}
