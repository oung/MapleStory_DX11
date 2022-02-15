#pragma once

enum class Gender
{
	None, 
	Male, 
	Female
};

enum class EPlayer_State
{
	Idle,
	Walk,
	Rope, 
	Ladder, 
	Attack,
	PhantomBlow, 
	BladeFury, 
	Die
};

enum class EMonster_State
{
	Idle,
	Walk,
	Trace, 
	Attack,
	Die
};