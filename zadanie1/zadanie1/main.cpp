#include <SFML/Graphics.hpp> //��� ����������� �����

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Picrure");
    
    Texture Picture;
    Picture.loadFromFile("C:/Users/pc/Desktop/����� �����/2 ����/4 �������/����/ImageScaling/output.bmp");
    Sprite Sprite1(Picture);//������

    while (window.isOpen())	//���� ���� ����������� ���� �� �������
    {
        sf::Event event;
        while (window.pollEvent(event))	//�������� �������
        {
            if (event.type == sf::Event::Closed)	//���� ��������� ������� �������� ����
                window.close();
        };
        window.clear(sf::Color::White);
        window.draw(Sprite1);
        window.display();
    }

}
