#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>



template<typename T>
class GameFactoryPattern
{
	/*
	Basically a Factory consists of an interface class which is common
	to all of the implementation classes that the factory will create. Then
	you have the factory class which is usually a singleton class that spawns
	instances of these implementation classes.
	*/
public:
	static std::unique_ptr<T> create(const char&, sf::Vector2f&); 
	static bool registerit(const char & obj, std::unique_ptr<T>(*type)(sf::Vector2f &)){
		getMap().emplace(obj, type);
		return true;
}
private:
	static std::map<char, std::unique_ptr<T>(*)(sf::Vector2f&)>& getMap() {
		static myMap m_map;	return m_map;;}
	GameFactoryPattern() {};
	~GameFactoryPattern() {};
	using myMap = std::map<char, std::unique_ptr<T>(*)(sf::Vector2f&)>;
};

/*
Now comes the Factory class. This is a singleton pattern implementation--meaning
only one instance of the factory can ever be instantiated, no more, no less.
*/
template<typename T>
inline std::unique_ptr<T> GameFactoryPattern<T>::create(const char& obj, sf::Vector2f &position)
{
	auto it = getMap().find(obj);
	if (it == getMap().end()) { return nullptr; }
	return it->second(position);
}