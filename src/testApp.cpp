#include "testApp.h"
#include "Functor.h"
#include "Telegram.h"

float xC = 500;
float yC = 500;
float radius = 200;

float xR = 600;
float yR = 600;
float width = 100;
float height = 50;


//--------------------------------------------------------------
void testApp::setup()
{
	//Sets the title and dimensions of the window.
	ofSetWindowTitle("BreakOut");
	ofSetWindowShape(1280, 768);
	
	//Sets up a ball and paddle for the of
	paddle = new Paddle(Vector(600, 700), 150, 25);
	ball = new Ball(Vector(paddle->position.x + 50, paddle->position.y - 20), 20); 
	
	balls.push_back(ball);

	for (ballIterator = balls.begin(); ballIterator != balls.end(); ballIterator++)
	{
		Functor::Init(*(*ballIterator), Telegram(paddle));
	}
	
	Functor::Init(*paddle, Telegram(ball));
	Functor::Init(*BlockManagement, Telegram(BlockManagement));

	//Creates a block for of, and lays multiples out with the manager
	block = Block(Vector(117.5f, 100), width, height);
	BlockManagement->Layout(block);
}

//--------------------------------------------------------------
void testApp::update()
{
	for (ballIterator = balls.begin();  ballIterator != balls.end(); ballIterator++)
	{
		(*ballIterator)->Update();

		for (checkForNeighbors = balls.begin();  checkForNeighbors != balls.end(); 
			checkForNeighbors++)
		{
			Vector distanceBetweeenVec = ((*ballIterator)->position - (*checkForNeighbors)->position);
			Vector localCoords = (*ballIterator)->position - (*ballIterator)->position;
			Vector neighborCoords = ((*checkForNeighbors)->position - (*ballIterator)->position);
			if ((*ballIterator)->GetID() != (*checkForNeighbors)->GetID()
				&& (localCoords < distanceBetweeenVec
				|| localCoords > distanceBetweeenVec)
				&& (distanceBetweeenVec < neighborCoords
				|| distanceBetweeenVec > neighborCoords))
			{
				Vector ToAgent = (*ballIterator)->position - (*checkForNeighbors)->position;
				(*ballIterator)->SetSteeringForce(ToAgent);
			}
			else if((*ballIterator)->GetSteeringForce() != 0.0)
 				(*ballIterator)->SetSteeringForce(Vector(0, 0)); 
		}
	}
	//ball->Update();
	paddle->Update();
	BlockManagement->Update();

	if (balls.size() < BlockManagement->theBalls.size())
		balls = BlockManagement->BallsToUpdate();
}

//--------------------------------------------------------------
void testApp::draw()
{
	//sets the color of the circle and rect, and draws them to screen in their current location.
	
	paddle->Draw();

	for (ballIterator = balls.begin();  ballIterator != balls.end(); ballIterator++)
	{
		(*ballIterator)->Draw();
	}

	//ball->Draw();

	if (ball->Flash == true)
	{
		ofSetColor(ofRandom(0, 250), ofRandom(0, 250),ofRandom(0, 250), ofRandom(0, 250));
		ofRect(0, 0, 1280, 768);
	}
	
	BlockManagement->Draw();
}

#pragma region "Default Inputs" 
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
#pragma endregion