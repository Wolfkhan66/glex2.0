#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>

#include <GL/gl.h>

class GameAsset {
 public:
	enum AType {CUBE, STAR};
  virtual void Draw(GLuint) = 0;
	virtual AType GetAType() = 0;

	protected:
	AType aType;

};

#endif
