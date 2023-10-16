// Лаба 8 (4).cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Лаба 8 (4).h"

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
    LoadStringW(hInstance, IDC_MY84, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY84));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY84));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY84);
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
//ФУНКЦИИ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//ЛАБЫ 4 и 7
void drawTree(HDC hdc) {
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
    SelectObject(hdc, based);

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
}

void drawTree2(HDC hdc) {
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
}

void drawZabor(HDC hdc) {
    //Задача 4 Забор
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
    SelectObject(hdc, zabor);
    //Первая точка забора
    int x_z1 = 150, y_z1 = 0;
    //Вторая точка забора
    int x_z2 = 150, y_z2 = 100;
    do {
        //соединяем первую со второй
        MoveToEx(hdc, x_z1, y_z1, NULL);
        LineTo(hdc, x_z2, y_z2);
        x_z1 += 10;
        x_z2 += 10;
    } while (x_z1 <= 450);
}

void drawHome(HDC hdc) {
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
}
void Yolka(HDC hdc) {
    //Ёлка
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
}
void drawRiver(HDC hdc) {
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
}
void drawTree3(HDC hdc) {
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
}
void drawTableandChairs(HDC hdc) {
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
}
void DrawBottle(HDC hdc) {
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
}

void drawVeed(HDC hdc) {
    //Задание 5 Трава у дома, зелёная, зелёная трава
            // Задний ряд
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
}
void drawStrangePurpleThing(HDC hdc) {
    //Задача 5 Второй объект 
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
    } while (penteract_y5 >= 300);
}
//ЛАБА 5
void drawCar(HDC hdc)
{
    HPEN wheels, wheels2, razmetka, inomarka_roof, treshina, UAZ_Roof, windows_angle, UAZ_BackWheel, Porogs;
    HBRUSH road, UAZ, UAZ_Down, sky, sky1, sky2, sky3, inomarka, inomarka_centr, fara, windows;

    road = CreateSolidBrush(RGB(63, 63, 63));
    UAZ = CreateSolidBrush(RGB(116, 116, 116));
    razmetka = CreatePen(PS_SOLID, 20, RGB(180, 180, 180));
    wheels = CreatePen(PS_SOLID, 15, RGB(27, 27, 27));
    wheels2 = CreatePen(PS_SOLID, 30, RGB(202, 202, 202));
    inomarka = CreateSolidBrush(RGB(210, 0, 0));
    inomarka_roof = CreatePen(PS_SOLID, 10, RGB(250, 250, 250));
    fara = CreateSolidBrush(RGB(255, 242, 0));
    inomarka_centr = CreateSolidBrush(RGB(0, 0, 255));
    sky = CreateSolidBrush(RGB(121, 163, 249));
    sky1 = CreateSolidBrush(RGB(108, 152, 249));
    sky2 = CreateSolidBrush(RGB(100, 136, 248));
    sky3 = CreateSolidBrush(RGB(86, 112, 248));
    treshina = CreatePen(PS_SOLID, 7, RGB(46, 46, 46));
    UAZ_Roof = CreatePen(PS_SOLID, 10, RGB(116, 116, 116));
    windows = CreateSolidBrush(RGB(183, 183, 183));
    windows_angle = CreatePen(PS_SOLID, 10, RGB(183, 183, 183));
    UAZ_Down = CreateSolidBrush(RGB(110, 110, 110));
    UAZ_BackWheel = CreatePen(PS_SOLID, 10, RGB(100, 100, 100));
    Porogs = CreatePen(PS_SOLID, 20, RGB(70, 70, 70));
    //Корпус УАЗика
    SelectObject(hdc, UAZ);
    RECT Body = { 650,500,1200,650 };
    FillRect(hdc, &Body, UAZ);

    //Передний бампер
    RECT Bamper0 = { 630,520,1200,650 };
    FillRect(hdc, &Bamper0, UAZ);
    RECT Bamper1 = { 610,550,1200,645 };
    FillRect(hdc, &Bamper1, UAZ);
    RECT Bamper2 = { 598,560,1200,640 };
    FillRect(hdc, &Bamper2, UAZ);

    //Пороги
    SelectObject(hdc, Porogs);
    MoveToEx(hdc, 700, 625, NULL);
    LineTo(hdc, 1100, 625);

    //Задний бампер
    RECT Bamper_zad0 = { 1200,640,1215,500 };
    FillRect(hdc, &Bamper_zad0, UAZ);
    RECT Bamper_zad1 = { 1215,630,1230,500 };
    FillRect(hdc, &Bamper_zad1, UAZ);
    RECT Bamper_zad2 = { 1225,620,1240,500 };
    FillRect(hdc, &Bamper_zad2, UAZ);


    //Диск запаски на дороге
    SelectObject(hdc, wheels2);
    Ellipse(hdc, 1420, 585, 1480, 605);

    //Передний бампер и еще один цвет корпуса
    SelectObject(hdc, UAZ_Down);
    RECT Body_Down = { 610,570,1240,520 };
    FillRect(hdc, &Body_Down, UAZ_Down);

    //Крыша УАЗика
    SelectObject(hdc, UAZ_Roof);
    MoveToEx(hdc, 655, 500, NULL);
    LineTo(hdc, 800, 480);
    LineTo(hdc, 870, 400);
    LineTo(hdc, 890, 395);
    LineTo(hdc, 900, 394);
    LineTo(hdc, 1220, 395);
    LineTo(hdc, 1230, 400);
    LineTo(hdc, 1235, 500);
    MoveToEx(hdc, 980, 395, NULL);
    LineTo(hdc, 980, 500);
    MoveToEx(hdc, 1120, 395, NULL);
    LineTo(hdc, 1120, 500);

    MoveToEx(hdc, 800, 481, NULL);
    LineTo(hdc, 1230, 481);
    MoveToEx(hdc, 700, 495, NULL);
    LineTo(hdc, 1230, 495);
    MoveToEx(hdc, 770, 490, NULL);
    LineTo(hdc, 1230, 490);

    //Стекла УАЗа
    RECT window1 = { 985,400,1115, 480 };
    FillRect(hdc, &window1, windows);
    RECT window2 = { 1125,400,1229,480 };
    FillRect(hdc, &window2, windows);
    RECT window3 = { 890,400,975,480 };
    FillRect(hdc, &window3, windows);

    SelectObject(hdc, windows_angle);
    MoveToEx(hdc, 815, 475, NULL);
    LineTo(hdc, 878, 405);
    MoveToEx(hdc, 825, 475, NULL);
    LineTo(hdc, 885, 404);
    MoveToEx(hdc, 815, 475, NULL);
    LineTo(hdc, 900, 475);
    MoveToEx(hdc, 835, 475, NULL);
    LineTo(hdc, 895, 404);
    MoveToEx(hdc, 845, 475, NULL);
    LineTo(hdc, 905, 404);
    MoveToEx(hdc, 855, 475, NULL);
    LineTo(hdc, 915, 404);
    MoveToEx(hdc, 865, 475, NULL);
    LineTo(hdc, 925, 404);
    MoveToEx(hdc, 875, 475, NULL);
    LineTo(hdc, 935, 404);
    MoveToEx(hdc, 885, 475, NULL);
    LineTo(hdc, 945, 404);
    MoveToEx(hdc, 878, 405, NULL);
    LineTo(hdc, 945, 405);

    //Передняя фара
    RECT Fara1 = { 610,500, 630, 550 };
    FillRect(hdc, &Fara1, fara);
    RECT Fara1_1 = { 610,500, 650, 520 };
    FillRect(hdc, &Fara1_1, fara);

    //Задняя фара
    RECT Fara2 = { 1210,500, 1240, 520 };
    FillRect(hdc, &Fara2, inomarka);
    RECT Fara2_1 = { 1225,520, 1240, 540 };
    FillRect(hdc, &Fara2_1, inomarka);

    //Ручки
    RECT hand = { 915, 500, 955, 520 };
    FillRect(hdc, &hand, road);
    RECT hand1 = { 1055, 500, 1095, 520 };
    FillRect(hdc, &hand1, road);

    //Шины УАЗика
    SelectObject(hdc, wheels);
    Ellipse(hdc, 670, 700, 770, 600);
    Ellipse(hdc, 1080, 700, 1180, 600);

    //Диски УАЗика
    SelectObject(hdc, wheels2);
    Ellipse(hdc, 690, 682, 750, 622);
    Ellipse(hdc, 1100, 682, 1160, 622);

}

