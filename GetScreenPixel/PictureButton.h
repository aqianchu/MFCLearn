#pragma once
#include "btnst.h"


// PictureButton
// ���ڼ���ʹ�ô���͸��ɫ��ͼ��İ�ť
class CPictureButton :
	public CButtonST
{
public:
	enum{STYLE_DEFAULT, STYLE_BITMAP_BUTTON, STYLE_CHECKBOX, STYLE_FOCUS, STYLE_LOGO};
	CPictureButton(void);
	virtual ~CPictureButton(void);
	void SetBitmapImage(int nID, int style = CPictureButton::STYLE_DEFAULT);
};


