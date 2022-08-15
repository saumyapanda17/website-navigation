#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node {
    char data[1000];
    int index;
    struct node* left;
    struct node* right;
    struct node* back;
    struct node* homeWay;
};


struct node* createNode(char str[],int ind) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->data,str);
    temp->index=ind;
    temp->left=temp->right=temp->back=temp->homeWay=NULL;
    return temp;
}

void home();
void signup();
void verifyemail();
void login();
void profilepage();
void editprofilepage();
void error();
void exitwebsite();

void display(int d) {
    if(d==0) home();
    if(d==1) signup();
    if(d==3) verifyemail();
    if(d==2) login();
    if(d==4) profilepage();
    if(d==5) editprofilepage();
}

void traversal(struct node* head) {
    struct node* temp = head;

    bool con = true;

    printf("\n\tWELCOME TO THE WEBSITE%s", head->data);
    home();
    while(con) {
        if(temp->left!=NULL || temp->right!=NULL){
        printf("\n\n1. Go to %s\n",temp->left->data);
        
        if(temp->right!=NULL)
        printf("2. Go to %s\n",temp->right->data);
        printf("3. Go BACK\n");
        printf("4. Go to HOME PAGE\n");
        printf("5. EXIT WEBSITE\n");
        }
        else{
            printf("\n\n\t*THIS IS END OF THE PAGE*\n\n");
            printf("\n3. Go BACK\n");
            printf("4. Go to HOME PAGE\n");
            printf("5. EXIT WEBSITE\n");
        }
        printf("\nEnter the choice: ");
        int n;
        scanf("%d",&n);
       
        switch (n) {
        
        case 1: 
            temp=temp->left;
            printf("\n\n");
            printf("\tPAGE %d",temp->index);
            printf("\n\tWELCOME TO %s\n",temp->data);
            printf("\n");
            if(temp->index==0) display(0);
            if(temp->index==1) display(1); 
            if(temp->index==3) display(3);
            if(temp->index==2) display(2);
            if(temp->index==4) display(4);
            if(temp->index==5) display(5);
            /* code */
            break;
         
         case 2:
            temp=temp->right;
            printf("\n\n");
            printf("\tPAGE %d",temp->index);
            printf("\n\tWELCOME TO %s\n", temp->data);
            printf("\n");
            if(temp->index==0) display(0);
            if(temp->index==1) display(1);
            if(temp->index==3) display(3);
            if(temp->index==2) display(2);
            if(temp->index==4) display(4);
            if(temp->index==5) display(5);
            break;

        case 3:
            if(temp == head) {
                printf("\n\n");
                printf("\tPAGE %d",temp->index);
                printf("\n\tYOU ARE ON THE HOME PAGE\n");
                printf("\n");
                if(temp->index==0) display(0);
                if(temp->index==1) display(1);
                if(temp->index==3) display(3);
                if(temp->index==2) display(2);
                if(temp->index==4) display(4);
                if(temp->index==5) display(5);
            }
            else {
                temp = temp->back;
                printf("\n\n");
                printf("\tPAGE %d",temp->index);
                if (temp->index!=0) printf("\n\tWELCOME BACK TO %s\n",temp->data);
                printf("\n");
                if(temp->index==0) display(0);
                if(temp->index==1) display(1);
                if(temp->index==3) display(3);
                if(temp->index==2) display(2);
                if(temp->index==4) display(4);
                if(temp->index==5) display(5);
            }
            break;
        
        case 4:
            if(temp == head) {
                printf("\n\n");
                printf("\tPAGE %d",temp->index);
                printf("\n\tALREADY ON THE HOME PAGE\n");
                printf("\n");
                if(temp->index==0) display(0);
                if(temp->index==1) display(1);
                if(temp->index==3) display(3);
                if(temp->index==2) display(2);
                if(temp->index==4) display(4);
                if(temp->index==5) display(5);
            }
            else {
                temp = head;
                printf("\n\n");
                printf("\tPAGE %d",temp->index);
                printf("\n\tWELCOME BACK TO THE HOME PAGE\n");
                printf("\n");
                if(temp->index==0) display(0);
                if(temp->index==1) display(1);
                if(temp->index==3) display(3);
                if(temp->index==2) display(2);
                if(temp->index==4) display(4);
                if(temp->index==5) display(5);
            }    
            break;
        
        case 5:
            con = false;
            break;
        default:
            printf("\n");
            error();
            break;
        }
        
    }
        printf("\n");
        exitwebsite();
        return;
}