void drawRoad(HDC hdc) {
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



    HPEN wheels, wheels2, razmetka, inomarka_roof, treshina, UAZ_Roof, windows_angle, UAZ_BackWheel, Porogs;
    HBRUSH road, UAZ, UAZ_Down, sky, sky1, sky2, sky3, inomarka, inomarka_centr, fara, windows;

    road = CreateSolidBrush(RGB(63, 63, 63));
    UAZ = CreateSolidBrush(RGB(116, 116, 116));
    razmetka = CreatePen(PS_SOLID, 20, RGB(180, 180, 180));
    wheels = CreatePen(PS_SOLID, 15, RGB(27, 27, 27));
    wheels2 = CreatePen(PS_SOLID, 30, RGB(202, 202, 202));
    inomarka = CreateSolidBrush(RGB(210, 0, 0));
    inomarka_roof = CreatePen(PS_SOLID, 10, RGB(250, 250, 250));
    fara = CreateSolidBrush(RGB(255, 242, 0));
    inomarka_centr = CreateSolidBrush(RGB(0, 0, 255));
    sky = CreateSolidBrush(RGB(121, 163, 249));
    sky1 = CreateSolidBrush(RGB(108, 152, 249));
    sky2 = CreateSolidBrush(RGB(100, 136, 248));
    sky3 = CreateSolidBrush(RGB(86, 112, 248));
    treshina = CreatePen(PS_SOLID, 7, RGB(46, 46, 46));
    UAZ_Roof = CreatePen(PS_SOLID, 10, RGB(116, 116, 116));
    windows = CreateSolidBrush(RGB(183, 183, 183));
    windows_angle = CreatePen(PS_SOLID, 10, RGB(183, 183, 183));
    UAZ_Down = CreateSolidBrush(RGB(110, 110, 110));
    UAZ_BackWheel = CreatePen(PS_SOLID, 10, RGB(100, 100, 100));
    Porogs = CreatePen(PS_SOLID, 20, RGB(70, 70, 70));
    //Дорога
    SelectObject(hdc, road);
    RECT doroga = { 0, 500, 2000, 2000 };
    FillRect(hdc, &doroga, road);
}

