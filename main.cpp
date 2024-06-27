// Dxライブラリを使ったsin, cosの円運動
#define _USE_MATH_DEFINES	// PIを使いたい場合

#include "DxLib.h"
#include <math.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const int WIDTH = 960, HEIGHT = 640;

	SetWindowText("Sin,Cosの円運動");
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) return -1;

	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	SetWaitVSyncFlag(TRUE);

	double r = 0;

	while (true)
	{
		ClearDrawScreen();

		// 中心点表示
		DrawCircle(WIDTH / 2, HEIGHT / 2, 10, 0xffffff);

		int x = (int)(cos(r) * 100);
		int y = (int)(sin(r) * 100);

		DrawCircle(x + WIDTH/2, y + HEIGHT/2, 10, 0xff00ff);
		r += 0.01;

		ScreenFlip();
		if (ProcessMessage() == -1) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
	}

	DxLib_End();

	return 0;
}