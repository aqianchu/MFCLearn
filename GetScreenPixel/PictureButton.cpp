// PictureButton.cpp : 实现文件
//

#include "stdafx.h"
#include "PictureButton.h"


// PictureButton
CPictureButton::CPictureButton(void)
	:CButtonST()
{
}


CPictureButton::~CPictureButton(void)
{
}


void CPictureButton::SetBitmapImage(int nID, int style)
{
	switch ( style )
	{
	case STYLE_BITMAP_BUTTON:		// Bitmap button（效果比禁用的Button控件好一点）
		SetBitmaps( nID, RGB(255, 255, 255));
		SetAlign(CButtonST::ST_ALIGN_OVERLAP, FALSE);
		SetPressedStyle(CButtonST::BTNST_PRESSED_TOPBOTTOM, FALSE);
		SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(255, 255, 255));
		SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0, 0, 0));
		SizeToContent();
		DrawBorder(FALSE, FALSE);
		break;
	case STYLE_CHECKBOX:		// Checkbox
		//		m_chkCheckbox.SetIcon(IDI_LEDON, IDI_LEDOFF);
		//		m_chkCheckbox.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
		break;
	case STYLE_LOGO:			// Logo Button 禁用的Button控件
		m_bShowDisabledBitmap = FALSE;
		SetBitmaps( nID, RGB(255, 255, 255));
		break;
	default:
		SetBitmaps( nID, RGB(255, 255, 255), 0, RGB(255, 255, 255));
		DrawTransparent();
		break;
	}
}
