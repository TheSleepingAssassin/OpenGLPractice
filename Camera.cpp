#include "Camera.h"

Camera::Camera(glm::vec3 tPos)
{
	mPos = tPos;
}

void Camera::uView()
{
	mView = glm::mat4(1.0f);
	mView = glm::translate(mView, glm::vec3(0.0f, 0.0f, -10.0f));
}

void Camera::MovePos(glm::vec3 tPos)
{
	mPos += tPos;
}

void Camera::SetPos(glm::vec3 tPos)
{
	mPos = tPos;
}

void Camera::SetFront(glm::vec3 tFront)
{
	mFront = tFront;
}

glm::mat4 Camera::getView() const
{
	return mView;
}

Camera::~Camera()
{
	delete &mPos, &mFront, &mDir, &mUp, &mRight;
}