void drawRoadCrushes(HDC hdc) {
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



    HPEN wheels, wheels2, razmetka, inomarka_roof, treshina, UAZ_Roof, windows_angle, UAZ_BackWheel, Porogs;
    HBRUSH road, UAZ, UAZ_Down, sky, sky1, sky2, sky3, inomarka, inomarka_centr, fara, windows;

    road = CreateSolidBrush(RGB(63, 63, 63));
    UAZ = CreateSolidBrush(RGB(116, 116, 116));
    razmetka = CreatePen(PS_SOLID, 20, RGB(180, 180, 180));
    wheels = CreatePen(PS_SOLID, 15, RGB(27, 27, 27));
    wheels2 = CreatePen(PS_SOLID, 30, RGB(202, 202, 202));
    inomarka = CreateSolidBrush(RGB(210, 0, 0));
    inomarka_roof = CreatePen(PS_SOLID, 10, RGB(250, 250, 250));
    fara = CreateSolidBrush(RGB(255, 242, 0));
    inomarka_centr = CreateSolidBrush(RGB(0, 0, 255));
    sky = CreateSolidBrush(RGB(121, 163, 249));
    sky1 = CreateSolidBrush(RGB(108, 152, 249));
    sky2 = CreateSolidBrush(RGB(100, 136, 248));
    sky3 = CreateSolidBrush(RGB(86, 112, 248));
    treshina = CreatePen(PS_SOLID, 7, RGB(46, 46, 46));
    UAZ_Roof = CreatePen(PS_SOLID, 10, RGB(116, 116, 116));
    windows = CreateSolidBrush(RGB(183, 183, 183));
    windows_angle = CreatePen(PS_SOLID, 10, RGB(183, 183, 183));
    UAZ_Down = CreateSolidBrush(RGB(110, 110, 110));
    UAZ_BackWheel = CreatePen(PS_SOLID, 10, RGB(100, 100, 100));
    Porogs = CreatePen(PS_SOLID, 20, RGB(70, 70, 70));
    //Трещины на дороге
    SelectObject(hdc, treshina);
    MoveToEx(hdc, 1000, 850, NULL);
    LineTo(hdc, 1100, 840);
    LineTo(hdc, 1200, 890);
    LineTo(hdc, 1400, 830);
    LineTo(hdc, 1600, 900);
    LineTo(hdc, 1800, 880);
    LineTo(hdc, 1920, 900);
    MoveToEx(hdc, 0, 850, NULL);
    LineTo(hdc, 100, 840);
    LineTo(hdc, 300, 950);
    LineTo(hdc, 500, 790);
    LineTo(hdc, 700, 880);
    LineTo(hdc, 900, 800);
    LineTo(hdc, 1000, 850);
}

