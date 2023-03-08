#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"



int main(void) {
	//ȥ�����
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;  //����Ϊfalse���겻�ɼ�
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	srand(time(NULL));  //�������������
	initWall();      //��ǽ
	initSnake();   //��ʼ����
	initFood();    //��ʼ��ʳ��
	initUI();      //���ߺ�ʳ��
	playGame();   //������Ϸ

	showScore();  //��ӡ����
	system("pause");
	return 0;
}

//������Ϸ
void playGame(void) {

	char key = 'd';

	//�ж���ײǽ
	while (snake.body[0].X >= 0 && snake.body[0].X < WIDE
		&& snake.body[0].Y >= 0 && snake.body[0].Y < HIGH) {
		initUI();  //������

		//�����û���������
		if (_kbhit()) {     //Ϊ��ʱ��˵���û����°���   _kbhit()�������ж��û�����
			key = _getch();   //                         _getch()�����Զ�ȡһ���ַ�
		}
		switch (key) {
		case 'w':	kx = 0;  ky = -1; break;
		case 's':	kx = 0;  ky = +1; break;
		case 'a':	kx = -1; ky = 0;  break;
		case 'd':	kx = +1; ky = 0;  break;
		default:	break;
		}

		//��ͷײ���� ��ͷ==��һһ������
		for (size_t i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
				return;    //��Ϸ����
		}
		//��ͷײʳ��
		if (snake.body[0].X == food.X && snake.body[0].Y == food.Y) {
			initFood();     //ʳ����ʧ		
			snake.size++;   //��������
			score += 10;    //�ӷ�
			sleepSecond -= 25;//����
		}

		//�洢��β����
		lastX = snake.body[snake.size - 1].X;
		lastY = snake.body[snake.size - 1].Y;

		//���ƶ���ǰһ���������һ�����帳ֵ
		for (size_t k = snake.size - 1; k > 0; k--)
		{
			snake.body[k].X = snake.body[k - 1].X;
			snake.body[k].Y = snake.body[k - 1].Y;
		}

		snake.body[0].X += kx;   //��ͷ��������û����� �޸�
		snake.body[0].Y += ky;

		Sleep(sleepSecond);
	}
	return;
}

//��ǽ
void initWall(void) {
	for (size_t i = 0; i <= HIGH; i++)
	{
		for (size_t j = 0; j <= WIDE; j++)
		{
			if (j == WIDE)
				cout << "|";
			else if (i == HIGH)
				cout << "_";
			else
				cout << " ";
		}
		cout << endl;
	}
}

//�����ʼ���ߺ���
void initSnake(void) {
	snake.size = 2;

	snake.body[0].X = WIDE / 2;		 //��ͷ��ʼ��
	snake.body[0].Y = HIGH / 2;

	snake.body[1].X = WIDE / 2 - 1;  //�ߵ�һ�������ʼ��
	snake.body[1].Y = HIGH / 2;

	return;
}

//ʳ��ĳ�ʼ������
void initFood(void) {
	food.X = rand() % WIDE;  // 0-59
	food.Y = rand() % HIGH;  // 0-19

	return;
}

//��ʼ������ؼ�
void initUI(void) {
	COORD coord = {0};         //����ƶ���λ��

	//����
	for (size_t i = 0; i < snake.size; i++)
	{
		coord.X = snake.body[i].X;
		coord.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

		if(i==0)
			putchar('@');
		else 
			putchar('*');
	}

	//ȥ����β
	coord.X = lastX;
	coord.Y = lastY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');

	//��ʳ��
	coord.X = food.X;
	coord.Y = food.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');
}

//��ӡ����
void showScore(void) {
	//�����Ĭ��λ���ƶ��� ��������Ϸ��λ��
	COORD coord;
	coord.X = 0;
	coord.Y = HIGH + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	cout << "Game Over!!!" << endl;
	cout << "�ɼ�Ϊ��" << score << endl<<endl<<endl;
}