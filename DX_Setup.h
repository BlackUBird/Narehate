/*
	ウィンドウモード/フルスクリーンモードの決定や
	ウィンドウサイズの情報など
	階層：1
*/
#ifndef __DX_SETUP_H__
#define __DX_SETUP_H__

// スクリーン情報
typedef struct ts_DXSetup_Status_Screen
{
	int SizeX;	// 横
	int SizeY;	// 縦
	int ColorBitNum;	// カラービット数
} DXSetup_Status_Screen;

// ウィンドウ情報
typedef struct ts_DXSetup_Status_Window
{
	int Mode;	// ウィンドウモード
} DXSetup_Status_Window;


// 情報
typedef struct ts_DXSetup_Status
{
	DXSetup_Status_Screen Screen;	// スクリーン情報
	DXSetup_Status_Window Window;	// ウィンドウ情報
} DXSetup_Setup;

// 情報を保持
static DXSetup_Setup setupOld;

// 初期化処理
int DX_Setup_Init( DXSetup_Setup* setup ,
				   int ScreenSizeX ,
				   int ScreenSizeY ,
				   int ScreenColorBitNum ,
				   int WindowMode );

// 描画処理
/*
	各情報を表示するだけ
*/
int DX_Setup_Draw( DXSetup_Setup setup , int CoordX , int CoordY ,int Color );

// 取得用
int DX_Setup_GetScreenSizeX( DXSetup_Setup setup );
int DX_Setup_GetScreenSizeY( DXSetup_Setup setup );
int DX_Setup_GetScreenColorBitNum( DXSetup_Setup setup );
int DX_Setup_GetWindowMode( DXSetup_Setup setup );

// 更新処理(いらなくね?画面サイズ変えるとかいう奇行に走るとき用?)
int DX_Setup_Update( DXSetup_Setup* setup );

// 終了処理
int DX_Setup_Finalize( DXSetup_Setup* setup );

#endif