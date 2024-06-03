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

    CImg<unsigned char> input_image(input_path); //�������� �����������

    int new_width = static_cast<int>(input_image.width() * scale_factor); //������ ����� ������
    int new_height = static_cast<int>(input_image.height() * scale_factor); //������ ����� ������

    CImg<unsigned char> output_image(new_width, new_height, 1, input_image.spectrum()); //�������� �����������, 1 - ������ �������� ��������� ����������� (���������� � 3� ��������� ��������, ������� ����� 1 - ������� �����������)
                                                                     //.spectrum - ����� ������� (�������, �������, �����)
    cimg_forXY(output_image, x, y)
    {
        double orig_x = x / scale_factor; //������ �������� �������� x
        double orig_y = y / scale_factor; //������ �������� �������� y

        int x1 = static_cast<int>(orig_x); 
        int y1 = static_cast<int>(orig_y); 
        int x2 = min(x1 + 1, input_image.width() - 1); 
        int y2 = min(y1 + 1, input_image.height() - 1); 

        double dx = orig_x - x1; //������� ����� ��������� � �������� ��������
        double dy = orig_y - y1; //������� ����� ��������� � �������� ��������

        for (int c = 0; c < input_image.spectrum(); c++) // �������� �� �������
        {        //c- ����� ������
            double interpolated_value = (1 - dx) * (1 - dy) * input_image(x1, y1, 0, c) + dx * (1 - dy) * input_image(x2, y1, 0, c) 
                + (1 - dx) * dy * input_image(x1, y2, 0, c) + dx * dy * input_image(x2, y2, 0, c); //��������� �� �����������

            output_image(x, y, 0, c) = static_cast<unsigned char>(interpolated_value); //0 - ������� ���� ����������� (���������� �� ������� ���� ����������� ������)
        }
    }
    output_image.save(output_path); //��������� 

    //ULONG_PTR gdiToken;
    //GdiplusStartupInput gdiInput;
    //GdiplusStartup(&gdiToken, &gdiInput, NULL);

    //GdiplusShutdown(gdiToken);
    //Graphics graphics(wndDC); //wndDC - HDC ����
    //Bitmap bmp(L"C:\Users\pc\Desktop\����� �����\2 ����\4 �������\����\ImageScaling\\ouput.bmp");
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
    std::cout << "���� �� ������ ����� ����." << std::endl;
    std::cout << "(� �������� ������ ������� ������ ����� ���������� ���� ������: 1, 2 ��� 3)" << std::endl;

    // ������ 1
    std::cout << "1 - ���������� ����� �� ����������� ��������� � ����:" << std::endl;
    std::cout << "1.  ���-����" << std::endl;
    std::cout << "2.  �������" << std::endl;
    std::cout << "3.  ������" << std::endl;

    int answer1;
    std::cin >> answer1; // ����������� � ������������ ����� ������

    if (answer1 == 3)
    {
        std::cout << "���������! ���������� ����� �� ����������� ��������� � ���� - ������." << std::endl;
    }
    else
    {
        std::cout << "�����������. ���������� ����� �� ����������� ��������� � ���� - ������." << std::endl;
    }

    // ������ 2
    std::cout << std::endl;
    std::cout << "2 - � ����� ������ ��������� ������ ����� ����?" << std::endl;
    std::cout << "1.  ������" << std::endl;
    std::cout << "2.  ������" << std::endl;
    std::cout << "3.  ��������" << std::endl;

    int answer2;
    std::cin >> answer2; // ����������� � ������������ ����� ������

    if (answer2 == 2)
    {
        std::cout << "���������! ������ ����� ���� � ���� ��������� � ������." << std::endl;
    }
    else
    {
        std::cout << "�����������. ������ ����� ���� � ���� ��������� � ������." << std::endl;
    }

    // ������ 3
    std::cout << std::endl;
    std::cout << "3 - ������ � ����� ������� ����������� ������� ������:" << std::endl;
    std::cout << "1.  �������" << std::endl;
    std::cout << "2.  ������" << std::endl;
    std::cout << "3.  ���" << std::endl;

    int answer3;
    std::cin >> answer3; // ����������� � ������������ ����� ������

    if (answer3 == 1)
    {
        std::cout << "���������! ������ � ����� ������� ����������� ������� ������ - �������." << std::endl;
    }
    else
    {
        std::cout << "�����������. ������ � ����� ������� ����������� ������� ������ - �������." << std::endl;
    }

    // ������ 4
    std::cout << std::endl;
    std::cout << "4 - ������ � ���������� ����������� ������:" << std::endl;
    std::cout << "1.  ������" << std::endl;
    std::cout << "2.  ���������" << std::endl;
    std::cout << "3.  ����� � ����� ������" << std::endl;

    int answer4;
    std::cin >> answer4; // ����������� � ������������ ����� ������

    if (answer4 == 3)
    {
        std::cout << "���������! ������ ���������� ����������� ������ - ����� � ����� ������." << std::endl;
    }
    else
    {
        std::cout << "�����������. ������ ���������� ����������� ������ - ����� � ����� ������." << std::endl;
    }

    // ������ 5
    std::cout << std::endl;
    std::cout << "5 - ���� ����� ������ ������� �� �����������?" << std::endl;
    std::cout << "1.  ��������" << std::endl;
    std::cout << "2.  �����" << std::endl;
    std::cout << "3.  ������" << std::endl;

   // IShellDispatch2::ShellExecute(NULL, "open", "output.bmp", NULL, NULL, SW_SHOWNORMAL);

    int answer5;
    std::cin >> answer5; // ����������� � ������������ ����� ������

    if (answer5 == 3)
    {
        std::cout << "���������! ���� � ���������� ����� ����������� ������." << std::endl;
    }
    else
    {
        std::cout << "�����������. ���� � ���������� ����� ����������� ������." << std::endl;
    }

    return 0;
}