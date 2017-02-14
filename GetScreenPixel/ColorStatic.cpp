// ColorStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GetScreenPixel.h"
#include "ColorStatic.h"


// CColorStatic

IMPLEMENT_DYNAMIC(CColorStatic, CStatic)

CColorStatic::CColorStatic() 
	:CStatic(), m_ForeColor(RGB(255,0,255)), m_BackColor(RGB(0,255,0)), p_Font()
{
	m_BkBrush.CreateSolidBrush( m_BackColor ); //��������ˢ
}

CColorStatic::~CColorStatic()
{
	if ( p_Font )    delete p_Font;        //ɾ������
}


BEGIN_MESSAGE_MAP(CColorStatic, CStatic)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// CColorStatic ��Ϣ�������




HBRUSH CColorStatic::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	pDC->SetTextColor( m_ForeColor );         //����������ɫ
	pDC->SetBkColor( m_BackColor );           //���ñ���ɫ
	return (HBRUSH)m_BkBrush.GetSafeHandle(); //���ر���ˢ
}



//���ÿؼ�������ɫ

void CColorStatic::SetForeColor(COLORREF color)
{
	if ( m_ForeColor != color )
	{
		m_ForeColor = color;         //����������ɫ
		Invalidate();		//�ػ洰��
	}
} 

//���ÿؼ�������ɫ

void CColorStatic::SetBkColor(COLORREF color)
{
	if ( m_BackColor != color )
	{
		m_BackColor = color;
		m_BkBrush.Detach();           //����ԭ����ˢ
		m_BkBrush.CreateSolidBrush( m_BackColor ); //��������ˢ
		Invalidate();
	}
} 

//���ÿؼ�����

void CColorStatic::SetTextFont(int FontHight, LPCTSTR FontName)
{
	if ( p_Font )   delete p_Font;    //ɾ��������
	p_Font = new CFont;               //�����������
	p_Font->CreatePointFont( FontHight, FontName ); //��������
	SetFont( p_Font );                //���ÿؼ�����
	Invalidate();
} 

