#pragma once

#include "ofMain.h"
#include "Paddle.h"
#include "Vector2D.h"
#include "BlockManager.h"
#include "Ball.h"
#include <list>

//A testApp with references to all of the basic objects needed for break out.
class testApp : public ofBaseApp{

	public:
		Paddle *paddle;
		Block block;
		Ball *ball;

		std::list<Ball*> balls;
		std::list<Ball*>::const_iterator ballIterator;
		std::list<Ball*>::const_iterator checkForNeighbors;
		testApp(){}

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	private:
		int searchDepth;
};
