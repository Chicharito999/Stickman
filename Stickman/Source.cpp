#include <gl/glut.h>
#include <stdlib.h>
#include <stdio.h>

#define SOLID 1
#define WIRE 2

int spinX = 0;
int spinY = 0;
int des = 0;
int i = 0; int a = 1; int ii = 0; int b = 1; 
int i1 = 0; int a1 = 1; int ii1 = 0; int b1 = 1;
int c = 0;

//������������
void init() {
	GLfloat ambient[] = { 0.5, 0.8, 0.1, 0.1 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { -80.0, 50.0, 25.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);//���ñ�����ɫ
	glShadeModel(GL_SMOOTH);//����Ϊ�⻬��ɫģʽ
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient); //���ù�Դ�еĻ�����ǿ��
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);//��Դ�е�ɢ���ǿ��
	glLightfv(GL_LIGHT0, GL_POSITION, position);//ָ����Դλ��
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);//����ȫ�ֻ�����
	//glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glEnable(GL_LIGHTING);//���õ�Դ
	glEnable(GL_LIGHT0);//����0�ŵ�
}

//����
void drawBall(double R,  int MODE) {
	glPushMatrix();
	if (MODE == SOLID) {
		glutSolidSphere(R, 20, 20);//��Ⱦһ���뾶ΪR ��������Ϊ20������
	}
	else if (MODE == WIRE) {
		glutWireSphere(R, 20, 20);//��Ⱦһ���뾶ΪR ��������Ϊ20������
	}
	glPopMatrix();
}

//������
void drawHalfBall(double R, int MODE) {
	glPushMatrix();
	GLdouble eqn[4] = { 0.0, 1.0, 0.0, 0.0 };
	glClipPlane(GL_CLIP_PLANE0, eqn);//�趨�и�ģʽΪ�и��°벿��
	glEnable(GL_CLIP_PLANE0);//����ͼ���и�ܵ�
	if (MODE == SOLID) {
		glutSolidSphere(R, 20, 20);//��Ⱦһ���뾶ΪR ��������Ϊ20������
	}
	else if (MODE == WIRE) {
		glutWireSphere(R, 20, 20);//��Ⱦһ���뾶ΪR ��������Ϊ20������
	}
	glDisable(GL_CLIP_PLANE0);//�ر�ͼ���и�ܵ�
	glPopMatrix();
}

