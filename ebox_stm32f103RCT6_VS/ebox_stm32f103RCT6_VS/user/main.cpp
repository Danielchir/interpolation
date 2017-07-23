#include "ebox.h"
#include "my_math.h"
#include "uart_vcan.h"
#include "interpolation.h"
//#define  searchDebug
//#define LinearInterpolationDebug
//#define  QuadraticInterpolationDebug
#define  Interpolation2DDebug

UartVscan vscan(&uart1);
void setup()
{
	uart1.begin(115200);
	vscan.begin(115200);
	PA8.mode(OUTPUT_PP);
}

#ifdef LinearInterpolationDebug
float x[5] = { 1,2,3,4,5 };
float y[5] = { 5,3,2,4,5 };
int length = 5;
FpsCounter fps;
LinearInterpolation liner(x, y, length);
#endif

#ifdef QuadraticInterpolationDebug
float x[10] = { 1.1,2.1,3.1,4.1,5.1,6.1,7.1,8.1,9.1,13 };
float y[10] = { 18,19,20,7,4,5,7,8,3,1 };
int length = 10;
//float x[3] = { 4,5,6 };
//float y[3] = { 10,5.25,1 };
//int length = 3;
FpsCounter fps;
QuadraticInterpolation Quadratic(x, y, length);
#endif



#ifdef searchDebug
float x[5] = { 1, 2, 3, 4, 5 };
float y[5] = { 1, 2, 3, 4, 5 };
int length = 5;
LinearInterpolation SearchDebug(x, y, length);
int main()
{
	setup()
	int z = SearchDebug.search(1.1);
	while (1)
	{
		PA8.toggle();
		delay_ms(100);
	}
	return 0;
}
#endif 

#ifdef LinearInterpolationDebug
int main()
{
	float y;

	setup();
	while (1)
	{
	//��֤���Բ�ֵ
	float x = 5;
	for (int i = 0; i < 100; i++)
	{
		y = liner.getY(x);
		x += 0.01;
		uart1.printf("%.3f\r\n", y);
	}

	//��֤��������
	//float x = -1;
	//for (int i = 0; i < 100; i++)
	//{
	//	y = liner.getY(x);
	//	x += 0.1;
	//	uart1.printf("%.3f\r\n", y);
	//}
	//PA8.toggle();
	}
	return 1;

}
#endif

#ifdef QuadraticInterpolationDebug
int main()
{
	float y;
	setup();

	//��֤������
	//float t=1.1
	//for (int i = 0; i < 10; i++)
	//{
	//	y = Quadratic.getY(t);
	//	t = t + 1;
	//	uart1.printf("%.5f\r\n", y);
	//}


	//��֤��ֵ���
	//float t = 1.1;
	//for (int i = 1; i < 200; i++)
	//{
	//	t += 0.05;
	//	y = Quadratic.getY(t);
	//	uart1.printf("%.5f\r\n", y);
	//}
	//PA8.toggle();


	//��֤�߽�֮��Ĳ�ֵ���
	float t = 0.1;
	for (int i = 1; i < 70; i++)
	{
		t += 0.2;
		y = Quadratic.getY(t);
		uart1.printf("%.5f\r\n", y);
	}
	PA8.toggle();


	return 0;

}

#endif


#ifdef Interpolation2DDebug
float x[4] = { 1,2 };
float y[4] = { 1,2 };
float z[16] = { 1,2,3,4 };
int lengthx = 2;
int lengthy = 2;
Interpolation2D Binary(x, y, z, lengthx, lengthy);
int main()
{
	setup();
	float t1 = 0.1, t2 = 0.1;
	for (int i = 0; i < 22; i++)
	{
		t2 = 0.1;
		for (int j = 0; j < 22; j++)
		{
			float fz = Binary.getZ(t1, t2);
			uart1.printf("%8.3f", fz);
			t2 += 0.1;
		}
		uart1.printf("\n");
		t1 += 0.1;
	}
	return 0;
}
#endif // Interpolation2DDebug
