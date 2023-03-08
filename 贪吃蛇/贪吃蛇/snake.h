#pragma once


#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<map>
#include<algorithm>
#include<functional>
#include<numeric>
#include<time.h>
#include<math.h>
#include<Windows.h>
#include<conio.h>

using namespace std;

#define WIDE 60  //���
#define HIGH 20  //�߶�

//һ������Ķ���
struct BODY {
	int X;
	int Y;
};

//�����߶���
struct SNAKE {
	struct BODY body[WIDE * HIGH];
	int size;
}snake;

//����ʳ�����
struct FOOD {
	int X;
	int Y;
}food;

int score = 0;   //����

int kx = 0;   //�û�����asdw����һ���������õ�������ֵ
int ky = 0;

int lastX = 0;  //��β������
int lastY = 0;
int sleepSecond = 300;

void initSnake(void);
void initFood(void);
void initUI(void);
void initWall(void);
void playGame(void);
void showScore(void);