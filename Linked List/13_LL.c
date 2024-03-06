#include <stdio.h>
void traversing(int *data , int *link , int *start){
    int ptr = *start;
    while (ptr!=-1){
        printf("%d -> ",data[ptr]);
        ptr=link[ptr];
    }
    printf("null");
    printf("\n");
}
void insertAt(int *data , int *link ,int *start ,int *avail, int value , int idx){
    int flag=0;
    if(*avail==-1){
        printf("OverFlow");
        return;
    }
    int ptr = *start;
    while(ptr!=-1){
        if(ptr==idx){ 
            flag=1;
            break;
        }
        ptr=link[ptr];
    }
    if (flag==0){
        printf("Given index is not found in the list\n");
        return;
    }
    int temp=*avail;
    *avail=link[*avail];
    data[temp]=value;
    link[temp]=link[ptr];
    link[ptr]=temp;
}
void insertAtHead(int *data , int *link ,int *start ,int *avail, int value ){
    if(*avail==-1){
        printf("OverFlow");
        return;
    }
    
    int temp=*avail;
    *avail=link[*avail];
    data[temp]=value;
    link[temp]=*start;
    *start=temp;
}
void insertAtTail(int *data , int *link ,int *start ,int *avail, int value ){
    if(*avail==-1){
        printf("OverFlow");
        return;
    }
    int ptr=*start;
    while (link[ptr]!=-1){
        ptr=link[ptr];
    }
    int temp=*avail;
    *avail=link[*avail];
    data[temp]=value;
    link[temp]=-1;
    link[ptr]=temp;
}
void deleteHead(int *data , int *link ,int *start ,int *avail){
    int loc = *start;
    *start = link[*start];
    link[loc]=*avail;
    *avail=loc;
}
void deleteTail(int *data , int *link ,int *start ,int *avail){
    if(link[*start]==-1){ 
        deleteHead(data,link,start,avail);
        return;
    }
    int ptr = *start;
    while(link[link[ptr]]!=-1){
        ptr=link[ptr];
    }
    int loc =ptr;
    link[link[loc]]=*avail;
    link[loc]=-1;
    *avail=link[loc];
}
void deleteSpecific(int *data , int *link ,int *start ,int *avail, int ploc ,int loc){
   
    if (ploc==-1){
        *start=link[*start];
    }
    else{
        link[ploc]=link[loc];
    }
    link[loc]=*avail;
    *avail=loc;
}
void Find_Loc(int *data , int *link ,int start ,int item , int *loc , int *ploc){
    if(link[start]==-1){
        *loc = start;
        return;
    }
    int ptr = start;
    while(ptr!=-1){
        if(data[link[ptr]] == item){
            *ploc = ptr;
            *loc=link[ptr];
        }
        ptr = link[ptr];
    }
    
}
void Delete(int *data , int *link ,int *start ,int *avail,int item){
    int ploc=-1, loc=-1;
    Find_Loc(data,link,*start,item ,&loc , &ploc);
     if(loc ==-1){
        printf("Item Not Found!! \n");
        return;
    }
    deleteSpecific(data ,link ,start ,avail, ploc,loc);
    
}
void size(int *start , int *data , int *link){
    int count = 0;
    int ptr=*start;
    while(ptr != -1){
        count++;
        ptr=link[ptr];
    }
    printf("The length of the list is : %d\n",count);
    
}
int search(int *start ,int target, int *data , int *link){
    int ptr=*start;
    int idx = 0;
    while(ptr != -1){
        if(data[ptr]==target){
        printf("It's present at position %d and ",idx);
        return ptr;
        }
        idx++;
        ptr=link[ptr];
    }
    return -1;
}

int main() {
    int start=-1; // head of data
    int avail=0; // head of empty data
    int data[10]; // List for storing data
    int link[10]; // List for storing the indexes
    int choice = 1;
    // Assingning the data and next index
    for(int i=0; i<10; i++){
        if(i==9) link[i]=-1;
        else link[i]=i+1;
    }
    while(choice){
        printf("1.Display \t 2.Size \t 3.Search\n4.InsertAtSpecific \t 5.InsertAtStart \t 6.InsertAtEnd\n7.DeleteAtSpecific \t 8.DeleteFirst \t 9.DeleteEnd\n10.DeleteItem\t11.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
            if(choice ==1 ) traversing(data,link,&start);
            else if(choice ==2 ) size(&start , data ,link);
            else if(choice ==3 ) {
                printf("Enter the intacter which you want to search : ");
                int target;
                scanf("%d",&target);
                if(search(&start,target , data ,link) !=-1)
                    printf(" at index %d \n",search(&start,target , data ,link));
                else printf("Target is not present in the list \n");
            }
            else if(choice ==4 ){
                printf("Enter the element : ");
                int val;
                scanf("%d",&val);
                printf("Enter the location : ");
                int loc ;
                scanf("%d",&loc);
                insertAt(data, link ,&start,&avail,val,loc);
            }
            else if(choice ==5 ){
                printf("Enter the element : ");
                int val;
                scanf("%d",&val);
                insertAtHead(data, link ,&start,&avail,val);
            }
            else if(choice ==6 ){
                printf("Enter the element : ");
                int val;
                scanf("%d",&val);
                insertAtTail(data, link ,&start,&avail,val);
            }
            else if(choice ==7 ){
                printf("Enter the location you want to delete : ");
                int loc;
                scanf("%d",&loc);
                printf("Enter the pre-location you want to delete : ");
                int ploc;
                scanf("%d",&ploc);
                deleteSpecific(data ,link ,&start ,&avail,ploc ,loc);
            }
            else if(choice ==8 ){
                deleteHead(data , link ,&start ,&avail);
            }
            else if(choice ==9 ){
                deleteTail(data , link ,&start ,&avail);
            }
            else if(choice ==10 ){
                printf("Enter the item you want to delete : ");
                int item;
                scanf("%d",&item);
                Delete(data ,link ,&start ,&avail, item);
            }
            else if(choice ==11) break;
            else{
                printf("Wrong Input!!");
            }
            
        }
    printf("Program end here");

    return 0;
    }