int main() {
    int d;
    struct node* home = (struct node*)malloc(sizeof(struct node));

    // home page
    home = createNode("\n\n\tYOU ARE ON THE HOME PAGE\n",0);
    
    struct node* head = home;

    // LEFT PART
    
    //1nd page 
    head->left=createNode("SIGN-UP PAGE",1);
    head->left->back = head;
    head->left->homeWay=home;

    // 2nd page
    head->left->left = createNode("VERIFY EMAIL PAGE",3);
    head->left->left->back = head->left;
    head->left->left->homeWay = head;

    // RIGHT PART
    
    //3rd page
    head->right=createNode("LOGIN PAGE",2);
    head->right->back = home;
    head->back = head;
    head->right->back = head;
    head->right->homeWay = home;

    // 4th page
    head->right->left = createNode("PROFILE PAGE",4);             
    head->right->left->back = head->right;
    head->right->left->homeWay = home;

    // 5th page
    head->right->right = createNode("EDIT PROFILE PAGE",5);
    head->right->right->back = head->right;
    head->right->right->homeWay = home;

    traversal(home);

    return 0;
}

void home() {
    printf("\n\t---------------------------------------------------");
    printf("\n       |                      HOME PAGE                    |");
    printf("\n       |                                                   |");
    printf("\n       |                       MOODLE                      |");
    printf("\n       |               Getting started is easy             |");
    printf("\n       |                                                   |");
    printf("\n       |                                  SIGN UP    LOGIN |");
    printf("\n       |                                                   |");
    printf("\n       |  Moodle is the world's most popular learning      |");
    printf("\n       |  anagement system. Start creating your online     |");
    printf("\n       |  learning site in minutes!                        |");
    printf("\n       |                                                   |");
    printf("\n       |  Announcements:                                   |");
    printf("\n       |  --------------                                   |");
    printf("\n       |  Moodle core plugins review - Wed, Aug 25, 2021   |");
    printf("\n       |  Update on Moodle 4.0 release - Fri, Aug 6, 2021  |");
    printf("\n       |                                                   |");
    printf("\n       |  Useful Posts          Events          Resources  |");
    printf("\n       |  ------------          ------          ---------  |");
    printf("\n       |          Moodle™ is a registered trademark        |");
    printf("\n       |                                                   |");
    printf("\n       |              Site Policy | Contact US             |");
    printf("\n\t---------------------------------------------------");
}

void signup() {
    printf("\n\t-----------------------------");
    printf("\n       |         SIGN UP PAGE        |");
    printf("\n       |                             |");
    printf("\n       |  First Name:                |");
    printf("\n       |  Last Name:                 |");
    printf("\n       |  Username:                  |");
    printf("\n       |  Email:                     |");
    printf("\n       |  Password:                  |");
    printf("\n       |                             |");
    printf("\n       |       VERIFY YOUR EMAIL     |");
    printf("\n\t-----------------------------");
}

void verifyemail() {
    printf("\n\t---------------------------------------------------");
    printf("\n       |                 VERIFY YOUR EMAIL                 |");
    printf("\n       |                                                   |");
    printf("\n       |             Thank you for signing up!             |");
    printf("\n       |    We have sent a link to your email address.     |");
    printf("\n       |  If you have not received the verification mail,  |");
    printf("\n       |    please check your Spam or Bulk Email folder.   |");
    printf("\n       |                                                   |");
    printf("\n       |            Still can't find the email?            |");
    printf("\n       |        CLICK HERE TO RESEND VERIFICATION MAIL     |");
    printf("\n\t---------------------------------------------------");
}