//��������
void drawSkewed(double l, double w, double h, int MODE) {
	glPushMatrix();
	glScaled(l, w, h);//��ǰͼ����x,y,z��ֱ�Ŵ�Ϊl��w��h��
	if (MODE == SOLID) {
		glutSolidCube(1);//���߳�Ϊ1��һ��������
	}
	else if (MODE == WIRE) {
		glutWireCube(1);//���߳�Ϊ1��һ��������
	}
	glPopMatrix();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);//�����һ��ѭ��ִ�����µĻ�������ɫ
	glColor3f(1.0, 1.0, 1.0);//�൱��rgb���廭�ʰ�ɫ
	glLoadIdentity();//ԭ�������������
	gluLookAt(-2.0, -1.0,20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//���ô��ĸ�����
	//glPushMatrix();
	glRotated(spinX, 0, 1, 0);//��ص������¼�adʱ������תspinX��
	glRotated(spinY, 1, 0, 0);
	glTranslated(0, 0,des);//��ص������¼�wsʱǰ���ƶ�des

	glTranslatef(3.5, -2.1, 0);//�ƶ����Ҽ��
	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(0.0, 0.1, 0.0);//�ƶ������ϸ첲��
	glRotatef(i, -1, 0, 0);//�����ϸ첲���¸첲��תi��  
	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(0.0, -1, 0.0);//�ƶ������¸첲��
	glRotatef(ii, -1, 0, 0);//�����¸첲��תii�� 
	drawSkewed(1, 1.5, 1, WIRE);//�������¸첲
	glPopMatrix();//ջ�������ջ  �ص���첲��
	drawSkewed(1, 1.5, 1, WIRE);//�������ϸ첲
	glPopMatrix();//ջ�������ջ  �ص��Ҽ��
	
	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(-7, 0.0, 0.0);
	glTranslatef(0.0, 0.1, 0.0);//�ƶ������ϸ첲
	glRotatef(i1, -1, 0, 0);////�����ϸ첲���¸첲��תi1��  
	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(0.0, -1, 0.0);//�ƶ������¸첲
	glRotatef(ii1, -1, 0, 0);//�����¸첲��תii1�� 
	drawSkewed(1, 1.5, 1, WIRE);//�������¸첲
	glPopMatrix();//ջ�������ջ  �ص���첲��
	drawSkewed(1, 1.5, 1, WIRE);//�������ϸ첲
	glPopMatrix();//ջ�������ջ  �ص��Ҽ��

	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(0.0, 0.3, 0.0);//�ƶ����Ҽ�����ĵ㴦
	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(-7, 0, 0.0);//�ƶ����������ĵ㴦
	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(3.5,2.8, 0.0);//�ƶ���ͷ��
	drawBall(2, WIRE);//����ͷ
	glPopMatrix();//ջ�������ջ  �ص��������ĵ㴦
	drawHalfBall(1, WIRE);//��������
	glPopMatrix();//ջ�������ջ  �ص��Ҽ�����ĵ㴦
	drawHalfBall(1, WIRE);//�����Ҽ��
	glPopMatrix();//ջ�������ջ  �ص��Ҽ��

	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(-3.5, -1.05, 0.0);//�ƶ������Ӵ�
	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(1.5, -3.5, 0.0);//�ƶ����Ҵ��ȴ�
	glRotatef(i1, -1, 0, 0);//�����Ҵ��ȡ���С����תi1��
	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(0.0, -1.8, 0.0);//�ƶ�����С�ȴ�
	glRotatef(-i1, -1, 0, 0);//������С����ת-i1��
	drawSkewed(1.2, 1.5, 2, WIRE);//������С��
	glPopMatrix();//�����ջ �ص��Ҵ��ȴ�
	drawSkewed(1.2, 2, 2, WIRE);//�����Ҵ���
	glPopMatrix();//�����ջ �ص����Ӵ�

	glPushMatrix();//����ѹջ����ջ������һ��
	glTranslatef(-1.5, -3.5, 0.0);//�ƶ�������ȴ�
	glRotatef(i, -1, 0, 0);//��������ȡ���С����תi��
	glPushMatrix();////����ѹջ����ջ������һ��
	glTranslatef(0, -1.8, 0.0);//�ƶ�����С�ȴ�
	glRotatef(-i, -1, 0, 0);//������С����ת-i��
	drawSkewed(1.2, 1.5, 1, WIRE);//������С��
	glPopMatrix();//�����ջ �ص������
	drawSkewed(1.2, 2, 1, WIRE);//���������
	glPopMatrix();//�����ջ�ص�����
	drawSkewed(5, 4.4, 4, WIRE);//���ƶ���
	glPopMatrix();//��ջ
	glPopMatrix();//��ջ

	
	//i�����Ҹ첲������  ii������С�첲
	if (i < 0) {//��첲 С�첲��ת��С��0��ʱ  ��ʼ����i
		a = 1;
	}
	if (i == 45) {//��첲 С�첲��ת��45��ʱ  ����i���� ��ʼ����ii
		a = 0;
		if (ii > 15) {//С�첲��ת������15��ʱ  ��ʼ��Сii
			b = -1;
			
		}
		if (ii < 0) {//С�첲��ת��С��0��ʱ  ��ʼ��Сi  ͬʱ��b��Ϊ1
			b = 1;
			a = -1;
			c = c + 1;//i�ڻص�0��ʱc��0
			
		}
		ii = ii + b;
	}
	i = i + a;

	//��c��0ʱ��ʼ�ڶ���첲������
	//i1������첲������  ii1������С�첲
	if (c != 0) {
		if (i1 < 0) {
			a1 = 1;
		}
		if (i1 == 45) {
			a1 = 0;
			if (ii1 > 15) {
				b1 = -1;

			}
			if (ii1 < 0) {
				b1 = 1;
				a1 = -1;
			}
			ii1 = ii1 + b1;
		}
		i1 = i1 + a1;
	}
	//С�첲��ת��15��ʱ ��ʼ�ƶ�һ��
	if (ii1 ==15||ii==15) {
		des++;
	}
	glutPostRedisplay();
	glutSwapBuffers();
}


void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		spinX -= 1;
		break;
	case 'd':
		spinX += 1;
		break;
	case 'w':
		des += 1;
		break;
	case 's':
		des -= 1;
		break;
	}
	glutPostRedisplay();
}

//���ڱ仯ʱ���õĺ���
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//�̶�ģ������ͼ�����λ��
	glMatrixMode(GL_PROJECTION);//����ǰ��������ΪͶӰ����
	glLoadIdentity();//��������Ϊ��λ����
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);//���
	glMatrixMode(GL_MODELVIEW);//�л���ģ����ͼ����ʼ��ͼ
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);//��ʼ��glut��
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//��ʼ��Ϊ˫���壬RGB��ɫģʽ�Ĵ��� 
	glutInitWindowSize(500, 500);//���ó�ʼ���ڵĴ�С
	glutInitWindowPosition(100, 100);//���ó�ʼ���ڵ�λ��
	glutCreateWindow("Stickman");//����һ������ΪStickman�Ĵ���
	//init();//������������
	glutReshapeFunc(reshape);//���ڱ仯ʱ����reshape����
	glutDisplayFunc(display);//����ˢ��ʱ����display����  
	glutKeyboardFunc(keyPressed);//�����¼�����ʱ����keyPressed����
	glutMainLoop();//���������¼��йصĺ�������ѭ��
	return 0;

}