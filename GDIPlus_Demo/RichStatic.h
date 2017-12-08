#pragma once


// CRichStatic

class CRichStatic : public CStatic
{
	DECLARE_DYNAMIC(CRichStatic)

public:
	CRichStatic();
	virtual ~CRichStatic();

protected:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg LRESULT OnSetText(WPARAM,LPARAM);
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();
	void PaintBG(CDC *pDC);

private:
	COLORREF m_clrText;          // ����ǰ��ɫ
	COLORREF m_clrBackground;    // ���ֱ���ɫ
	CBitmap m_Bmp;               // ���汳���õ�λͼ����
	BOOL m_selfCreated;
	 CFont m_hFont;
	UINT  m_xAlignment;
	CDC             m_BGMemDC;
public:
	void SetBkGnd(CDC* pDC,BOOL bRedraw = TRUE);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	// ���ñ���ɫ����clrΪCLR_NONE���򱳾�͸����
	void SetBackgroundColor(COLORREF clr){m_clrBackground = clr;}
	// ��������ǰ��ɫ
	void SetTextColor(COLORREF clr){m_clrText = clr;}
	// ������������
	BOOL SetFont(TCHAR* lpFaceName = _T("Arial"), int nSize = 14, int nWeight = FW_NORMAL, BOOL bItalic = FALSE);
	BOOL SetFont(const LPLOGFONT lpFont);
	void SetTextAlign(UINT ulTextAlign = DT_CENTER|DT_SINGLELINE|DT_VCENTER|DT_END_ELLIPSIS){m_xAlignment = ulTextAlign;}
	void SetText(LPCTSTR lpszText,BOOL bRedraw = TRUE);

public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};

