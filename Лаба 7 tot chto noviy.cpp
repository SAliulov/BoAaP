// Лаба 7.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Лаба 7.h"

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
    LoadStringW(hInstance, IDC_MY7, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY7));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY7));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY7);
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
            
            
            HPEN penteract, weed, zabor, roof, based, okno, rama, texture, Terraria_tree, water, water1, water2, water3, chair, table, bottle, probka;
            roof = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
            SelectObject(hdc, roof);
            based = CreatePen(PS_SOLID, 3, RGB(50, 50, 50));
            okno = CreatePen(PS_SOLID, 5, RGB(0, 162, 232));
            rama = CreatePen(PS_SOLID, 10, RGB(64, 0, 0));
            texture = CreatePen(PS_SOLID, 6, RGB(195, 195, 195));
            Terraria_tree = CreatePen(PS_SOLID, 10, RGB(34, 177, 76));
            water = CreatePen(PS_SOLID, 500, RGB(0, 162, 232));
            water1 = CreatePen(PS_SOLID, 500, RGB(0, 137, 196));
            water2 = CreatePen(PS_SOLID, 500, RGB(0, 112, 160));
            water3 = CreatePen(PS_SOLID, 500, RGB(0, 87, 124));
            chair = CreatePen(PS_SOLID, 20, RGB(101, 51, 1));
            table = CreatePen(PS_SOLID, 20, RGB(69, 35, 1));
            bottle = CreatePen(PS_SOLID, 5, RGB(50, 117, 0));
            probka = CreatePen(PS_SOLID, 5, RGB(101, 51, 1));
            zabor = CreatePen(PS_SOLID, 3, RGB(94, 47, 0));
            weed = CreatePen(PS_SOLID, 3, RGB(34, 177, 76));
            penteract = CreatePen(PS_SOLID, 3, RGB(75, 0, 151));
            //Крыша
            MoveToEx(hdc, 150, 350, NULL);
            LineTo(hdc, 275, 250);
            LineTo(hdc, 400, 350);
            LineTo(hdc, 150, 350);

            //Это база, это основа
            SelectObject(hdc, based);
            LineTo(hdc, 150, 525);
            LineTo(hdc, 400, 525);
            LineTo(hdc, 400, 350);

            //Окно
            SelectObject(hdc, okno);
            MoveToEx(hdc, 225, 400, NULL);
            LineTo(hdc, 325, 400);
            LineTo(hdc, 325, 475);
            LineTo(hdc, 225, 475);
            LineTo(hdc, 225, 400);
            MoveToEx(hdc, 275, 400, NULL);
            LineTo(hdc, 275, 475);
            MoveToEx(hdc, 275, 425, NULL);
            LineTo(hdc, 325, 425);

            //Оконная рама
            SelectObject(hdc, rama);
            MoveToEx(hdc, 330, 395, NULL);
            LineTo(hdc, 220, 395);
            LineTo(hdc, 220, 480);
            LineTo(hdc, 330, 480);
            LineTo(hdc, 330, 395);

            //Текстуры стекла
            SelectObject(hdc, texture);
            MoveToEx(hdc, 231, 420, NULL);
            LineTo(hdc, 248, 405);
            MoveToEx(hdc, 250, 440, NULL);
            LineTo(hdc, 270, 420);
            MoveToEx(hdc, 280, 455, NULL);
            LineTo(hdc, 300, 435);
            MoveToEx(hdc, 305, 465, NULL);
            LineTo(hdc, 320, 450);

            //Ёлка

            HPEN yolka;
            yolka = CreatePen(PS_SOLID, 5, RGB(0, 106, 53));
            SelectObject(hdc, yolka);

            //1 Треугольник

            MoveToEx(hdc, 450, 525, NULL);
            LineTo(hdc, 600, 525);
            LineTo(hdc, 525, 450);
            LineTo(hdc, 450, 525);

            HPEN nozhka;
            nozhka = CreatePen(PS_SOLID, 7, RGB(64, 0, 0));

            //Ножка Ёлки

            SelectObject(hdc, nozhka);
            MoveToEx(hdc, 500, 530, NULL);
            LineTo(hdc, 500, 550);
            LineTo(hdc, 550, 550);
            LineTo(hdc, 550, 530);

            //2-ой и 3-й треугольник

            MoveToEx(hdc, 525, 400, NULL);
            SelectObject(hdc, yolka);
            LineTo(hdc, 475, 450);
            LineTo(hdc, 575, 450);
            LineTo(hdc, 525, 400);

            LineTo(hdc, 500, 400);
            LineTo(hdc, 525, 375);
            LineTo(hdc, 550, 400);
            LineTo(hdc, 500, 400);

            //Река
            SelectObject(hdc, water);
            MoveToEx(hdc, 0, 900, NULL);
            LineTo(hdc, 10000, 900);
            MoveToEx(hdc, 0, 1000, NULL);
            SelectObject(hdc, water1);
            LineTo(hdc, 10000, 1000);
            MoveToEx(hdc, 0, 1100, NULL);
            SelectObject(hdc, water2);
            LineTo(hdc, 10000, 1100);
            MoveToEx(hdc, 0, 1200, NULL);
            SelectObject(hdc, water3);
            LineTo(hdc, 10000, 1200);

            //Дерево 2
            SelectObject(hdc, rama);
            MoveToEx(hdc, 100, 550, NULL);
            LineTo(hdc, 100, 350);
            MoveToEx(hdc, 50, 550, NULL);
            LineTo(hdc, 50, 350);
            MoveToEx(hdc, 0, 350, NULL);

            //Листва
            SelectObject(hdc, Terraria_tree);
            LineTo(hdc, 0, 200);
            LineTo(hdc, 150, 200);
            LineTo(hdc, 150, 350);
            LineTo(hdc, 0, 350);
            MoveToEx(hdc, 5, 300, NULL);
            LineTo(hdc, 25, 325);
            LineTo(hdc, 50, 320);
            MoveToEx(hdc, 100, 325, NULL);
            LineTo(hdc, 125, 330);
            LineTo(hdc, 148, 301);

            MoveToEx(hdc, 5, 250, NULL);
            LineTo(hdc, 25, 220);
            LineTo(hdc, 50, 230);
            MoveToEx(hdc, 100, 225, NULL);
            LineTo(hdc, 125, 220);
            LineTo(hdc, 148, 250);

            //Стул
            SelectObject(hdc, chair);
            MoveToEx(hdc, 700, 525, NULL);
            LineTo(hdc, 700, 100);
            MoveToEx(hdc, 700, 350, NULL);
            LineTo(hdc, 900, 350);
            LineTo(hdc, 900, 525);

            //Стол
            SelectObject(hdc, table);
            MoveToEx(hdc, 1000, 525, NULL);
            LineTo(hdc, 1000, 250);
            LineTo(hdc, 1500, 250);
            LineTo(hdc, 1500, 525);

            //Стул2
            SelectObject(hdc, chair);
            MoveToEx(hdc, 1600, 525, NULL);
            LineTo(hdc, 1600, 350);
            LineTo(hdc, 1800, 350);
            LineTo(hdc, 1800, 100);
            LineTo(hdc, 1800, 525);

            //бутылка
            SelectObject(hdc, bottle);
            MoveToEx(hdc, 1025, 160, NULL);
            LineTo(hdc, 1025, 240);
            LineTo(hdc, 1070, 240);
            LineTo(hdc, 1070, 160);
            LineTo(hdc, 1055, 140);
            LineTo(hdc, 1055, 100);
            LineTo(hdc, 1040, 100);
            LineTo(hdc, 1040, 140);
            LineTo(hdc, 1025, 160);
            //Пробка или крышка

            MoveToEx(hdc, 1040, 99, NULL);
            SelectObject(hdc, probka);
            LineTo(hdc, 1055, 99);


            //LABA 7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

            SelectObject(hdc, based);  

            //Задача 1 первый куст
            
            //Первая точка - кончик ветки куста
            int x1 = 400, y1 = 150;

            //Вторая точка - корень куста
            int x2 = 500, y2 = 250;

            do {
                //Соединяем линией первую точку со второй
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);

                //1 точку перемещаем вправо на 25 пикселей 
                x1 += 25;
            } while (x1 <= 600);

            //Задача 2 второй куст
            SelectObject(hdc, bottle);

            //первая точка кончик ветки
            int x11 = 0, y11 = 200;
            //вторая точка корень куста
            int x22 = 100, y22 = 200;
            do {
                //соединяем линией первую точку со второй
                MoveToEx(hdc, x11, y11, NULL);
                LineTo(hdc, x22, y22);
                x11 += 25;
                //вверх на 50 пикс
                y11 -= 50;
            } while (x11 <= 100);
            x11 = 100;
            y11 = 0;
            do {
                //соединяем линией левую верхнюю точку со второй
                MoveToEx(hdc, x11, y11, NULL);
                LineTo(hdc, x22, y22);
                x11 += 25;
                y11 += 50;
            } while (x11 <= 200);
            

            //Задача 4 Забор
            
            SelectObject(hdc, zabor);
            //Первая точка забора
            int x_z1 = 150, y_z1 = 0;
            //Вторая точка забора
            int x_z2 = 150, y_z2 = 100;
            do {
                //соединяем первую со второй
                MoveToEx(hdc, x_z1, y_z1, NULL);
                LineTo(hdc, x_z2, y_z2);
                x_z1 += 25;
                x_z2 += 25; 
            } while (x_z1 <= 450);

            //Задание 5 Трава у дома, зелёная, зелёная трава
            // Задний ряд
            SelectObject(hdc, weed);
            int x_weed1 = 0, y_weed1 = 600;
            int x_weed2 = 10, y_weed2 = 550;
            int x_weed3 = 20, y_weed3 = 600;
            do {
                MoveToEx(hdc, x_weed1, y_weed1, NULL);
                LineTo(hdc, x_weed2, y_weed2);
                LineTo(hdc, x_weed3, y_weed3);
                x_weed1 += 20;
                x_weed2 += 20;
                x_weed3 += 20;
            } while (x_weed3 <= 2000);

            // Средний ряд
            int x_weed111 = 0, y_weed111 = 625;
            int x_weed222 = 10, y_weed222 = 575;
            int x_weed333 = 20, y_weed333 = 625;
            do {
                MoveToEx(hdc, x_weed111, y_weed111, NULL);
                LineTo(hdc, x_weed222, y_weed222);
                LineTo(hdc, x_weed333, y_weed333);
                x_weed111 += 20;
                x_weed222 += 20;
                x_weed333 += 20;
            } while (x_weed333 <= 2000);
            // Передний ряд
            int x_weed11 = 0, y_weed11 = 650;
            int x_weed22 = 10, y_weed22 = 600;
            int x_weed33 = 20, y_weed33 = 650;
            do {
                MoveToEx(hdc, x_weed11, y_weed11, NULL);
                LineTo(hdc, x_weed22, y_weed22);
                LineTo(hdc, x_weed33, y_weed33);
                x_weed11 += 20;
                x_weed22 += 20;
                x_weed33 += 20;
            } while (x_weed33 <= 2000);


            //Задача 5 Второй объект 
            SelectObject(hdc, penteract);
            int penteract_x = 1400, penteract_y = 200;
            int penteract_x2 = 1050, penteract_y2 = 520;
            int penteract_x3 = 1200, penteract_y3 = 510;
            int penteract_x4 = 1150, penteract_y4 = 490;
            int penteract_x5 = 1000, penteract_y5 = 500;
            do {
                MoveToEx(hdc, penteract_x, penteract_y, NULL);
                LineTo(hdc, penteract_x2, penteract_y2);
                LineTo(hdc, penteract_x3, penteract_y3);
                LineTo(hdc, penteract_x4, penteract_y4);
                LineTo(hdc, penteract_x5, penteract_y5);
                
                penteract_y -= 7;
                penteract_y2 -= 7;
                penteract_y3 -= 7;
                penteract_y4 -= 7;
                penteract_y5 -= 7;
                penteract_x5 += 20;
            } while (penteract_y5 >=300);

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
