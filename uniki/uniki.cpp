#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<Windows.h>
#include<iostream>
#include<locale.h>
#include<stdlib.h>
#include"App.h"
#include"config.h"
#include"tools.h"

using namespace std;
using namespace sf;


                //-------stałe-----------//
const int xSquare = 18;
const int ySquare = 9;
float squareSize = 100.f;
Color bgColor(Color(0, 0, 40));
Color pustaColor(Color(70, 70, 70));
Color graczColor(Color(0, 255, 0));
Color przeszkodaColor(randomColor());
Vector2f backgroundStartPosition(Vector2f(20, 20));
//Vector2f wynikStartPosistion(Vector2f(20, 10));

                //-------pomoc--------//
inline int menuselected{ 0 };
inline bool isMenuOpen = true;


                //-------komórki--------//
class Cell : public RectangleShape {
public:
    
    
    //Texture texturaGraj;
    //String strGraj,strWyjdz;
    //Text textGraj, textWyjdz;
    //Font font;
    
    //czy kormorka jest pusta
    bool czyPusta = true;
    //sprawdza czy w komorce jest gracz
    bool czyJestGracz = false;
    //czy w komorce jest przeszkoda
    bool czyJestPrzeszkoda = false;
    int x{}, y{};
    Cell() : RectangleShape() {}
    Cell(Vector2f f) : RectangleShape(f) {}
    void setPusta() {
        this->czyPusta = true;
        this->czyJestGracz = false;
        this->czyJestPrzeszkoda = false;
        this->setFillColor(pustaColor);
    }
    void setPelnaGracz() {
        this->czyPusta = false;
        this->czyJestPrzeszkoda = false;
        this->czyJestGracz = true;
        this->setFillColor(graczColor);
        
    }
    void setPelnaPrzeszkoda() {
        this->czyPusta = false;
        this->czyJestGracz = false;
        this->czyJestPrzeszkoda = true;
        this->setFillColor(przeszkodaColor);
    }
    void budujPuste() {
        this->czyPusta = true;
        this->setSize(Vector2f(squareSize, squareSize));
        this->setOrigin(0, 0);
        this->setPusta();
    }
    //void budujKomorki() {
    //    
    //    this->setOrigin(0, 0);
    //    this->setFillColor(bgColor);

    //}
    void ustawPuste(int x, int y) {
        this->setPosition(Vector2f(
            backgroundStartPosition.x + x * squareSize,
            backgroundStartPosition.y + y * squareSize));
        this->x = x;
        this->y = y;
    }
    //void buttonGraj() {

    //    //this->setFillColor(Color::Green);
    //    this->setPosition(Vector2f(800, 300));
    //    this->setSize(Vector2f(240, 120));
    //    this->setOutlineColor(Color::Red);
    //    this->setOutlineThickness(10);
    //}
    //void buttonWyjdz() {

    //    this->setPosition(Vector2f(800, 520));
    //    this->setSize(Vector2f(240, 120));
    //    this->setOutlineColor(Color::Red);
    //    this->setOutlineThickness(10);
    //}

    //
    //vector<vector<Cell>> menu{};
    //void createMenu() {
    //    this->menu.resize(1, {});
    //    for (auto& c : this->menu)c.resize(2, Cell());
    //    this->menu[0][0].buttonGraj();
    //    this->menu[0][1].buttonWyjdz();
    //    this->menu[0][menuselected].setFillColor(Color::Green);
    //    app.W.draw(this->menu[0][0]);
    //    app.W.draw(this->menu[0][1]);
    //}
    //
    //void menuGora() {
    //    this->menu[0][menuselected].setFillColor(Color::White);
    //    if (menuselected == 0)menuselected = 1;
    //    else menuselected = 0;
    //    this->menu[0][menuselected].setFillColor(Color::Green);
    //}
    //void menuDol() {
    //    this->menu[0][menuselected].setFillColor(Color::White);
    //    if (menuselected == 1)menuselected = 0;
    //    else menuselected = 1;
    //    this->menu[0][menuselected].setFillColor(Color::Green);
    //}



};




