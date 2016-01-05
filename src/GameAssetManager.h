#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>

#include <GL/gl.h>
#include <glm/ext.hpp>

#include "common.h"
#include "GameAsset.h"
#include "Camera.h"

/**
 * GameAssetManager is a container for GameAssets.  It also provides utility
 * functions to to create a simple OpenGL program that can be used to draw a
 * simple GameAsset.
 */
class GameAssetManager {
 public:
  explicit GameAssetManager(ApplicationMode); // constructor
  virtual ~GameAssetManager();
  GameAssetManager(GameAssetManager const&); // copy constructor
  GameAssetManager(GameAssetManager const&&); // move constructor
  void operator=(GameAssetManager const&); // assignment
  void AddAsset(std::shared_ptr<GameAsset>);
  void Draw();
  void UpdateCameraPosition(Input, int mouseX, int mouseY);

 private:
  GLuint CreateGLProgram(std::string &, std::string &);
  GLuint CreateGLESShader(GLenum, std::string &);
  // As this is private and we're writing to the GPU, we will use raw pointers.
  std::pair<GLchar *, GLint>  ReadShader(std::string &);
	 std::vector<std::shared_ptr<GameAsset>> draw_list;
  Camera camera;
  GLuint program_token;


// variables to communicate with the shader(Camera)

  GLuint translateMatrix_link;
  GLuint viewMatrix_link;
  GLuint projectionMatrix_link;

  glm::mat4 projectionMatrix;
  glm::mat4 translateMatrix; 
  glm::mat4 viewMatrix;	

   GLuint cameraPositionX;
   GLuint cameraPositionZ;


};

#endif // GAMEASSETMANAGER_H
