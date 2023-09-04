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
//HBITMAP CreateGrayBitmap(int width, int height);
//void DrawBackGround(HDC HDc, HBITMAP playground, int nWidth, int nHeight);
struct _Tank
{
	int x;
	int y;
	int direction;

}; 

_Tank myTank; //我方坦克
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
	myTank.direction = 1;
	myTank.x = 100;
	myTank.y = 100;
	g_hInstance = hInstance;
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
	HWND  hwnd = CreateWindow(szAPPCLASSName, szWindowTitle, WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 0, 0, 1000, 600, NULL, NULL, hInstance, NULL);
	//显示窗口
	ShowWindow(hwnd, nCmdShow);// 显示窗口
	UpdateWindow(hwnd);//更新窗口
	//接受消息
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//虚拟消息转为字符消息
		DispatchMessage(&msg);//分发回调 

	}
	return msg.wParam;

};
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hDC;
	switch (uMsg) {
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_UP:
			myTank.direction = 1;
			myTank.y -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_LEFT:
			myTank.direction = 3;
			myTank.x -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_RIGHT:
			myTank.x = myTank.x + 10;
			myTank.direction = 4;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_DOWN:
			myTank.y = myTank.y +10;
			myTank.direction = 2;
			InvalidateRect(hWnd, NULL, TRUE);
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
	}
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
	DrawBackGround(hMemDC,bmp,nWidth,nHeight);
	DrawTank(hMemDC);
	//一次性绘制到桌面上
	BitBlt(hdc,0,0,nWidth,nHeight,hMemDC,0,0,SRCCOPY);

}
void DrawBackGround(HDC HDc,HBITMAP playground, int nWidth,int nHeight){
	HDC hMemDC = CreateCompatibleDC(HDc);
	SelectObject(hMemDC,playground);
	StretchBlt(HDc, 0, 0, nWidth,nHeight, hMemDC, 0, 0, nWidth, nHeight, SRCPAINT);
}
void DrawTank(HDC HDc) 
{
	HDC hMemDC = CreateCompatibleDC(HDc);
	//加载坦克照片
	HBITMAP hMyTank	 = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\tanky.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	switch (myTank.direction)
	{
	case 1:
		hMyTank = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\tanks.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	case 2 :
		hMyTank = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\tankx.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	case 3:
		hMyTank = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\tankz.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	case 4:
		hMyTank = (HBITMAP)LoadImage(g_hInstance, TEXT("D:\\tanky.png"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	default: 
		break;
	}
	SelectObject(hMemDC,hMyTank);
	StretchBlt(HDc,myTank.x,myTank.y,800,800,hMemDC,0,0,1000,1000, SRCPAINT);
}
