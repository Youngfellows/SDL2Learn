#include <iostream>
#include "SuperComputer.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Use SDL Thread Mutex" << endl;
	Dungeon::SuperComputer *computer = new Dungeon::SuperComputer();
	computer->Start();//开启子线程
	computer->Wait();//等待子线程结束
	delete computer;
	return 0;
}