void drawRoadLine(HDC hdc) {
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



    HPEN wheels, wheels2, razmetka, inomarka_roof, treshina, UAZ_Roof, windows_angle, UAZ_BackWheel, Porogs;
    HBRUSH road, UAZ, UAZ_Down, sky, sky1, sky2, sky3, inomarka, inomarka_centr, fara, windows;

    road = CreateSolidBrush(RGB(63, 63, 63));
    UAZ = CreateSolidBrush(RGB(116, 116, 116));
    razmetka = CreatePen(PS_SOLID, 20, RGB(180, 180, 180));
    wheels = CreatePen(PS_SOLID, 15, RGB(27, 27, 27));
    wheels2 = CreatePen(PS_SOLID, 30, RGB(202, 202, 202));
    inomarka = CreateSolidBrush(RGB(210, 0, 0));
    inomarka_roof = CreatePen(PS_SOLID, 10, RGB(250, 250, 250));
    fara = CreateSolidBrush(RGB(255, 242, 0));
    inomarka_centr = CreateSolidBrush(RGB(0, 0, 255));
    sky = CreateSolidBrush(RGB(121, 163, 249));
    sky1 = CreateSolidBrush(RGB(108, 152, 249));
    sky2 = CreateSolidBrush(RGB(100, 136, 248));
    sky3 = CreateSolidBrush(RGB(86, 112, 248));
    treshina = CreatePen(PS_SOLID, 7, RGB(46, 46, 46));
    UAZ_Roof = CreatePen(PS_SOLID, 10, RGB(116, 116, 116));
    windows = CreateSolidBrush(RGB(183, 183, 183));
    windows_angle = CreatePen(PS_SOLID, 10, RGB(183, 183, 183));
    UAZ_Down = CreateSolidBrush(RGB(110, 110, 110));
    UAZ_BackWheel = CreatePen(PS_SOLID, 10, RGB(100, 100, 100));
    Porogs = CreatePen(PS_SOLID, 20, RGB(70, 70, 70));
    //Разметка
    SelectObject(hdc, razmetka);
    MoveToEx(hdc, 0, 750, NULL);
    LineTo(hdc, 2000, 750);
}

