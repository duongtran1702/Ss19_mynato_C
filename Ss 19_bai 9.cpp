#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Admin{
	int id;
	char name[30];
	int age;
	char tel[15];
}student;
void enter_list(student **hs,int *n);
void delete_student(student **hs,int*n);
void print_list(student *hs,int n);	
void show_menu();
void format_name(char *name);
void update_list(student *sv,int n);
void search_student(student *sv,int n);
void add_student(student **sv,int *n);
void arrange_list(student *hs,int n);
int main(){
	student *sv;
	int n;
	enter_list(&sv,&n);
	do{
		show_menu();
		int choice;
		printf("Enter your choice :");
		scanf("%d",&choice);
		getchar();
		if(choice==1){
			print_list(sv,n);
		}
		else if(choice==2){
			add_student(&sv,&n);	
		}
		else if(choice==3){
			update_list(sv,n);
		}
		else if(choice==4){
			delete_student(&sv,&n);
		}
		else if(choice==5){
			search_student(sv,n);
		}
		else if(choice==6){
			arrange_list(sv,n);
		}
		else if(choice==7){
			printf("Exit !");
			free(sv);
			return 0;
		}
		else {
			printf("Invalid choice !\n");
		}
	}while(1);
	return 0;
}
void show_menu() {
    printf("\n===== Menu =====\n");
    printf("1. Print list\n");
    printf("2. Add student\n");
    printf("3. Update student\n");
    printf("4. Delete student\n");
    printf("5. Search student\n");
    printf("6. Arrange student\n");
    printf("7. Exit\n");
    printf("================\n");
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

void delete_student(student **hs,int*n){
	int flag=0;
	int id;
	printf("Enter the ID you want to delete :");
	scanf("%d",&id);
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

void format_name(char *name){
	int new_word=1;
	size_t len=strlen(name);
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

void add_student(student **sv,int *n){
	*n+=1;
	*sv=(student*)realloc(*sv,*n*sizeof(student));
	printf("New student:\n");
	printf("Enter id:");
	scanf("%d",&(*sv)[*n-1].id);
	getchar();
	printf("Enter name :");
	fgets((*sv)[*n-1].name,30,stdin);
	(*sv)[*n-1].name[strcspn((*sv)[*n-1].name,"\n")]='\0';
	format_name((*sv)[*n-1].name);
	printf("Enter age:");
	scanf("%d",&(*sv)[*n-1].age);
	getchar();
	printf("Enter telephone number:");
	fgets((*sv)[*n-1].tel,11,stdin);
	(*sv)[*n-1].tel[strcspn((*sv)[*n-1].tel,"\n")]='\0';
	printf("\n");
}

void update_list(student *sv,int n){
	int flag=0;
	printf("Enter the id you want to fix information:");
	int id;
	scanf("%d",&id);
	getchar();
	for(int i=0;i<n;i++){
		if(sv[i].id==id){
			flag=1;
			printf("Id sudent %d:\n",sv[i].id);
			printf("Name :%s\n",(*(sv+i)).name);
			printf("Age :%d\n",(*(sv+i)).age);
			printf("Tel :%s\n",(*(sv+i)).tel);
			printf("\n");
			printf("\nUpdate information of student id %d:\n",id);
			printf("Update name :");
			fgets(sv[i].name,30,stdin);
			sv[i].name[strcspn(sv[i].name,"\n")]='\0';
			format_name(sv[i].name);
			printf("Update age:");
			scanf("%d",&sv[i].age);
			getchar();
			printf("Update telephone number:");
			fgets(sv[i].tel,11,stdin);
			sv[i].tel[strcspn(sv[i].tel,"\n")]='\0';
			printf("\n");
		}
	}
	if(flag==0){
		printf("ID does not exist!\n");
		printf("\n");
	}
}

void search_student(student *sv,int n){
	int flag=0;
	int id;
	printf("Enter id you want to find :");
	scanf("%d",&id);
	getchar();
	for(int i=0;i<n;i++){
		if(sv[i].id==id){
			flag=1;
			printf("Id sudent %d:\n",sv[i].id);
			printf("Name :%s\n",(*(sv+i)).name);
			printf("Age :%d\n",(*(sv+i)).age);
			printf("Tel :%s\n",(*(sv+i)).tel);
			printf("\n");
		}
	}
	if(flag==0){
		printf("ID does not exist!\n");
		printf("\n");
	}
}




