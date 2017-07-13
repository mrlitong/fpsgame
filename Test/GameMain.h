#pragma once
class CGameProcess;
class CGameMain
{
public:
	CGameMain(void);
	virtual ~CGameMain(void); 
public:
	int        Init();
	int        ShutDown();
	int        Update();
	int        Render();	
	CGameProcess*		m_pGameProcess;
};