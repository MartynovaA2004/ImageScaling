#include <iostream>
//#include <SFML/Graphics.hpp>
//#pragma comment(lib, "gdiplus.lib")
//#include <gdiplus.h>
//#include <gtk/gtk.h>

#include "CImg.h"
#include "ImageScaling.h"
#include <vector>
#include <string>

//using namespace Gdiplus;

using namespace cimg_library;
using namespace std;

void bilinear_interpolation(const char* input_path, const char* output_path, double scale_factor)
{
    if (scale_factor <= 0)
    {
        cout << "Invalid scale factor" << endl;
        return;
    }

    CImg<unsigned char> input_image(input_path); //исходное изображение

    int new_width = static_cast<int>(input_image.width() * scale_factor); //задаем новую ширину
    int new_height = static_cast<int>(input_image.height() * scale_factor); //задаем новую высоту

    CImg<unsigned char> output_image(new_width, new_height, 1, input_image.spectrum()); //конечное изображение, 1 - размер третьего измерения изображения (библиотека с 3д объектами работает, поэтому пишем 1 - плоское изображение)
                                                                     //.spectrum - число каналов (красный, зеленый, синий)
    cimg_forXY(output_image, x, y)
    {
        double orig_x = x / scale_factor; //задаем исходное значение x
        double orig_y = y / scale_factor; //задаем исходное значение y

        int x1 = static_cast<int>(orig_x); 
        int y1 = static_cast<int>(orig_y); 
        int x2 = min(x1 + 1, input_image.width() - 1); 
        int y2 = min(y1 + 1, input_image.height() - 1); 

        double dx = orig_x - x1; //разница между начальным и конечным пикселем
        double dy = orig_y - y1; //разница между начальным и конечным пикселем

        for (int c = 0; c < input_image.spectrum(); c++) // проходим по каналам
        {        //c- номер канала
            double interpolated_value = (1 - dx) * (1 - dy) * input_image(x1, y1, 0, c) + dx * (1 - dy) * input_image(x2, y1, 0, c) 
                + (1 - dx) * dy * input_image(x1, y2, 0, c) + dx * dy * input_image(x2, y2, 0, c); //двигаемся по изображению

            output_image(x, y, 0, c) = static_cast<unsigned char>(interpolated_value); //0 - верхний слой изображения (записываем на нулевой слой изображения данные)
        }
    }
    output_image.save(output_path); //сохраняем 

    //ULONG_PTR gdiToken;
    //GdiplusStartupInput gdiInput;
    //GdiplusStartup(&gdiToken, &gdiInput, NULL);

    //GdiplusShutdown(gdiToken);
    //Graphics graphics(wndDC); //wndDC - HDC окна
    //Bitmap bmp(L"C:\Users\pc\Desktop\Папка Насти\2 курс\4 семестр\АиСД\ImageScaling\\ouput.bmp");
    //graphics.DrawImage(&bmp, 0, 0, new_width, new_height);
}

int main() 
{
    const char* input_path = "input.bmp";
    const char* output_path = "output.bmp";
    double scale_factor = 2.0;

    bilinear_interpolation(input_path, output_path, scale_factor);

    cout << "Image scaled successfully." << endl;
    system("chcp 1251");
    std::cout << "Тест на знание стран мира." << std::endl;
    std::cout << "(в качестве ответа укажите только цифру выбранного вами ответа: 1, 2 или 3)" << std::endl;

    // Вопрос 1
    std::cout << "1 - Крупнейший город по численности населения в мире:" << std::endl;
    std::cout << "1.  Нью-Йорк" << std::endl;
    std::cout << "2.  Гонконг" << std::endl;
    std::cout << "3.  Шанхай" << std::endl;

    int answer1;
    std::cin >> answer1; // Запрашиваем у пользователя номер ответа

    if (answer1 == 3)
    {
        std::cout << "Правильно! Крупнейший город по численности населения в мире - Шанхай." << std::endl;
    }
    else
    {
        std::cout << "Неправильно. Крупнейший город по численности населения в мире - Шанхай." << std::endl;
    }

    // Вопрос 2
    std::cout << std::endl;
    std::cout << "2 - В какой стране находится больше всего озер?" << std::endl;
    std::cout << "1.  Россия" << std::endl;
    std::cout << "2.  Канада" << std::endl;
    std::cout << "3.  Норвегия" << std::endl;

    int answer2;
    std::cin >> answer2; // Запрашиваем у пользователя номер ответа

    if (answer2 == 2)
    {
        std::cout << "Правильно! Больше всего озер в мире находится в Канаде." << std::endl;
    }
    else
    {
        std::cout << "Неправильно. Больше всего озер в мире находится в Канаде." << std::endl;
    }

    // Вопрос 3
    std::cout << std::endl;
    std::cout << "3 - Страна с самым большим количеством часовых поясов:" << std::endl;
    std::cout << "1.  Франция" << std::endl;
    std::cout << "2.  Россия" << std::endl;
    std::cout << "3.  США" << std::endl;

    int answer3;
    std::cin >> answer3; // Запрашиваем у пользователя номер ответа

    if (answer3 == 1)
    {
        std::cout << "Правильно! Страна с самым большим количеством часовых поясов - Франция." << std::endl;
    }
    else
    {
        std::cout << "Неправильно. Страна с самым большим количеством часовых поясов - Франция." << std::endl;
    }

    // Вопрос 4
    std::cout << std::endl;
    std::cout << "4 - Страна с наибольшим количеством языков:" << std::endl;
    std::cout << "1.  Италия" << std::endl;
    std::cout << "2.  Филиппины" << std::endl;
    std::cout << "3.  Папуа – Новая Гвинея" << std::endl;

    int answer4;
    std::cin >> answer4; // Запрашиваем у пользователя номер ответа

    if (answer4 == 3)
    {
        std::cout << "Правильно! Страна наибольшим количеством языков - Папуа – Новая Гвинея." << std::endl;
    }
    else
    {
        std::cout << "Неправильно. Страна наибольшим количеством языков - Папуа – Новая Гвинея." << std::endl;
    }

    // Вопрос 5
    std::cout << std::endl;
    std::cout << "5 - Герб какой страны показан на изображении?" << std::endl;
    std::cout << "1.  Германия" << std::endl;
    std::cout << "2.  Китай" << std::endl;
    std::cout << "3.  Россия" << std::endl;

   // IShellDispatch2::ShellExecute(NULL, "open", "output.bmp", NULL, NULL, SW_SHOWNORMAL);

    int answer5;
    std::cin >> answer5; // Запрашиваем у пользователя номер ответа

    if (answer5 == 3)
    {
        std::cout << "Правильно! Герб с двухглавым орлом принадлежит России." << std::endl;
    }
    else
    {
        std::cout << "Неправильно. Герб с двухглавым орлом принадлежит России." << std::endl;
    }

    return 0;
}