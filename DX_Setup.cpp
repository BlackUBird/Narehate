/*
	�E�B���h�E���[�h/�t���X�N���[�����[�h�̌����
	�E�B���h�E�T�C�Y�̏��Ȃ�
	�K�w�F1
*/
#include "DX_Setup.h"
#include "DxLib.h"

// ����������
int DX_Setup_Init( DXSetup_Setup* setup ,
				   int ScreenSizeX ,
				   int ScreenSizeY ,
				   int ScreenColorBitNum ,
				   int WindowMode )
{
	// �ݒ�A�ύX-------------------------------------------
	// �E�C���h�E���[�h�ɕύX
	if( ChangeWindowMode( WindowMode ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// ��ʃ��[�h�̐ݒ�
	if( SetGraphMode( ScreenSizeX , ScreenSizeY , ScreenColorBitNum ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}

	// ����ێ�---------------------------------
	// �X�N���[�����
	// ��ʃT�C�Y���Z�b�g
	setup->Screen.SizeX = ScreenSizeX;
	setup->Screen.SizeY = ScreenSizeY;
	// �J���[�r�b�g�����Z�b�g
	setup->Screen.ColorBitNum = ScreenColorBitNum;

	// �E�B���h�E���
	// �E�B���h�E���[�h���Z�b�g
	setup->Window.Mode = WindowMode;

	return 0;
}

// �`�揈��
int DX_Setup_Draw( DXSetup_Setup setup , int CoordX , int CoordY ,int Color )
{
	// �\������ʒu
	int x,y;
	// ���������̒l�Ȃ�(0,0)
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

	// �`��-----------------------------------------------
	// �`�悷����̐�(�s��)
	int RowCnt = 0;
	// �X�N���[������`��
	DrawFormatString( x , y+16*RowCnt++ , Color , "ScreenSizeX=%d ScreenSizeY=%d" , setup.Screen.SizeX , setup.Screen.SizeY );
	DrawFormatString( x , y+16*RowCnt++ , Color , "ScreenColorBitNum=%d" , setup.Screen.ColorBitNum );
	// �E�B���h�E���
	DrawFormatString( x , y+16*RowCnt++ , Color , "WindowMode=%s" , setup.Window.Mode == TRUE ? "WindowMode" : "FullScreen" );

	return (y+16*RowCnt);
}

// �擾�p
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

// �I������
int DX_Setup_Finalize( DXSetup_Setup* setup )
{
	DxLib_End();
	return 0;
}