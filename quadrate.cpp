//quadrate.c - a program for solving a quadratic equation
#include <stdio.h>
#include <stdlib.h>
#include <TXlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdbool.h>

float read_number();
void solve_quadratic_equation (float a, float b, float c, float discr);
void solve_linear_equation (float a, float b, float c);
bool is_zero (float x);
const float epsillon = 1e-6;

int main(){
    float a = 0, b = 0, c = 0;
    printf("��� ��������� ���� ax^2+bx+c = 0 ������� ������������:\n");
    printf("a = ");
    a = read_number();  //�������� ����� �� �����
    printf("b = ");
    b = read_number();  //�������� ����� �� �����
    printf("c = ");
    c = read_number();  //�������� ����� �� �����
    if (a == 0) {    //��������� ������� ��� a == 0, ������� ��������� ���������
        solve_linear_equation (a,b,c);
    }
    else {  //��������� ������� ��� a != 0, ������� ����������� ���������
        float discr = 0;
        discr = pow (b, 2) - 4*a*c;
        solve_quadratic_equation (a, b, c, discr);  //��������� ������� ����� ������������
    }
return 0;
}

float read_number() {
    char ch = 0;
    float x = 0;
    while (scanf("%f", &x) != 1){
        while ((ch = getchar()) != '\n')
        putchar(ch);
        printf(" - �� ���� ��������� �����. ��������� �������. \n");
    }
    while (getchar() != '\n'){
        continue;
    }
    return x;
}

void solve_quadratic_equation (float a, float b, float c, float discr) {
    if (discr > 0){
        printf("��������� ����� ��� ������������ �����:\n");
        printf("x1 = %f\n", (-b + sqrt(discr))/2*a);
        printf("x2 = %f\n", (-b - sqrt(discr))/2*a);
    }
    if ( is_zero(discr) ){
        printf("��������� ����� ���� ������������ ������:\n");
        printf("x = %f\n", -b/2*a);
    }
    if (discr < 0){
        printf("��������� �� ����� ������������ ������\n");
    }
}

bool is_zero (float x) {
    return (abs(x - 0) < epsillon);
}

void solve_linear_equation (float a, float b, float c){
    if (is_zero(b) == false) {
        printf("��������� �� ����������, � ��������. x = %f", c/b);
    }
    if ( (is_zero(b)) && (is_zero(c) == false) ) {
        printf("������ ���. ������������ ���������");
    }
    if ( (is_zero(b)) && (is_zero(c)) ){
        printf("���������� ����� ������");
    }
}


