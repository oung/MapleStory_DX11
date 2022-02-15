#include "DataWindow.h"
#include "IMGUIButton.h"
#include "IMGUISameLine.h"
#include "IMGUILabel.h"
#include "IMGUIText.h"
#include "IMGUITextInput.h"
#include "IMGUIListBox.h"
#include "IMGUIComboBox.h"
#include "IMGUIImage.h"
#include "IMGUIMenuBar.h"
#include "IMGUISeparator.h"
#include "Engine.h"
#include "PathManager.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"
#include "Scene/SceneResource.h"
#include "Component/SpriteComponent.h"
#include "Component/StaticMeshComponent.h"
#include "Component/ColliderBox2D.h"
#include "Component/ColliderCircle.h"
#include "Component/ColliderPixel.h"
#include "Component/CameraComponent.h"
#include "Component/WidgetComponent.h"
#include "IMGUIManager.h"

CDataWindow::CDataWindow()
{
}

CDataWindow::~CDataWindow()
{
}

bool CDataWindow::Init()
{
	CIMGUIWindow::Init();

	AddWindowFlag(ImGuiWindowFlags_MenuBar);

	m_MenuBar = AddWidget<CIMGUIMenuBar>("File");

	m_MenuBar->AddItem("Save");
	m_MenuBar->AddItem("Load");

	m_MenuBar->SetSelectCallback(this, &CDataWindow::SelectMenu);

	// Input Name
	CIMGUILabel* Label = AddWidget<CIMGUILabel>("Name", 100.f, 30.f);
	Label->SetColor(0, 0, 0);
	Label->SetAlign(0.5f, 0.f);

	CIMGUISameLine* Line = AddWidget<CIMGUISameLine>("Line");

	m_InputName = AddWidget<CIMGUITextInput>("InputName", 100.f, 100.f);
	m_InputName->SetHideName(true);
	m_InputName->AddFlag(ImGuiInputTextFlags_::ImGuiInputTextFlags_EnterReturnsTrue);
	m_InputName->SetTextType(ImGuiText_Type::String);
	m_InputName->SetCallback(this, &CDataWindow::CallBackName);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_TextName = AddWidget<CIMGUIText>("Name", 100.f, 100.f);
	m_TextName->SetText("Name");
	m_TextName->SetTextType(Text_Type::Multibyte);
	m_TextName->SetColor(255, 255, 255);

	Line = AddWidget<CIMGUISameLine>("Line");
	Line->SetOffsetX(400.f);

	m_TypeCombo = AddWidget<CIMGUIComboBox>("ObjectCombo", 150.f, 30.f);

	m_TypeCombo->SetHideName(true);
	m_TypeCombo->AddItem("Player");
	m_TypeCombo->AddItem("Monster");

	CIMGUISeparator* Separator = AddWidget<CIMGUISeparator>("Separator");

	// Input HP;
	Label = AddWidget<CIMGUILabel>("HP", 100.f, 30.f);
	Label->SetColor(0, 0, 0);
	Label->SetAlign(0.5f, 0.f);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_InputHP = AddWidget<CIMGUITextInput>("InputHP");
	m_InputHP->SetHideName(true);
	m_InputHP->SetTextType(ImGuiText_Type::Int);
	m_InputHP->SetCallback(this, &CDataWindow::CallBackHP);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_TextHP = AddWidget<CIMGUIText>("HP", 300.f);
	std::string str = std::to_string(m_DataInfo.HP);
	m_TextHP->SetText(str.c_str());
	m_TextHP->SetColor(255, 255, 255);

	Separator = AddWidget<CIMGUISeparator>("Separator");

	// Input MP
	Label = AddWidget<CIMGUILabel>("MP", 100.f, 30.f);
	Label->SetColor(0, 0, 0);
	Label->SetAlign(0.5f, 0.f);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_InputMP = AddWidget<CIMGUITextInput>("InputMP");
	m_InputMP->SetHideName(true);
	m_InputMP->SetTextType(ImGuiText_Type::Int);
	m_InputMP->SetCallback(this, &CDataWindow::CallBackMP);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_TextMP = AddWidget<CIMGUIText>("MP", 300.f);
	str = std::to_string(m_DataInfo.MP);
	m_TextMP->SetText(str.c_str());
	m_TextMP->SetColor(255, 255, 255);

	Separator = AddWidget<CIMGUISeparator>("Separator");

	// Input Exp
	Label = AddWidget<CIMGUILabel>("Exp", 100.f, 30.f);
	Label->SetColor(0, 0, 0);
	Label->SetAlign(0.5f, 0.f);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_InputExp = AddWidget<CIMGUITextInput>("InputExp");
	m_InputExp->SetHideName(true);
	m_InputExp->SetTextType(ImGuiText_Type::Int);
	m_InputExp->SetCallback(this, &CDataWindow::CallBackExp);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_TextExp = AddWidget<CIMGUIText>("Exp", 300.f);
	str = std::to_string(m_DataInfo.Exp);
	m_TextExp->SetText(str.c_str());
	m_TextExp->SetColor(255, 255, 255);

	Separator = AddWidget<CIMGUISeparator>("Separator");

	// Input Level
	Label = AddWidget<CIMGUILabel>("Level", 100.f, 30.f);
	Label->SetColor(0, 0, 0);
	Label->SetAlign(0.5f, 0.f);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_InputLevel = AddWidget<CIMGUITextInput>("InputLevel");
	m_InputLevel->SetHideName(true);
	m_InputLevel->SetTextType(ImGuiText_Type::Int);
	m_InputLevel->SetCallback(this, &CDataWindow::CallBackLevel);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_TextLevel = AddWidget<CIMGUIText>("Level", 300.f);
	str = std::to_string(m_DataInfo.Level);
	m_TextLevel->SetText(str.c_str());
	m_TextLevel->SetColor(255, 255, 255);

	Separator = AddWidget<CIMGUISeparator>("Separator");

	// Input Attack
	Label = AddWidget<CIMGUILabel>("Attack", 100.f, 30.f);
	Label->SetColor(0, 0, 0);
	Label->SetAlign(0.5f, 0.f);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_InputAttack = AddWidget<CIMGUITextInput>("InputAttack");
	m_InputAttack->SetHideName(true);
	m_InputAttack->SetTextType(ImGuiText_Type::Int);
	m_InputAttack->SetCallback(this, &CDataWindow::CallBackAttack);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_TextAttack = AddWidget<CIMGUIText>("Attack", 300.f);
	str = std::to_string(m_DataInfo.Attack);
	m_TextAttack->SetText(str.c_str());
	m_TextAttack->SetColor(255, 255, 255);

	Separator = AddWidget<CIMGUISeparator>("Separator");

	// Input Armor
	Label = AddWidget<CIMGUILabel>("Armor", 100.f, 30.f);
	Label->SetColor(0, 0, 0);
	Label->SetAlign(0.5f, 0.f);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_InputArmor = AddWidget<CIMGUITextInput>("InputArmor");
	m_InputArmor->SetHideName(true);
	m_InputArmor->SetTextType(ImGuiText_Type::Int);
	m_InputArmor->SetCallback(this, &CDataWindow::CallBackArmor);

	Line = AddWidget<CIMGUISameLine>("Line");

	m_TextArmor = AddWidget<CIMGUIText>("Armor", 300.f);
	str = std::to_string(m_DataInfo.Armor);
	m_TextArmor->SetText(str.c_str());
	m_TextArmor->SetColor(255, 255, 255);

	Separator = AddWidget<CIMGUISeparator>("Separator");

	// Input Monster_Type

	return true;
}

