#pragma once

#include <string>

//Utility class to load, compile and attach a vertex and a fragment shader to a program
class ShaderUtil
{
private:
	unsigned int mProgramId;
	unsigned int GetCompiledShader(unsigned int shader_type, const std::string& shader_source);

public:
	ShaderUtil() {}
	~ShaderUtil() {}

	//Load a vertex and a fragment shader from file
	bool Load(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);

	// Use the program
	void Use();

	// Delete the Program
	void Delete();
};