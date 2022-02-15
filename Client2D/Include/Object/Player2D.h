#pragma once

#include "ObjectManager.h"
#include "Component/SpriteComponent.h"
#include "Component/ColliderBox2D.h"
#include "Component/CameraComponent.h"
#include "Data/Data.h"
#include "../ClientInfo.h"

class CPlayer2D :
    public CObjectManager
{
    friend class CScene;
    friend class CPlayerAnimation2D;

protected:
    CPlayer2D();
    CPlayer2D(const CPlayer2D& obj);
    virtual ~CPlayer2D();

private:
    CSharedPtr<CSpriteComponent> m_Sprite;
    CSharedPtr<CColliderBox2D> m_Body;
    CSharedPtr<CCameraComponent> m_Camera;

    //CSharedPtr<CData> m_Data;

    CharacterInfo m_CharacterInfo;

    bool m_SolW;
    float m_WDistance;
    float m_Opacity;

public:
    bool m_IsMove;
    static Gender m_Gender;

public:
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void PostUpdate(float DeltaTime);
    virtual CPlayer2D* Clone();

private:
    void MoveLeft(float DeltaTime);
    void MoveRight(float DeltaTime);
    void Attack(float DeltaTime);
    void Attack1(float DeltaTime);
};

