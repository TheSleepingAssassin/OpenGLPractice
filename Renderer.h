#include "defines.h"
#include <iostream>
#include <vector>

class Renderer
{
public:
	void Draw();

private:
	std::vector<float> *mVertices;
	std::vector<unsigned int> *mIndices;
};
