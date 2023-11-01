#include "header.h"

//������ ���α׷� ��ü
extern GLuint shaderProgramID;

//��ǥ�� VAO, VBO
GLuint VAO_coord;
GLuint VBO_coord_position;
GLuint VBO_coord_color;

//������ü VAO, VBO
GLuint VAO;

glm::mat4 model;

//��ǥ��
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

// 3���� ��ǥ�� ���簢�� �׸��� ��; 11.01
const GLfloat rect[] = {
	0.5f, 0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f
};

//�׸��� �ݹ� �Լ�
GLvoid Display(GLvoid)
{
	//�ʱ� ���� ����
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//������ ������ ��ü ĥ�ϱ�
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//��ǥ�� �׸���
	drawCoord();
	
	//ȭ�鿡 ����ϱ�
	glutSwapBuffers();
}

//ũ�� ����� �ٽ� �׸��� �ݹ� �Լ�
GLvoid Reshape(int w, int h)
{
	//openGL ����Ʈ ����
	glViewport(0, 0, w, h);
}

//���� �ʱ�ȭ �Լ�
void InitBuffer(void)
{
	InitCoordBuffer();
}

//��ǥ�� ���� �ʱ�ȭ �Լ�
void InitCoordBuffer(void)
{
	//VAO ��ü ���� �� ���ε�
	glGenVertexArrays(1, &VAO_coord);
	glBindVertexArray(VAO_coord);

	//���ؽ� ��ġ VBO ��ü ����
	glGenBuffers(1, &VBO_coord_position);

	//���ؽ� ��ġ VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_coord_position);
	//���ؽ� ��ġ ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(coord), coord, GL_STATIC_DRAW);
	//���ؽ� ��ġ ������ �迭 ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ��ġ �迭 ���
	glEnableVertexAttribArray(0);

	//���ؽ� ���� VBO ��ü ����
	glGenBuffers(1, &VBO_coord_color);

	//���ؽ� ���� VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_coord_color);
	//���ؽ� ���� ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(coordColor), coordColor, GL_STATIC_DRAW);
	//���ؽ� ���� ������ �迭 ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ���� �迭 ���
	glEnableVertexAttribArray(1);
}

//��ǥ�� �׸��� �Լ�
void drawCoord(void)
{
	//����� ���̴� ���α׷� ����
	glUseProgram(shaderProgramID);

	model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	//����� VAO ��ü ���ε�
	glBindVertexArray(VAO_coord);
	glDrawArrays(GL_LINES, 0, 6);
}