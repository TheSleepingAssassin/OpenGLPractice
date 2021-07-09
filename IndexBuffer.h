#include "defines.h"

class IndexBuffer
{
public:
	IndexBuffer();
	IndexBuffer(int count, const void *data);
	void Bind() const;
	void Unbind() const;
	int GetCount() const;
	~IndexBuffer();

private:
	unsigned int ID;
	int mCount;
};
