#pragma once
#include "btnst.h"


// PictureButton
// 用于简便地使用带有透明色彩图像的按钮
class CPictureButton :
	public CButtonST
{
public:
	enum{STYLE_DEFAULT, STYLE_BITMAP_BUTTON, STYLE_CHECKBOX, STYLE_FOCUS, STYLE_LOGO};
	CPictureButton(void);
	virtual ~CPictureButton(void);
	void SetBitmapImage(int nID, int style = CPictureButton::STYLE_DEFAULT);
};