void drawSky(HDC hdc) {
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



    HPEN wheels, wheels2, razmetka, inomarka_roof, treshina, UAZ_Roof, windows_angle, UAZ_BackWheel, Porogs;
    HBRUSH road, UAZ, UAZ_Down, sky, sky1, sky2, sky3, inomarka, inomarka_centr, fara, windows;

    road = CreateSolidBrush(RGB(63, 63, 63));
    UAZ = CreateSolidBrush(RGB(116, 116, 116));
    razmetka = CreatePen(PS_SOLID, 20, RGB(180, 180, 180));
    wheels = CreatePen(PS_SOLID, 15, RGB(27, 27, 27));
    wheels2 = CreatePen(PS_SOLID, 30, RGB(202, 202, 202));
    inomarka = CreateSolidBrush(RGB(210, 0, 0));
    inomarka_roof = CreatePen(PS_SOLID, 10, RGB(250, 250, 250));
    fara = CreateSolidBrush(RGB(255, 242, 0));
    inomarka_centr = CreateSolidBrush(RGB(0, 0, 255));
    sky = CreateSolidBrush(RGB(121, 163, 249));
    sky1 = CreateSolidBrush(RGB(108, 152, 249));
    sky2 = CreateSolidBrush(RGB(100, 136, 248));
    sky3 = CreateSolidBrush(RGB(86, 112, 248));
    treshina = CreatePen(PS_SOLID, 7, RGB(46, 46, 46));
    UAZ_Roof = CreatePen(PS_SOLID, 10, RGB(116, 116, 116));
    windows = CreateSolidBrush(RGB(183, 183, 183));
    windows_angle = CreatePen(PS_SOLID, 10, RGB(183, 183, 183));
    UAZ_Down = CreateSolidBrush(RGB(110, 110, 110));
    UAZ_BackWheel = CreatePen(PS_SOLID, 10, RGB(100, 100, 100));
    Porogs = CreatePen(PS_SOLID, 20, RGB(70, 70, 70));
    //Небо 0 слой
    SelectObject(hdc, sky);
    RECT nebo = { 0,0,2000,500 };
    FillRect(hdc, &nebo, sky);

    //Небо 1 слой
    SelectObject(hdc, sky1);
    RECT nebo1 = { 0,375,2000,250 };
    FillRect(hdc, &nebo1, sky1);

    //Небо 2 слой
    SelectObject(hdc, sky1);
    RECT nebo2 = { 0,250,2000,125 };
    FillRect(hdc, &nebo2, sky2);

    //Небо 3 слой
    SelectObject(hdc, sky1);
    RECT nebo3 = { 0,125,2000,0 };
    FillRect(hdc, &nebo3, sky3);
}

void drawSaveWheel(HDC hdc) {
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



    HPEN wheels, wheels2, razmetka, inomarka_roof, treshina, UAZ_Roof, windows_angle, UAZ_BackWheel, Porogs;
    HBRUSH road, UAZ, UAZ_Down, sky, sky1, sky2, sky3, inomarka, inomarka_centr, fara, windows;

    road = CreateSolidBrush(RGB(63, 63, 63));
    UAZ = CreateSolidBrush(RGB(116, 116, 116));
    razmetka = CreatePen(PS_SOLID, 20, RGB(180, 180, 180));
    wheels = CreatePen(PS_SOLID, 15, RGB(27, 27, 27));
    wheels2 = CreatePen(PS_SOLID, 30, RGB(202, 202, 202));
    inomarka = CreateSolidBrush(RGB(210, 0, 0));
    inomarka_roof = CreatePen(PS_SOLID, 10, RGB(250, 250, 250));
    fara = CreateSolidBrush(RGB(255, 242, 0));
    inomarka_centr = CreateSolidBrush(RGB(0, 0, 255));
    sky = CreateSolidBrush(RGB(121, 163, 249));
    sky1 = CreateSolidBrush(RGB(108, 152, 249));
    sky2 = CreateSolidBrush(RGB(100, 136, 248));
    sky3 = CreateSolidBrush(RGB(86, 112, 248));
    treshina = CreatePen(PS_SOLID, 7, RGB(46, 46, 46));
    UAZ_Roof = CreatePen(PS_SOLID, 10, RGB(116, 116, 116));
    windows = CreateSolidBrush(RGB(183, 183, 183));
    windows_angle = CreatePen(PS_SOLID, 10, RGB(183, 183, 183));
    UAZ_Down = CreateSolidBrush(RGB(110, 110, 110));
    UAZ_BackWheel = CreatePen(PS_SOLID, 10, RGB(100, 100, 100));
    Porogs = CreatePen(PS_SOLID, 20, RGB(70, 70, 70));

    //Запаска на дороге
    SelectObject(hdc, wheels);
    Ellipse(hdc, 1400, 600, 1500, 650);
    Ellipse(hdc, 1400, 590, 1500, 640);
    Ellipse(hdc, 1400, 580, 1500, 630);
    Ellipse(hdc, 1400, 570, 1500, 620);
}

