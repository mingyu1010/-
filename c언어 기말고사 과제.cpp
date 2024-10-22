#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//snack 구조체 정의
struct snack
{
    char snack_title[30];
    int snack_number;
    int snack_price;
};
typedef struct snack Snack;

// 함수 선언
void printMenu(void);
void addSnack(void);
void searchBySnackNumber(void);
void showSnackList(void);
void searchBySnackName(void);
void flushInputBuffer(void);
void removeInputEnter(char* str);

// 전역 변수로 선언
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
            printf("종료합니다!");
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
    printf("1. 새로 들어온 과자 입력 \n");
    printf("2. 과자 검색(상품 번호로 검색) \n");
    printf("3. 과자 검색(과자 이름으로 검색) \n");
    printf("4. 전체 과자 정보 출력 \n");
    printf("5. 종료 \n");
    printf("메뉴 입력 >> ");
    return;
}

void addSnack(void)
{
    // 과자 번호 자동 추가
    snacks[snack_count].snack_number = snack_count;

    // 과자 이름 입력
    flushInputBuffer();
    printf("과자 이름 입력 >> ");
    fgets(snacks[snack_count].snack_title, sizeof(snacks[snack_count].snack_title), stdin);
    removeInputEnter(snacks[snack_count].snack_title);

    // 과자 가격 입력
    printf("과자 가격 정수 값 입력 >> ");
    scanf("%d", &snacks[snack_count].snack_price);

    // 추가된 과자 출력
    printf("과자 추가 - - - - - -\n");
    printf("과자 번호 [%d] | 과자 이름 : [%s] | 과자 가격 : [%d] \n",
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

    printf("과자 번호 입력 >> ");
    scanf("%d", &snack_number);

    if (snack_number >= snack_count)
    {
        printf("등록되지 않은 과자 번호입니다\n");
        return;
    }

    printf("과자 조회 - - - - - -\n");
    printf("과자 번호 [%d] | 과자 이름 : [%s] | 과자 가격 : [%d] \n",
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

    printf("과자 이름 입력 >> ");
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
        printf("존재하지 않는 과자\n");
    }
    else {
        printf("과자 조회 - - - - - - -\n");
        printf("과자 번호 [%d] | 과자 이름 : [%s] | 과자 가격 : [%d] \n",
            snacks[target_number].snack_number,
            snacks[target_number].snack_title,
            snacks[target_number].snack_price
        );
    }
    return;
}

void showSncakList(void)
{
    printf("과자 전체 출력 - - - - - - -\n");
    for (int i = 0; i < snack_count; i++)
    {
        printf("과자 번호 [%d] | 과자 이름 : [%s] | 과자 가격 : [%d] \n",
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