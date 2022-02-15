#include "Data.h"
#include "../ExcelManager.h"

CData::CData() : m_Excel(nullptr), m_Sheet(nullptr)
{
}

CData::~CData()
{
	
}

void CData::LoadExcel(const std::string& Name, const TCHAR* FileName, const std::string& PathName)
{
	CExcelManager::GetInst()->LoadExcel(&m_Excel ,Name, FileName, PathName);
}
