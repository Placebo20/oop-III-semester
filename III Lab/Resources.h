//
// Created by dimag on 01.12.2020.
//
#ifndef III_LAB_RESOURCES_H
#define III_LAB_RESOURCES_H
#include <SFML/Graphics.hpp>

class Resources
{
public:
	sf::Font font;
public:
	static Resources& Instance()
	{
		static Resources s;
		return s;
	}
	void Load();
private:
	Resources();
	~Resources();
	Resources(Resources const&) = delete;
	Resources& operator= (Resources const&) = delete;
};


#endif //III_LAB_RESOURCES_H
