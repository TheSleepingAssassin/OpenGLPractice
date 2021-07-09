#include "defines.h"

class VertexBuffer
{
public:
	VertexBuffer();
	VertexBuffer(unsigned int size, const void *data);
	void Bind() const;
	void Unbind() const;
	~VertexBuffer();

private:
	unsigned int ID;
};
