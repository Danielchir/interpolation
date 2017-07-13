
#ifndef  INTERPOLATION_H
#define  INTERPOLATION_H
#include"ebox.h"
class Interpolation
{
public:
	//���캯����������������������������׵�ַ�����鳤��
	Interpolation(float *x, float *y, int n);
	//������������������������׵�ַ�����鳤��
	void setSamplePoint(float *x, float *y, int n);
	//�ö��ֲ��Ҳ�������x����������
	float *search(float x);
	//���麯������ȡ��ֵ�����������µ�ֵ
	virtual float getY(float x) = 0;
	//��ȡmeasureY
	int geyMeasureY(void);
private:
	float *xaxis;
	float *yaxis;
	int length;
	int measureY;    //����ȷ����ֵ���Ӧ��yֵ

};


class LinearInterpolation :public Interpolation
{
public:
	LinearInterpolation(float *x, float *y, int n);
	float getY(float x);

private:
	float *xaxis;
	float *yaxis;
	int length;
};



class QuadraticInterpolation :public Interpolation
{
public:
	//���캯��
	QuadraticInterpolation(float *x, float *y, int n);
	//������ി�麯��
	float getY(float x);

private:
	float *xaxis;
	float *yaxis;
	int length;

};




#endif