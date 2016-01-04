#ifndef STARASSET_H
#define STARASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"


using namespace std;

class StarAsset : public GameAsset {
 public:
  StarAsset(GLfloat positionX,GLfloat positionY,GLfloat positionZ);
  ~StarAsset();
  virtual void Draw(GLuint);
  virtual AType GetAType();


 private:

  GLuint element_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token;
  void checkError(string file, int line);
};

#endif // STARASSET_H
