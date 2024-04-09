#include "module.h"

int calc_2(int num, char s[]) {
    int i = 15, j;
    while (num > 1) {
        s[i] = (char) (num % 2 + 48);
        i--;
        num /= 2;
    }
    s[i] = (char) (num + 48);
    j = i;
    while (i != 0) {
        i--;
        s[i] = '0';
    }
    return j;
}


int calc_16(int num, char s[]) {
    int i = 3, j;
    while (num > 15) {
        if (num % 16 < 10) {
            s[i] = (char) (num % 16 + 48);
        } else {
            s[i] = (char) (num % 16 + 55);
        }
        i--;
        num /= 16;
    }
    if (num < 10) {
        s[i] = (char) (num + 48);
    } else {
        s[i] = (char) (num + 55);
    }
    j = i;
    while (i != 0) {
        i--;
        s[i] = '0';
    }
    return j;
}


bool twoInSix() {
    srand((unsigned int) time(NULL));
    int num, i_2, i_16, j = 0;
    char n_2[17], n_16[17], answer[1024];
    bool b = true;
    num = rand() % 65536;
    n_2[16] = '\0';
    n_16[4] = '\0';
    i_2 = calc_2(num, n_2);
    i_16 = calc_16(num, n_16);
    printf("\nПредложенное для перевода число: %s (2cc)\nВаш ответ (16сс): ", n_2 + i_2);
    scanf("%s", answer);
    while (*(answer + j) == '0' && *(answer + j) != '\0') {
        j++;
    }
    for (int i = 0; *(n_16 + i + i_16) != '\0' && b; i++) {
        if ((*(answer + j + i) != *(n_16 + i + i_16)) || (strlen(answer+j) != strlen(n_16+i_16))) {
            b = false;
        }
    }
    if (!b) {
        printf("Ваш ответ является неверным\n%s (2cc) --> %s (16cc)", (n_2 + i_2), (n_16 + i_16));
        return false;
    } else {
        printf("Вы молодец!");
        return true;
    }
}

bool sixIntwo() {
    srand((unsigned int) time(NULL));
    int num, i_2, i_16, j = 0;
    char n_2[17], n_16[17], answer[1024];
    bool b = true;
    num = rand() % 65536;
    n_2[16] = '\0';
    n_16[4] = '\0';
    i_2 = calc_2(num, n_2);
    i_16 = calc_16(num, n_16);
    printf("\nПредложенное для перевода число: %s (16cc)\nВаш ответ (2сс): ", n_16 + i_16);
    scanf("%s", answer);
    while (*(answer + j) == '0' && *(answer + j) != '\0') {
        j++;
    }
    for (int i = 0; *(n_2 + i + i_2) != '\0' && b; i++) {
        if ((*(answer + j + i) != *(n_2 + i + i_2)) || (strlen(answer+j) != strlen(n_2+i_2))) {
            b = false;
        }
    }
    if (!b) {
        printf("Ваш ответ является неверным\n%s (16cc) --> %s (2cc)", (n_16 + i_16), (n_2 + i_2));
        return false;
    } else {
        printf("Вы молодец!");
        return true;
    }
}