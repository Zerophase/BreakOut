#ifndef BLOCK_H
#define BLOCK_H
#include "CollidableRect.h"
#include "Telegram.h"

//Blocks to be rendered to screen.
class Block : public CollidableRect
{
	public:
		Vector blockVector;
		Block();

		virtual void Update();
		virtual void HandleMessage(Telegram *telegram);

		void Draw();

		Block(Vector blockVector, float width, float height);
		~Block();
		void Destroy();
};

#endif