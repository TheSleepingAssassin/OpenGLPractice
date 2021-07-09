#include "defines.h"
#include <iostream>

class Shader
{
public:
	Shader();
	Shader(const char *vSS, const char *fSS);
	void Use() const;
	void Disuse() const;
	void setMat4(glm::mat4 mat, const std::string &matName);
	void setVec4(float v1, float v2, float v3, float v4, const std::string &locName);
	~Shader();

private:
	unsigned int ID;
	const char *dVSS;
	const char *dFSS;
};
