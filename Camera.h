#include "defines.h"

class Camera
{
public:
	Camera(glm::vec3 mPos);
	void uView();
	void MovePos(glm::vec3 tPos);
	void SetPos(glm::vec3 tPos);
	void SetFront(glm::vec3 tFront);
	glm::mat4 getView() const;
	~Camera();

private:
	glm::vec3 mPos;
	glm::vec3 mFront;
	glm::vec3 mDir = glm::normalize(mPos * mFront);
	glm::vec3 mUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 mRight = glm::normalize(glm::cross(mUp, mDir));

	glm::mat4 mView = glm::mat4(1.0f);
};
