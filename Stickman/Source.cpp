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

//设置启动光照
void init() {
	GLfloat ambient[] = { 0.5, 0.8, 0.1, 0.1 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { -80.0, 50.0, 25.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);//设置背景颜色
	glShadeModel(GL_SMOOTH);//设置为光滑着色模式
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient); //设置光源中的环境光强度
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);//光源中的散射光强度
	glLightfv(GL_LIGHT0, GL_POSITION, position);//指定光源位置
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);//设置全局环境光
	//glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glEnable(GL_LIGHTING);//启用灯源
	glEnable(GL_LIGHT0);//启用0号灯
}

//画球
void drawBall(double R,  int MODE) {
	glPushMatrix();
	if (MODE == SOLID) {
		glutSolidSphere(R, 20, 20);//渲染一个半径为R 横线竖线为20的球体
	}
	else if (MODE == WIRE) {
		glutWireSphere(R, 20, 20);//渲染一个半径为R 横线竖线为20的球体
	}
	glPopMatrix();
}

//画半球
void drawHalfBall(double R, int MODE) {
	glPushMatrix();
	GLdouble eqn[4] = { 0.0, 1.0, 0.0, 0.0 };
	glClipPlane(GL_CLIP_PLANE0, eqn);//设定切割模式为切割下半部分
	glEnable(GL_CLIP_PLANE0);//启动图形切割管道
	if (MODE == SOLID) {
		glutSolidSphere(R, 20, 20);//渲染一个半径为R 横线竖线为20的球体
	}
	else if (MODE == WIRE) {
		glutWireSphere(R, 20, 20);//渲染一个半径为R 横线竖线为20的球体
	}
	glDisable(GL_CLIP_PLANE0);//关闭图形切割管道
	glPopMatrix();
}

