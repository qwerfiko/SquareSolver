#include <stdio.h>
#include <TXlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
int main(){

    float a, b, c, discr;
    printf("��� ��������� ���� ax^2+bx+c = 0 ������� ������������\n");
    printf("a = ");
    scanf ("%f", &a);
    printf("b = ");
    scanf ("%f", &b);
    printf("c = ");
    scanf ("%f", &c);
    discr = pow (b, 2) - 4*a*c;                                       //���������� �������������
    if (a == 0 && b!=0){                                              //��������� ������� ��� a = 0
        printf("��������� �� ����������, � ��������. x = %f", c/b);
    }
    if (a == 0 && b ==0 && c != 0){
        printf("������ ���. ������������ ���������");
    }
    if (a == 0 && b ==0 && c == 0){
        printf("���������� ����� ������");
    }                                                                 //��������� ������� � ����� ���� ����� ������������
    if (a!=0 && discr > 0){
        printf("��������� ����� ��� ������������ �����:\n");
        printf("x1 = %f\n", (-b + sqrt(discr))/2*a);
        printf("x2 = %f\n", (-b - sqrt(discr))/2*a);
    }
    if (a!=0 && discr == 0){
        printf("��������� ����� ���� ������������ ������:\n");
        printf("x = %f\n", -b/2*a);
    }
    if (a!=0 && discr < 0){
        printf("��������� �� ����� ������������ ������\n");
    }

    return 0;
}
