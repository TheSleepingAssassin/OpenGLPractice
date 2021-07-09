#include "GameObject.h"

GameObject::GameObject(glm::vec3 tPos, glm::vec3 tRot, glm::vec3 tScale)
{
	mPos = tPos;
	mRot = tRot;
	mScale = tScale;

	// model = glm::mat4(1.0f);
	// model = glm::translate(model, mPos);
	// model = glm::rotate(model, mRot.x, glm::vec3(1.0f, 0.0f, 0.0f));
	// model = glm::rotate(model, mRot.y, glm::vec3(0.0f, 1.0f, 0.0f));
	// model = glm::rotate(model, mRot.z, glm::vec3(0.0f, 0.0f, 1.0f));
	// model = glm::scale(model, mScale);

	// shader = Shader();
	this->uModel();
}

void GameObject::Set3DViewProj(glm::mat4 proj, glm::mat4 view)
{
	shader.setMat4(proj, "proj");
	shader.setMat4(view, "view");
}

void GameObject::SetPos(glm::vec3 tPos)
{
	mPos = tPos;

	this->uModel();
}

void GameObject::SetRot(glm::vec3 tRot)
{
	mRot = tRot;

	this->uModel();
}

void GameObject::SetScale(glm::vec3 tScale)
{
	mScale = tScale;

	this->uModel();
}

void GameObject::uModel()
{
	model = glm::mat4(1.0f);
	model = glm::translate(model, mPos);
	model = glm::rotate(model, mRot.x, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, mRot.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, mRot.z, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, mScale);
	shader.setMat4(model, "model");
}

GameObject::~GameObject()
{
	delete &mPos, &mRot, &mScale, &vertices, &indices;
}
