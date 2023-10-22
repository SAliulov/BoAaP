// Лаба 9.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Лаба 9.h"

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
    LoadStringW(hInstance, IDC_MY9, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY9));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY9));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY9);
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
void StClausAuto(HDC hdc, int x, int y) {
    //Верхний треугольник
    MoveToEx(hdc, x + 20, y + 0, NULL);
    LineTo(hdc, x + 30, y + 20);
    LineTo(hdc, x + 10, y + 20);
    LineTo(hdc, x + 20, y + 0);
    //Средний треугольник
    MoveToEx(hdc, x + 20, y + 10, NULL);
    LineTo(hdc, x + 30, y + 40);
    LineTo(hdc, x + 10, y + 40);
    LineTo(hdc, x + 20, y + 10);
    //Нижний треугольник
    MoveToEx(hdc, x + 20, y + 30, NULL);
    LineTo(hdc, x + 40, y + 80);
    LineTo(hdc, x + 0, y + 80);
    LineTo(hdc, x + 20, y + 30);
}

void drawTruck(HDC hdc, int X, int Y) {
    HPEN TruckBased = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, TruckBased);

    Rectangle(hdc, X + 0, Y + 30, X + 40, Y + 50);
    Rectangle(hdc, X + 10, Y + 10, X + 40, Y + 30);
    Rectangle(hdc, X + 40, Y + 0, X + 100, Y + 50);

    HPEN TruckWheels = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, TruckWheels);
    Ellipse(hdc, X + 10, Y + 40, X + 30, Y + 60);
    Ellipse(hdc, X + 70, Y + 40, X + 90, Y + 60);
}

void drawTrucks1(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 10, 310);
    drawTruck(hdc, 310, 10);
    drawTruck(hdc, 310, 310);
    drawTruck(hdc, 160, 160);
}

void drawTrucks2(HDC hdc) {
    int x = 10;
    do {
        drawTruck(hdc, x, 10);
        x += 110;
    } while (x <= 560);

}
void drawTrucks3(HDC hdc) {
    int y = 10;
    do {
        drawTruck(hdc, 10, y);
        y += 70;
    } while (y <= 400);
}

void drawTrucks4(HDC hdc) {
    int x = 10;
    int y = 10;
    do {
        drawTruck(hdc, x, y);
        x += 110;
        y += 70;
    } while (x <= 600);
}

void Logo0(HDC hdc, int x, int y) {
    HPEN Citroen = CreatePen(PS_SOLID, 20, RGB(163, 161, 166));
    HPEN CitroenDown = CreatePen(PS_SOLID, 5, RGB(56, 56, 56));
    HPEN CitroenDown2 = CreatePen(PS_SOLID, 7, RGB(20, 20, 20));
    HPEN CitroenUP = CreatePen(PS_SOLID, 5, RGB(130, 130, 130));
    SelectObject(hdc, Citroen);
    MoveToEx(hdc, x + 50, y + 50, NULL);
    LineTo(hdc, x + 100, y + 20);
    LineTo(hdc, x + 150, y + 50);
    SelectObject(hdc, CitroenDown);
    MoveToEx(hdc, x + 50, y + 60, NULL);
    LineTo(hdc, x + 100, y + 30);
    LineTo(hdc, x + 150, y + 60);
    SelectObject(hdc, CitroenDown2);
    MoveToEx(hdc, x + 70, y + 40, NULL);
    LineTo(hdc, x + 100, y + 25);
    LineTo(hdc, x + 130, y + 40);
    SelectObject(hdc, CitroenUP);
    MoveToEx(hdc, x + 45, y + 45, NULL);
    LineTo(hdc, x + 100, y + 15);
    LineTo(hdc, x + 155, y + 45);
}

void Logo1(HDC hdc, int x, int y) {
    Logo0(hdc, x, y);
    Logo0(hdc, x, y+40);
}

void Logo5_1(HDC hdc) {
    int x = 0;
    int y = 0;
    do {
        Logo1(hdc, x, y);
        x += 100;
        y += 100;
    } while (x<=200);

    Logo1(hdc, 0, 200);
    Logo1(hdc, 200, 0);
}

void Logo5_2(HDC hdc) {
    int x = 0;
    int y = 0;
    do {
        Logo1(hdc, x, y);
        x += 125;
    } while (x <= 900);
}

void Logo5_3(HDC hdc) {
    int x = 0;
    int y = 0;
    do {
        Logo1(hdc, x, y);
        y += 100;
    } while (y <= 350);
}

void Logo5_4(HDC hdc) {
    int x = 0;
    int y = 0;
    do {
        Logo1(hdc, x, y);
        x += 125;
        y += 100;
    } while (x <= 450);
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
            HPEN StClausAutoColor;
            /*StClausAutoColor = CreatePen(PS_SOLID, 4, RGB(26, 132, 57));
            SelectObject(hdc, StClausAutoColor);*/

            //Чтоб закомментить CTRL + K + C (U разкомментить)
            
            ////Задача 1.1 5 логотипов по углам и в центре
            //StClausAuto(hdc,0,0);
            //StClausAuto(hdc, 200, 200);
            //StClausAuto(hdc, 100, 100);
            //StClausAuto(hdc, 0, 200);
            //StClausAuto(hdc, 200, 0);
            //
            ////Задача 1.2: 8 Логотипов в линию
            //int x = 0;
            //do {
            //    StClausAuto(hdc, x, 0);
            //    x += 50;
            //} while (x <= 400);

            ////Задача 1.3: 4 Логотипа в вертикальную линию
            //int y = 0;
            //do {
            //    StClausAuto(hdc, 0, y);
            //    y += 90;
            //} while (y <= 300);

            ////Задача 1.4: 4 Логотипа в диагональную линию
            //int x1 = 0;
            //int y1 = 0;
            //do {
            //    StClausAuto(hdc, x1, y1);
            //    x1 += 50;
            //    y1 += 90;
            //} while (x1 <= 180);

            //Задача 2.1 Ф-ция DrawTruck (Строка 142)
 
            //Задача 2.2 5 автомобилей по углам и в центре

            /*drawTrucks1(hdc);*/
            
            //Задача 2.3 - 2.5 - 3 рисунка грузовиков

            //drawTrucks2(hdc);
            //drawTrucks3(hdc);
            //drawTrucks4(hdc);
            
            //Задача 4

            //Logo1(hdc, 0, 0);

            //Задача 5
            
            /*Logo5_1(hdc);*/

            Logo5_2(hdc);
            Logo5_3(hdc);
            Logo5_4(hdc);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
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
