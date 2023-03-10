/*	*************************
 *	�������ƣ�	LoveSnow - ��׳���
 *	********* ˵�� **********
 *	��Ҫ�Լ��ṩһ�Ŵ�СΪ 640��480 ��ͼƬ(img.jpg)����Ŀ��Ŀ¼��
 *	��С�����ڳ����ڸ��ģ�ͼƬ����Ҳ���ԡ�
 *	*************************/
#include <graphics.h>

#define MAX_STAR 500			// ѩ����������
#define SCREEN_WIDTH 640		// ��Ļ���
#define SCREEN_HEIGHT 480		// ��Ļ�߶�
#define MAX_STEP 3				// ѩ��ÿ���ƶ���߲���
#define MAX_RADIUS 3			// ѩ�����뾶
#define IMGNAME _T("���.jpg")	// ͼƬ����

using namespace std;

// ͼƬת���飨����кܴ��Ż��ռ�ģ���Ҫʶ���ɫ��Ƭ���Կ��⣩
int imgList[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

// ѩ��״̬
enum STATUS
{
	STOP = 0,	// ����
	UP,			// ����
	DOWN,		// ����
	LEFT,		// ����
	RIGHT,		// ����
	RANDOM,		// ���
	ALL_STATUS	// ��¼״̬����
};
struct STAR
{
	int x;				// ѩ���� x ����
	int y;				// ѩ���� y ����
	enum STATUS stat;	// ѩ��״̬
	unsigned radius;	// ѩ���İ뾶
	int step;			// ѩ��ÿ���ƶ��Ĳ���
	int color;			// ѩ������ɫ
};
struct SqList
{
	struct STAR* elems; // ˳���Ļ���ַ
	int length;			// ˳���ĳ���
	int size;			// ˳���Ŀռ�
};

// ˳���Ľӿ�
bool initList(SqList& L);
bool listAppend(SqList& L, struct STAR e);
bool listDelete(SqList& L, int i);
void destroyList(SqList& L);

bool initList(SqList& L)
{
	L.elems = new struct STAR[MAX_STAR];
	if (!L.elems) return false;
	L.length = 0;
	L.size = MAX_STAR;
	return true;
}
bool listAppend(SqList& L, struct STAR e)
{
	if (L.length == L.size) return false;	// �洢�ռ�����
	L.elems[L.length] = e;
	L.length++;								// ���� 1
	return true;
}
bool listDelete(SqList& L, int i)
{
	if (i < 0 || i >= L.length) return false;
	if (i == L.length - 1)
	{										// ɾ�����һ��Ԫ��
		L.length--;
		return true;
	}
	for (int j = i; j < L.length - 1; j++)
	{
		L.elems[j] = L.elems[j + 1];		// ɾ��λ�õĺ���Ԫ��һ����ǰ��
	}
	L.length--;
	return true;
}
void destroyList(SqList& L)
{
	if (L.elems) delete[]L.elems;			// �ͷŴ洢�ռ�
	L.length = 0;
	L.size = 0;
}

/************************************
* ���ܣ��ƶ�ѩ��������ָ����������ѩ��
* ���������
* L - ѩ������
* i - ѩ����ȫ�������е��±�
* ����ֵ����
************************************/
void MoveStar(SqList& L, int i)
{
	// ����ѩ��
	if (L.elems[i].stat == DOWN)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1)
		{
			L.elems[i].y += L.elems[i].step;
			L.elems[i].x -= 2;
		}
	}
	if (L.elems[i].stat == UP)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1)
		{
			L.elems[i].y -= L.elems[i].step;
			L.elems[i].x -= 2;
		}
	}
	if (L.elems[i].stat == LEFT)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) L.elems[i].x -= L.elems[i].step;
	}
	if (L.elems[i].stat == RIGHT)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) L.elems[i].x += L.elems[i].step;
	}

	if (L.elems[i].stat == STOP) return;
	// ����ԭ����ѩ��
	setfillcolor(BLACK);
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius);
	if (L.elems[i].stat == DOWN)
	{
		L.elems[i].y += L.elems[i].step;
		L.elems[i].x -= 2;
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH;
		if (L.elems[i].y > SCREEN_HEIGHT) L.elems[i].y = 0;
		//if(L.elems[i].y>SCREEN_HEIGHT) listDelete(L, i);	// ��δ��������Ʈ����Ļ���ѩ������
	}
	else if (L.elems[i].stat == UP)
	{
		L.elems[i].y -= L.elems[i].step;
		L.elems[i].x -= 2;
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH;
		if (L.elems[i].y < 0) L.elems[i].y = SCREEN_HEIGHT;
		//if(L.elems[i].y<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == LEFT)
	{
		L.elems[i].x -= L.elems[i].step;
		if (L.elems[i].x > 0) L.elems[i].x = SCREEN_WIDTH;
		//if(L.elems[i].x<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == RIGHT)
	{
		L.elems[i].x += L.elems[i].step;
		if (L.elems[i].x > SCREEN_HEIGHT) L.elems[i].x = 0;
		//if(L.elems[i].x>SCREEN_WIDTH) listDelete(L, i);
	}
	setfillcolor(L.elems[i].color);
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius);
}


