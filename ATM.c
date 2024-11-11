#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

#define MIN_BALANCE 500
#define CODE_LENGTH 6

struct Node
{
    struct Node *next;
    struct Node *prev;
    char name[20];
    char bal[10];
    char uniqueID[CODE_LENGTH + 1];
    char code[7];
};

struct Node *createNode(char *name, char *bal, char *uniqueID, char *code)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL)
    {
        strcpy(newNode->name, name);
        strcpy(newNode->bal, bal);
        strcpy(newNode->uniqueID, uniqueID);
        strcpy(newNode->code, code);
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtLast(struct Node **head, char *name, char *bal, char *uniqueID, char *code)
{
    struct Node *newNode = createNode(name, bal, uniqueID, code);
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
        }
    }
}

char *generateUniqueCode()
{
    srand(time(NULL));
    char *code = (char *)malloc((CODE_LENGTH + 1) * sizeof(char));
    for (int i = 0; i < CODE_LENGTH; ++i)
    {
        if (i < 4)
            code[i] = '0' + (time(NULL) % 10);
        else
            code[i] = '0' + (rand() % 10);
    }
    code[CODE_LENGTH] = '\0';

    return code;
}

char *createPIN()
{
    char *code = (char *)malloc(7 * sizeof(char));
    printf("\nEnter a 6 digit pin : ");

    char ch;
    int i = 0;
    while ((ch = getch()) != '\r')
    {
        if (ch == 27)
        {
            printf("\nEscape key pressed!\n");
            free(code);
            return NULL;
        }
        if (ch == '\b')
        {
            if (i > 0)
            {
                printf("\b \b");
                i--;
            }
            continue;
        }
        if (i < 6 && isdigit(ch))
        {
            code[i++] = ch;
            printf("%c", ch);
        }
    }
    code[i] = '\0';

    return code;
}

void display(struct Node *head, char *uniqueID)
{
    printf("\nBalance : ");
    if (head != NULL)
    {
        while (head != NULL)
        {
            if (strcmp(head->uniqueID, uniqueID) == 0)
                printf(head->bal);
            head = head->next;
        }
    }
    else
        printf("\nThe list is empty");
}

