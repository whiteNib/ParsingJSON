
// ParsingJSON_TEST_20240726Dlg.h : 헤더 파일
//

#pragma once


// CParsingJSON_TEST_20240726Dlg 대화 상자
class CParsingJSON_TEST_20240726Dlg : public CDialogEx
{
// 생성입니다.
public:
	CParsingJSON_TEST_20240726Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PARSINGJSON_TEST_20240726_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonYyjson();
	afx_msg void OnBnClickedButtonRapidjson();
};
