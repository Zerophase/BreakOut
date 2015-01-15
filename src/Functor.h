#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <vector>

class Object;
struct Telegram;

struct Functor
{
public:
	static void Init(Object &object, Telegram &telegram);
	static void Send();

private:
	static std::vector<Object*> bankOfObjects;
	static std::vector<Telegram> bankOfTelegrams;

	static void addTo(Object &object, Telegram &telegram);
	
};
#endif // !FUNCTOR_H
