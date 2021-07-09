#include "IndexBuffer.h"

IndexBuffer::IndexBuffer() : mCount(3)
{
	unsigned int indices[] =
			{0, 1, 2};

	glCreateBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

IndexBuffer::IndexBuffer(int count, const void *data) : mCount(count)
{
	glCreateBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int IndexBuffer::GetCount() const
{
	return mCount;
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &ID);
}
