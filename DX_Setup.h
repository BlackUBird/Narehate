/*
	�E�B���h�E���[�h/�t���X�N���[�����[�h�̌����
	�E�B���h�E�T�C�Y�̏��Ȃ�
	�K�w�F1
*/
#ifndef __DX_SETUP_H__
#define __DX_SETUP_H__

// �X�N���[�����
typedef struct ts_DXSetup_Status_Screen
{
	int SizeX;	// ��
	int SizeY;	// �c
	int ColorBitNum;	// �J���[�r�b�g��
} DXSetup_Status_Screen;

// �E�B���h�E���
typedef struct ts_DXSetup_Status_Window
{
	int Mode;	// �E�B���h�E���[�h
} DXSetup_Status_Window;


// ���
typedef struct ts_DXSetup_Status
{
	DXSetup_Status_Screen Screen;	// �X�N���[�����
	DXSetup_Status_Window Window;	// �E�B���h�E���
} DXSetup_Setup;

// ����ێ�
static DXSetup_Setup setupOld;

// ����������
int DX_Setup_Init( DXSetup_Setup* setup ,
				   int ScreenSizeX ,
				   int ScreenSizeY ,
				   int ScreenColorBitNum ,
				   int WindowMode );

// �`�揈��
/*
	�e����\�����邾��
*/
int DX_Setup_Draw( DXSetup_Setup setup , int CoordX , int CoordY ,int Color );

// �擾�p
int DX_Setup_GetScreenSizeX( DXSetup_Setup setup );
int DX_Setup_GetScreenSizeY( DXSetup_Setup setup );
int DX_Setup_GetScreenColorBitNum( DXSetup_Setup setup );
int DX_Setup_GetWindowMode( DXSetup_Setup setup );

// �X�V����(����Ȃ���?��ʃT�C�Y�ς���Ƃ�������s�ɑ���Ƃ��p?)
int DX_Setup_Update( DXSetup_Setup* setup );

// �I������
int DX_Setup_Finalize( DXSetup_Setup* setup );

#endif