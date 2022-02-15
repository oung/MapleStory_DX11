#pragma once

#include "IMGUIWindow.h"

struct DataInfo
{
	int HP;
	int MP;

	int Exp;

	int Attack;
	int Armor;

	int Level;

	std::string Name;
	
	Object_Type ObjectType;

	DataInfo() : HP(0), MP(0), Exp(0), Attack(0), Armor(0), Level(1), Name{}, ObjectType(Object_Type::Player)
	{

	}
};

class CDataWindow :
	public CIMGUIWindow
{
public:
	CDataWindow();
	virtual ~CDataWindow();

private:
	class CIMGUIMenuBar* m_MenuBar;

private:
	DataInfo m_DataInfo;
	std::vector<DataInfo> m_vecData;

private:
	class CIMGUIComboBox* m_TypeCombo;

	class CIMGUIText* m_TextHP;
	class CIMGUIText* m_TextMP;
	class CIMGUIText* m_TextExp;
	class CIMGUIText* m_TextAttack;
	class CIMGUIText* m_TextArmor;
	class CIMGUIText* m_TextLevel;
	class CIMGUIText* m_TextName;

	class CIMGUITextInput* m_InputHP;
	class CIMGUITextInput* m_InputMP;
	class CIMGUITextInput* m_InputExp;
	class CIMGUITextInput* m_InputAttack;
	class CIMGUITextInput* m_InputArmor;
	class CIMGUITextInput* m_InputLevel;
	class CIMGUITextInput* m_InputName;

public:
	DataInfo GetDataInfo() const
	{
		return m_DataInfo;
	}

	DataInfo GetDataInfo(int Index)
	{
		return m_vecData[Index];
	}

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);

private:
	void CallBackName();
	void CallBackHP();
	void CallBackMP();
	void CallBackExp();
	void CallBackLevel();
	void CallBackAttack();
	void CallBackArmor();

private:
	void SelectMenu(int Index, std::string Label);

	void Save();
	void SaveFullPath(const char* FullPath);
	void Load();
	void LoadFullPath(const char* FullPath);
};

