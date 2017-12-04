#include <stdio.h>
#define BASE 1000		//�������� 100��Ԫ/h
#define TIME 40			//����40hΪ�Ӱ�
#define	MUL	1.5			//�Ӱ�ʱ������ƽʱ��1.5��
#define	RATE1 0.15		//ǰ300��Ԫ��˰��
#define RATE2 0.2		//300-450��Ԫ��˰��
#define RATE3 0.25		//����450��Ԫ��˰��
#define BREAK1 300		//˰�ʵĵ�һ���ֽ��
#define BREAK2 450		//˰�ʵĵڶ����ֽ��
int main(void)
{
	double hour, tax, gross;
	
	printf("Input your work hours in a week: ");
	scanf("%lf", &hour);
	if (hour <= TIME)
		gross = hour * BASE;
	else
		gross = TIME * BASE + (hour - TIME) * MUL * BASE;
	//����������
	if (gross <= BREAK1)
		tax = gross * RATE1;
	else if (gross <= BREAK2)
		tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
	else
		tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2 
			+ (gross - BREAK2) * RATE3;
	//����˰��
	printf("Your gross income is $%.2lf\nYour tax is $%.2lf\n" 
			"Your net income is $%.2lf\n",
			gross, tax, (gross - tax));
	
	return 0;
}

