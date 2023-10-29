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

//그리기 콜백함수
GLvoid Display(GLvoid);
//크기 변경시 다시 그리기 콜백 함수
GLvoid Reshape(int, int);

//텍스트 문자열 저장 함수
char* filetobuf(const char* file);
//버텍스 셰이더 생성 함수
void MakeVertexShader(void);
//프래그먼트 셰이더 생성 함수
void MakeFragmentShader(void);
//셰이더 프로그램 생성 함수
GLuint MakeShaderProgram(void);
//버퍼 초기화 함수
void InitBuffer(void);
//좌표축 버퍼 초기화 함수
void InitCoordBuffer(void);
//죄표축 그리기 함수
void drawCoord(void);