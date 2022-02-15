#pragma once

#include "GameInfo.h"
#include "../ClientInfo.h"

class CPlayerManager
{
public:
	bool Init();

private:
	Gender m_Gender;

public:
	void SetGender(Gender gender)
	{
		m_Gender = gender;
	}

	Gender GetGender() const
	{
		return m_Gender;
	}

	DECLARE_SINGLE(CPlayerManager)
};

