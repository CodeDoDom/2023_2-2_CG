#include "header.h"

//������ ���α׷� ��ü
GLuint shaderProgramID;

//������ ���� �� �ݹ��Լ� ����
void main(int argc, char** argv)
{
	//glut �ʱ�ȭ
	glutInit(&argc, argv);
	//���÷��� ��� ����
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	//������ ��ġ ����
	glutInitWindowPosition(100, 50);
	//������ ũ�� ����
	glutInitWindowSize(600, 600);
	//������ ���� �� �̸� ����
	glutCreateWindow("�ǽ�1-18");

	//GLEW �ʱ�ȭ
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("Unable to initialize GLEW\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("GLEW Initialized\n");

	//���� ����
	glEnable(GL_DEPTH_TEST);

	//���̴� ���α׷� ����
	shaderProgramID = MakeShaderProgram();

	//���� �ʱ�ȭ
	InitBuffer();

	//�ݹ��Լ� ����
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	//�̺�Ʈ ó�� ����
	glutMainLoop();
}