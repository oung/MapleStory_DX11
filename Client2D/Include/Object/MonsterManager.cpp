#include "MonsterManager.h"

CMonsterManager::CMonsterManager()
{
	SetTypeID<CMonsterManager>();
}

CMonsterManager::CMonsterManager(const CMonsterManager& obj) : CObjectManager(obj)
{
}

CMonsterManager::~CMonsterManager()
{
}

void CMonsterManager::Start()
{
	CObjectManager::Start();
}

bool CMonsterManager::Init()
{
	CObjectManager::Init();

	return true;
}

void CMonsterManager::Update(float DeltaTime)
{
	CObjectManager::Update(DeltaTime);
}

void CMonsterManager::PostUpdate(float DeltaTime)
{
	CObjectManager::PostUpdate(DeltaTime);
}

CMonsterManager* CMonsterManager::Clone()
{
	return new CMonsterManager(*this);
}
