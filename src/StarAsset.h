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
  StarAsset(glm::vec3);
  ~StarAsset();
  virtual void Draw(GLuint);
glm::vec3 GetVec3();

 private:
glm::vec3 position;
  GLuint element_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token;
  void checkError(string file, int line);
};

#endif // STARASSET_H
