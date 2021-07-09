#include "defines.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

#include <iostream>
#include <vector>

class GameObject
{
public:
	GameObject(glm::vec3, glm::vec3, glm::vec3);
	void Set3DViewProj(glm::mat4, glm::mat4);
	void SetPos(glm::vec3);
	void SetRot(glm::vec3);
	void SetScale(glm::vec3);
	void uModel();
	~GameObject();

protected:
	glm::mat4 model;
	glm::vec3 mPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 mRot = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 mScale = glm::vec3(1.0f, 1.0f, 1.0f);

	std::vector<float> *vertices;
	std::vector<unsigned int> *indices;

	Shader shader = Shader();
};
