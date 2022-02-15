#include "Player2D.h"
#include "Scene/Scene.h"
#include "Input.h"
#include "Resource/Material/Material.h"
#include "PlayerAnimation2D.h"
#include "Animation/AnimationSequence2DInstance.h"

CPlayer2D::CPlayer2D()
{
	SetTypeID<CPlayer2D>();

	m_SolW = false;
	m_WDistance = 0.f;
	m_Opacity = 1.f;
	m_IsMove = false;
}

CPlayer2D::CPlayer2D(const CPlayer2D& obj) : CObjectManager(obj)
{
	m_Sprite = (CSpriteComponent*)FindComponent("PlayerSprite");

	m_Body = (CColliderBox2D*)FindComponent("Body");

	m_Opacity = obj.m_Opacity;
}

CPlayer2D::~CPlayer2D()
{
}

bool CPlayer2D::Init()
{
	m_Sprite = CreateComponent<CSpriteComponent>("PlayerSprite");
	m_Body = CreateComponent<CColliderBox2D>("Body");
	m_Camera = CreateComponent<CCameraComponent>("Camera");

	SetRootComponent(m_Sprite);

	m_Sprite->SetTransparency(true);

	//m_Sprite->CreateAnimationInstance<CPlayerAnimation2D>();

	m_Sprite->CreateAnimationInstance<CAnimationSequence2DInstance>();

	CAnimationSequence2DInstance* Anim = m_Sprite->GetAnimationInstance();

	Anim->AddAnimation(TEXT("PlayerWalkM.sqc"), ANIMATION_PATH, "Walk", true);
	Anim->AddAnimation(TEXT("PlayerIdleM.sqc"), ANIMATION_PATH, "Idle", true);

	m_Camera->OnViewportCenter();

	m_Body->SetCollisionProfile("Player");

	m_Sprite->AddChild(m_Camera);
	m_Sprite->AddChild(m_Body);

	m_Sprite->SetRelativeScale(272.f, 271.f, 1.f);
	m_Sprite->SetRelativePos(100.f, 50.f, 0.f);
	m_Sprite->SetPivot(0.5f, 0.5f, 0.f);

	CInput::GetInst()->SetKeyCallback<CPlayer2D>("MoveLeft", KeyState_Push, this, &CPlayer2D::MoveLeft);
	CInput::GetInst()->SetKeyCallback<CPlayer2D>("MoveRight", KeyState_Push, this, &CPlayer2D::MoveRight);
	CInput::GetInst()->SetKeyCallback<CPlayer2D>("Attack", KeyState_Down, this, &CPlayer2D::Attack);

	return true;
}

void CPlayer2D::Update(float DeltaTime)
{
	CObjectManager::Update(DeltaTime);
}

void CPlayer2D::PostUpdate(float DeltaTime)
{
	CObjectManager::PostUpdate(DeltaTime);
}

CPlayer2D* CPlayer2D::Clone()
{
	return new CPlayer2D(*this);
}

void CPlayer2D::MoveLeft(float DeltaTime)
{
	CAnimationSequence2DInstance* Anim = m_Sprite->GetAnimationInstance();

	Anim->SetAnimFlip(false);

	m_Sprite->AddRelativePos(m_Sprite->GetWorldAxis(AXIS_X) * -300.f * DeltaTime);
}

void CPlayer2D::MoveRight(float DeltaTime)
{
	CAnimationSequence2DInstance* Anim = m_Sprite->GetAnimationInstance();

	Anim->SetAnimFlip(true);

	m_Sprite->AddRelativePos(m_Sprite->GetWorldAxis(AXIS_X) * 300.f * DeltaTime);
}

void CPlayer2D::Attack(float DeltaTime)
{
}

void CPlayer2D::Attack1(float DeltaTime)
{
}
