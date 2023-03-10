#include <stdio.h>
#include <easyx.h>

int main03()
{
    initgraph(800, 600);

    //  ����
    setbkcolor(RGB(169, 92, 10));
    cleardevice();

    //  ������Ӱ
    setfillcolor(RGB(130, 69, 4));
    solidcircle(200, 130, 90);
    solidcircle(600, 130, 90);
    //  ��������״��Ӱ
    //setfillcolor(RGB(255, 178, 50));
    //solidcircle(200, 120, 90);
    //solidcircle(600, 120, 90);

    //  �����������
    HRGN leftEarClip = CreateEllipticRgn(110, 30, 290, 210);
    HRGN rightEarClip = CreateEllipticRgn(510, 30, 690, 210);
    HRGN earsClip = CreateRectRgn(0, 0, 0, 0);
    CombineRgn(earsClip, leftEarClip, rightEarClip, RGN_OR);
    setcliprgn(earsClip);

    //  ��������߹�
    setfillcolor(RGB(243, 154, 2));
    solidcircle(200, 130, 90);
    solidcircle(600, 130, 90);

    //  ��������
    setfillcolor(RGB(255, 178, 50));
    solidcircle(200, 210, 90);
    solidcircle(600, 210, 90);

    //  �ͷ�����
    DeleteObject(leftEarClip);
    DeleteObject(rightEarClip);
    DeleteObject(earsClip);
    //  ���ü�������
    setcliprgn(NULL);

    //  ͷ
    setfillcolor(RGB(255, 178, 50));
    solidcircle(400, 300, 250);

    //  ͷ��������
    HRGN headClip = CreateEllipticRgn(150, 50, 650, 550);
    setcliprgn(headClip);

    //  ����ͷ�߹�
    setfillcolor(RGB(243, 154, 2));
    solidcircle(400, 320, 250);

    //  �ͷ�����
    DeleteObject(headClip);
    //  ���ü�������
    setcliprgn(NULL);

    //  �۾�
    setfillcolor(RGB(51, 34, 8));
    solidcircle(275, 300, 25);
    solidcircle(525, 300, 25);

    //  ��ɫ��Բ��Ӱ
    setfillcolor(RGB(130, 69, 4));
    solidellipse(310, 385, 490, 485);

    //  ��ɫ��Բ
    setfillcolor(WHITE);
    solidellipse(310, 380, 490, 480);

    //  ����
    setfillcolor(RGB(51, 34, 8));
    solidcircle(400, 420, 15);

    //  ����
    setlinestyle(PS_SOLID, 5);
    setlinecolor(RGB(51, 34, 8));
    line(400, 420, 370, 450);
    line(400, 420, 430, 450);


    getchar();
    closegraph();
    return 0;
}