int main()
{
    struct Node *head = NULL;
    int a = 1;
    int Choice;
    char ch;
    while (a == 1)
    {
    case0:
        printf("\n\nWELCOME TO THE ATM...!!\n"
               "0.Create New Account\n"
               "1. %-20s 2. %-20s\n"
               "3. %-20s 4. %-20s\n"
               "5. %-20s 6. %-20s\n"
               "7. %-20s 8. %-20s\n",
               "Balance Inquiry", "Withdrawal", "Deposit", "Transfer",
               "Change PIN", "Set PIN", "Receipt", "Exit");
        printf("\nEnter a choice : ");
        Choice = getch() - '0';
        char name[20];
        char bal[10];
        char *uniqueID;
        char *code;
        switch (Choice)
        {
        case 0:
        case1:
            printf("\nEnter your name : ");
            int i = 0;
            while ((ch = getch()) != '\r')
            {
                if (ch == 27)
                {
                    printf("\nEscape key pressed!\n");
                    goto case0;
                }
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
                    printf("\nEnter a valid name as input\n");
                    goto case1;
                }
            }
            name[i] = '\0';
            ch;
            i = 0;
            printf("\nEnter min balance (Rs.500) to your account : ");
            while ((ch = getch()) != '\r')
            {
                if (ch == 27)
                {
                    printf("\nEscape key pressed!\n");
                    goto case0;
                }
                if (ch == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }
                if (i < 9 && isdigit(ch))
                {
                    bal[i++] = ch;
                    printf("%c", ch);
                }
            }
            bal[i] = '\0';
            int bali;
            bali = atoi(bal);
            if (bali < 500)
                printf("\nEnter minimun balance to continue..!!");
            else
            {
                uniqueID = generateUniqueCode();
                printf("\nYour unique ID : %s", uniqueID);
                code = createPIN();
                if (code != NULL)
                {
                    insertAtLast(&head, name, bal, uniqueID, code);
                    printf("\nAccount created successfully!\n");
                }
                else
                    printf("\nAccount creation aborted!\n");
            }
            break;
        case 1:
        case2:
            struct Node *temp = head;
            printf("\nInsert your card : ");
            char ch2;
            i = 0;
            while ((ch2 = getch()) != '\r')
            {
                if (ch2 == 27)
                    goto case0;
                if (ch2 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }
                if (i < 19 && (isalpha(ch2) || isdigit(ch2)))
                {
                    uniqueID[i++] = ch2;
                    printf("%c", ch2);
                }
                else
                {
                    printf("\nEnter a valid uniqueID as input\n");
                    goto case2;
                }
            }
            uniqueID[i] = '\0';
            while (temp != NULL && strcmp(temp->uniqueID, uniqueID) != 0)
                temp = temp->next;
            if (temp == NULL)
            {
                printf("\nNo such user found...Try again!!");
                goto case0;
            }

            else
            {

                printf("\nEnter your 6 digit PIN : ");
                ch2 = '\0';
                i = 0;
                while ((ch2 = getch()) != '\r')
                {
                    if (ch2 == 27)
                        goto case0;
                    if (ch2 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 7 && isdigit(ch2))
                    {
                        code[i++] = ch2;
                        printf("%c", ch2);
                    }
                    else
                    {
                        printf("\nEnter a valid 6 digit code as input\n");
                        goto case2;
                    }
                }
                code[i] = '\0';
            }

            if (strcmp(temp->uniqueID, uniqueID) == 0)
            {
                if (strcmp(code, temp->code) == 0)
                    display(head, uniqueID);
                else
                    printf("\nYou entered wrong PIN...please try again!!");
            }

            break;
        case 2:
        case3:
            printf("\nInsert your card : ");
            ch2 = '\0';
            i = 0;
            while ((ch2 = getch()) != '\r')
            {
                if (ch2 == 27)
                    goto case0;
                if (ch2 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }
                if (i < 19 && (isalpha(ch2) || isdigit(ch2)))
                {
                    uniqueID[i++] = ch2;
                    printf("%c", ch2);
                }
                else
                {
                    printf("\nEnter a valid uniqueID as input\n");
                    goto case3;
                }
            }
            uniqueID[i] = '\0';
            while (temp != NULL && strcmp(temp->uniqueID, uniqueID) != 0)
                temp = temp->next;
            if (temp == NULL)
            {
                printf("\nNo such user found...Try again!!");
                goto case0;
            }
            else
            {

                printf("\nEnter the amount to withdraw : ");
                ch2 = '\0';
                i = 0;
                int amt;
                char amtc[10];
                while ((ch2 = getch()) != '\r')
                {
                    if (ch2 == 27)
                        goto case0;
                    if (ch2 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 9 && isdigit(ch2))
                    {
                        amtc[i++] = ch2;
                        printf("%c", ch2);
                    }
                    else if (isdigit(ch2))
                    {
                        printf("\nYou exceeded your daily limit!!");
                        goto case3;
                    }
                    else
                    {
                        printf("\nEnter a valid amount as input\n");
                        goto case3;
                    }
                }
                amtc[i] = '\0';
                amt = atoi(amtc);
                printf("\nEnter your 6 digit PIN : ");
                ch2 = '\0';
                i = 0;
                while ((ch2 = getch()) != '\r')
                {
                    if (ch2 == 27)
                        goto case0;
                    if (ch2 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 7 && isdigit(ch2))
                    {
                        code[i++] = ch2;
                        printf("%c", ch2);
                    }
                    else
                    {
                        printf("\nEnter a valid 6 digit code as input\n");
                        goto case3;
                    }
                }
                code[i] = '\0';
                if (strcmp(temp->uniqueID, uniqueID) == 0)
                {
                    if (strcmp(code, temp->code) == 0)
                    {
                        int ibal;
                        ibal = atoi(temp->bal);
                        if (ibal >= amt)
                        {
                            printf("\nWithdrawal of Rs.%d for %s is successfull...!!", amt, temp->name);
                            printf("\nYour current balance is %d", (ibal - amt));
                            sprintf(temp->bal, "%d", (ibal - amt));
                        }
                        else
                        {
                            printf("\nInsufficient balance in your account!!");
                        }
                        if (ibal < 500)
                            printf("\nYour balance is lower than minimum balance..!!");
                    }
                    else
                    {
                        printf("\nYou entered wrong PIN...please try again!!");
                        goto case3;
                    }
                }
            }
            break;
        case 3:
        case4:
            printf("\nInsert your card : ");
            ch2 = '\0';
            i = 0;
            while ((ch2 = getch()) != '\r')
            {
                if (ch2 == 27)
                    goto case0;
                if (ch2 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }
                if (i < 19 && isdigit(ch2))
                {
                    uniqueID[i++] = ch2;
                    printf("%c", ch2);
                }
                else
                {
                    printf("\nEnter a valid uniqueID as input\n");
                    goto case4;
                }
            }
            uniqueID[i] = '\0';
            temp = head;
            while (temp != NULL && strcmp(temp->uniqueID, uniqueID) != 0)
                temp = temp->next;
            if (temp == NULL)
            {
                printf("\nNo such user found...Try again!!");
                goto case0;
            }
            else
            {

                printf("\nEnter the amount to deposit : ");
                ch2 = '\0';
                i = 0;
                int amt;
                char amtc[10];
                while ((ch2 = getch()) != '\r')
                {
                    if (ch2 == 27)
                        goto case0;
                    if (ch2 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 9 && isdigit(ch2))
                    {
                        amtc[i++] = ch2;
                        printf("%c", ch2);
                    }
                    else if (isdigit(ch2))
                    {
                        printf("\nYou exceeded your daily limit!!");
                        goto case4;
                    }
                    else
                    {
                        printf("\nEnter a valid amount as input\n");
                        goto case4;
                    }
                }
                amtc[i] = '\0';
                amt = atoi(amtc);
                printf("\nEnter your 6 digit PIN : ");
                ch2 = '\0';
                i = 0;
                while ((ch2 = getch()) != '\r')
                {
                    if (ch2 == 27)
                        goto case0;
                    if (ch2 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 7 && isdigit(ch2))
                    {
                        code[i++] = ch2;
                        printf("%c", ch2);
                    }
                    else
                    {
                        printf("\nEnter a valid 6 digit code as input\n");
                        goto case4;
                    }
                }
                code[i] = '\0';
                if (strcmp(temp->uniqueID, uniqueID) == 0)
                {
                    if (strcmp(code, temp->code) == 0)
                    {
                        int ibal;
                        ibal = atoi(temp->bal);
                        printf("\nDeposition of Rs.%d for %s is successfull...!!", amt, temp->name);
                        printf("\nYour current balance is %d", (ibal + amt));
                        sprintf(temp->bal, "%d", (ibal + amt));
                    }
                    else
                    {
                        printf("\nYou entered wrong PIN...please try again!!");
                        goto case4;
                    }
                }
            }
            break;
        case 4:
        case5:
            printf("\nInsert your card : ");
            ch2 = '\0';
            i = 0;
            char uniqueID1[20];
            struct Node *temp1 = head;
            while ((ch2 = getch()) != '\r')
            {
                if (ch2 == 27)
                    goto case0;
                if (ch2 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }
                if (i < 19 && isdigit(ch2))
                {
                    uniqueID1[i++] = ch2;
                    printf("%c", ch2);
                }
                else
                {
                    printf("\nEnter a valid uniqueID as input\n");
                    goto case5;
                }
            }
            uniqueID1[i] = '\0';
            while (temp1 != NULL && strcmp(temp1->uniqueID, uniqueID1) != 0)
                temp1 = temp1->next;
            if (temp1 == NULL)
            {
                printf("\nNo such user found...Try again!!");
                goto case0;
            }
            else
            {
                printf("\nEnter the Unique ID of reciever to transfer : ");
                ch2 = '\0';
                i = 0;
                while ((ch2 = getch()) != '\r')
                {
                    if (ch2 == 27)
                        goto case0;
                    if (ch2 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 19 && (isalpha(ch2) || isdigit(ch2)))
                    {
                        uniqueID[i++] = ch2;
                        printf("%c", ch2);
                    }
                    else
                    {
                        printf("\nEnter a valid uniqueID as input\n");
                        goto case5;
                    }
                }
                uniqueID[i] = '\0';
                temp = head;
                while (temp != NULL && strcmp(temp->uniqueID, uniqueID) != 0)
                    temp = temp->next;
                if (temp == NULL)
                {
                    printf("\nNo such user found...Try again!!");
                    goto case0;
                }
                else
                {
                    printf("\nEnter the amount to transfer : ");
                    ch2 = '\0';
                    i = 0;
                    int amt;
                    char amtc[10];
                    while ((ch2 = getch()) != '\r')
                    {
                        if (ch2 == 27)
                            goto case0;
                        if (ch2 == '\b')
                        {
                            if (i > 0)
                            {
                                printf("\b \b");
                                i--;
                            }
                            continue;
                        }
                        if (i < 9 && isdigit(ch2))
                        {
                            amtc[i++] = ch2;
                            printf("%c", ch2);
                        }
                        else if (isdigit(ch2))
                        {
                            printf("\nYou exceeded your daily limit!!");
                            goto case5;
                        }
                        else
                        {
                            printf("\nEnter a valid amount as input\n");
                            goto case5;
                        }
                    }
                    amtc[i] = '\0';
                    amt = atoi(amtc);
                    printf("\nEnter your 6 digit PIN : ");
                    ch2 = '\0';
                    i = 0;
                    while ((ch2 = getch()) != '\r')
                    {
                        if (ch2 == 27)
                            goto case0;
                        if (ch2 == '\b')
                        {
                            if (i > 0)
                            {
                                printf("\b \b");
                                i--;
                            }
                            continue;
                        }
                        if (i < 7 && isdigit(ch2))
                        {
                            code[i++] = ch2;
                            printf("%c", ch2);
                        }
                        else
                        {
                            printf("\nEnter a valid 6 digit code as input\n");
                            goto case5;
                        }
                    }
                    code[i] = '\0';
                    if (strcmp(temp->uniqueID, uniqueID) == 0)
                    {
                        if (strcmp(code, temp1->code) == 0)
                        {
                            int ibal;
                            ibal = atoi(temp1->bal);
                            int ibal2;
                            ibal2 = atoi(temp->bal);
                            if (ibal >= amt)
                            {
                                printf("\nTransfer of Rs.%d from %s to %s is successfull...!!", amt, temp1->name, temp1->name);
                                printf("\nYour current balance is %d", (ibal - amt));
                                sprintf(temp1->bal, "%d", (ibal - amt));
                                sprintf(temp->bal, "%d", (ibal2 + amt));
                            }
                            else
                            {
                                printf("\nInsufficient balance in your account!!");
                            }
                            if (ibal < 500)
                                printf("\nYour balance is lower than minimum balance..!!");
                        }
                        else
                        {
                            printf("\nYou entered wrong PIN...please try again!!");
                            goto case5;
                        }
                    }
                }
            }
            break;
        case 5:
        case6:
            temp = head;
            printf("\nInsert your card : ");
            ch2;
            i = 0;
            char code1[7];
            while ((ch2 = getch()) != '\r')
            {
                if (ch2 == 27)
                    goto case0;
                if (ch2 == '\b')
                {
                    if (i > 0)
                    {
                        printf("\b \b");
                        i--;
                    }
                    continue;
                }
                if (i < 19 && (isalpha(ch2) || isdigit(ch2)))
                {
                    uniqueID[i++] = ch2;
                    printf("%c", ch2);
                }
                else
                {
                    printf("\nEnter a valid uniqueID as input\n");
                    goto case6;
                }
            }
            uniqueID[i] = '\0';
            while (temp != NULL && strcmp(temp->uniqueID, uniqueID) != 0)
                temp = temp->next;
            if (temp == NULL)
                printf("\nNo such user found...Try again!!");
            else
            {
                printf("\nEnter your old 6 digit PIN : ");
                ch2 = '\0';
                i = 0;
                while ((ch2 = getch()) != '\r')
                {
                    if (ch2 == 27)
                        goto case0;
                    if (ch2 == '\b')
                    {
                        if (i > 0)
                        {
                            printf("\b \b");
                            i--;
                        }
                        continue;
                    }
                    if (i < 7 && isdigit(ch2))
                    {
                        code[i++] = ch2;
                        printf("%c", ch2);
                    }
                    else
                    {
                        printf("\nEnter a valid 6 digit code as input\n");
                        goto case6;
                    }
                }
                code[i] = '\0';
                if (strcmp(temp->uniqueID, uniqueID) == 0)
                {
                    if (strcmp(code, temp->code) == 0)
                    {
                        printf("\nEnter new 6 digit PIN : ");
                        ch2 = '\0';
                        i = 0;
                        while ((ch2 = getch()) != '\r')
                        {
                            if (ch2 == 27)
                                goto case0;
                            if (ch2 == '\b')
                            {
                                if (i > 0)
                                {
                                    printf("\b \b");
                                    i--;
                                }
                                continue;
                            }
                            if (i < 7 && isdigit(ch2))
                            {
                                code1[i++] = ch2;
                                printf("%c", ch2);
                            }
                            else
                            {
                                printf("\nEnter a valid 6 digit code as input\n");
                                goto case6;
                            }
                        }
                        code1[i] = '\0';
                        sprintf(temp->code, "%s", code1);
                    }
                    else
                    {
                        printf("\nYou entered wrong PIN...please try again!!");
                        goto case6;
                    }
                }
            }
            break;
        case 6:
            createPIN();
            break;
        case 7:
            printf("\nCurrently unavailable...!!\nPrinter out of stock...!!");
            break;
        case 8:
            a = 0;
            break;
        default:
            printf("\nEnter a valid choice!!\n");
            break;
        }
    }

    return 0;
}
