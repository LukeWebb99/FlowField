#include "Utility.h"
#include <iostream>

const int WindowWidth()
{
	return 1200;
}

const int WindowHeight()
{
	return 600;
}

const int scl()
{
	return 30;
}

const int cols()
{
	return floor(WindowWidth() / scl());
}

const int rows()
{
	return floor(WindowHeight() / scl());
}
