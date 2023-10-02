// Лаба 5.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Лаба 5.h"

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
    LoadStringW(hInstance, IDC_MY5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY5));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY5);
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

            HPEN wheels, wheels2, razmetka, inomarka_roof, treshina, UAZ_Roof, windows_angle,UAZ_BackWheel;
            HBRUSH road, UAZ, UAZ_Down, sky, sky1, sky2, sky3, inomarka, inomarka_centr, fara, windows;

            road = CreateSolidBrush(RGB(63, 63, 63));
            UAZ = CreateSolidBrush(RGB(116, 116, 116));
            razmetka = CreatePen(PS_SOLID, 20, RGB(180, 180, 180));
            wheels = CreatePen(PS_SOLID, 15, RGB(27,27,27));
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
            UAZ_Down = CreateSolidBrush(RGB(115, 115, 115));
            UAZ_BackWheel = CreatePen(PS_SOLID, 10, RGB(100,100,100));

            //Дорога
            SelectObject(hdc, road);
            RECT doroga = { 0, 500, 2000, 2000 };
            FillRect(hdc, &doroga, road);

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

            //Разметка
            SelectObject(hdc, razmetka);
            MoveToEx(hdc, 0,750, NULL);
            LineTo(hdc, 2000, 750);

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
            RECT nebo2 = { 0,250,2000,125};
            FillRect(hdc, &nebo2, sky2);

            //Небо 3 слой
            SelectObject(hdc, sky1);
            RECT nebo3 = { 0,125,2000,0};
            FillRect(hdc, &nebo3, sky3);

            //Корпус УАЗика
            SelectObject(hdc, UAZ);
            RECT Body = { 650,500,1200,650};
            FillRect(hdc, &Body, UAZ);

            //Передний бампер
            RECT Bamper0 = { 630,520,1200,650 };
            FillRect(hdc, &Bamper0, UAZ);
            RECT Bamper1 = { 610,550,1200,645};
            FillRect(hdc, &Bamper1, UAZ);
            RECT Bamper2 = { 598,560,1200,640};
            FillRect(hdc, &Bamper2, UAZ);

            //Пороги
            
            //Задний бампер
            RECT Bamper_zad0 = { 1200,640,1215,500 };
            FillRect(hdc, &Bamper_zad0, UAZ);
            RECT Bamper_zad1 = { 1215,630,1230,500 };
            FillRect(hdc, &Bamper_zad1, UAZ);
            RECT Bamper_zad2 = { 1225,620,1240,500 };
            FillRect(hdc, &Bamper_zad2, UAZ);

            //Запаска на дороге
            SelectObject(hdc, wheels);
            Ellipse(hdc, 1400, 600, 1500, 650);
            Ellipse(hdc, 1400, 590, 1500, 640);
            Ellipse(hdc, 1400, 580, 1500, 630);
            Ellipse(hdc, 1400, 570, 1500, 620);

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
            RECT window1 = { 985,400,1115, 480};
            FillRect(hdc, &window1, windows);
            RECT window2 = { 1125,400,1229,480};
            FillRect(hdc, &window2, windows);
            RECT window3 = { 890,400,975,480};
            FillRect(hdc, &window3, windows);

            SelectObject(hdc, windows_angle);
            MoveToEx(hdc, 815, 475,NULL);
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
            RECT Fara1 = {610,500, 630, 550};
            FillRect(hdc, &Fara1, fara);
            RECT Fara1_1 = {610,500, 650, 520 };
            FillRect(hdc, &Fara1_1, fara);  

            //Задняя фара
            RECT Fara2 = { 1210,500, 1240, 520 };
            FillRect(hdc, &Fara2, inomarka);
            RECT Fara2_1 = { 1225,520, 1240, 540 };
            FillRect(hdc, &Fara2_1, inomarka);
            
            //Ручки
            RECT hand = {915, 500, 955, 520 };
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

            //Иномарка Нижняя часть
            SelectObject(hdc, inomarka);
            RECT Ino_Down = { 50,800,500,900};
            FillRect(hdc, &Ino_Down, inomarka);

            //Иномарка Средняя часть
            SelectObject(hdc, inomarka_centr);
            RECT Ino_Centr = { 50,800,500,850};
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
            FillRect (hdc, &Fara, fara);




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
