#include "PlayerManager.h"

DEFINITION_SINGLE(CPlayerManager)

CPlayerManager::CPlayerManager() : m_Gender(Gender::None)
{
}

CPlayerManager::~CPlayerManager()
{
	
}

bool CPlayerManager::Init()
{
	return true;
}
