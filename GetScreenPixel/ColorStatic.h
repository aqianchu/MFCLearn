#pragma once


// CColorStatic
// �����Զ�������̬�ı������屳������ɫ�ȵ���
class CColorStatic : public CStatic
{
	DECLARE_DYNAMIC(CColorStatic)

public:
	CColorStatic();
	virtual ~CColorStatic();

protected:
	DECLARE_MESSAGE_MAP()

private:
	COLORREF    m_ForeColor;        //�ı���ɫ
	COLORREF    m_BackColor;        //����ɫ
	CBrush      m_BkBrush;          //����ˢ
	CFont*      p_Font;             //����

public:
	void SetForeColor(COLORREF color);      //�����ı���ɫ
	void SetBkColor(COLORREF color);        //���ñ�����ɫ
	void SetTextFont(int FontHight,LPCTSTR FontName);   //�������� 

	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
};


