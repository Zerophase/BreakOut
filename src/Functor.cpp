#include "Functor.h"
#include "Object.h"
#include "Telegram.h"

void Functor::Init(Object &object, Telegram &telegram)
{
	addTo(object, telegram);
}

void Functor::addTo(Object &object, Telegram &telegram)
{
	bankOfObjects.push_back(&object);
	bankOfTelegrams.push_back(telegram);
}

vector<Object*> Functor::bankOfObjects;
vector<Telegram> Functor::bankOfTelegrams;

void Functor::Send()
{
	for (int i = 0; i < bankOfObjects.size(); i++)
	{
		for (int j = 0; j < bankOfTelegrams.size(); j++)
		{
			(bankOfObjects.at(i))->HandleMessage(&bankOfTelegrams.at(j));
		}
	}
}