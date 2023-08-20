//quadrate.c - a program for solving a quadratic equation
#include <stdio.h>
#include <stdlib.h>
#include <TXlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>

float check_input_number (float x);
void solve_quadratic_equation (float a, float b, float c, float discr);
void solve_linear_equation (float a, float b, float c);

int main(){
    float a = 0, b = 0, c = 0;
    printf("��� ��������� ���� ax^2+bx+c = 0 ������� ������������:\n");
    printf("a = ");
    a = check_input_number (a);
    printf("b = ");
    b = check_input_number (b);
    printf("c = ");
    c = check_input_number (c);
    if (a == 0) {    //��������� ������� ��� a = 0
    solve_linear_equation (a,b,c);
    }
    else {
    float discr;
    discr = pow (b, 2) - 4*a*c; //���������� �������������
    solve_quadratic_equation (a, b, c, discr);  //��������� ������� ����� ������������
    }
return 0;
}

float check_input_number (float x) {
    char ch;
    while (scanf("%f", &x) != 1){
    while ((ch = getchar()) != '\n')
       putchar(ch);
       printf(" - �� ���� ��������� �����. ��������� �������. \n");
    }
    return x;
    fflush(stdin);
}

void solve_quadratic_equation (float a, float b, float c, float discr) {
    float epsillon = 1e-6;
    if (abs(a - 0) > epsillon && discr>0){
        printf("��������� ����� ��� ������������ �����:\n");
        printf("x1 = %f\n", (-b + sqrt(discr))/2*a);
        printf("x2 = %f\n", (-b - sqrt(discr))/2*a);
    }
    if (abs(a - 0) > epsillon && discr == 0){
        printf("��������� ����� ���� ������������ ������:\n");
        printf("x = %f\n", -b/2*a);
    }
    if (abs(a - 0) > epsillon && discr < 0){
        printf("��������� �� ����� ������������ ������\n");
    }
}

void solve_linear_equation (float a, float b, float c){
    float epsillon = 1e-6;
    if (abs(b - 0) > epsillon){
        printf("��������� �� ����������, � ��������. x = %f", c/b);
    }
    if (b == 0 && abs(c - 0) > epsillon){
        printf("������ ���. ������������ ���������");
    }
    if (b == 0 && c == 0){
        printf("���������� ����� ������");
    }
}