//画长方体
void drawSkewed(double l, double w, double h, int MODE) {
	glPushMatrix();
	glScaled(l, w, h);//当前图形沿x,y,z轴分别放大为l，w，h倍
	if (MODE == SOLID) {
		glutSolidCube(1);//画边长为1的一个正方体
	}
	else if (MODE == WIRE) {
		glutWireCube(1);//画边长为1的一个正方体
	}
	glPopMatrix();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);//清楚上一次循环执行留下的缓冲区颜色
	glColor3f(1.0, 1.0, 1.0);//相当于rgb定义画笔白色
	glLoadIdentity();//原点放在坐标中心
	gluLookAt(-2.0, -1.0,20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//设置从哪个方向看
	//glPushMatrix();
	glRotated(spinX, 0, 1, 0);//监控到键盘事件ad时左右旋转spinX度
	glRotated(spinY, 1, 0, 0);
	glTranslated(0, 0,des);//监控到键盘事件ws时前后移动des

	glTranslatef(3.5, -2.1, 0);//移动到右肩膀
	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(0.0, 0.1, 0.0);//移动到右上胳膊处
	glRotatef(i, -1, 0, 0);//控制上胳膊与下胳膊旋转i度  
	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(0.0, -1, 0.0);//移动到右下胳膊处
	glRotatef(ii, -1, 0, 0);//控制下胳膊旋转ii度 
	drawSkewed(1, 1.5, 1, WIRE);//绘制右下胳膊
	glPopMatrix();//栈顶矩阵出栈  回到大胳膊处
	drawSkewed(1, 1.5, 1, WIRE);//绘制右上胳膊
	glPopMatrix();//栈顶矩阵出栈  回到右肩膀处
	
	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(-7, 0.0, 0.0);
	glTranslatef(0.0, 0.1, 0.0);//移动到左上胳膊
	glRotatef(i1, -1, 0, 0);////控制上胳膊与下胳膊旋转i1度  
	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(0.0, -1, 0.0);//移动到左下胳膊
	glRotatef(ii1, -1, 0, 0);//控制下胳膊旋转ii1度 
	drawSkewed(1, 1.5, 1, WIRE);//绘制左下胳膊
	glPopMatrix();//栈顶矩阵出栈  回到大胳膊处
	drawSkewed(1, 1.5, 1, WIRE);//绘制左上胳膊
	glPopMatrix();//栈顶矩阵出栈  回到右肩膀处

	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(0.0, 0.3, 0.0);//移动到右肩膀中心点处
	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(-7, 0, 0.0);//移动到左肩膀中心点处
	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(3.5,2.8, 0.0);//移动到头部
	drawBall(2, WIRE);//绘制头
	glPopMatrix();//栈顶矩阵出栈  回到左肩膀中心点处
	drawHalfBall(1, WIRE);//绘制左肩膀
	glPopMatrix();//栈顶矩阵出栈  回到右肩膀中心点处
	drawHalfBall(1, WIRE);//绘制右肩膀
	glPopMatrix();//栈顶矩阵出栈  回到右肩膀处

	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(-3.5, -1.05, 0.0);//移动到肚子处
	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(1.5, -3.5, 0.0);//移动到右大腿处
	glRotatef(i1, -1, 0, 0);//控制右大腿、右小腿旋转i1度
	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(0.0, -1.8, 0.0);//移动到右小腿处
	glRotatef(-i1, -1, 0, 0);//控制右小腿旋转-i1度
	drawSkewed(1.2, 1.5, 2, WIRE);//绘制右小腿
	glPopMatrix();//矩阵出栈 回到右大腿处
	drawSkewed(1.2, 2, 2, WIRE);//绘制右大腿
	glPopMatrix();//矩阵出栈 回到肚子处

	glPushMatrix();//矩阵压栈并在栈顶复制一份
	glTranslatef(-1.5, -3.5, 0.0);//移动到左大腿处
	glRotatef(i, -1, 0, 0);//控制左大腿、左小腿旋转i度
	glPushMatrix();////矩阵压栈并在栈顶复制一份
	glTranslatef(0, -1.8, 0.0);//移动到左小腿处
	glRotatef(-i, -1, 0, 0);//控制左小腿旋转-i度
	drawSkewed(1.2, 1.5, 1, WIRE);//绘制左小腿
	glPopMatrix();//矩阵出栈 回到左大腿
	drawSkewed(1.2, 2, 1, WIRE);//绘制左大腿
	glPopMatrix();//矩阵出栈回到肚子
	drawSkewed(5, 4.4, 4, WIRE);//绘制肚子
	glPopMatrix();//出栈
	glPopMatrix();//出栈

	
	//i控制右胳膊和左腿  ii控制右小胳膊
	if (i < 0) {//大胳膊 小胳膊旋转到小于0度时  开始增加i
		a = 1;
	}
	if (i == 45) {//大胳膊 小胳膊旋转到45度时  保持i不变 开始调整ii
		a = 0;
		if (ii > 15) {//小胳膊旋转到大于15度时  开始减小ii
			b = -1;
			
		}
		if (ii < 0) {//小胳膊旋转到小于0度时  开始减小i  同时将b置为1
			b = 1;
			a = -1;
			c = c + 1;//i摆回到0度时c非0
			
		}
		ii = ii + b;
	}
	i = i + a;

	//当c非0时开始摆动左胳膊和左腿
	//i1控制左胳膊和左腿  ii1控制左小胳膊
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
	//小胳膊旋转到15度时 开始移动一步
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

//窗口变化时调用的函数
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//固定模型与视图的相对位置
	glMatrixMode(GL_PROJECTION);//将当前矩阵设置为投影矩阵
	glLoadIdentity();//将矩阵设为单位矩阵
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);//相乘
	glMatrixMode(GL_MODELVIEW);//切换到模型视图矩阵开始画图
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);//初始化glut库
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//初始化为双缓冲，RGB颜色模式的窗口 
	glutInitWindowSize(500, 500);//设置初始窗口的大小
	glutInitWindowPosition(100, 100);//设置初始窗口的位置
	glutCreateWindow("Stickman");//创建一个标题为Stickman的窗口
	//init();//设置启动光照
	glutReshapeFunc(reshape);//窗口变化时调用reshape函数
	glutDisplayFunc(display);//窗口刷新时调用display函数  
	glutKeyboardFunc(keyPressed);//键盘事件发生时调用keyPressed函数
	glutMainLoop();//让所有与事件有关的函数无限循环
	return 0;

}