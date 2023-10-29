#include "header.h"

//셰이터 프로그램 객체
extern GLuint shaderProgramID;

//좌표축 VAO, VBO
GLuint VAO_coord;
GLuint VBO_coord_position;
GLuint VBO_coord_color;

//정육면체 VAO, VBO
GLuint VAO;

glm::mat4 model;

//좌표축
const GLfloat coord[] = {
	-1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, 1.0f
};

const float coordColor[] = {
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f
};

//그리기 콜백 함수
GLvoid Display(GLvoid)
{
	//초기 색깔 지정
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//설정된 색으로 전체 칠하기
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//좌표축 그리기
	drawCoord();
	
	//화면에 출력하기
	glutSwapBuffers();
}

//크기 변경시 다시 그리기 콜백 함수
GLvoid Reshape(int w, int h)
{
	//openGL 뷰포트 설정
	glViewport(0, 0, w, h);
}

//버퍼 초기화 함수
void InitBuffer(void)
{
	InitCoordBuffer();
}

//좌표축 버퍼 초기화 함수
void InitCoordBuffer(void)
{
	//VAO 객체 생성 및 바인딩
	glGenVertexArrays(1, &VAO_coord);
	glBindVertexArray(VAO_coord);

	//버텍스 위치 VBO 객체 생성
	glGenBuffers(1, &VBO_coord_position);

	//버텍스 위치 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_coord_position);
	//버텍스 위치 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(coord), coord, GL_STATIC_DRAW);
	//버텍스 위치 데이터 배열 정의
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 위치 배열 사용
	glEnableVertexAttribArray(0);

	//버텍스 색상 VBO 객체 생성
	glGenBuffers(1, &VBO_coord_color);

	//버텍스 색상 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_coord_color);
	//버텍스 색상 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(coordColor), coordColor, GL_STATIC_DRAW);
	//버텍스 색상 데이터 배열 정의
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 색상 배열 사용
	glEnableVertexAttribArray(1);
}

//죄표축 그리기 함수
void drawCoord(void)
{
	//사용할 셰이더 프로그램 지정
	glUseProgram(shaderProgramID);

	model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	//사용할 VAO 객체 바인딩
	glBindVertexArray(VAO_coord);
	glDrawArrays(GL_LINES, 0, 6);
}