#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int id;
	char name[30];
	int age;
	char tel[15];
}student;
void enter_list(student **hs,int *n);
void delete_student(student **hs,int*n,int id);
void print_list(student *hs,int n);	
int main(){
	student *sv;
	int n;
	enter_list(&sv,&n);
	int id;
	printf("Enter the ID you want to delete :");
	scanf("%d",&id);
	getchar();
	delete_student(&sv,&n,id);
	print_list(sv,n);
	return 0;
}
void enter_list(student **hs,int *n){
	printf("Enter the number of students :");
	scanf("%d",n);
	if(*n<1){
		printf("Invalid number of students!");
		exit(1);
	}
	*hs=(student*)calloc(*n,sizeof(student));
	if(*hs==NULL){
		printf("Memory allocation failed!");
		exit(1);
	}
	for(int i=0;i<*n;i++){
		printf("Enter information of student %d:\n",i+1);
		printf("Enter id:");
		scanf("%d",&(*hs)[i].id);
		getchar();
		printf("Enter name:");
		fgets((*hs)[i].name,30,stdin);
		(*hs)[i].name[strcspn((*hs)[i].name,"\n")]='\0';
		printf("Enter age:");
		scanf("%d",&(*hs)[i].age);
		getchar();
		printf("Enter telephone number:");
		fgets((*hs)[i].tel,30,stdin);
		(*hs)[i].tel[strcspn((*hs)[i].tel,"\n")]='\0';
		printf("\n");	
	}
}

void delete_student(student **hs,int*n,int id){
	int flag=0;
	for(int i=0;i<*n;i++){
		if((*hs)[i].id==id){
			flag=1;
			for(int j=i;j<*n-1;j++){
				(*hs)[j]=(*hs)[j+1];
			}
			*n-=1;
			break;
		}
	}
	if(flag==0){
		printf("This ID does not exist!\n");
	}
	else{
	*hs=(student*)realloc(*hs,*n*sizeof(student));
	printf("Delete student successfully !\n");
	}
}

void print_list(student *hs,int n){
	printf("\nList student:\n");
	printf("------------------------------------\n");
	for(int i=0;i<n;i++){
		printf("Student %d:\n",i+1);
		printf("Id: %d\n",hs[i].id);
		printf("Name: %s\n",hs[i].name);
		printf("Age: %d\n",hs[i].age);
		printf("Tel: %s\n",hs[i].tel);
		printf("------------------------------------\n");
	}
}


































































































