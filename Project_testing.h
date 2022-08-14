typedef unsigned char uint8;

enum bool{false,true};
typedef enum bool bool;

struct courses{
    uint8 courses_id[3];
    uint8 courses_grades[3];
};typedef struct courses courses;
struct student
{
    uint8 id ;
    uint8 Student_Year ;
    courses CoursesAndGrades;
};typedef struct student student;

student db[10];

bool SDB_IsFull(void);

uint8 SDB_GetUsedSize(void);

bool SDB_AddEntry(uint8 id,uint8 year , uint8* subjects, uint8* grades);

void SDB_DeleteEntry(uint8 id);

bool SDB_ReadEntry(uint8 id,uint8* year , uint8* subjects, uint8* grades);

void SDB_GetIdList(uint8* count,uint8* list); 

bool SDB_IsIdExist(uint8 id); 

int search(uint8 id);

void bubble_sorting(uint8 id){
    int temp,i,j;
    for (i=0; i<9; i++){
      for (j=i+1; j<10; j++){
         if (db[i].id > db[j].id){
            temp = db[i].id;
            db[i].id =  db[j].id;
            db[j].id = temp;
         }
      }
   }
}

bool SDB_IsFull(void){
    int i,flag=1;
    for(i=0;i<=9;i++){
        
        if (db[i].id==0){
            flag=0;
            break;
        }
    }
    if (flag ==1){
        return true;
    }
    else {
        return false;
    }
}

uint8 SDB_GetUsedSize(void){
    int Entrie;
    for(Entrie=0;Entrie<=9;Entrie++){
        if (db[Entrie].id==0){
            break;
        }
    }
    return Entrie;
}

int search(uint8 id){
    bubble_sorting(id);
    uint8 left=0,middle,right=9;
    while(left<=right){
        middle=(left+right)/2;
        if(id < db[middle].id){
            right=middle-1;
        }

        else if(id > db[middle].id){
            left=middle+1;
        }
        else{
            return middle;
    }}
        return -1;
}

bool SDB_AddEntry(uint8 id,uint8 year , uint8* subjects, uint8* grades){ //assuming the user will send the location of 2 arrays one containing subjects and the other containing grades
    uint8 i,EmptyPlace;
    
    for (EmptyPlace=0;EmptyPlace<=10;EmptyPlace++){
        if(db[EmptyPlace].id==0){
            break;
        }
        else if(EmptyPlace==10 && db[EmptyPlace].id!=0){
            return false;
        }
    }
    db[EmptyPlace].id=id;
    db[EmptyPlace].Student_Year=year;
    for(i=0;i<3;i++){
       
        if(*(grades+i)<0 || *(grades+i)>100){
            return false;
        }
        else{
            db[EmptyPlace].CoursesAndGrades.courses_id[i]=*(subjects+i);
            db[EmptyPlace].CoursesAndGrades.courses_grades[i]=*(grades+i);
        }
    }

    printf("%d\n",db[0].id);
    return true;
    }

void SDB_DeleteEntry(uint8 id){
    uint8 place=search(id);

    if (place<=0 && place<=10){
        db[place].id=0;
        db[place].Student_Year=0;
        for(uint8 i=0;i<3;i++){
        db[place].CoursesAndGrades.courses_grades[i]=0;
        db[place].CoursesAndGrades.courses_id[i]=0;
        }}
    
}  

bool SDB_ReadEntry(uint8 id,uint8* year , uint8* subjects, uint8* grades){
    uint8 place=search((int) id);
    if (place != -1){
        year=&db[place].Student_Year;
        for(int i=0;i<3;i++){
        subjects=&(db[place].CoursesAndGrades.courses_id[i]);     // the module user will access the rest of grades by using *(subject+1)   
                                                                // i considered using self referential structure with multiple links but i guess it wouldn't differ that match

        grades=&(db[place].CoursesAndGrades.courses_grades[i]);  
        }
        return true;
    }
     else {
        return false;
     }
}

void SDB_GetIdList(uint8* count,uint8* list){
    uint8 i;
    *count=0;
    for(i=0;i<=10;i++){
        if(db[i].id!=0){
        (*count)++;
        }
    }
    for(i=0;i<=(*count);i++){
        list=&db[i].id;             //Here also, if we used self-referntial structure it would make it a list but the assignment requires that we have no return
                                    // so,the user should make a for loop from 0 until the count and access each element using *(list+ itterator_Name) to print it or whatever
    }
}

bool SDB_IsIdExist(uint8 id){
    int left=0,right=10,place=1000;
    while(left<=right){
        int middle=left+right/2;
        if(db[middle].id==id){
            return true;
        }

        if(db[middle].id<id){
            left=middle+1;
        }
        else  
            right=middle-1;
    }
    return false;
}

// add sorting !!!!!!!
