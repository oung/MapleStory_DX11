#include "LoadingThread.h"
#include "MainScene.h"
#include "Scene/SceneManager.h"
#include "TestScene.h"

CLoadingThread::CLoadingThread()
{
}

CLoadingThread::~CLoadingThread()
{
}

bool CLoadingThread::Init()
{
	if (!CThread::Init())
	{
		return false;
	}

	return true;
}

void CLoadingThread::Run()
{
	// ·Îµù
	CSceneManager::GetInst()->CreateNextScene(false);
	CTestScene* MainScene = CSceneManager::GetInst()->CreateSceneModeEmpty<CTestScene>(false);

	MainScene->SetLoadingFunction<CLoadingThread>(this, &CLoadingThread::AddMessage);

	MainScene->Init();

	AddMessage(false, 1.f);

	Sleep(2000);

	AddMessage(true, 1.f);
}
