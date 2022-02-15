#pragma once

#include "ObjectManager.h"
#include "../ClientInfo.h"

class CMonsterManager :
    public CObjectManager
{
public:
	CMonsterManager();
	CMonsterManager(const CMonsterManager& obj);
	virtual ~CMonsterManager();

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual CMonsterManager* Clone();
};

