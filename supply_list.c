/*HUY DUONG 
this program will sort and output all the supply in the list into the new file */
#include <stdio.h>
#include <string.h>
#define MAX 100
struct supply{//create a structure	
    char color[MAX];
    char name[MAX];
    int quantity;
};
void selection_sort(struct supply list[],int n);
int main(){
    char file_name[MAX];//user input file name
    printf("Enter the input file name: ");
    scanf("%s",file_name);
    char new_name[100]="sorted_";//
    char *fname= strcat(new_name,file_name);
    FILE *rf=fopen(file_name,"r");//create file read file
    FILE *wf=fopen(fname,"w");//create file to write file
    if(rf==NULL){//if file not open then exit the program
        printf("The name of the file is invalid.");
        return 1;
    }
    struct supply list[200];
    int i=0;
    while(!feof(rf)&&!ferror(rf)){//checking end of the file
        fscanf(rf,"%s %d %[^\n]\n",list[i].color, &list[i].quantity,list[i].name);
        i++;
    }
    selection_sort(list,i);//recall the sort function
    int j;
    for(j=0;j<i;j++){
        fprintf(wf,"%-10s\t%-5d\t%-15s\n",list[j].color, list[j].quantity,list[j].name);
    }
    fclose(rf);//close the read file
    fclose(wf);//close the write file
    return 1;
}
void selection_sort(struct supply list[],int n){//mofify the sort function
    int i, last=0;
    struct supply temp;
    if(n==1) 
	return;
    for(i=0;i<n;i++){//sort the function
        if(strcmp(list[last].name,list[i].name)<0)    
		last=i;
    }
    if(last<n-1){//swap the function and move largest to the last postion 
        temp=list[n-1];
        list[n-1]=list[last];
        list[last]=temp;
    }
    selection_sort(list,n-1);
}
