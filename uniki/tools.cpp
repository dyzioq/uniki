#include <SFML/Graphics.hpp>
#include "tools.h"
using namespace std;
using namespace sf;

int los255() { return los(rng); }
int los8() { return los1(rng); }
int los4() { return los2(rng); }
Color randomColor() { return Color(los255(), 0, los255()); }
