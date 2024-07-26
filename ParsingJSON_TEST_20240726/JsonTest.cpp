#include "stdafx.h"
#include "JsonTest.h"
#include "yyjson/yyjson.h"

CJsonTest::CJsonTest(void)
{
	m_strFilePath = _T("C:\\TEST\\SPEC\\M393A4K40CB2-M06_V05-M-P2");
}


CJsonTest::~CJsonTest(void)
{
}

void CJsonTest::yyjson()
{
	yyjson_read_flag flg = YYJSON_READ_ALLOW_COMMENTS | YYJSON_READ_ALLOW_TRAILING_COMMAS;
	yyjson_read_err err;
	yyjson_doc *doc = yyjson_read_file(CT2CA(m_strFilePath), flg, NULL, &err);

	if (doc) 
	{
		yyjson_val *obj = yyjson_doc_get_root(doc);
		yyjson_obj_iter iter;
		yyjson_obj_iter_init(obj, &iter);
		yyjson_val *key, *val;
		while ((key = yyjson_obj_iter_next(&iter))) 
		{
			val = yyjson_obj_iter_get_val(key);
			printf("%s: %s\n", yyjson_get_str(key), yyjson_get_type_desc(val));
		}

		AfxMessageBox(_T("Good"));
	} 
	else 
	{
		CString strErrorMessage = CString(err.msg);
		AfxMessageBox(strErrorMessage);
	}

	CString stop;
}

void CJsonTest::rapidjson()
{
	CString strLog;
	USES_CONVERSION;

	DWORD	t1, t2;
	t1 = ::GetTickCount();

	CFile cFile;	
	CFileException error;

	if (!cFile.Open( m_strFilePath, CFile::modeRead | CFile::typeBinary, &error) )
	{
		TCHAR cErrorMessage[1024];
		error.GetErrorMessage(cErrorMessage, 1024);

		strLog.Format(_T("ERROR : Cannot Open RST file.\n Path : %s, Error message : %s"),
			m_strFilePath,
			cErrorMessage);

		AfxMessageBox(strLog);

		return;
	}

	// 파일 크기 확인
	ULONGLONG fileSize = cFile.GetLength();
	ULONGLONG bufferSize = fileSize + 1;  // +1 for null terminator

	char* buffer = new char[static_cast<size_t>(bufferSize)];
	memset(buffer, 0, static_cast<size_t>(bufferSize));  // 버퍼 초기화

	try
	{
		UINT bytesRead = cFile.Read(buffer, static_cast<UINT>(fileSize));
		buffer[bytesRead] = '\0';  // null terminator 추가
		cFile.Close();
	}
	catch (CFileException* e)
	{
		TCHAR cErrorMessage[1024];
		e->GetErrorMessage(cErrorMessage, 1024);

		strLog.Format(_T("ERROR : Cannot Read RST file.\n Path : %s, Error message : %s"),
			m_strFilePath,
			cErrorMessage);

		cFile.Close();
		delete[] buffer;  // 예외 발생 시 메모리 해제
		
		AfxMessageBox(strLog);

		return;
	}

	rapidjson::Document document;
	document.Parse(buffer);
	delete[] buffer;
	if ( document.HasParseError() )
	{
		strLog.Format( _T("ERROR (rapidjson code - %u) : %s"), (unsigned)document.GetErrorOffset(), GetParseError_En(document.GetParseError()) );
		AfxMessageBox(strLog);

		return;
	}

	t2 = ::GetTickCount() - t1;
	float fProcessTime = static_cast<float>(t2/1000.0f);

	strLog.Format(_T("Success to parse RST File - %.3f[sec] [%s]"), fProcessTime, m_strFilePath);

	AfxMessageBox(strLog);
}

