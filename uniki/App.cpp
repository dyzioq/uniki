#include "App.h"
#include<iostream>

//funkcje dla myszki oraz niektóre rzeczy zakomentowa³em, poniewa¿ nie u¿y³em ich w obecnej wersji gry
//ale zamierzam w wolnych chwilach j¹ ulepszaæ i prawdopodobnie bêdê te rzeczy wykorzystywa³

App::App() {
	//// konfiguracja okna g³ównego
	//W.create(VideoMode(WIDTH, HEIGHT, 32), "Uniki");
	//W.setActive(true);
	//W.setKeyRepeatEnabled(false);
	//W.setFramerateLimit(60);
	//W.setVerticalSyncEnabled(false);
	//W.setPosition(Vector2i(0, 0));
	////Camera.reset(FloatRect(0, 0, WIDTH, HEIGHT));
	////Camera.setCenter(WIDTH / 2.0f, HEIGHT / 2.0f);
	////Camera.setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));
}
void App::createApp() {
	// konfiguracja okna g³ównego
	W.create(VideoMode(WIDTH, HEIGHT, 32), "Uniki");
	W.setActive(true);
	W.setKeyRepeatEnabled(false);
	W.setFramerateLimit(60);
	W.setVerticalSyncEnabled(false);
	W.setPosition(Vector2i(0, 0));
}

void App::update() {
	this->W.clear(Color::Black);
}

bool App::isClosedEvent() {
	return (event.type == Event::Closed || (App::isKeyPressedEvent(Keyboard::Escape)));
}

bool App::isKeyPressedEvent(int key) {
	return (event.type == Event::KeyPressed && event.key.code == key);
}

bool App::isKeyReleasedEvent(int key) {
	return (event.type == Event::KeyReleased && event.key.code == key);
}
void App::monitorKeyStatus() {
	if (event.type == Event::KeyPressed) { keyboardStatus[event.key.code] = true; }
	if (event.type == Event::KeyReleased) { keyboardStatus[event.key.code] = false; }
}
//void App::monitorMouseStatus() {
//	if (event.type == Event::MouseButtonPressed) { mouseStatus[event.mouseButton.button] = true; }
//	if (event.type == Event::MouseButtonReleased) { mouseStatus[event.mouseButton.button] = false; }
//}

bool App::isKeyStillPressed(int key) {
	return keyboardStatus[key];
}

//bool App::isStillMousePressed(int key) {
//	return mouseStatus[key];
//}

//bool App::isMousePressedEvent(int button) {
//	return (event.type == Event::MouseButtonPressed and event.mouseButton.button == button);
//}
//bool App::isMouseReleasedEvent(int button) {
//	return (event.type == Event::MouseButtonReleased and event.mouseButton.button == button);
//}

void App::doAfterPressedEvent() {
	//for (auto& [button, f] : mousePressedFunctions) {
	//	if (isMousePressedEvent(button)) {
	//		f();
	//	}
	//}
	for (auto& [button, f] : keyboardPressedFunctions) {
		if (isKeyPressedEvent(button)) {
			f();
		}
	}
}

//void App::bindMouse(int button, function<void(void)> f) {
//	mousePressedFunctions[button] = f;
//}
void App::bindKeyboard(int button, function<void(void)> f) {
	keyboardPressedFunctions[button] = f;
}

//Vector2f App::getMousePosition() {
//	return Vector2f(Mouse::getPosition(W));
//}




