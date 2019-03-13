#ifndef GROUND_H
#define GROUND_H

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

#include <stdio.h>
#include <string.h>
#include <Cube.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class Ground
{
private:
	// Cube Elements
	GLfloat vertex[ARRAY_SIZE(vertices)];
	GLfloat color[ARRAY_SIZE(colors)];
	GLfloat uv[ARRAY_SIZE(uvs)];
	GLfloat index[ARRAY_SIZE(indices)];
	vec3 position;
public:
	Ground();
	~Ground();

	virtual vec3 getPosition();
	virtual void setPosition(vec3 position);

	// Returns the first element of the array
	virtual GLfloat* getVertex();
	// 3 Vertices
	virtual int getVertexCount();

	// Returns the first element of the array
	virtual GLfloat* getColor();
	// 3 Colors RGB
	virtual int getColorCount();

	// Returns the first element of the array
	virtual GLfloat* getUV();
	// 3 Colors RGB
	virtual int getUVCount();

	// Returns the first element of the array
	virtual GLfloat* getIndex();
	// 3 Colors RGB
	virtual int getIndexCount();
};

#endif // !GROUND_H
