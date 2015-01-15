#include "Block.h"
#include "testApp.h"

//sets up default block widths and heights
Block::Block()
{
	this->height = 0;
	this->width = 0;
}

//Gives the block explicit heights and widths.
Block::Block(Vector blockVector, float width, float height)
	:CollidableRect(blockVector, width, height)
{
	this->height = height;
	this->width = width;
}

Block::~Block()
{

}

void Block::Update()
{

}

void Block::HandleMessage(Telegram *telegram)
{

}

void Block::Draw()
{
	ofSetColor(200, 55, 220);
	ofRect(position.x, position.y, width, height);
}

void Block::Destroy()
{
	this->~Block();
}