void CDataWindow::Update(float DeltaTime)
{
	CIMGUIWindow::Update(DeltaTime);
}

void CDataWindow::CallBackName()
{
	m_DataInfo.Name = m_InputName->GetTextUTF8();

	m_TextName->SetText(m_InputName->GetTextMultibyte());
}

void CDataWindow::CallBackHP()
{
	m_DataInfo.HP = m_InputHP->GetValueInt();

	std::string str = std::to_string(m_DataInfo.HP);

	m_TextHP->SetText(str.c_str());
}

void CDataWindow::CallBackMP()
{
	m_DataInfo.MP = m_InputMP->GetValueInt();

	std::string str = std::to_string(m_DataInfo.MP);

	m_TextMP->SetText(str.c_str());
}

void CDataWindow::CallBackExp()
{
	m_DataInfo.Exp = m_InputExp->GetValueInt();

	std::string str = std::to_string(m_DataInfo.Exp);

	m_TextExp->SetText(str.c_str());
}

void CDataWindow::CallBackLevel()
{
	m_DataInfo.Level = m_InputLevel->GetValueInt();

	std::string str = std::to_string(m_DataInfo.Level);

	m_TextLevel->SetText(str.c_str());
}

void CDataWindow::CallBackAttack()
{
	m_DataInfo.Attack = m_InputAttack->GetValueInt();

	std::string str = std::to_string(m_DataInfo.Attack);

	m_TextAttack->SetText(str.c_str());
}

void CDataWindow::CallBackArmor()
{
	m_DataInfo.Armor = m_InputArmor->GetValueInt();

	std::string str = std::to_string(m_DataInfo.Armor);

	m_TextArmor->SetText(str.c_str());
}

void CDataWindow::SelectMenu(int Index, std::string Label)
{
	MenuItem Item = m_MenuBar->GetItem(Index);

	if (Item.Label == "Save")
	{
		Save();
	}

	else if (Item.Label == "Load")
	{
		Load();
	}
}

void CDataWindow::Save()
{
	
}

void CDataWindow::SaveFullPath(const char* FullPath)
{
	FILE* File = nullptr;

	fopen_s(&File, FullPath, "wb");

	if (!File)
	{
		return;
	}

	fclose(File);
}

void CDataWindow::Load()
{
	
}

void CDataWindow::LoadFullPath(const char* FullPath)
{
	FILE* File = nullptr;

	fopen_s(&File, FullPath, "rb");

	if (!File)
	{
		return;
	}

	fclose(File);
}

