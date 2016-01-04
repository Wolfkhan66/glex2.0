#ifndef STARASSET_H
#define STARASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class StarAsset : public GameAsset {
 public:
  StarAsset();
  ~StarAsset();
  virtual void Draw(GLuint);

 private:
  GLuint element_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token;
};

#endif // STARASSET_H
