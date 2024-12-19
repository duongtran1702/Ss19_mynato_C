#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	int id;
	char name[30];
	int age;
	char tel[15];
}student;
void enter_list(student **hs,int *n);
void arrange_list(student *hs,int n);
void print_list(student *hs,int n);	
int main(){
	student *sv;
	int n;
	enter_list(&sv,&n);
	arrange_list(sv,n);
	print_list(sv,n);
	return 0;
}

void format_name(char *name){
	size_t len=strlen(name);
	int new_word=1;
	for(int i=0;i<len;i++){
		if(isspace(*(name+i))){
			new_word=1;
		}
		else if(new_word==1){
			*(name+i)=toupper(*(name+i));
			new_word=0;
		}
		else{
			*(name+i)=tolower(*(name+i));
		}
	}
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
		format_name((*hs)[i].name);
		printf("Enter age:");
		scanf("%d",&(*hs)[i].age);
		getchar();
		printf("Enter telephone number:");
		fgets((*hs)[i].tel,30,stdin);
		(*hs)[i].tel[strcspn((*hs)[i].tel,"\n")]='\0';
		printf("\n");	
	}
}
void swap(student *x,student *y){
	student temp=*x;
	*x=*y;
	*y=temp;
}
void arrange_list(student *hs,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(strcmp(hs[j].name,hs[j+1].name)>0){
				swap(&hs[j],&hs[j+1]);	
			}
		}
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


































































































