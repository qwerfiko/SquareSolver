//quadrate.c - a program for solving a quadratic equation
#include <stdio.h>
#include <stdlib.h>
#include <TXlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdbool.h>

float read_number ();
void solve_quadratic_equation (float a, float b, float c, float discr);
void solve_linear_equation (float a, float b, float c);
bool is_equal(float x);
const float epsillon = 1e-6;

int main(){
    float a = 0, b = 0, c = 0;
    printf("��� ��������� ���� ax^2+bx+c = 0 ������� ������������:\n");
    printf("a = ");
    a = read_number ();
    printf("b = ");
    b = read_number ();
    printf("c = ");
    c = read_number ();
    if (a == 0) {    //��������� ������� ��� a = 0
    solve_linear_equation (a,b,c);
    }
    else {
    float discr = 0;
    discr = pow (b, 2) - 4*a*c; //���������� �������������
    solve_quadratic_equation (a, b, c, discr);  //��������� ������� ����� ������������
    }
return 0;
}

float read_number () {
    char ch;
    float x;
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
    if (is_equal(a) == true && discr>0){
        printf("��������� ����� ��� ������������ �����:\n");
        printf("x1 = %f\n", (-b + sqrt(discr))/2*a);
        printf("x2 = %f\n", (-b - sqrt(discr))/2*a);
    }
    if (is_equal(a)==true && discr == 0){
        printf("��������� ����� ���� ������������ ������:\n");
        printf("x = %f\n", -b/2*a);
    }
    if (is_equal(a) == true && discr < 0){
        printf("��������� �� ����� ������������ ������\n");
    }
}

bool is_equal (float x) {
    if (abs(x - 0) > epsillon){
    return true;
    }
    else {
    return false;
    }
}

void solve_linear_equation (float a, float b, float c){
    if (is_equal(b) == true) {
        printf("��������� �� ����������, � ��������. x = %f", c/b);
    }
    if (b == 0 && is_equal(c) == true) {
        printf("������ ���. ������������ ���������");
    }
    if (b == 0 && c == 0){
        printf("���������� ����� ������");
    }
}


