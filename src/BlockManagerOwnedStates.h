#ifndef BLOCKMANAGER_OWNEDSTATES_H
#define BLOCKMANAGER_OWNEDSTATES_H

#include "State.h"
#include "Telegram.h"
#include "Ball.h"

class BlockManager;

class CollisionWithBall : public State<BlockManager>
{
private:
	CollisionWithBall() {}

	CollisionWithBall(const CollisionWithBall&);
	CollisionWithBall &operator=(const CollisionWithBall&);

	

public:
	static CollisionWithBall *Instance();

	virtual void Enter(BlockManager *blockManager);
	virtual void Execute(BlockManager *blockManager);
	virtual void Exit(BlockManager *blockManager);
	virtual void OnMessage(BlockManager *blockManager, Telegram *telegram);


};
#endif // !BLOCKMANAGER_OWNEDSTATES_H
