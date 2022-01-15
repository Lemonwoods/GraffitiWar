#pragma once
#include<Windows.h>
class GSprite
{
public:
	GSprite(HDC hdcD,HDC hdcS,BITMAP bitmap,int spe,int z);//new ���캯��
	~GSprite();
	void Render(int,int);//��Ⱦ
	void SetHotPoint(const POINT temp);//�����ȵ�����(new)
	void SetPos(const POINT temp);//���þ���ĵ�ǰλ��(new)
	void CalculateNextPos(const POINT PositionPos);//���㾫�����һ���ȵ�����λ�� �������������(new)
	void CalculateNextPos(POINT&, bool);//��y�Ḻ����֮��ĽǶ�
	POINT CalculateNextPos(POINT&, int);
	void UpdateHotPoint();//�����ȵ�����
	void SetZ_Order(int);//���þ����Z������
	void SetAngle(double);//���þ������ת�Ƕ�
	void SetScaleFactor(double,double);//���þ��������ϵ��
	void SetBitmap(BITMAP temp);//����λͼ�ļ��ṹ��Ϣ��ָ��(new)
	void SetKeyColor(COLORREF Color);//���ùؼ�ɫ
	void SetVisibility(bool Judge);//���þ���Ŀɼ���
	void SetDestDC(HDC thdcDest);//���þ�����Ⱦ��Ŀ��DC
	void SetSpriteDC(HDC thdcSprite);//���þ���λͼDC
	void SetSpeed(int);
	int GetWidth();//��þ���Ŀ��
	int GetHeight();//��þ���ĸ߶�
	POINT GetPos();//��þ����λ��(new)
	POINT GetHotPoint();//��þ�����ȵ�����
	POINT GetCurrentPos();
	bool GetVisibility();//��þ���Ŀɼ���
	void SetTransparent(bool);//�����Ƿ����͸����Ⱦ
	bool GetTransparent();//��ȡ�Ƿ����͸����Ⱦ
	void SetSinAndCosValue(double,double);//new ���غ����������������ڸ�����������ʹ��
	void SetSinAndCosValue(double);//new ���غ����������������ڸ����Ƕ�(ע�ⲻ�ǻ��ȣ��������ʹ��
	double GetSinValue();//new
	double GetCosValue();//new
	void SetxFormAngle();//new
	void SetxFormScale();//new
	void SetxFormPos(int, int);//new
	void RotateAroundHotPoint(double,double);//new ���ȵ���ת
	void RotateAroundHotPoint(double);//new
	void ReSetTransformWorld();
	POINT GetnextHotPoint();//��ʱ�������ԣ�new��
	double Distance(int, int);//���ڼ��������Ŀ���֮��ľ���

protected:
	HDC hdcDest;//��ȾĿ��DC
	HDC hdcSprite;//������ָ���ͼƬ��Դ

	POINT currentPos;//����ĵ�ǰλ��
	POINT hotPoint;//�ȵ�����
	POINT nextHotPoint;//�������һ���ȵ�λ��

	BITMAP bitmap;
	int width;//���þ���Ŀ��
	int height;//���þ���ĸ߶�
	int Z_Order;//Z�����꣬���ھ�����Ⱦʱ�ĵ��Ӵ���
	COLORREF keyColor;//�ؼ�ɫ����ȾʱΪ͸��

	int speed;//������ٶ�

	double xScaleFactor;//�����x��������ϵ��
	double yScaleFactor;//�����y��������ϵ��
	double angle;//������ת�ĽǶ�
	double sinValue;//new ���ڴ洢��ת��sinֵ
	double cosValue;//new ���ڴ洢��ת��cosֵ
	
	XFORM xFormAngle;//�任�������ڽ���λͼ����ת
	XFORM xFormScale;//�任�������ڽ���λͼ������
	XFORM xFormPos;//�任�������ڽ���λͼ��λ��
	XFORM world;//new �ϲ�����
	XFORM reWorld;//new �ϲ��ָ�����

	bool visibility=true;//���þ���Ŀɼ���
	bool transparent;//�����Ƿ����͸����Ⱦ
};