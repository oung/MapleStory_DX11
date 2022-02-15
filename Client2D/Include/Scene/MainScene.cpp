#include "MainScene.h"
#include "Scene/Scene.h"
#include "../Object/Player2D.h"
#include "../Object/TestMonster.h"
#include "Scene/SceneResource.h"

CMainScene::CMainScene()
{
	SetTypeID<CMainScene>();
}

CMainScene::~CMainScene()
{
}

bool CMainScene::Init()
{
	CreateMaterial();

	CreateAnimationSequence();

	CPlayer2D* Player = m_Scene->CreateGameObject<CPlayer2D>("Player");

	SetPlayerObject(Player);

	CTestMonster* TestMonster = m_Scene->CreateGameObject<CTestMonster>("TestMonster");

	return true;
}

void CMainScene::CreateMaterial()
{
}

void CMainScene::CreateAnimationSequence()
{
	/*m_Scene->GetResource()->LoadSequence2D("PlayerIdle.sqc");
	m_Scene->GetResource()->LoadSequence2D("PlayerRun.sqc");*/
}