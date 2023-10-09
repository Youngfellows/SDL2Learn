#include<iostream>
#include "Cursor.h"

using namespace std;
using namespace Game;

int main(int argc, char *argv[])
{
	cout << "Hello Visual Studio" << endl;

	Cursor *cursor = new Cursor();
	DisplayObject *displayObject = cursor->Cursor_Create(0, 0, 10, 20);
	Renderer *renderer = new Renderer();
	renderer->color = 10086;
	Event *event = new Event();
	Motion motion;
	motion.x = 33;
	motion.y = 44;
	event->motion = motion;
	displayObject->DisplayObject_Draw(renderer);
	displayObject->DisplayObject_OnMouseMove(event);

	return 0;
}