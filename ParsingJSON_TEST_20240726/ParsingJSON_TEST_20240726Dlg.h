
// ParsingJSON_TEST_20240726Dlg.h : ��� ����
//

#pragma once


// CParsingJSON_TEST_20240726Dlg ��ȭ ����
class CParsingJSON_TEST_20240726Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CParsingJSON_TEST_20240726Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PARSINGJSON_TEST_20240726_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonYyjson();
	afx_msg void OnBnClickedButtonRapidjson();
};