void drawInomarka(HDC hdc) {
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



    HPEN wheels, wheels2, razmetka, inomarka_roof, treshina, UAZ_Roof, windows_angle, UAZ_BackWheel, Porogs;
    HBRUSH road, UAZ, UAZ_Down, sky, sky1, sky2, sky3, inomarka, inomarka_centr, fara, windows;

    road = CreateSolidBrush(RGB(63, 63, 63));
    UAZ = CreateSolidBrush(RGB(116, 116, 116));
    razmetka = CreatePen(PS_SOLID, 20, RGB(180, 180, 180));
    wheels = CreatePen(PS_SOLID, 15, RGB(27, 27, 27));
    wheels2 = CreatePen(PS_SOLID, 30, RGB(202, 202, 202));
    inomarka = CreateSolidBrush(RGB(210, 0, 0));
    inomarka_roof = CreatePen(PS_SOLID, 10, RGB(250, 250, 250));
    fara = CreateSolidBrush(RGB(255, 242, 0));
    inomarka_centr = CreateSolidBrush(RGB(0, 0, 255));
    sky = CreateSolidBrush(RGB(121, 163, 249));
    sky1 = CreateSolidBrush(RGB(108, 152, 249));
    sky2 = CreateSolidBrush(RGB(100, 136, 248));
    sky3 = CreateSolidBrush(RGB(86, 112, 248));
    treshina = CreatePen(PS_SOLID, 7, RGB(46, 46, 46));
    UAZ_Roof = CreatePen(PS_SOLID, 10, RGB(116, 116, 116));
    windows = CreateSolidBrush(RGB(183, 183, 183));
    windows_angle = CreatePen(PS_SOLID, 10, RGB(183, 183, 183));
    UAZ_Down = CreateSolidBrush(RGB(110, 110, 110));
    UAZ_BackWheel = CreatePen(PS_SOLID, 10, RGB(100, 100, 100));
    Porogs = CreatePen(PS_SOLID, 20, RGB(70, 70, 70));

    //Иномарка Нижняя часть
    SelectObject(hdc, inomarka);
    RECT Ino_Down = { 50,800,500,900 };
    FillRect(hdc, &Ino_Down, inomarka);

    //Иномарка Средняя часть
    SelectObject(hdc, inomarka_centr);
    RECT Ino_Centr = { 50,800,500,850 };
    FillRect(hdc, &Ino_Centr, inomarka_centr);

    //Шины иномарки 
    SelectObject(hdc, wheels);
    Ellipse(hdc, 70, 970, 170, 870);
    Ellipse(hdc, 380, 970, 480, 870);

    //Диски иномарки
    SelectObject(hdc, UAZ);
    Ellipse(hdc, 80, 875, 160, 960);
    Ellipse(hdc, 390, 875, 470, 960);

    //Крыша иномарки (Верхняя часть)
    SelectObject(hdc, inomarka_roof);
    MoveToEx(hdc, 400, 798, NULL);
    LineTo(hdc, 350, 730);
    LineTo(hdc, 55, 730);
    LineTo(hdc, 55, 798);
    LineTo(hdc, 400, 798);
    MoveToEx(hdc, 203, 730, NULL);
    LineTo(hdc, 203, 798);

    //Фарa иномарки
    SelectObject(hdc, fara);
    RECT Fara = { 460, 850, 500, 830 };
    FillRect(hdc, &Fara, fara);
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
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            



            //В ЭТОМ ПРОЕКТЕ И ЛАБА 4 И ЛАБА 5 И ЛАБА 7!!!!!!!!!!!!!!!!!!
            
           
            

            

            



            

            //ВЫЗОВЫ ФУНКЦИЙ ВЫЗЫВАТЬ ЗДЕСЬ!

            drawTree2(hdc);
            drawTree(hdc);
            
            


            
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
