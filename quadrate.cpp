#include <stdio.h>
#include <TXlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>

int var;
float check_number (float x);
void discr_on (float a, float b, float c, float discr);
void discr_off (float a, float b, float c);
int main(){
    float a, b, c;
    printf("Для уравнения вида ax^2+bx+c = 0 введите коэффициенты\n");
    printf("a = ");
    a = check_number (a);   //Проверка на ввод только числа
    printf("b = ");
    b = check_number (b);   //Проверка на ввод только числа
    printf("c = ");
    c = check_number (c);   //Проверка на ввод только числа
    discr_off (a,b,c);  //Обработка случаев при a = 0
    float discr;
    discr = pow (b, 2) - 4*a*c; //Вычисление дискриминанта
    discr_on (a, b, c, discr);  //Обработка решений через дискриминант
return 0;
}

float check_number (float x) {
    do {
        var = scanf("%f", &x);
    } while (getchar () != '\n');
    return x;
}

void discr_on (float a, float b, float c, float discr) {
    if (a!= 0 && discr > 0){
        printf("Уравнение имеет два вещественных корня:\n");
        printf("x1 = %f\n", (-b + sqrt(discr))/2*a);
        printf("x2 = %f\n", (-b - sqrt(discr))/2*a);
    }
    if (a!= 0 && discr == 0){
        printf("Уравнение имеет один вещественный корень:\n");
        printf("x = %f\n", -b/2*a);
    }
    if (a!= 0 && discr < 0){
        printf("Уравнение не имеет вещественных корней\n");
    }
}

void discr_off (float a, float b, float c){
    if (a == 0 && b!= 0){
        printf("Уравнение не квадратное, а линейное. x = %f", c/b);
    }
    if (a == 0 && b == 0 && c != 0){
        printf("Корней нет. Неправильное уравнение");
    }
    if (a == 0 && b == 0 && c == 0){
        printf("Бесконечно много корней");
    }
}


