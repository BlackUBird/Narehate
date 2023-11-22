/*
	ウィンドウモード/フルスクリーンモードの決定や
	ウィンドウサイズの情報など
	階層：1
*/
#include "DX_Setup.h"
#include "DxLib.h"

// 初期化処理
int DX_Setup_Init( DXSetup_Setup* setup ,
				   int ScreenSizeX ,
				   int ScreenSizeY ,
				   int ScreenColorBitNum ,
				   int WindowMode )
{
	// 設定、変更-------------------------------------------
	// ウインドウモードに変更
	if( ChangeWindowMode( WindowMode ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// 画面モードの設定
	if( SetGraphMode( ScreenSizeX , ScreenSizeY , ScreenColorBitNum ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 )
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}

	// 情報を保持---------------------------------
	// スクリーン情報
	// 画面サイズをセット
	setup->Screen.SizeX = ScreenSizeX;
	setup->Screen.SizeY = ScreenSizeY;
	// カラービット数をセット
	setup->Screen.ColorBitNum = ScreenColorBitNum;

	// ウィンドウ情報
	// ウィンドウモードをセット
	setup->Window.Mode = WindowMode;

	return 0;
}

// 描画処理
int DX_Setup_Draw( DXSetup_Setup setup , int CoordX , int CoordY ,int Color )
{
	// 表示する位置
	int x,y;
	// 引数が負の値なら(0,0)
	if( CoordX < 0 || CoordY < 0 )
	{
		x = 0;
		y = 0;
	}
	else
	{
		x = CoordX;
		y = CoordY;
	}

	// 描画-----------------------------------------------
	// 描画する情報の数(行数)
	int RowCnt = 0;
	// スクリーン情報を描画
	DrawFormatString( x , y+16*RowCnt++ , Color , "ScreenSizeX=%d ScreenSizeY=%d" , setup.Screen.SizeX , setup.Screen.SizeY );
	DrawFormatString( x , y+16*RowCnt++ , Color , "ScreenColorBitNum=%d" , setup.Screen.ColorBitNum );
	// ウィンドウ情報
	DrawFormatString( x , y+16*RowCnt++ , Color , "WindowMode=%s" , setup.Window.Mode == TRUE ? "WindowMode" : "FullScreen" );

	return (y+16*RowCnt);
}

// 取得用
int DX_Setup_GetScreenSizeX( DXSetup_Setup setup )
{
	return (setup.Screen.SizeX);
}
int DX_Setup_GetScreenSizeY( DXSetup_Setup setup )
{
	return (setup.Screen.SizeY);
}
int DX_Setup_GetScreenColorBitNum( DXSetup_Setup setup )
{
	return (setup.Screen.ColorBitNum);
}
int DX_Setup_GetWindowMode( DXSetup_Setup setup )
{
	return (setup.Window.Mode);
}

// 終了処理
int DX_Setup_Finalize( DXSetup_Setup* setup )
{
	DxLib_End();
	return 0;
}