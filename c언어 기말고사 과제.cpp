#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//snack ����ü ����
struct snack
{
    char snack_title[30];
    int snack_number;
    int snack_price;
};
typedef struct snack Snack;

// �Լ� ����
void printMenu(void);
void addSnack(void);
void searchBySnackNumber(void);
void showSnackList(void);
void searchBySnackName(void);
void flushInputBuffer(void);
void removeInputEnter(char* str);

// ���� ������ ����
Snack snacks[50];
int snack_count;

int main(void)
{
    int input_menu = 0;

    while (1)
    {
        printMenu();
        scanf("%d", &input_menu);

        switch (input_menu)
        {
        case 1:
            addSnack();
            break;
        case 2:
            searchBySnackNumber();
            break;
        case 3:
            searchBySnackName();
            break;
        case 4:
            showSnackList();
            break;
        case 5:
            printf("�����մϴ�!");
            break;
        default:
            break;
        }
        if (input_menu == 5)
            break;
    }
    return 0;
}

void printMenu(void)
{
    printf("- - - - - - - - - - - - - - - - - - -\n");
    printf("1. ���� ���� ���� �Է� \n");
    printf("2. ���� �˻�(��ǰ ��ȣ�� �˻�) \n");
    printf("3. ���� �˻�(���� �̸����� �˻�) \n");
    printf("4. ��ü ���� ���� ��� \n");
    printf("5. ���� \n");
    printf("�޴� �Է� >> ");
    return;
}

void addSnack(void)
{
    // ���� ��ȣ �ڵ� �߰�
    snacks[snack_count].snack_number = snack_count;

    // ���� �̸� �Է�
    flushInputBuffer();
    printf("���� �̸� �Է� >> ");
    fgets(snacks[snack_count].snack_title, sizeof(snacks[snack_count].snack_title), stdin);
    removeInputEnter(snacks[snack_count].snack_title);

    // ���� ���� �Է�
    printf("���� ���� ���� �� �Է� >> ");
    scanf("%d", &snacks[snack_count].snack_price);

    // �߰��� ���� ���
    printf("���� �߰� - - - - - -\n");
    printf("���� ��ȣ [%d] | ���� �̸� : [%s] | ���� ���� : [%d] \n",
        snacks[snack_count].snack_number,
        snacks[snack_count].snack_title,
        snacks[snack_count].snack_price
    );

    snack_count++;


    return;
}

void searchBySnackNumber(void)
{
    int snack_number = 0;

    printf("���� ��ȣ �Է� >> ");
    scanf("%d", &snack_number);

    if (snack_number >= snack_count)
    {
        printf("��ϵ��� ���� ���� ��ȣ�Դϴ�\n");
        return;
    }

    printf("���� ��ȸ - - - - - -\n");
    printf("���� ��ȣ [%d] | ���� �̸� : [%s] | ���� ���� : [%d] \n",
        snacks[snack_number].snack_number,
        snacks[snack_number].snack_title,
        snacks[snack_number].snack_price
    );
    return;
}

void searchBySnackName(void)
{
    char snack_title[30];
    int target_number = -1;

    printf("���� �̸� �Է� >> ");
    flushInputBuffer();
    fgets(snack_title, sizeof(snack_title), stdin);
    removeInputEnter(snack_title);

    for (int i = 0; i < snack_count; i++)
    {
        if (!strcmp(snack_title, snacks[i].snack_title))
        {
            target_number = i;
            break;
        }
    }

    if (target_number == -1) {
        printf("�������� �ʴ� ����\n");
    }
    else {
        printf("���� ��ȸ - - - - - - -\n");
        printf("���� ��ȣ [%d] | ���� �̸� : [%s] | ���� ���� : [%d] \n",
            snacks[target_number].snack_number,
            snacks[target_number].snack_title,
            snacks[target_number].snack_price
        );
    }
    return;
}

void showSncakList(void)
{
    printf("���� ��ü ��� - - - - - - -\n");
    for (int i = 0; i < snack_count; i++)
    {
        printf("���� ��ȣ [%d] | ���� �̸� : [%s] | ���� ���� : [%d] \n",
            snacks[i].snack_number,
            snacks[i].snack_title,
            snacks[i].snack_price
        );
    }
    return;
}
void flushInputBuffer(void)
{
    while (getchar() != '\n');
    return;
}

void removeInputEnter(char* str)
{
    int i = 0;
    while (str[i] != '\n')
        i++;
    str[i] = '\0';
    return;
}