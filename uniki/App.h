#pragma once
#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
#include<SFML/Graphics.hpp>
#include<map>
#include<functional>
#include<iostream>
#include<cstdlib>
#include"config.h"
#include"tools.h"

using namespace std;
using namespace sf;

//funkcje dla myszki oraz niekt�re rzeczy zakomentowa�em, poniewa� nie u�y�em ich w obecnej wersji gry
//ale zamierzam w wolnych chwilach j� ulepsza� i prawdopodobnie b�d� te rzeczy wykorzystywa�

class App {
private:
public:
	int WIDTH = ::WIDTH;
	int HEIGHT = ::HEIGHT;
	//okno glowne
	RenderWindow W;
	//reprezentant zdarzen w oknie .okno
	Event event{};
	//zegar czasu
	//Clock clock;
	//kamera dodatkowa( domyslna to W.getDefaultView() )
	//View Camera;
	//zapamietuje sobie ostatnie wydarzenie: kod znaku z klawiatury -> status wcisniety/puszczony
	// (true - wcisniety, false - puszczony)
	map<int, bool> keyboardStatus{};
	//zapamietuje ostatnie wydarzenie: przycisk w myszce -> true: wcisniety, false: puszczony
	//map<int, bool> mouseStatus{};
	//mapa z lambdami przypisanymi do wciskanych przyciskow klawiatury
	map<int, function<void(void)>> keyboardPressedFunctions{};
	//mapa z lambdami przypisanymi do przyciskow myszy
	//map<int, function<void(void)>> mousePressedFunctions{};

	App();

	// czy wydarzenie to zamkni�cie okna g��wnego W za pomoc� ESC lub x ?
	bool isClosedEvent();

				//-----------komendy dla klawiatury----------//
	
	// test wydarzenia: czy kto� w�a�nie wcisn�� klawisz o kodzie key ?
	bool isKeyPressedEvent(int key);
	// test wydarzenia: czy kto� w�a�nie pu�ci� klawisz o kodzie key ?
	bool isKeyReleasedEvent(int key);
	// zapami�taj ostatnie wydarzenie dla klawisza: true (wci�ni�ty) false (puszczony). Pami�� w zmiennej keyboardStatus
	void monitorKeyStatus();
	// czy przycisk key jest wci�ni�ty? (nie by�o puszczenia, a ostatnie wydarzenie to wci�ni�cie)
	bool isKeyStillPressed(int key);
	// przypisz pod przycisk klawiatury jak�� labmd� void(void) (Pressed)
	void bindKeyboard(int button, function<void(void)> f);

	//			//--------komendy dla myszki-------//

	//// czy wydarzenie to wci�ni�cie przyciski myszki (button) ?
	//bool isMousePressedEvent(int button);
	//// czy wydarzenie to puszczenie przycisku myszki (button) ?
	//bool isMouseReleasedEvent(int button);
	//// zapami�taj ostatnie wydarzenie dla przycisk�w myszki: true/false (wci�ni�cie/puszczenie). Pami�� w zmiennej mouseStatus
	//void monitorMouseStatus();
	////czy przyciski myszy s� wci�ni�te? (trwa wci�ni�cie)
	//bool isStillMousePressed(int key);
	//// przypisz pod przycisk myszki jak�� lambd� void(void) (Pressed)
	//void bindMouse(int button, function<void(void)> f);
	//// zbierz pozycje myszki
	//Vector2f getMousePosition();

	// kilka rzeczy do tworzenia klatki obrazu zwi�zane z oknem, zebrane do kupki,
	// np. czyszczenie obrazu, ustawienie kamery itp. W przysz�o�ci mo�na tam b�dzie co� doda�.
	void update();
	void createApp();
	// Wykonaj akcje przypisane wci�ni�tym przyciskom klawiatury i myszy
	void doAfterPressedEvent();



};

inline App app;

#endif // !APP_H_INCLUDED

