#include <stdio.h>
#include <TXlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
int main(){

    float a, b, c, discr;
    printf("��� ��������� ���� ax^2+bx+c = 0 ������� ������������\n");
    int var;
    printf("������� Enter");
    do {
        scanf("%*[^\n]");   //�������� �� ���� ������ �����
        printf("a = ");
        var = scanf("%f", &a);
    } while (getc(stdin) != '\n');
    printf("������� Enter");
    do {
        scanf("%*[^\n]");
        printf("b = ");
        var = scanf("%f", &b);
    } while (getc(stdin) != '\n');
    printf("������� Enter");
    do {
        scanf("%*[^\n]");
        printf("c = ");
        var = scanf("%f", &c);
    } while (getc(stdin) != '\n');
    discr = pow (b, 2) - 4*a*c; //���������� �������������
    if (a == 0 && b!=0){    //��������� ������� ��� a = 0
        printf("��������� �� ����������, � ��������. x = %f", c/b);
    }
    if (a == 0 && b ==0 && c != 0){
        printf("������ ���. ������������ ���������");
    }
    if (a == 0 && b ==0 && c == 0){
        printf("���������� ����� ������");
    }
    if (a!=0 && discr > 0){     //��������� ������� � ����� ���� ����� ������������
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
