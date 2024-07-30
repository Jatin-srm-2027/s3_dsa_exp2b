/*
2. Write a program to create a Student structure and have a nested structure for members address and date of birth. Store the data and display the records. 
    */
#include <stdio.h>

// creating structure Address
struct Address {
    char st[100];
    char city[50];
    char zip[10];
    char state[50];
};

// creating structure DateOfBirth
struct DateOfBirth {
    int day;
    int month;
    int year;
};

 //creating strtucture Student
struct Student {
    char name[90];
    int age;
    long regi;
    struct Address add; //intializing structure varibale of Address type
    struct DateOfBirth dob; //intializing structure variable of DateOfBirth type
}; 

void get(struct Student *s) {
    // Pointer to struct Student 
    printf("Enter student details:\n");
    printf("Name: ");
    scanf(" %[^\n]%*c", s->name); 
    printf("Age: ");
    scanf("%d", &s->age);
    printf("Registration Number: ");
    scanf("%ld", &s->regi);
    
    printf("Address:\n");
    printf("Street: ");
    scanf(" %[^\n]%*c", s->add.st);  // Pointer `s` accesses the Address structure's street field
    printf("City: ");
    scanf(" %[^\n]%*c", s->add.city);    // Pointer `s` accesses the Address structure's city field
    printf("ZIP Code: ");
    scanf(" %[^\n]%*c", s->add.zip);      // Pointer `s` accesses the Address structure's zip field
    printf("State: ");
    scanf(" %[^\n]%*c", s->add.state);    // Pointer `s` accesses the Address structure's state field
    
    printf("Date of Birth (dd mm yyyy): ");
    scanf("%d %d %d", &s->dob.day, &s->dob.month, &s->dob.year); // Pointer `s` accesses the DateOfBirth structure's fields
    
    printf("\n");
}

void put(const struct Student *s) {
    // Const pointer to struct Student is used to access but not modify the structure data
    printf("\nStudent Details:\n");
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("Registration Number: %ld\n", s->regi);
   
    printf("Address:\n");
    printf("Street: %s\n", s->add.st); 
    printf("City: %s\n", s->add.city);    
    printf("ZIP Code: %s\n", s->add.zip);  
    printf("State: %s\n", s->add.state); 
    
    printf("Date of Birth: %02d-%02d-%04d\n", s->dob.day, s->dob.month, s->dob.year); 
    
    printf("\n");
}

int main() {
    struct Student s; // Declare a variable of type Student
    
    // Call get() function to populate the student's data
    // Pass the address of the structure variable `s` to the function
    // This allows the function to modify the original `s` structure
    get(&s);
    
    // Call put() function to display the student's data
    // Pass the address of the structure variable `s` to the function
    // This allows the function to read and display the original `s` structure without modifying it
    put(&s);
    
    return 0; 
}
