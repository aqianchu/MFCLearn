// ColorStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "GetScreenPixel.h"
#include "ColorStatic.h"


// CColorStatic

IMPLEMENT_DYNAMIC(CColorStatic, CStatic)

CColorStatic::CColorStatic() 
	:CStatic(), m_ForeColor(RGB(255,0,255)), m_BackColor(RGB(0,255,0)), p_Font()
{
	m_BkBrush.CreateSolidBrush( m_BackColor ); //建立背景刷
}

CColorStatic::~CColorStatic()
{
	if ( p_Font )    delete p_Font;        //删除字体
}


BEGIN_MESSAGE_MAP(CColorStatic, CStatic)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// CColorStatic 消息处理程序




HBRUSH CColorStatic::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
	pDC->SetTextColor( m_ForeColor );         //设置文字颜色
	pDC->SetBkColor( m_BackColor );           //设置背景色
	return (HBRUSH)m_BkBrush.GetSafeHandle(); //返回背景刷
}



//设置控件文字颜色

void CColorStatic::SetForeColor(COLORREF color)
{
	if ( m_ForeColor != color )
	{
		m_ForeColor = color;         //设置文字颜色
		Invalidate();		//重绘窗口
	}
} 

//设置控件背景颜色

void CColorStatic::SetBkColor(COLORREF color)
{
	if ( m_BackColor != color )
	{
		m_BackColor = color;
		m_BkBrush.Detach();           //分离原背景刷
		m_BkBrush.CreateSolidBrush( m_BackColor ); //建立背景刷
		Invalidate();
	}
} 

//设置控件字体

void CColorStatic::SetTextFont(int FontHight, LPCTSTR FontName)
{
	if ( p_Font )   delete p_Font;    //删除旧字体
	p_Font = new CFont;               //生成字体对象
	p_Font->CreatePointFont( FontHight, FontName ); //创建字体
	SetFont( p_Font );                //设置控件字体
	Invalidate();
} 

