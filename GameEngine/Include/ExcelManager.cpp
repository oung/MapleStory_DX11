#include "ExcelManager.h"
#include "Excel.h"
#include "Engine.h"

DEFINITION_SINGLE(CExcelManager)

CExcelManager::CExcelManager()
{
}

CExcelManager::~CExcelManager()
{
	
}

bool CExcelManager::Init()
{
	setlocale(LC_ALL, "KOREAN");

	return true;
}

bool CExcelManager::LoadExcel(libxl::Book** Book, const std::string& Name, const TCHAR* FileName, const std::string& PathName)
{
	CExcel* Excel = FindExcel(Name);

	if (Excel)
	{
		return true;
	}

	Excel = new CExcel;

	if (!Excel->LoadExcel(Book, Name, FileName, PathName))
	{
		SAFE_RELEASE(Excel);
		return false;
	}

	m_mapData.insert(std::make_pair(Name, Excel));

	return true;
}

bool CExcelManager::LoadExcelFullPath(const std::string& Name, const TCHAR* FullPath)
{
	return true;
}

CExcel* CExcelManager::FindExcel(const std::string& Name)
{
	auto iter = m_mapData.find(Name);

	if (iter == m_mapData.end())
	{
		return nullptr;
	}

	return iter->second;
}

void CExcelManager::ReleaseExcel(const std::string& Name)
{
	auto iter = m_mapData.find(Name);

	if (iter == m_mapData.end())
	{
		return;
	}
}
