#include "BlockManager.h"
#include "testApp.h"
#include "Ball.h"
#include "CustomMath.h"
#include "Functor.h"

BlockManager *BlockManager::instance = nullptr;

std::list<Ball*> BlockManager::theBalls;
std::list<Ball*>::const_iterator BlockManager::ballIterator;

BlockManager *BlockManager::Instance()
{
	if (instance == nullptr)
	{
		instance = new BlockManager;

		stateMachine = new StateMachine<BlockManager>(instance);
		stateMachine->SetCurrentState(CollisionWithBall::Instance());
		stateMachine->SetGlobalState(nullptr);
	}
	
	return instance;
}


void BlockManager::HandleCollision()
{
	nodeMethods.Search(CurrentBlock);
	
	for (ballIterator = theBalls.begin(); ballIterator != theBalls.end(); ballIterator++)
	{
		if (((*ballIterator)->position.y - (*ballIterator)->radius) <= (CurrentBlock->BlockNode.position.y + CurrentBlock->BlockNode.height) &&
			((*ballIterator)->position.x - (*ballIterator)->radius) <= (CurrentBlock->BlockNode.position.x + CurrentBlock->BlockNode.width) &&
			(*ballIterator)->position >= CurrentBlock->BlockNode.position &&
			(*ballIterator)->position >= CurrentBlock->BlockNode.position)
		{
			nodeMethods.RemoveAt(CurrentBlock, CurrentBlock->Index);

			(*ballIterator)->target = (*ballIterator)->position + RandomFloat(10, 5);
			(*ballIterator)->desiredSpeed = Normalize((*ballIterator)->position - (*ballIterator)->target) * (*ballIterator)->speed;
			(*ballIterator)->position = (*ballIterator)->position - ((*ballIterator)->desiredSpeed - (*ballIterator)->speed);

			(*ballIterator)->Bounce(*(*ballIterator), 1280, 768);

			Vector ballOneVec = Vector((*ballIterator)->position.x + 5, (*ballIterator)->position.y + 3);
			Vector ballTwoVec = Vector((*ballIterator)->position.x - 5, (*ballIterator)->position.y + 3);
			
			theBalls.push_back((*ballIterator)->Clone(ballOneVec));
			theBalls.push_back((*ballIterator)->Clone(ballTwoVec));
		}
	}
	

	if (CurrentBlock->Index == 0)
		return;
	else
		HandleCollision();
}

StateMachine<BlockManager> *BlockManager::stateMachine;

void BlockManager::Layout(Block blockPassed)
{
	spacerX = 5.0f;
	spacerY = 10.0f;

	int horizontalSize = 10;
	int verticalSize = 5;

	float initialXPosition = blockPassed.position.x;
	
	for (int i = 0; i < verticalSize; i++)
	{
		for (int j = 0; j < horizontalSize; j++)
		{
			nodeMethods.Insert(blockPassed);
			blockPassed.position.x += (blockPassed.width + spacerX);
				
			if (j == (horizontalSize - 1))
			{
				blockPassed.position.y += (blockPassed.height + spacerY);
				blockPassed.position.x = initialXPosition;
			}
		}
	}

	nodeMethods.SetCurrent(CurrentBlock);
}

void BlockManager::Update()
{
	stateMachine->Update();
}

void BlockManager::HandleMessage(Telegram *telegram)
{
	stateMachine->HandleMessage(telegram);
}

void BlockManager::Draw()
{
	CurrentBlock->BlockNode.Draw();

	nodeMethods.Search(CurrentBlock);
	
	if (CurrentBlock->Index == 0)
		return;
	else
		Draw();
}