void login() {
    printf("\n\t---------------------------------------------------");
    printf("\n       |                     LOGIN PAGE                    |");
    printf("\n       |                                                   |");
    printf("\n       |  Username:                                        |");
    printf("\n       |  Password:                                        |");
    printf("\n       |                                                   |");
    printf("\n       |                CLICK HERE TO LOGIN                |");
    printf("\n       |                                                   |");
    printf("\n       |               Forgot your password?               |");
    printf("\n\t---------------------------------------------------");
}

void profilepage() {
    printf("\n\t---------------------------------------------------");
    printf("\n       |                    PROFILE PAGE                   |");
    printf("\n       |                                                   |");
    printf("\n       | YOUR RECENT COURSES:                              |");
    printf("\n       |                                                   |");
    printf("\n       | Introduction to Programming: 3 Courses Taken      |");
    printf("\n       | Data Structures and Algorithms: 1 Course Taken    |");
    printf("\n       | Probability and Statistics: 0 Courses Taken       |");
    printf("\n       |                                                   |");
    printf("\n       | CLICK HERE TO ADD MORE COURSES                    |");
    printf("\n       |                                                   |");
    printf("\n       | QUIZZES TAKEN: 12/15                              |");
    printf("\n       |                                                   |");
    printf("\n       |                                                   |");
    printf("\n       |                                                   |");
    printf("\n       |                                Latest Badges: 0   |");
    printf("\n       |                                Overall Grade: A   |");
    printf("\n\t---------------------------------------------------");
}

void editprofilepage() {
    printf("\n\t---------------------------------------------------");
    printf("\n       |               EDIT YOUR PROFILE PAGE              |");
    printf("\n       |                                                   |");
    printf("\n       |  Username:                                        |");
    printf("\n       |                                                   |");
    printf("\n       |  First Name:                                      |");
    printf("\n       |  Last Name:                                       |");
    printf("\n       |  Email:                                           |");
    printf("\n       |  Phone no:                                        |");
    printf("\n       |  City:                                            |");
    printf("\n       |  College:                                         |");
    printf("\n       |  Branch:                                          |");
    printf("\n       |                                                   |");
    printf("\n       |  Password:                                        |");
    printf("\n       |  New Password:                                    |");
    printf("\n       |  Confirm New Password:                            |");
    printf("\n       |                                                   |");
    printf("\n       |            CLICK HERE TO UPDATE PROFILE           |");
    printf("\n\t---------------------------------------------------");
}

void error() {
    printf("\n\t---------------------------------------------------");
    printf("\n       |                                                   |");
    printf("\n       |  MOODLE                                           |");
    printf("\n       |                                                   |");
    printf("\n       |  404. That's an error.                            |");
    printf("\n       |  The requested URL was not found in this server.  |");
    printf("\n       |                                                   |");
    printf("\n       |                                                   |");
    printf("\n       |                                                   |");
    printf("\n       |  PLEASE ENTER VALID CHOICE                        |");
    printf("\n\t---------------------------------------------------");
}

void exitwebsite() {
    printf("\n\t---------------------------------------------------");
    printf("\n       |  MOODLE                                           |");
    printf("\n       |                                                   |");
    printf("\n       |  You have successfully exited out of the website. |");
    printf("\n       |                                                   |");
    printf("\n       |                                                   |");
    printf("\n       |                                                   |");
    printf("\n       |  To log back in, kindly run the program again.    |");
    printf("\n       |                                                   |");
    printf("\n       |                           2021 - Moodle - Privacy |");
    printf("\n\t---------------------------------------------------");
}
