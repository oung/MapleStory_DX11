#include "ObjectManager.h"

CObjectManager::CObjectManager() : m_CharacterInfo{}
{
}

CObjectManager::CObjectManager(const CObjectManager& obj) : CGameObject(obj)
{
	m_CharacterInfo = obj.m_CharacterInfo;
}

CObjectManager::~CObjectManager()
{
}

void CObjectManager::Start()
{
	CGameObject::Start();
}

bool CObjectManager::Init()
{
	if (!CGameObject::Init())
	{
		return false;
	}

	return true;
}

void CObjectManager::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CObjectManager::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

CObjectManager* CObjectManager::Clone()
{
	return nullptr;
}
