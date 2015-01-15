#ifndef BLOCKMANAGER_H
#define	BLOCKMANAGER_H
#include "Block.h"
#include "Node.h"
#include "StateMachine.h"
#include "Object.h"
#include "Telegram.h"
#include "BlockManagerOwnedStates.h"
#include <list>

class Ball;

#define BlockManagement BlockManager::Instance()

//manages the blocks
class BlockManager : public Object
{
	public:
		void Layout(Block blockPassed);
		Block *Blocks;
		Node *CurrentBlock;
		Node *HeadBlock;
		Node *LastBlock;
		Block BlockArray[50];
		int Blockerator;

		static BlockManager *Instance();

		static std::list<Ball*> theBalls;
		static std::list<Ball*>::const_iterator ballIterator;

		static std::list<Ball*> BallsToUpdate() { return theBalls; }

		StateMachine<BlockManager> *GetFSM() const { return stateMachine; }

		void HandleCollision();
		NodeMethods nodeMethodsToRemove;
		Node *blockSearchedToRemove;

		virtual void Update();
		virtual void HandleMessage(Telegram *telegram);
		virtual void Draw();

	private:
		BlockManager() {}
		static BlockManager *instance;

		NodeMethods nodeMethods;
		Block block;
		bool check;
		float spacerX;
		float spacerY;

		static StateMachine<BlockManager> *stateMachine;
};
	
#endif