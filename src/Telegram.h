#ifndef TELEGRAM_H
#define TELEGRAM_H

#include <vector>

class Object;

struct Telegram
{
public:
	Object* message;

	Telegram(Object *m);
};
#endif // !TELEGRAM_H
