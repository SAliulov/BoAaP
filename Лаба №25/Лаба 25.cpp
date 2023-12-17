// Лаба 25.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Лаба 25.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY25, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY25));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY25));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY25);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

//Изначальные фигуры
void Triangle(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx + size, cy - size);
    LineTo(hdc, cx - size, cy - size);
    LineTo(hdc, cx, cy + size);
    LineTo(hdc, cx + size, cy - size);

    DeleteObject(hPen);
}

void SandClock(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy - size;
    int x2 = cx + size / 2;
    int y2 = cy - size;
    int x3 = cx - size;
    int y3 = cy + size;
    int x4 = cx + size;
    int y4 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);


    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void Rhombus(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;

    int x2 = cx + size;
    int y2 = cy;

    int x3 = cx;
    int y3 = cy + size;

    int x4 = cx - size;
    int y4 = cy;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);


    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void Star(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;

    int x2 = cx + size / 4;
    int y2 = cy - size / 4;

    int x3 = cx + size;
    int y3 = cy;

    int x4 = cx + size / 4;
    int y4 = cy + size / 4;

    int x51 = cx;
    int y51 = cy + size;

    int x52 = cx - size / 4;
    int y52 = cy + size / 4;

    int x6 = cx - size;
    int y6 = cy;

    int x7 = cx - size / 4;
    int y7 = cy - size / 4;

    int x8 = cx;
    int y8 = cy - size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);


    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x51, y51);
    LineTo(hdc, x52, y52);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}


// 1 - 4 задания реализация
void RecursiveImage1_1(HDC hdc, int cx, int cy, int size) {
    Triangle(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    //Задача 1
    ////1 рисунок
    //RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);
    //RecursiveImage1_1(hdc, cx + size, cy - size, size / 2);

    ////2 рисунок
    //RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);
    //RecursiveImage1_1(hdc, cx, cy + size, size / 2);
    
    ////3 рисунок
    //RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);
    //RecursiveImage1_1(hdc, cx, cy + size, size / 2);
    //RecursiveImage1_1(hdc, cx + size, cy - size, size / 2);

    ////4 рисунок
    //RecursiveImage1_1(hdc, cx, cy - size, size / 2);
    
    ////5 рисунок
    //RecursiveImage1_1(hdc, cx + size, cy, size / 2);

    ////6 рисунок
    //RecursiveImage1_1(hdc, cx - size, cy, size / 2);

    ////7 рисунок
    //RecursiveImage1_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage1_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage1_1(hdc, cx, cy - size, size / 2);
}

void RecursiveImage2_1(HDC hdc, int cx, int cy, int size) {
    SandClock(hdc, cx, cy, size);
    //20 для 4 рисунка
    if (size < 20) {
        return;
    }
    //Задача 2
    
    ////1 рисунок
    //RecursiveImage2_1(hdc, cx - size / 2, cy - size, size / 2);
    ////2 рисунок
    //RecursiveImage2_1(hdc, cx - size / 2, cy - size, size / 2);
    //RecursiveImage2_1(hdc, cx + size / 2, cy - size, size / 2);
    ////3 рисунок
    //RecursiveImage2_1(hdc, cx - size, cy + size, size / 2);
    //RecursiveImage2_1(hdc, cx + size, cy + size, size / 2);

    //4 рисунок
    //поставить size = 20
    //RecursiveImage2_1(hdc, cx - size, cy + size, size / 2);
    //RecursiveImage2_1(hdc, cx + size, cy + size, size / 2);
    //RecursiveImage2_1(hdc, cx - size/2, cy - size, size / 2);
    //RecursiveImage2_1(hdc, cx + size/2, cy - size, size / 2);
    
    ////5 рисунок
    //RecursiveImage2_1(hdc, cx - size, cy, size / 2);

    ////6 рисунок
    //RecursiveImage2_1(hdc, cx + size, cy, size / 2);

    ////7 рисунок
    //RecursiveImage2_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage2_1(hdc, cx - size, cy, size / 2);

}

void RecursiveImage3_1(HDC hdc, int cx, int cy, int size) {
    Rhombus(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    //Задача 3

    ////1 рисунок
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);
    
    ////2 рисунок
    
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx, cy + size, size / 2);
     
    ////3 рисунок
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx, cy - size, size / 2);
    
    //4 рисунок
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx, cy + size, size / 2);
    
    ////5 рисунок (Свой)
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx + size / 2, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx + size / 2, cy + size, size / 2);

    ////6 рисунок (Свой)
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx - size / 2, cy + size, size / 2);
    //RecursiveImage3_1(hdc, cx - size / 2, cy - size, size / 2);

    ////7 рисунок (Свой)
    //RecursiveImage3_1(hdc, cx, cy, size / 2);
    //RecursiveImage3_1(hdc, cx - size / 2, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx + size / 2, cy - size, size / 2);

    ////8 рисунок (Свой)
    //RecursiveImage3_1(hdc, cx + size / 2, cy, size / 2);
    //RecursiveImage3_1(hdc, cx - size / 10, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx, cy - size, size / 2);
}

void RecursiveImage4_1(HDC hdc, int cx, int cy, int size) {
    Star(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }

    //Задача 4

    ////1 рисунок
    //RecursiveImage4_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage4_1(hdc, cx - size, cy, size / 2);

    ////2 рисунок
    //RecursiveImage4_1(hdc, cx, cy + size, size / 2);
    //RecursiveImage4_1(hdc, cx, cy - size, size / 2);


    ////3 рисунок
    //RecursiveImage4_1(hdc, cx, cy + size, size / 2);
    //RecursiveImage4_1(hdc, cx, cy - size, size / 2);
    //RecursiveImage4_1(hdc, cx - size, cy, size / 2);

    //4 рисунок (Свой)
    //RecursiveImage4_1(hdc, cx, cy + size, size / 2);
    //RecursiveImage4_1(hdc, cx, cy - size, size / 2);
    //RecursiveImage4_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage4_1(hdc, cx + size, cy, size / 2);

    ////5 рисунок (Свой)
    //RecursiveImage4_1(hdc, cx, cy, size / 2);
    //RecursiveImage4_1(hdc, cx, cy - size * 1.5, size / 2);


    ////6 рисунок (Свой)
    //RecursiveImage4_1(hdc, cx, cy + size, size / 2);
    //RecursiveImage4_1(hdc, cx + size / 1.2, cy, size / 2);
    //RecursiveImage4_1(hdc, cx - size / 1.2, cy, size / 2);

    ////7 рисунок (Свой)
    //RecursiveImage4_1(hdc, cx, cy - size, size / 2);
    //RecursiveImage4_1(hdc, cx + size / 1.2, cy, size / 2);
    //RecursiveImage4_1(hdc, cx - size / 1.2, cy, size / 2);


}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            
            //Задание 1
            RecursiveImage1_1(hdc, 200, 160, 80);

            //Задание 2
            RecursiveImage2_1(hdc, 500, 500, 100);

            //Задание 3
            RecursiveImage3_1(hdc, 1200, 500, 100);

            //Задание 4
            RecursiveImage4_1(hdc, 800, 300, 100);



            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
