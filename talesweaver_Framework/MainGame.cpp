#include "Config.h"
#include "MainGame.h"

#include "TitleScene.h"

HRESULT MainGame::Init()
{
	KEY_MGR->Init();
	TIMER_MGR->Init();
	SCENE_MGR->Init();

	SceneManager::GetSingleton()->AddScene(eSceneTag::Title, new TitleScene());

	srand((unsigned int) time(nullptr));
	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);
	
	mousePosX = 0;
	mousePosY = 0;
	clickedMousePosX = 0; 
	clickedMousePosY = 0;
	
	SceneManager::GetSingleton()->ChangeScene(eSceneTag::Title);

	return S_OK;
}

void MainGame::Update()
{
	TIMER_MGR->Update();

	SCENE_MGR->Update();

	KEY_MGR->Update();

	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	Graphics G(hdc);
	Image I(L"./Image/Title.png");


	G.DrawImage(&I, 0, 0);

	//SCENE_MGR->Render();

	//TIMER_MGR->Render();
}

void MainGame::Release()
{
	//SAFE_RELEASE(backBuffer);
	/*
	IMG_MGR->Release();
	IMG_MGR->ReleaseSingleton();
	*/

	TIMER_MGR->Release();
	TIMER_MGR->ReleaseSingleton();

	KEY_MGR->Release();
	KEY_MGR->ReleaseSingleton();

	SCENE_MGR->Release();
	SCENE_MGR->ReleaseSingleton();

	KillTimer(g_hWnd, 0);

}


LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_LBUTTONDOWN:
		clickedMousePosX = LOWORD(lParam);
		clickedMousePosY = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_MOUSEMOVE:
		g_ptMouse.x = LOWORD(lParam);
		g_ptMouse.y = HIWORD(lParam);
		break;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
