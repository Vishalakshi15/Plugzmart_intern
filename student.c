#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define MAX_AGE_LENGTH 3
#define MAX_PHONE_LENGTH 10

struct Node
{
    struct Node *next;
    struct Node *prev;
    char name[20];
    char age[MAX_AGE_LENGTH + 1];
    char phno[10];
};

struct Node *createNode(char *name, char *age, char phno[10])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL)
    {
        strcpy(newNode->name, name);
        strcpy(newNode->age, age);
        strcpy(newNode->phno, phno);
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtLast(struct Node **head, char *name, char *age, char phno[10])
{
    struct Node *newNode = createNode(name, age, phno);
    struct Node *temp = *head;
    if (newNode != NULL)
    {
        if (*head == NULL)
            *head = newNode;
        else
        {
            struct Node *temp = *head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
        }
    }
}

void deleteNode(struct Node **head_ref, struct Node *del)
{

    if (*head_ref == NULL || del == NULL)
    {
        printf("\nThe list is empty!!");
        return;
    }

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}

void SearchAge(struct Node **head, char *age)
{
    struct Node *temp = *head;
    int pos = 0;
    int found = 0;

    while (temp != NULL)
    {
        if (strcmp(temp->age, age) == 0)
        {
            found = 1;
            printf("\nThe value %s is present at position %d!!\nName : %s\nAge : %d\nPhone no : %s\n", age, pos, temp->name, temp->age, temp->phno);
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
    {
        printf("\nNo match found!!\n");
        return;
    }

    int wantNext;
    printf("\nWant to find the next match? (1 for yes, 0 for no): ");
    scanf("%d", &wantNext);

    while (wantNext)
    {
        temp = temp->next;
        pos++;
        if (temp == NULL)
        {
            printf("\nNo more matches found!!\n");
            return;
        }
        if (strcmp(temp->age, age) == 0)
        {
            printf("\nThe value %s is present at position %d!!\nName : %s\nAge : %d\nPhone no : %s\n", age, pos, temp->name, temp->age, temp->phno);
        }
        else
        {
            printf("\nNo more matches found!!\n");
            return;
        }
        printf("\nWant to find the next match? (1 for yes, 0 for no): ");
        scanf("%d", &wantNext);
    }
}

void SearchName(struct Node **head, char name[20])
{
    struct Node *temp = *head;
    int pos = 0;
    int found = 0;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            found = 1;
            printf("\nThe value %s is present at position %d!!\nName : %s\nAge : %s\nPhone no : %s\n", name, pos, temp->name, temp->age, temp->phno);
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
    {
        printf("\nNo match found!!\n");
        return;
    }

    int wantNext;
    printf("\nWant to find the next match? (1 for yes, 0 for no): ");
    scanf("%d", &wantNext);

    while (wantNext)
    {
        temp = temp->next;
        pos++;
        if (temp == NULL)
        {
            printf("\nNo more matches found!!\n");
            return;
        }
        if (strcmp(temp->name, name) == 0)
        {
            printf("\nThe value %s is present at position %d!!\nName : %s\nAge : %s\nPhone no : %s\n", name, pos, temp->name, temp->age, temp->phno);
        }
        else
        {
            printf("\nNo more matches found!!\n");
            return;
        }
        printf("\nWant to find the next match? (1 for yes, 0 for no): ");
        scanf("%d", &wantNext);
    }
}

void SearchPhone(struct Node **head, char phno[10])
{
    struct Node *temp = *head;
    int pos = 0;
    while (strcmp(temp->phno, phno) != 0)
    {
        pos++;
        temp = temp->next;
    }
    if (strcmp(temp->phno, phno) == 0)
        printf("\nThe value %s is present in the position %d!! \nName : %s \nage : %s", phno, pos, temp->name, temp->age);
    else
        printf("\nNo match found!!");

    int want;
    printf("\nWant next match ?? (1 or 0)");
    scanf("%d", &want);
    if (want)
    {
        temp = temp->next;
        if (strcmp(temp->phno, phno) != 0)
        {
            while (strcmp(temp->phno, phno) == 0)
            {
                pos++;
                temp = temp->next;
            }
        }

        if (strcmp(temp->phno, phno) != 0)
            printf("\nNo more match found!!");
        else
            printf("\nThe value %s is present in the position %d!! \n Name : %s \n age : %s", phno, pos, temp->name, temp->age);
    }
}

void display(struct Node *head)
{
    printf("\nLinked List:\n");
    if (head != NULL)
    {
        while (head != NULL)
        {
            printf("Name: %s\t\tAge: %s\t\tPhoneNO: %s\n", head->name, head->age, head->phno);
            head = head->next;
        }
    }
    else
    {
        printf("\nThe list is empty");
    }
}

void update_age(struct Node *head, char *old, char *new)
{
    struct Node *current = head;
    int pos = 0;
    if (current == NULL)
    {
        printf("\nLinked List not initialized");
        return;
    }

    while (current != NULL)
    {
        pos++;
        if (strcmp(current->age, old) == 0)
        {
            strcpy(current->age, new);
            printf("\n%s found at position %d, replaced with %s\n", old, pos, new);
            return;
        }

        current = current->next;
    }

    printf("\n%s does not exist in the list\n", old);
}

void update_num(struct Node *head, char old[10], char new[10])
{
    struct Node *current = NULL;
    int pos = 0;

    if (head == NULL)
    {
        printf("\nLinked List not initialized");
        return;
    }
    current = head;
    while (current != NULL)
    {
        pos++;

        if (strcmp(current->phno, old) == 0)
        {
            strcpy(current->phno, new);
            printf("\n%s found at position %d, replaced with %s\n", old, pos, new);
            return;
        }

        if (current->next != NULL)
            current = current->next;
        else
            break;
    }
    printf("\n%s does not exist in the list\n", old);
}

void update_name(struct Node *head, char old[], char new[])
{
    struct Node *current = NULL;
    int pos = 0;

    if (head == NULL)
    {
        printf("\nLinked List not initialized");
        return;
    }

    current = head;
    while (current != NULL)
    {
        pos++;

        if (strcmp(current->name, old) == 0)
        {
            strcpy(current->name, new);
            printf("\n%s found at position %d, replaced with %s\n", old, pos, new);
            return;
        }

        if (current->next != NULL)
            current = current->next;
        else
            break;
    }
    printf("\n%s does not exist in the list\n", old);
}

void deleteNext(char name[20], struct Node **head)
{
    struct Node *temp3 = *head;
    while (temp3 != NULL && strcmp(temp3->name, name) != 0)
        temp3 = temp3->next;
    if ((strcmp(temp3->name, name) == 0))
    {
        deleteNode(head, temp3);
        printf("\n%s is deleted!", name);
    }
    else
        printf("\nNo match found!!");
}

void deleteAll(char name[20], struct Node **head)
{
    int items = 0;
    struct Node *current = *head;
    struct Node *nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        if (strcmp(current->name, name) == 0)
        {
            deleteNode(head, current);
            items++;
        }
        current = nextNode;
    }

    if (items)
        printf("\n%d persons with name %s are deleted succefully!!", items, name);
    else
        printf("\nNo match found for name %s!!", name);
}

int matchFounder(char name[20], struct Node **head)
{
    int items = 0;
    struct Node *temp3 = *head;
    while (temp3 != NULL)
    {
        if (strcmp(temp3->name, name) == 0)
            items++;
        temp3 = temp3->next;
    }
    return items;
}

int main()
{
    struct Node *head = NULL;
    char choice[4];
    int a = 1;
    int Choice;
    char option[3];
    while (a == 1)
    {
    case0:
        printf("\n\n1.Insert a person\n2.Delete a person\n3.Modify a person\n4.Search for a person\n5.Display\n6.Exit");
        printf("\nEnter your choice : ");
        char ch8;
        int j = 0;
        while ((ch8 = getch()) != '\r')
        {
            if (ch8 == 27)
            {
                printf("Escape key pressed!");
                goto case0;
            }

            if (ch8 == '\b')
            {
                if (j > 0)
                {
                    printf("\b \b");
                    j--;
                }
                continue;
            }

            if (j < MAX_AGE_LENGTH && isdigit(ch8))
            {
                choice[j++] = ch8;
                printf("%c", ch8);
            }
            else
            {
                printf("Enter a valid choice!!");
                goto case0;
            }
        }
        choice[j] = '\0';

        Choice = atoi(choice);
        char name[20];
        char age[MAX_AGE_LENGTH + 1];
        char phno[10];
        int pos;
        char ch;
        int i = 0;

        switch (Choice)
        {
        case 1:
        case1:
            char age[MAX_AGE_LENGTH + 1];
            char name[20];
            printf("\nEnter your name : ");
            while ((ch = getch()) != '\r')
            {
                if (ch == 27)
                    goto case0;
                if (ch == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }
                if (i < 19 && isalpha(ch))
                {
                    name[i++] = ch;
                    printf("%c", ch);
                }
                else
                {
                    printf("\nEnter a valid namem as input\n");
                    goto case1;
                }
            }
            name[i] = '\0';
            char ch1;
            i = 0;
            printf("\nEnter your age : ");
            while ((ch1 = getch()) != '\r')
            {
                if (ch1 == 27)
                {
                    printf("Escape key pressed!");
                    goto case0;
                }

                if (ch1 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }

                if (i < MAX_AGE_LENGTH && isdigit(ch1))
                {
                    age[i++] = ch1;
                    printf("%c", ch1);
                }
                else
                {
                    printf("\nEnter a valid age as input\n");
                    goto case1;
                }
            }
            age[i] = '\0';
            char ch2;
            i = 0;
            printf("\nEnter your phone no : ");
            while ((ch2 = getch()) != '\r')
            {
                if (ch2 == 27)
                {
                    goto case0;
                }
                if (ch2 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }
                if (i < MAX_PHONE_LENGTH && isdigit(ch2))
                {
                    phno[i++] = ch2;
                    printf("%c", ch2);
                }
                else
                {
                    printf("\nEnter a valid phone number as input\n");
                    goto case1;
                }
            }
            phno[i] = '\0';
            insertAtLast(&head, name, age, phno);
            break;
        case 2:
        case2:
            char Fname[20];
            printf("\nEneter the name to delete : ");
            char ch4;
            i = 0;
            while ((ch4 = getch()) != '\r')
            {
                if (ch4 == 27)
                    goto case0;
                if (ch4 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }
                if (i < 19 && isalpha(ch4))
                {
                    Fname[i++] = ch4;
                    printf("%c", ch4);
                }
                else
                {
                    printf("\nEnter a valid name to search!!");
                    goto case2;
                }
            }
            Fname[i] = '\0';
            printf("\n%d number of matches are found want to delete all(1) or delete 1st occurance(0) : ", matchFounder(Fname, &head));
            char ch5;
            i = 0;
            while ((ch5 = getch()) != '\r')
            {
                if (ch5 == 27)
                {
                    printf("Escape key pressed!");
                    goto case0;
                }

                if (ch5 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }

                if (i < 4 && isdigit(ch5))
                {
                    option[i++] = ch5;
                    printf("%c", ch5);
                }
                else
                {
                    printf("\nEnter a valid choice!!");
                    goto case2;
                }
            }
            option[i] = '\0';
            int Option = atoi(option);

            if (Option)
                deleteAll(Fname, &head);
            else
                deleteNext(Fname, &head);

            break;
        case 3:
        case3:
            printf("\n1.Modify Age\n2.Modify phone number\n3.Modify name\n4.Back\n");
            printf("Enter the option : ");
            char ch6;
            i = 0;
            while ((ch6 = getch()) != '\r')
            {
                if (ch6 == 27)
                {
                    printf("Escape key pressed!");
                    goto case0;
                }

                if (ch6 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }

                if (i < 4 && isdigit(ch6))
                {
                    option[i++] = ch6;
                    printf("%c", ch6);
                }
                else
                {
                    printf("\nEnter a valid choice!!");
                    goto case3;
                }
            }
            option[i] = '\0';
            Option = atoi(option);
            switch (Option)
            {
            case 1:
            case5:
                char oldAge[4];
                char newAge[4];
                printf("\nEnter the old data : ");
                char ch12;
                i = 0;
                while ((ch12 = getch()) != '\r')
                {
                    if (ch12 == 27)
                    {
                        printf("Escape key pressed!");
                        goto case0;
                    }

                    if (ch12 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }

                    if (i < MAX_AGE_LENGTH && isdigit(ch12))
                    {
                        oldAge[i++] = ch12;
                        printf("%c", ch12);
                    }
                    else
                    {
                        printf("\nEneter a valid age!!");
                        goto case5;
                    }
                }
                oldAge[i] = '\0';
                printf("\nEnter the new data : ");
                char ch13;
                i = 0;
                while ((ch13 = getch()) != '\r')
                {
                    if (ch13 == 27)
                    {
                        printf("Escape key pressed!");
                        goto case0;
                    }

                    if (ch13 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }

                    if (i < MAX_AGE_LENGTH && isdigit(ch13))
                    {
                        newAge[i++] = ch13;
                        printf("%c", ch13);
                    }
                    else
                    {
                        printf("\nEneter a valid age!!");
                        goto case5;
                    }
                }
                newAge[i] = '\0';
                update_age(head, oldAge, newAge);
                break;

            case 2:
            case6:
                char oldnumc[20];
                char newnumc[20];
                printf("\nEnter the old data : ");
                char ch14;
                i = 0;
                while ((ch14 = getch()) != '\r')
                {
                    if (ch14 == 27)
                    {
                        goto case0;
                    }
                    if (ch14 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < MAX_PHONE_LENGTH && isdigit(ch14))
                    {
                        oldnumc[i++] = ch14;
                        printf("%c", ch14);
                    }
                    else
                    {
                        printf("\nEnter a valid phone number as input\n");
                        goto case6;
                    }
                }
                oldnumc[i] = '\0';
                printf("\nEnter the new data : ");
                char ch15;
                i = 0;
                while ((ch15 = getch()) != '\r')
                {
                    if (ch15 == 27)
                    {
                        goto case0;
                    }
                    if (ch15 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < MAX_PHONE_LENGTH && isdigit(ch15))
                    {
                        newnumc[i++] = ch15;
                        printf("%c", ch15);
                    }
                    else
                    {
                        printf("\nEnter a valid phone number as input\n");
                        goto case6;
                    }
                }
                newnumc[i] = '\0';
                update_num(head, oldnumc, newnumc);
                break;

            case 3:
            case4:
                char oldname[20];
                char newname[20];
                printf("\nEnter the old data : ");
                char ch16;
                i = 0;
                while ((ch16 = getch()) != '\r')
                {
                    if (ch16 == 27)
                        goto case0;
                    if (ch16 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 19 && isalpha(ch16))
                    {
                        oldname[i++] = ch16;
                        printf("%c", ch16);
                    }
                    else
                    {
                        printf("\nEnter a valid namem as input\n");
                        goto case4;
                    }
                }
                oldname[i] = '\0';
                printf("\nEnter the new data : ");
                char ch17;
                i = 0;
                while ((ch17 = getch()) != '\r')
                {
                    if (ch17 == 27)
                        goto case0;
                    if (ch17 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 19 && isalpha(ch17))
                    {
                        newname[i++] = ch17;
                        printf("%c", ch17);
                    }
                    else
                    {
                        printf("\nEnter a valid namem as input\n");
                        goto case4;
                    }
                }
                newname[i] = '\0';
                update_name(head, oldname, newname);
                break;
            case 4:
                break;

            default:
                break;
            }

            break;
        case 4:
        case7:
            printf("\n1.Search using name\n2.Search using age\n3.Search using phone num\n4.Back\n");
            printf("Enter your choice : ");
            char ch7;
            i = 0;
            while ((ch7 = getch()) != '\r')
            {
                if (ch7 == 27)
                {
                    printf("Escape key pressed!");
                    goto case0;
                }

                if (ch7 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }

                if (i < 4 && isdigit(ch7))
                {
                    option[i++] = ch7;
                    printf("%c", ch7);
                }
                else
                {
                    printf("\nEnter a valid choice!!");
                    goto case7;
                }
            }
            option[i] = '\0';
            Option = atoi(option);
            switch (Option)
            {
            case 1:
            case8:
                printf("\nEnter the name to search : ");
                char ch9;
                i = 0;
                while ((ch9 = getch()) != '\r')
                {
                    if (ch9 == 27)
                        goto case0;
                    if (ch9 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 19 && isalpha(ch9))
                    {
                        name[i++] = ch9;
                        printf("%c", ch9);
                    }
                    else
                    {
                        printf("\nEneter a valid name");
                        goto case8;
                    }
                }
                name[i] = '\0';
                SearchName(&head, name);
                break;

            case 2:
            case9:
                printf("\nEnter the age to search : ");
                char ch10;
                i = 0;
                while ((ch10 = getch()) != '\r')
                {
                    if (ch10 == 27)
                    {
                        printf("Escape key pressed!");
                        goto case0;
                    }

                    if (ch10 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }

                    if (i < MAX_AGE_LENGTH && isdigit(ch10))
                    {
                        age[i++] = ch10;
                        printf("%c", ch10);
                    }
                    else
                    {
                        printf("\nEneter a valid age");
                        goto case9;
                    }
                }
                age[i] = '\0';
                SearchAge(&head, age);
                break;

            case 3:
            case10:
                printf("\nEnter the phone num to search : ");
                char phnoc[20];
                char ch11;
                i = 0;
                while ((ch11 = getch()) != '\r')
                {
                    if (ch11 == 27)
                    {
                        goto case0;
                    }
                    if (ch11 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < MAX_PHONE_LENGTH && isdigit(ch11))
                    {
                        phnoc[i++] = ch11;
                        printf("%c", ch11);
                    }
                    else
                    {
                        printf("\nEnter a valid phone number as input\n");
                        goto case10;
                    }
                }
                phnoc[i] = '\0';
                SearchPhone(&head, phnoc);
                break;
            case 4:
                break;

            default:
                printf("Enter a valid option!!");
                break;
            }

            break;
        case 5:
            display(head);
            break;
        case 6:
            a = 0;
            break;

        default:
            printf("Enter a valid choice!");
            break;
        }
    }

    return 0;
}
