//created by Youssef ElGendy 

#include <stdio.h>
#include "Project_testing.h"

int choice(void);

int main(){
    printf("Welcome to our SimpleDataBase\n Please select one of the following options \n ");
    while(1){
        uint8 User_Input,i=1;
        int id,year,Entries;
        int subjects[3],grades[3];
        uint8* list;
        uint8 count;
        uint8* ptr;
        User_Input=choice();
        int flag;
        switch (User_Input)
        {
            case 0:
                return 0;
                break; //no need for this break 
            case 1:
                if(SDB_IsFull()==true){
                    printf("Yes it is full\n");
                }
                else{
                    printf("No it's not full\n");
                }
                break;
            case 2: // usedsize
                Entries=SDB_GetUsedSize();
                printf("%d",Entries);
                break;
            case 3: //add entry
            flag=0;
                while(flag==0){
                printf("Please enter the id");
                // getchar();
                scanf("%d",&id);
                printf("\n Please enter the student year");
                scanf("%d",&year);
                for(i=0;i<3;i++){
                    printf("Please enter the Course ID");
                    scanf("%d",&subjects[i]);
                    printf("please enter the grade");
                    scanf("%d",&grades[i]);
                }
                printf("%d\n\n\n",id);
                flag=SDB_AddEntry((uint8)id,(uint8)year,(uint8*) &subjects,(uint8*) &grades);
                }
                printf("Entry added successfully :D \n \n");
                break;
            case 4: //delete entry
                printf("Please enter id to delete");
                scanf("%d",&id);
                SDB_DeleteEntry(id);
                printf("Deleted succesfully \n");
                break;
            case 5: //read entry 
                printf("Please enter id to read");
                scanf("%d",&id);
                flag=SDB_ReadEntry((uint8) id,(uint8*) &year,(uint8*) &subjects,(uint8*) &grades);
                if (flag==1){
                    printf("The student year is %d\n ",year);
                    printf("Here a list of courses and grades \n \n");
                    for(i=0;i<3;i++){
                        printf("%d\t",*(subjects+i));
                        printf(": %d\n",*(grades+i));
                    }}
                else {
                    printf("Not found\n");
                }
                break;

            case 6: //get id list
                SDB_GetIdList((uint8*)&count,(uint8*)& list);
                printf("the number of entries is %d",count);
                printf("here's a list of ids :");
                for(uint8 i=0;i<count;i++){
                    printf("%d",*(list+i));
                }
                break;

            case 7: // is id exit?
                printf("Please enter The id you're looking for");
                scanf("%d",&id);
                flag=SDB_IsIdExist(id);
                if (flag==1){
                    printf("the id exists \n");
                }
                else{
                    printf("Not found");
                }
                break;
        }
    }
    return 0;
}

int choice(void){
   int i=0;
        int choice;
        while(choice<1 || choice>7){
        printf("To Check if the database is full :\t 1\n");
        printf("To get the number of entries in the database :\t 2\n");
        printf("To add a new entry :\t 3\n");
        printf("To delete an existing entery :\t 4 \n");
        printf("To read an existing entry :\t 5\n");
        printf("To get list of the ids :\t 6\n");
        printf("To check if the id exist:\t 7\n");
        printf("To exist:\t 0 ");
        scanf("%d",&choice);
        if(choice>=1 && choice<=7 ){
            return choice;
        }
        else if(choice == 0){
            printf("Thank you for using our database \n");
            return 0;
        }
        else {
            printf("incorrect input please try again or choose 0 to exit");
        }

        }
    return 0;
}