/************************************
* ���ܣ���ʼ��ѩ��
* ���������
* i - ѩ����ȫ�������е��±�
* ����ֵ����
************************************/
void initStar(struct STAR& _star)
{
	int rgb = 0;
	//rand() �õ��������Χ 0 - 32767 RAND_MAX
	_star.x = rand() % SCREEN_WIDTH;		// x ��Χ 0 - SCREEN_WIDTH
	_star.y = rand() % SCREEN_HEIGHT;		// y ��Χ 0 - SCREEN_HEIGHT
	//_star.stat = STATUS(rand() % 6);		// ѩ��״̬�����
	_star.stat = DOWN;						// ѩ��״̬������
	_star.radius = 1 + rand() % MAX_RADIUS; // �뾶���� 1 - MAX_RADIUS
	_star.step = rand() % MAX_STEP + 1;		// ���� 1 - MAX_STEP
	rgb = 255 * _star.step / MAX_STEP;		// RGB��0 - 255
	_star.color = RGB(rgb, rgb, rgb);
}


int main02()
{
	bool quit = false;
	struct STAR star;
	SqList starList;

	// ��ʼ����Ļ
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	// ��ʼ��ͼƬ
	IMAGE img(SCREEN_WIDTH, SCREEN_HEIGHT);
	//loadimage(&img, IMGNAME);
	SetWorkingImage(&img);	// ���� imgΪ�����豸
	setbkcolor(WHITE);
	cleardevice();
	settextcolor(BLACK);
	settextstyle(120, 55, _T("����"));
	outtextxy(100, 150, _T("���ض���"));
	//outtextxy(100, 250, _T("��һ����"));
	COLORREF color;			// ��¼������ɫ
	BYTE r, b, g;			// ��¼����RGB

	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			color = getpixel(x, y);		// ��ȡ������ɫ
			r = GetRValue(color);
			b = GetBValue(color);
			g = GetGValue(color);
			if (r < 200 && b < 200 && g < 200)
			{							// �ж������¡�ѩ�ۡ�������λ��
				imgList[y][x] = 1;
			}
		}
	}

	SetWorkingImage();	// ���û�Ĭ�ϻ����豸
	cleardevice();

	// ��ʼ������ѩ��״̬��˳���
	initList(starList);

	for (int i = 0; i < MAX_STAR; i++)
	{
		initStar(star);
		listAppend(starList, star);
	}

	for (int i = 0; i < starList.length; i++)
	{
		setfillcolor(starList.elems[i].color);
		solidcircle(starList.elems[i].x, starList.elems[i].y,
			starList.elems[i].radius);
	}

	while (quit == false)
	{
		for (int i = 0; i < starList.length; i++)
		{
			MoveStar(starList, i);
		}

		if (starList.length == 0)
		{	// ������ѩ���뿪��Ļ����������ᴥ�����˳�
			quit = true;
		}
		Sleep(50);
	}
	system("pause");
	closegraph();
	return 0;
}