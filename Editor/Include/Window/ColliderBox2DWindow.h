#pragma once

#include "IMGUIWindow.h"

class CColliderBox2DWindow :
	public CIMGUIWindow
{
public:
	CColliderBox2DWindow();
	virtual ~CColliderBox2DWindow();

private:
	class CIMGUIText* m_TextWidth;
	class CIMGUIText* m_TextHeight;

	class CIMGUIText* m_TextProfile;

	class CIMGUITextInput* m_InputWidth;
	class CIMGUITextInput* m_InputHeight;

	class CIMGUITextInput* m_InputProfile;

	class CGameObject* m_Object;
	class CComponent* m_Component;

private:
	float m_Width;
	float m_Height;

	std::string m_Profile;

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);

private:
	bool IsComponent();
	bool OpenWindow();

private:
	void WidthCallback();
	void HeightCallback();
	void ProfileCallBack();

};