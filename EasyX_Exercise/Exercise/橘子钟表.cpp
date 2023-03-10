/////////////////////////////////////////////////////////
// �������ƣ������ӱ�

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

const double PI = 3.141592654;	// ����Բ����


// ������
void dial()
{
	// ����ɫ����
	setbkcolor(0xe6cdb4);		// ���ñ���ɫ
	cleardevice();				// ����

	// ����ɫ��Բ
	setlinestyle(PS_SOLID, 10);	// �����߿�Ϊʮ������
	setlinecolor(YELLOW);		// ���û�����ɫΪ��ɫ
	setfillcolor(WHITE);		// ���������ɫΪ��ɫ
	fillcircle(0, 0, 170);		// ��Բ

	// ���������ɫ
	int r = 150;				// ����뾶Ϊ 150
	setlinestyle(PS_SOLID, 2);	// �����߿�Ϊ������
	for (int n = 0; n < 10; n++)
	{
		// �����Ӱ�����α���������
		POINT pts[13];				// �������飬��ʼ�㡢���Ƶ� 1�����Ƶ� 2���յ㣨��㣩�����Ƶ� 1�����Ƶ� 2���յ㣨��㣩����
		double a = 2 * PI * n / 10;	// ���Ӱ껡��
		pts[0].x = int(r / 8 * cos(a + 2 * PI / 22));
		pts[0].y = int(r / 8 * sin(a + 2 * PI / 22));	pts[12] = pts[11] = pts[0];
		pts[1].x = int(r / 12 * cos(a + 2 * PI / 22));	pts[2].x = int(r / 12 * cos(a - 2 * PI / 22));
		pts[1].y = int(r / 12 * sin(a + 2 * PI / 22));	pts[2].y = int(r / 12 * sin(a - 2 * PI / 22));
		pts[3].x = int(r / 8 * cos(a - 2 * PI / 22));
		pts[3].y = int(r / 8 * sin(a - 2 * PI / 22));	pts[4] = pts[3];
		pts[5].x = int(r * cos(a - 2 * PI / 22));
		pts[5].y = int(r * sin(a - 2 * PI / 22));		pts[6] = pts[5];
		pts[9].x = int(r * cos(a + 2 * PI / 22));
		pts[9].y = int(r * sin(a + 2 * PI / 22));		pts[10] = pts[9];
		pts[7].x = int(r * 1.1 * cos(a - 2 * PI / 30));	pts[8].x = int(r * 1.1 * cos(a + 2 * PI / 30));
		pts[7].y = int(r * 1.1 * sin(a - 2 * PI / 30));	pts[8].y = int(r * 1.1 * sin(a + 2 * PI / 30));

		int c = HSLtoRGB(36.0f * n, 0.8f, 0.8f);				// ���òʺ�ɫ
		setlinecolor(c);										// ���û�����ɫΪ�ʺ�ɫ
		polybezier(pts, 13);									// �����α���������	

		setfillcolor(c);										// �������ɫΪ�ʺ�ɫ
		floodfill(int(r / 2 * cos(a)), int(r / 2 * sin(a)), c);	// ������Ӱ�
	}

	// ��ʾ����ϸ��
	settextcolor(BLACK);				// ����������ɫ
	setbkmode(TRANSPARENT);				// ���ñ���ɫΪ͸��
	for (int n = 0; n < 12; n++)
	{
		// ����̶�
		setfillcolor(BLACK);
		solidcircle(int(145 * cos(n * 2 * PI / 12)), -int(145 * sin(n * 2 * PI / 12)), 2);
		solidcircle(int(145 * cos(n * 2 * PI / 4)), -int(145 * sin(n * 2 * PI / 4)), 4);

		// ��ʾ����
		wchar_t s[10];
		swprintf_s(s, 10, L"%d", 12 - n);		// int ����ת���� char ����

		// �������塢��С�����
		if ((12 - n) % 3 == 0)	settextstyle(48, 0, L"Broadway");
		else					settextstyle(24, 0, L"Broadway");

		// �����ַ������Ϳ�����
		int w, h;
		w = textwidth(s);
		h = textheight(s);
		outtextxy(int(125 * cos(n * 2 * PI / 12 + PI / 2) - w / 2),
			-int(125 * sin(n * 2 * PI / 12 + PI / 2) - h / 2),
			s);
	}
}


// ��ʾ����ʱ��
void digital(int h, int m, int s)
{
	// ����ʾ��ǰʱ�������С����
	setlinecolor(LIGHTGRAY);	// ���ñ߿���ɫΪǳ��ɫ
	setfillcolor(WHITE);		// ���������ɫΪ��ɫ
	fillrectangle(-40 - 13, 50, -40 + 13, 50 + 26);
	fillrectangle(-13, 50, 13, 50 + 26);
	fillrectangle(40 - 13, 50, 40 + 13, 50 + 26);

	// ��ʾ��ǰʱ��
	settextstyle(24, 0, L"Consolas");
	wchar_t a[10];
	int w;
	swprintf_s(a, 10, L"%d", h);	w = textwidth(a);	outtextxy(-40 - w / 2, 50, a);
	swprintf_s(a, 10, L"%d", m);	w = textwidth(a);	outtextxy(-w / 2, 50, a);
	swprintf_s(a, 10, L"%d", s);	w = textwidth(a);	outtextxy(40 - w / 2, 50, a);
}


// ������
void needles(int h, int m, int s)
{
	double a = PI / 2 - (2 * PI * h / 12 + 2 * PI * 1 / 12 * m / 60);	// ʱ�����߻���
	double b = PI / 2 - (2 * PI * m / 60 + 2 * PI * 1 / 60 * s / 60);	// �������߻���
	double c = PI / 2 - 2 * PI * s / 60;								// �������߻���

	setlinecolor(BLACK);												// ���û�����ɫΪ��ɫ
	setlinestyle(PS_SOLID, 9);											// �����߿�Ϊ������
	line(0, 0, int(50 * cos(a)), int(-50 * sin(a)));					// ��ʱ��

	setlinestyle(PS_SOLID, 6);											// �����߿�Ϊ������
	line(0, 0, int(100 * cos(b)), int(-100 * sin(b)));					// ������

	setlinecolor(RED);													// ���û�����ɫΪ��ɫ
	setlinestyle(PS_SOLID, 3);											// �����߿�Ϊ������
	line(int(20 * cos(c + PI)), -int(20 * sin(c + PI)), int(130 * cos(c)), -int(130 * sin(c)));	// ������
}


// ������
int main06()
{
	// ������ͼ����
	initgraph(640, 480);
	BeginBatchDraw();		// ����������ͼ
	setorigin(320, 240);	// ����ԭ��

	while (true)
	{
		// ����
		SYSTEMTIME ti;		// ����������浱ǰʱ��
		GetLocalTime(&ti);	// ��ȡ��ǰʱ��

		// �滭
		cleardevice();
		dial();										// ������
		digital(ti.wHour, ti.wMinute, ti.wSecond);	// ������ʱ��
		needles(ti.wHour, ti.wMinute, ti.wSecond);	// ������

		// ��ʱ
		FlushBatchDraw();
		Sleep(1000);
	}

	_getch();
	EndBatchDraw();
	closegraph();
	return 0;
}