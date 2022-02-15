#pragma once

#include "IMGUIWidget.h"

class CIMGUIRadio :
    public CIMGUIWidget
{
	friend class CIMGUIWindow;

protected:
	CIMGUIRadio();
	virtual ~CIMGUIRadio();

public:
	virtual bool Init();
	virtual void Render();
};

