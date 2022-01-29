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

//funkcje dla myszki oraz niektóre rzeczy zakomentowa³em, poniewa¿ nie u¿y³em ich w obecnej wersji gry
//ale zamierzam w wolnych chwilach j¹ ulepszaæ i prawdopodobnie bêdê te rzeczy wykorzystywa³

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

	// czy wydarzenie to zamkniêcie okna g³ównego W za pomoc¹ ESC lub x ?
	bool isClosedEvent();

				//-----------komendy dla klawiatury----------//
	
	// test wydarzenia: czy ktoœ w³aœnie wcisn¹³ klawisz o kodzie key ?
	bool isKeyPressedEvent(int key);
	// test wydarzenia: czy ktoœ w³aœnie puœci³ klawisz o kodzie key ?
	bool isKeyReleasedEvent(int key);
	// zapamiêtaj ostatnie wydarzenie dla klawisza: true (wciœniêty) false (puszczony). Pamiêæ w zmiennej keyboardStatus
	void monitorKeyStatus();
	// czy przycisk key jest wciœniêty? (nie by³o puszczenia, a ostatnie wydarzenie to wciœniêcie)
	bool isKeyStillPressed(int key);
	// przypisz pod przycisk klawiatury jak¹œ labmdê void(void) (Pressed)
	void bindKeyboard(int button, function<void(void)> f);

	//			//--------komendy dla myszki-------//

	//// czy wydarzenie to wciœniêcie przyciski myszki (button) ?
	//bool isMousePressedEvent(int button);
	//// czy wydarzenie to puszczenie przycisku myszki (button) ?
	//bool isMouseReleasedEvent(int button);
	//// zapamiêtaj ostatnie wydarzenie dla przycisków myszki: true/false (wciœniêcie/puszczenie). Pamiêæ w zmiennej mouseStatus
	//void monitorMouseStatus();
	////czy przyciski myszy s¹ wciœniête? (trwa wciœniêcie)
	//bool isStillMousePressed(int key);
	//// przypisz pod przycisk myszki jak¹œ lambdê void(void) (Pressed)
	//void bindMouse(int button, function<void(void)> f);
	//// zbierz pozycje myszki
	//Vector2f getMousePosition();

	// kilka rzeczy do tworzenia klatki obrazu zwi¹zane z oknem, zebrane do kupki,
	// np. czyszczenie obrazu, ustawienie kamery itp. W przysz³oœci mo¿na tam bêdzie coœ dodaæ.
	void update();
	void createApp();
	// Wykonaj akcje przypisane wciœniêtym przyciskom klawiatury i myszy
	void doAfterPressedEvent();



};

inline App app;

#endif // !APP_H_INCLUDED

