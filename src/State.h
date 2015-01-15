#ifndef STATE_H
#define STATE_H

struct Telegram;

template<class Object>
class State
{
public:
	virtual ~State() {}

	virtual void Enter(Object*) = 0;
	virtual void Execute(Object*) = 0;
	virtual void Exit(Object*) = 0;
	virtual void OnMessage(Object*, Telegram*) = 0;
};
#endif // !STATE_H
