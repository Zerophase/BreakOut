#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include "Telegram.h"

template<class Object>
class StateMachine
{
private:
	Object *owner;
	State<Object> *currentState;
	State<Object> *previousState;
	State<Object> *globalState;
public:
	StateMachine(Object *owner) : owner(owner),
		currentState(NULL), previousState(NULL), globalState(NULL)
	{}
	virtual ~StateMachine() {}

	void SetCurrentState(State<Object> *s) { currentState = s; }
	void SetPreviousState(State<Object> *s) { previousState = s; }
	void SetGlobalState(State<Object> *s) {globalState = s; }

	State<Object> *CurrentState() const { return currentState; }
	State<Object> *PreviousSate() const { return previousState; }
	State<Object> *GlobalState() const { return globalState; }

	void Update() const
	{
		if(globalState)
			globalState->Execute(owner);

		if(currentState)
			currentState->Execute(owner);
	}

	void HandleMessage(Telegram *telegram)
	{
		currentState->OnMessage(owner, telegram);

		if (globalState != nullptr)
			globalState->OnMessage(owner, telegram);
	}

	//TODO add in messaging
	void ChangeState(State<Object> *newState)
	{
		previousState = currentState;
		currentState->Exit(owner);

		currentState = newState;
		currentState->Enter(owner);
	}
};
#endif // !STATEMACHINE_H
