#pragma once

#include "../GameInfo.h"
#include "../Ref.h"

class CData : 
	public CRef
{
public:
	CData();
	~CData();

public:
	libxl::Book* m_Excel;
	libxl::Sheet* m_Sheet;

public:
	void SetBook(libxl::Book* book)
	{
		m_Excel = book;
	}

	void SetSheet(libxl::Sheet* sheet)
	{
		m_Sheet = sheet;
	}

public:
	libxl::Book* GetBook() const
	{
		return m_Excel;
	}

	libxl::Sheet* GetSheet() const
	{
		return m_Sheet;
	}

public:
	void ReleaseBook()
	{
		if (m_Excel)
		{
			m_Excel->release();
		}
	}

public:
	void LoadExcel(const std::string& Name, const TCHAR* FileName, const std::string& PathName = DATA_PATH);
};

