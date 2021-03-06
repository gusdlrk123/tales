#include "header.h"
#include "define.h"
#include "TimerManager.h"
#include "Timer.h"

void TimerManager::Init()
{
	timer = new Timer;
	timer->Init();
}

void TimerManager::Update()
{
	timer->Tick();
}

void TimerManager::Render(HDC hdc)
{
	wsprintf(szText, "FPS : %d", timer->GetFPS());
	TextOut(hdc, WIN_SIZE_X - 150, 30, szText, strlen(szText));
}

void TimerManager::Release()
{
	SAFE_DELETE(timer);
}


float TimerManager::GetDeltaTime()
{
	if (timer) return timer->GetDeltaTime();

	return 0.0f;
}