//----------gra-----------//
class Gra {
public:

    vector<vector<Cell>> background{};
    vector<Cell> poleWynik{};

    Gra() {
        ////generujemy plansze
        //this->background.resize(xSquare, {});
        //for (auto& c : this->background)c.resize(ySquare, Cell());
        ////wypelniamy pustymi komorkami
        //for (int x = 0; x < xSquare; x++)
        //{

        //    for (int y = 0; y < ySquare; y++)
        //    {
        //        this->background[x][y].budujPuste();
        //        this->background[x][y].ustawPuste(x, y);

        //    }
        //}
        //this->background[1][4].setPelnaGracz();
    }


    void narysujPlansze() {
        for (int x = 0; x < xSquare; x++)
        {
            for (int y = 0; y < ySquare; y++)
            {
                app.W.draw(this->background[x][y]);
            }
        }
    }
    bool czyczysta = false;
    void czysc() {
        if (czyczysta == false)
        {
            for (int x = 0; x < xSquare; x++)
            {
                for (int y = 0; y < ySquare; y++)
                {
                    this->background[x][y].setPusta();
                    this->background[x][y].setFillColor(Color(255, 0, 0));
                }
            }
            czyczysta = true;
        }
        else
        {
            generujPlansze();
            czyczysta = false;
        }

    }
    void generujPlansze() {
        //generujemy plansze
        this->background.resize(xSquare, {});
        for (auto& c : this->background)c.resize(ySquare, Cell());
        //wypelniamy pustymi komorkami
        for (int x = 0; x < xSquare; x++)
        {

            for (int y = 0; y < ySquare; y++)
            {
                this->background[x][y].budujPuste();
                this->background[x][y].ustawPuste(x, y);
            }
        }
        this->background[1][4].setPelnaGracz();
    }
    void gora() {
        for (int y = 0; y < ySquare; y++)
        {
            if ((this->background[1][y].czyJestGracz == true) && (y > 0))
            {
                if (this->background[1][y - 1].czyJestPrzeszkoda == true)
                {
                    czysc();
                    //isMenuOpen = true;
                }
                else
                {
                    this->background[1][y - 1].setPelnaGracz();
                    this->background[1][y].setPusta();
                    break;
                }

            }
        }
    }
    void dol() {
        for (int y = 0; y < ySquare; y++)
        {
            int i{};
            if ((this->background[1][y].czyJestGracz == true) && (y < 8))
            {
                if (this->background[1][y + 1].czyJestPrzeszkoda == true)
                {
                    czysc();
                    //isMenuOpen = true;
                }
                else
                {
                    this->background[1][y + 1].setPelnaGracz();
                    this->background[1][y].setPusta();
                    break;
                }
            }

        }
    }
    void postawPrzeszkody() {

        int x{};
        if (czyczysta == false)
        {
            for (int i = 0; i < los4(); i++)
            {
                while (true)
                {
                    x = los8();
                    if (this->background[17][x].czyPusta == true)
                    {
                        this->background[17][x].setPelnaPrzeszkoda();
                        break;
                    }
                }

            }
        }

    }
    void ruchPrzeszkod() {
        Sleep(trudnosc);

        for (int x = 0; x < xSquare; x++)
        {
            for (int y = 0; y < ySquare; y++)
            {
                if ((x == 0) && (this->background[x][y].czyJestPrzeszkoda == true))
                {
                    this->background[x][y].setPusta();
                }
                else if (this->background[x][y].czyJestPrzeszkoda == true)
                {
                    if (this->background[x - 1][y].czyJestGracz == true)
                    {
                        czysc();
                        //isMenuOpen = true;
                    }

                    else
                    {
                        this->background[x - 1][y].setPelnaPrzeszkoda();
                        this->background[x][y].setPusta();
                    }
                }


            }
        }
    }

};
inline Cell cell;
inline Gra uniki;
void bind() {
    app.bindKeyboard(Keyboard::W, [&]() {
        uniki.gora();
        });
    app.bindKeyboard(Keyboard::Up, [&]() {
        uniki.gora();
        });
    app.bindKeyboard(Keyboard::S, [&]() {
        uniki.dol();
        });
    app.bindKeyboard(Keyboard::Down, [&]() {
        uniki.dol();
        });
    app.bindKeyboard(Keyboard::BackSpace, [&]() {
        uniki.czysc();
        });
    app.bindKeyboard(Keyboard::Enter, [&]() {
        if (isMenuOpen)
        {
            if (menuselected == 0)
            {
                uniki.generujPlansze();
                isMenuOpen = false;
                uniki.czyczysta = false;
            }
            else if (menuselected == 1)app.W.close();
        }
        });

}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    HANDLE hout;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    bind();
    
    

    while (true)
    {
        int wybor{};
        system("cls");
        if (isMenuOpen == true)
        {
            SetConsoleTextAttribute(hout, FOREGROUND_GREEN);
            cout << "         ********\n";
            cout << "         * MENU *\n";
            cout << "         ********\n\n";
            cout << "1. Graj.\n";
            cout << "2. Instruckja i opis gry.\n";
            cout << "3. Ustaw poziom trduności.\n";
            cout << "4. Wyjdź.\n";
            cout << "Podaj liczbę: ";
            cin >> wybor;
            system("cls");
            if (wybor == 1)isMenuOpen = false;
            else if (wybor == 2)
            {
                cout << "STEROWANIE:\n\n";
                cout << "Ruch gracza w górę - 'W' lub strzalka w górę.\n";
                cout << "Ruch gracza w dół - 'S' lub strzalka w dół.\n";
                cout << "Wyjście z gry do menu - ESC lub krzyzyk w prawym gornym rogu.\n";
                cout << "Zakończenie gry bez wychodzenia do menu lub ponowna rozgrywka po porażce - BACKSPACE.\n\n";
                cout << "OPIS GRY:\n\n";
                cout << "Poruszasz sie kwadratem w pionie(góra/dół).\n";
                cout << "Twoim zadaniem jest omijać przeszkody.\n";
                cout << "Kiedy w którąś uderzysz - PRZEGRYWASZ.\n\n";
                cout << "ŻYCZĘ MIŁEJ ROZGRYWKI\n\n";
                cout << "Wpisz 1 jesli chcesz wrócić do menu: ";
                string x{};
                cin >> x;
                continue;
            }
            else if (wybor == 3)
            {
                cout << "WYBÓR POZIOMU TRUDNOŚCI:\n\n";
                cout << "Wybierasz liczbę całkowitą z przedziału 0-300(im większa liczba tym mniejsza trduność).\n";
                cout << "Pomoc przy wyborze:\n";
                cout << "0 - przegrasz od razu.\n";
                cout << "50 - ekstremalny.\n";
                cout << "100 - trudny.\n";
                cout << "150 - średni.\n";
                cout << "200 - łatwy.\n";
                cout << ">200 - możesz jeśli chcesz ale nie polecam.\n";
                cout << "Domyślny poziom trudności to 115.\n";
                cout << "Podaj poziom trudnosci: ";
                cin >> trudnosc;
            }
            else if (wybor == 4)break;
        }
        //system("cls");
        if (isMenuOpen == false)
        {

            app.createApp();
            uniki.generujPlansze();
            uniki.czyczysta = false;
            while (app.W.isOpen())
            {
                while (app.W.pollEvent(app.event))
                {
                    //if ((app.isClosedEvent()) && (isMenuOpen == false)) { isMenuOpen = true; break; }
                    //if ((app.isClosedEvent()) && (isMenuOpen == true)) { app.W.close(); break; }
                    if (app.isClosedEvent()) { isMenuOpen = true; app.W.close(); break; }
                    app.monitorKeyStatus();
                    //app.monitorMouseStatus();

                    app.doAfterPressedEvent();
                }
                if (isMenuOpen == true)break;
                //app.update();
                app.W.clear(Color::Black);
                //app.doAfterPressedEvent();


                uniki.postawPrzeszkody();
                uniki.ruchPrzeszkod();
                uniki.narysujPlansze();


                app.W.display();
            }
        }
    }

    return 0;
}