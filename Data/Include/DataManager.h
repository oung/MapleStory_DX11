#pragma once

#include "GameInfo.h"

class CDataManager
{
private:
	class CDataWindow* m_DataWindow;

public:
	bool Init(HINSTANCE hInst);
	void CreateDefaultSceneMode();
	int Run();

	DECLARE_SINGLE(CDataManager)
};

