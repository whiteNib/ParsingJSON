
// ParsingJSON_TEST_20240726.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CParsingJSON_TEST_20240726App:
// �� Ŭ������ ������ ���ؼ��� ParsingJSON_TEST_20240726.cpp�� �����Ͻʽÿ�.
//

class CParsingJSON_TEST_20240726App : public CWinApp
{
public:
	CParsingJSON_TEST_20240726App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CParsingJSON_TEST_20240726App theApp;