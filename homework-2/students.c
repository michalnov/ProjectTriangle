#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
   char city[20];
   int pc;
}address_detail;

typedef struct{
   char name[20];
   int age;
   float salary;
   address_detail address;
} person;

int main()
{
   srand(time(NULL));

   person student[20];
   strcpy(student[0].name,"Sebastian"); student[0].age=35; student[0].salary=1452;
   strcpy(student[0].address.city,"Kosice"); student[0].address.pc=92512;
   strcpy(student[1].name,"David"); student[1].age=45; student[1].salary=1471;
   strcpy(student[1].address.city,"Kosice"); student[1].address.pc=04001;
   strcpy(student[2].name,"Filip"); student[2].age=30; student[2].salary=987;
   strcpy(student[2].address.city,"Bardejov"); student[2].address.pc=82356;
   strcpy(student[3].name,"Janka"); student[3].age=19; student[3].salary=1203;
   strcpy(student[3].address.city,"Levoca"); student[3].address.pc=14780;
   strcpy(student[4].name,"Denisa"); student[4].age=35; student[4].salary=859;
   strcpy(student[4].address.city,"Kosice"); student[4].address.pc=90845;

   strcpy(student[5].name,"Dominik"); student[5].age=28; student[5].salary=1452;
   strcpy(student[5].address.city,"Kosice"); student[5].address.pc=84652;
   strcpy(student[6].name,"Jan"); student[6].age=31; student[6].salary=1020;
   strcpy(student[6].address.city,"Senica"); student[6].address.pc=71254;
   strcpy(student[7].name,"Tobias"); student[7].age=32; student[7].salary=456;
   strcpy(student[7].address.city,"Senec"); student[7].address.pc=12387;
   strcpy(student[8].name,"Tereza"); student[8].age=41; student[8].salary=785;
   strcpy(student[8].address.city,"Poprad"); student[8].address.pc=12874;
   strcpy(student[9].name,"Slavka"); student[9].age=20; student[9].salary=1025;
   strcpy(student[9].address.city,"Kosice"); student[9].address.pc=68787;

   strcpy(student[10].name,"Samuel"); student[10].age=24; student[10].salary=1332;
   strcpy(student[10].address.city,"Kosice"); student[10].address.pc=87458;
   strcpy(student[11].name,"Xenia"); student[11].age=22; student[11].salary=800;
   strcpy(student[11].address.city,"Presov"); student[11].address.pc=8001;
   strcpy(student[12].name,"Daniel"); student[12].age=44; student[12].salary=1701;
   strcpy(student[12].address.city,"Michalovce"); student[12].address.pc=07101;
   strcpy(student[13].name,"Branislav"); student[13].age=25; student[13].salary=1101;
   strcpy(student[13].address.city,"Martin"); student[13].address.pc=41444;
   strcpy(student[14].name,"Simona"); student[14].age=32; student[14].salary=1045;
   strcpy(student[14].address.city,"Kosice"); student[14].address.pc=04022;

   strcpy(student[15].name,"Dusan"); student[15].age=18; student[15].salary=697;
   strcpy(student[15].address.city,"Michalovce"); student[15].address.pc=55654;
   strcpy(student[16].name,"Kamil"); student[16].age=28; student[16].salary=1500;
   strcpy(student[16].address.city,"Kosice"); student[16].address.pc=04011;
   strcpy(student[17].name,"Michaela"); student[17].age=27; student[17].salary=1300;
   strcpy(student[17].address.city,"Senec"); student[17].address.pc=92545;
   strcpy(student[18].name,"Roman"); student[18].age=18; student[18].salary=1005;
   strcpy(student[18].address.city,"Presov"); student[18].address.pc=04001;
   strcpy(student[19].name,"Oliver"); student[19].age=30; student[19].salary=1206;
   strcpy(student[19].address.city,"Kosice"); student[19].address.pc=04012;











   int i = 0, KePo[20], count1 = 0, salarybetween[20], count2 = 0, ageall = 0, count3 = 0, count4 = 0, oldest = 0, count5 = 0;
   float salaryAV = 0, ageAV = 0;
   int maxsalary = 0, ascending[20], swap, j;

   for (i = 0; i < 20; i++) {
     ascending[i] = i;
   }



   for (i = 0; i < 20; i++)
   {
     // 5. calculate average age of all students
     ageall = ageall + student[i].age;
     if (student[i].age < 30)    // 6. calculate average salary of student that are under 30 years old
     {
       salaryAV = salaryAV + student[i].salary;
       count3++;
     }
     if (strcmp(student[i].address.city, "Kosice") == 0) {}// 7. count number of students not from Kosice
     else
     {
       count4++;
     }
     if (student[oldest].age < student[i].age)// 8. find and write down the oldest student
     {
       oldest = i;
     }
                                                        // 3. write down all students from Kosice or Presov
     if (strcmp(student[i].address.city, "Presov") == 0 || strcmp(student[i].address.city, "Kosice") == 0) {
       KePo[count1] = i;
       count1++;
     }
     if (student[i].salary >= 1000 && student[i].salary <= 1300)// 4. write down all student that thei salary is between 1000 and 1300
     {
       salarybetween[count2] = i;
       count2++;
     }
     if (student[maxsalary].salary < student[i].salary)  // 2. write down the name and salary of student with highest salary
     {
       maxsalary = i;
     }
     if (strlen(student[i].name) < 7)                    // 1. write down name and city of all students
     {
       printf("Student: %s\t\t From: %s\n", student[i].name, student[i].address.city);
     }
     else
     {
       printf("Student: %s\t From: %s\n", student[i].name, student[i].address.city);
       count5++;// 9. write down number of student that their name is longer than 7 characters
     }
   }
   printf("\n%s\n", "Highest salary:");
   printf("%s with salary: %.2f\n", student[maxsalary].name, student[maxsalary].salary);
   printf("\n%s\n", "Students from Kosice and Presov:");
   for (i = 0; i < count1; i++) {
     printf("%s From: %s\n", student[KePo[i]].name, student[KePo[i]].address.city);
   }
   printf("\n%s\n", "Salary is between 1000 and 1300:");
   for (i = 0; i < count2; i++) {
     printf("%s  salary: %.2f\n", student[salarybetween[i]].name, student[salarybetween[i]].salary);
   }
   printf("\n%s", "average age of all students is:");
   ageAV = (float)ageall / 20;
   printf("%.2f\n", ageAV);
   salaryAV = salaryAV / count3;
   printf("%s %.2f\n\n", "Average salary of students under 30 years is:",salaryAV);
   printf("%s %d %s\n\n", "There are ", count4, "students that are not from Kosice");
   printf("%s %s %s %d %s\n\n", "The oldes student is:", student[oldest].name, "with ", student[oldest].age, "years.");
   printf("%s %d %s \n\n", "there are ", count5, "students wich names are longer than 7 characters");

   for (i = 0; i < 20; i++) {
     for (j = 0; j <  20 -1 -i; j++) {
       if (student[ascending[j]].salary > student[ascending[j+1]].salary) {
         swap=ascending[j];
         ascending[j]=ascending[j+1];
         ascending[j+1]=swap;
       }
     }
   }
   for (i = 0; i < 20; i++) {
       printf("%s %.2f\n", student[ascending[i]].name, student[ascending[i]].salary);
    }
}
