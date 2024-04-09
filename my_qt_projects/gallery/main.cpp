#include "module.h"

int main() {
    setlocale(LC_ALL, "ru");
    int Count_example = 0, Count_right = 0, Choice = 0, Next;
    printf("Добро пожаловать в обучающую программу!\n");
    while (Choice != 2) {
        printf("\n\nВыберите, что вы хотите сделать:\n0 - Учится переводу из двоичной в шестнадцатеричную сс\n1 - Учится переводу из шестнадцатеричной в двоичную сс\n2 - Выход из программы\nВаш выбор: ");
        scanf("%d", &Choice);
        switch (Choice) {
            case 0:
                Next = 1;
                while (Next == 1) {
                    if (twoInSix()) {
                        Count_right++;
                    }
                    Count_example++;
                    printf("\n\nЖелаете ли вы продолжить передод из 2сс в 16сс?\n 0 - Нет. Выйти в меню\n 1 - Продолжить\nВаш выбор:");
                    scanf("%d", &Next);
                }
                break;
            case 1:
                Next = 1;
                while (Next == 1) {
                    if (sixIntwo()) {
                        Count_right++;
                    }
                    Count_example++;
                    printf("\n\nЖелаете ли вы продолжить передод из 16сс в 2сс?\n 0 - Нет. Выйти в меню\n 1 - Продолжить\nВаш выбор:");
                    scanf("%d", &Next);
                }
                break;
            case 2:
                printf("\nРешено примеров: %d, Решено верно: %d\nЗавершение работы", Count_example, Count_right);
                break;
            default:
                printf("Введено неверное значение, попробуйте ещё раз\n");
                break;
        }
    }
    return 0;
}
