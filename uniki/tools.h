#pragma once
#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include<SFML/Graphics.hpp>
#include<random>
#include<chrono>
#include"config.h"
using namespace std;
using namespace sf;

inline static default_random_engine rng(
	static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count())
);
inline static uniform_int_distribution<int> los(0, 255);
inline static uniform_int_distribution<int> los1(0, 8);
inline static uniform_int_distribution<int> los2(0, 3);


/** los: 0-255 */
int los255();
//los: 0-8
int los8();
//los: 0-6
int los4();
/** los: Color() */
Color randomColor();



#endif // !TOOLS_HPP_INCLUDED

