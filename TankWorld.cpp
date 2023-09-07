#include<Windows.h>
#include <iostream>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//HWND 窗口句柄
//UINT 无符号整形 消息类型 鼠标点击消息
//WPARAM 窗口附加信息  鼠标点击坐标
//LPARAM 窗口附加信息  鼠标按键
HINSTANCE g_hInstance;
void OnPaint(HWND hwnd, HDC hdc);
void DrawTank(HDC hDC);
void DrawBackGround(HDC HDc, HBITMAP playground, int nWidth, int nHeight);
void DrawZD(HDC hdczd, int x, int y, int direction);
void MoveZD(HDC h, int o);
//HBITMAP CreateGrayBitmap(int width, int height);
//void DrawBackGround(HDC HDc, HBITMAP playground, int nWidth, int nHeight);
struct _Tank
{
	int x;
	int y;
	int direction;
	int pointx;
	int pointy;
	int height;
	int wed;
}; 
struct ZD {
	int x;
	int y;
	int height;
	int wed;
	int direction;
};
_Tank myTank; //我方坦克
struct ZD zd[20];
static int zdcount;
HBITMAP hMyZD, hMyZD1, hMyZD2, hMyZD3, hMyZD4,hMyTank1,hMyTank2,hMyTank3,hMyTank4;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
    hMyZD = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\progect\\TankWorld\\picture\\black.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMyZD1 = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\progect\\TankWorld\\picture\\picturezds.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMyZD2 = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\progect\\TankWorld\\picture\\picturezdx.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMyZD3 = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\progect\\TankWorld\\picture\\picturezdz.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMyZD4 = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\progect\\TankWorld\\picture\\y.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMyTank2 = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\tankx.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMyTank1 = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\tanks.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMyTank3 = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\tankz.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hMyTank4 = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\tanky.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	myTank.direction = 1;
	myTank.pointx = 400;
	myTank.pointy = 400;
	myTank.wed = 400;
	myTank.height = 600;
	g_hInstance = hInstance;
	zdcount = 0;
	TCHAR szAPPCLASSName[] = TEXT("TankWorld CRL");
	WNDCLASS wc = { 0 };
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);//软件背景颜色
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);         //加载光标箭头
	wc.hInstance = hInstance;                        //当前应用程序实例句柄
	wc.lpfnWndProc = WindowProc;                    //窗口处理函数     
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;              //窗口类的风格
	wc.lpszClassName = szAPPCLASSName;        //类名
	MSG msg;
	//注册窗口类
	if (!RegisterClass(&wc)) {
		MessageBox(NULL, TEXT("窗口注册失败"), TEXT("错误"), MB_OK | MB_ICONERROR);
		return 0;
	}
	//创建窗口
	TCHAR szWindowTitle[] = TEXT("TankWorld");
	HWND  hwnd = CreateWindow(szAPPCLASSName, szWindowTitle, WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 260, 20, 1000,800, NULL, NULL, hInstance, NULL);
	//显示窗口
	SetTimer(hwnd, 1, 10, NULL);
	ShowWindow(hwnd, nCmdShow);// 显示窗口
	UpdateWindow(hwnd);//更新窗口
	//接受消息
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//虚拟消息转为字符消息
		DispatchMessage(&msg);//分发回调 

	}
	DeleteObject(hMyTank1);
	DeleteObject(hMyTank2);
	DeleteObject(hMyTank3);
	DeleteObject(hMyTank4);
	DeleteObject(hMyZD1);
	DeleteObject(hMyZD2);
	DeleteObject(hMyZD3);
	DeleteObject(hMyZD4);
	return msg.wParam;
};
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hDC{};
	static int count = 0;
	switch (uMsg) {
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_LEFT: {
			if (myTank.direction!=3) {
				count = 0;
			}
			else {
				count++;
			}
			myTank.height = 400;
			myTank.wed = 600;
			myTank.direction = 3;
			if (count!=0) {
				myTank.pointx -= 10;

			}
			//InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		case VK_RIGHT: {
			if (myTank.direction != 4) {
				count = 0;
			}
			else {
				count++;
			}
			myTank.height = 400;
			myTank.wed = 600;
			if (count!=0) {
				myTank.pointx += 10;
			}
			myTank.direction = 4;
			//InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		case VK_UP:
			if (myTank.direction != 1) {
				count = 0;
			}
			else {
				count++;
			}
			myTank.height = 600;
			myTank.wed = 400;
			myTank.direction = 1;
			if (count!=0) {
				myTank.pointy -= 10;
			}
			//InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_DOWN:
			if (myTank.direction != 2) {
				count = 0;
			}
			else {
				count++;
			}
			myTank.height = 600;
			myTank.wed = 400;
			if (count!=0) {
				myTank.pointy += 10;
			}
			myTank.direction = 2;
			//InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_SPACE:   //空格键发射子弹
			//依据坦克的方向设置子弹的方向
			int x = 0, y = 0;
			if (myTank.direction==2) {
				//在数组中新加一个子弹
				x = myTank.pointx - 171;
				y = myTank.pointy - 230;
				struct ZD z = { x,y,6,20,myTank.direction };
				zd[zdcount] = z;
				zdcount++;
			}
			else if (myTank.direction == 1) {
				x = myTank.pointx - 171;
					y = myTank.pointy - 320;
				struct ZD z = { x,y,6,20,myTank.direction };
				zd[zdcount] = z;
				zdcount++;
			}
			else if (myTank.direction==3) {
				x = myTank.pointx - 222;
				y = myTank.pointy - 267;
				struct ZD z = { x,y,20,5,myTank.direction };
				zd[zdcount] = z;
				zdcount++;
			}
			else if (myTank.direction==4) {
				x = myTank.pointx - 132;
				y = myTank.pointy - 266;
				struct ZD z = { x,y,20,5,myTank.direction };
				zd[zdcount] = z;
				zdcount++;
			}
			break;
		}
	case WM_CREATE: {
		RECT rect;
		GetClientRect(hWnd, &rect);
		int nWidth = rect.right - rect.left;
		int nHeight = rect.bottom - rect.top;
		break;
	}
	case WM_PAINT:
	   hDC =	BeginPaint(hWnd,&ps);
		//绘制坦克
		//加载图片
	  OnPaint(hWnd,hDC);
	  //显示图片
	  //创建内存DC
	  //设备上下文
	  //GDI图形设备接口
	  EndPaint(hWnd,&ps);
	  break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		//设置计时器 强制窗口重绘
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, TRUE); // 强制窗口重绘
		break;
	case	WM_ERASEBKGND:
		return TRUE;
	}
	InvalidateRect(hWnd, NULL, TRUE);
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
void OnPaint(HWND hwnd,HDC hdc) {
	//采用双缓冲机制
	//获取窗口大小
	RECT rect;
	GetClientRect(hwnd,&rect);
	int nWidth = rect.right - rect.left;
	int nHeight = rect.bottom - rect.top;
	//创建一张位图 纯黑色
	HBITMAP bmp = CreateCompatibleBitmap(hdc,nWidth,nHeight);
	////创建内存DC
	HDC hMemDC = CreateCompatibleDC(hdc);
  	SelectObject(hMemDC,bmp);
	DrawBackGround(hMemDC, bmp, nWidth, nHeight);
	DrawTank(hMemDC);
	//一次性绘制到桌面
	if (zdcount!=0) {
		for (int i = 0; i < zdcount; i++) {
			struct ZD z = zd[i];
			DrawZD(hMemDC, z.x, z.y, z.direction);
		}
	}
	BitBlt(hdc,0,0,nWidth,nHeight,hMemDC,0,0,SRCCOPY);
	DeleteDC(hMemDC);
	DeleteObject(bmp);
	ReleaseDC(hwnd,hdc);
}
void DrawBackGround(HDC HDc,HBITMAP playground, int nWidth,int nHeight){
	HDC hMemDC = CreateCompatibleDC(HDc);
	SelectObject(hMemDC,playground);
	StretchBlt(HDc, 0, 0, nWidth,nHeight, hMemDC, 0, 0, nWidth, nHeight, SRCPAINT);
	DeleteDC(hMemDC);
}
void DrawTank(HDC HDc) 
{
	HDC hMemDC = CreateCompatibleDC(HDc);
	//加载坦克照片
	switch (myTank.direction)
	{
		//依据方向载入图片
	case 1:
		SelectObject(hMemDC, hMyTank1);
		goto a;
	case 2 :
		SelectObject(hMemDC, hMyTank2);
		goto a;
	case 3:
		SelectObject(hMemDC, hMyTank3);
		goto a;
	case 4:
		SelectObject(hMemDC, hMyTank4);
		goto a;
	default: 
		goto a;
	}
	a:
	int x = 0;
	int y = 0;
	if (myTank.direction==1) {
		 x = myTank.pointx -1- myTank.wed/2;
		 y = myTank.pointy -6- myTank.height/2;

	}
	if (myTank.direction == 2) {
		 x = myTank.pointx-2-myTank.wed/2;
		 y = myTank.pointy-2-myTank.height/2;

	}
	if (myTank.direction==3) {
		x = myTank.pointx -10- myTank.height / 2;
		y = myTank.pointy +2- myTank.wed / 2;
	}
	if (myTank.direction==4) {
		x = myTank.pointx -5 - myTank.height / 2;
		y = myTank.pointy +5 - myTank.wed/ 2;
	}
	for (int i = 0; i < zdcount; i++) {
		MoveZD(hMemDC, i);
	}
	//将子弹绘制出来
	StretchBlt(HDc, x, y, myTank.height,myTank.wed, hMemDC, 0, 0, 1000, 1000, SRCPAINT);
	DeleteDC(hMemDC);
}
void DrawPICTURE(HDC HDc, HBITMAP picture)
{
	HDC hMemDC = CreateCompatibleDC(HDc);
	//加载坦克照片
	HBITMAP hMyTank = picture;
	SelectObject(hMemDC, hMyTank);
	int x = 0;
	int y = 0;
	StretchBlt(HDc, x, y, myTank.height, myTank.wed, hMemDC, 0, 0, 1000, 1000, SRCPAINT);
	DeleteObject(hMyTank);
	DeleteDC(hMemDC);
}
void DrawZD(HDC hdczd, int x, int y, int direction) {
	HDC hMemZD = CreateCompatibleDC(hdczd);
	//加载坦克照片
	HBITMAP hMyZDC = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\progect\\TankWorld\\picture\\picturezds.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	switch (direction)
	{
	case 1:
		SelectObject(hMemZD, hMyZD1);
		break;
	case 2:
		SelectObject(hMemZD, hMyZD2);
		break;
	case 3:
		SelectObject(hMemZD, hMyZD3);;
		break;
	case 4:
		SelectObject(hMemZD, hMyZD4);
		break;
	default:
		break;
	}
	if (direction==3) {
		StretchBlt(hdczd, x, y, 20, 5, hMemZD, 27,33, 178,34, SRCPAINT);
	}else if (direction==4) {
		StretchBlt(hdczd, x, y, 20, 5, hMemZD, 27,33, 178, 34, SRCPAINT);
	}
	else {
		StretchBlt(hdczd, x, y, 6, 20, hMemZD, 39, 20, 30, 149, SRCPAINT);
	}
	DeleteObject(hMyZDC);
	DeleteDC(hMemZD);
}
void MoveZD(HDC h, int o) {
	int x = 0, y = 0;
	x = zd[o].x;
	y = zd[o].y;
	HDC hMemZ = CreateCompatibleDC(h);
	//覆盖之前的子弹
	SelectObject(hMemZ, hMyZD);
	StretchBlt(h, x, y, myTank.height, myTank.wed, hMemZ, 0, 0, 1000, 1000, SRCPAINT);
	DeleteObject(hMyZD);
	switch (zd[o].direction) {
	//根据方向计算下一步子弹的坐标
	case 1:
		SelectObject(hMemZ, hMyZD1);
		zd[o].y -= 1;
		break;
	case 2:
		SelectObject(hMemZ, hMyZD2);
		zd[o].y += 1;
		break;
	case 3:
		SelectObject(hMemZ, hMyZD3);
		zd[o].x -= 1;
		break;
	case 4:
		SelectObject(hMemZ, hMyZD4);
		zd[o].x += 1;
		break;
	default:
		break;
	}
	StretchBlt(h, zd[o].x, zd[o].y, zd[o].height, zd[o].wed, hMemZ, 0, 0, 1000, 1000, SRCPAINT);
	DeleteObject(hMyZD);
	DeleteDC(hMemZ);
}
