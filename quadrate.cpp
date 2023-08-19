#include <stdio.h>
#include <TXlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
int main(){

    float a, b, c, discr;
    printf("Для уравнения вида ax^2+bx+c = 0 введите коэффициенты\n");
    int var;
    printf("Нажмите Enter");
    do {
        scanf("%*[^\n]");   //Проверка на ввод только числа
        printf("a = ");
        var = scanf("%f", &a);
    } while (getc(stdin) != '\n');
    printf("Нажмите Enter");
    do {
        scanf("%*[^\n]");
        printf("b = ");
        var = scanf("%f", &b);
    } while (getc(stdin) != '\n');
    printf("Нажмите Enter");
    do {
        scanf("%*[^\n]");
        printf("c = ");
        var = scanf("%f", &c);
    } while (getc(stdin) != '\n');
    discr = pow (b, 2) - 4*a*c; //Вычисление дискриминанта
    if (a == 0 && b!=0){    //Обработка случаев при a = 0
        printf("Уравнение не квадратное, а линейное. x = %f", c/b);
    }
    if (a == 0 && b ==0 && c != 0){
        printf("Корней нет. Неправильное уравнение");
    }
    if (a == 0 && b ==0 && c == 0){
        printf("Бесконечно много корней");
    }
    if (a!=0 && discr > 0){     //Обработка решений в общем виде через дискриминант
        printf("Уравнение имеет два вещественных корня:\n");
        printf("x1 = %f\n", (-b + sqrt(discr))/2*a);
        printf("x2 = %f\n", (-b - sqrt(discr))/2*a);
    }
    if (a!=0 && discr == 0){
        printf("Уравнение имеет один вещественный корень:\n");
        printf("x = %f\n", -b/2*a);
    }
    if (a!=0 && discr < 0){
        printf("Уравнение не имеет вещественных корней\n");
    }

    return 0;
}
