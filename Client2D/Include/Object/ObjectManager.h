#pragma once

#include "GameObject/GameObject.h"
#include "../ClientInfo.h"

class CObjectManager :
    public CGameObject
{
	friend class CScene;

public:
	CObjectManager();
	CObjectManager(const CObjectManager& obj);
	virtual ~CObjectManager();

protected:
	CharacterInfo m_CharacterInfo;

public:
	void SetCharacterInfo(int Attack, int Armor, int HP, int MP, int Level, int Exp, int Gold, float AttackSpeed, float AttackDistance)
	{
		m_CharacterInfo.Attack = Attack;
		m_CharacterInfo.Armor = Armor;
		m_CharacterInfo.HP = HP;
		m_CharacterInfo.MaxHP = HP;
		m_CharacterInfo.MP = MP;
		m_CharacterInfo.MaxMP = MP;
		m_CharacterInfo.Level = Level;
		m_CharacterInfo.Exp = Exp;
	}

public:
	void SetCharacterInfo(CharacterInfo characterInfo)
	{
		m_CharacterInfo = characterInfo;
	}

	CharacterInfo GetCharacterInfo() const
	{
		return m_CharacterInfo;
	}

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual CObjectManager* Clone();
};

