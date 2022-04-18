#include <windows.h> 

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
					HINSTANCE hPrevInst, 
					LPSTR lpCmdLine, 
					int nCmdShow)
{
	TCHAR szAppName[] = L"My class";
	HWND hMainWnd;
	MSG msg;
	WNDCLASSEX WindowClass;
	WindowClass.cbSize = sizeof(WindowClass);
	WindowClass.style = CS_HREDRAW | CS_VREDRAW;
	WindowClass.lpfnWndProc = WndProc;
	WindowClass.lpszMenuName = NULL;
	WindowClass.lpszClassName = szAppName;
	WindowClass.cbWndExtra = NULL;
	WindowClass.cbClsExtra = NULL;
	WindowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	WindowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WindowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WindowClass.hInstance = hInstance;
	RegisterClassEx(&WindowClass);

	hMainWnd = CreateWindow(
		szAppName,
		L"Забродський",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		NULL,
		CW_USEDEFAULT,
		NULL,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hMainWnd, nCmdShow);
	UpdateWindow(hMainWnd);
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static short cx, cy;
	switch (msg)
	{
	case WM_SIZE:
	{
		cx = LOWORD(lParam);
		cy = HIWORD(lParam);
		return 0;
	}
	case WM_PAINT:
	{
		TCHAR szText[] = L"Привіт, мене створив Олексій Русланович";
		PAINTSTRUCT ps;
		RECT rect;
		HDC hdc = BeginPaint(hwnd, &ps);
		SetTextColor(hdc, RGB(255, 0, 255));
		SetBkColor(hdc, RGB(255, 251, 240));
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szText, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	}
	case WM_RBUTTONUP: 
	{
		MessageBox(0, L"Права кнопка миші відпущена", L"Миша", MB_OK);
		return 0;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
