#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>

//�׸��� �ݹ��Լ�
GLvoid Display(GLvoid);
//ũ�� ����� �ٽ� �׸��� �ݹ� �Լ�
GLvoid Reshape(int, int);

//�ؽ�Ʈ ���ڿ� ���� �Լ�
char* filetobuf(const char* file);
//���ؽ� ���̴� ���� �Լ�
void MakeVertexShader(void);
//�����׸�Ʈ ���̴� ���� �Լ�
void MakeFragmentShader(void);
//���̴� ���α׷� ���� �Լ�
GLuint MakeShaderProgram(void);
//���� �ʱ�ȭ �Լ�
void InitBuffer(void);
//��ǥ�� ���� �ʱ�ȭ �Լ�
void InitCoordBuffer(void);
//��ǥ�� �׸��� �Լ�
void drawCoord(void);