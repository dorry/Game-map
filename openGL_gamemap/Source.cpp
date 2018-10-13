#include<GL/glut.h>

void init() {
	glClearColor(0.329412, 0.329412, 0.329412, 0);

	glMatrixMode(GL_PROJECTION); // Set projection parameters.

	gluOrtho2D(0.0, 1280, 0.0, 720);
}

void game(void) {

	int normalHeight = 200;
	int firstObstacle[] = { 120,140,200,240 };// {first 2 points x , second 2 point x , first  & last point y, inbetween points y (height)}
	int firstStair[] = { 340,380,0,230 };// {first 2 points x , second 2 point x , first  & last point y, inbetween points y (height)}
	int firstMonster[] = { 140,190 }; //{first x , end x , height};
	int stairsDiff[] = { 40, 30 }; // {x,y}
	int secondMonster[] = { firstStair[1] + stairsDiff[0] * 2 ,firstStair[1] + stairsDiff[0] * 2 + 150 }; \
	int firstTnt[] = { secondMonster[1] + 110 , secondMonster[1] + 150 , 0 , firstStair[3] + stairsDiff[1] * 2 + 40 }; // {first 2 points x , second 2 point x , first  & last point y, inbetween points y (height)}
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0.0);

	glBegin(GL_QUADS); //normal floor
	glVertex2f(0, normalHeight);
	glVertex2f(firstObstacle[1] + 200, normalHeight);
	glVertex2f(firstObstacle[1] + 200, 0);
	glVertex2f(0, 0);
	glVertex2f(0, normalHeight);
	glEnd();
	
	glBegin(GL_QUADS);//first stair
	glVertex2f(firstStair[0], 0);
	glVertex2f(firstStair[0], firstStair[3]);
	glVertex2f(firstStair[1] , firstStair[3]);
	glVertex2f(firstStair[1], 0);
	glVertex2f(firstStair[0], 0);
	glEnd();

	glBegin(GL_QUADS); // second stair
	glVertex2f(firstStair[0] + stairsDiff[0], 0);
	glVertex2f(firstStair[0] + stairsDiff[0], firstStair[3] + stairsDiff[1]);
	glVertex2f(firstStair[1] + stairsDiff[0], firstStair[3] + stairsDiff[1]);
	glVertex2f(firstStair[1] + stairsDiff[0], 0);
	glVertex2f(firstStair[0] + stairsDiff[0], 0);
	glEnd();

	glBegin(GL_QUADS); // third stair
	glVertex2f(firstStair[0] + stairsDiff[0] * 2, 0);
	glVertex2f(firstStair[0] + stairsDiff[0] * 2, firstStair[3] + stairsDiff[1] * 2);
	glVertex2f(firstStair[1] + stairsDiff[0] * 2, firstStair[3] + stairsDiff[1] * 2);
	glVertex2f(firstStair[1] + stairsDiff[0] * 2, 0);
	glVertex2f(firstStair[0] + stairsDiff[0] * 2, 0);
	glEnd();

	

	glBegin(GL_QUADS);  // floor after stairs
	glVertex2f(secondMonster[0] , 0);
	glVertex2f(secondMonster[0], firstStair[3] + stairsDiff[1] * 2);
	glVertex2f(secondMonster[1], firstStair[3] + stairsDiff[1] * 2);
	glVertex2f(secondMonster[1] , 0);
	glVertex2f(secondMonster[0], 0);
	glEnd();

	glBegin(GL_QUADS); // floor after the drop
	glVertex2f(secondMonster[1] + 70, 0);
	glVertex2f(secondMonster[1] + 70, firstStair[3] + stairsDiff[1] * 2);
	glVertex2f(secondMonster[1] + 250, firstStair[3] + stairsDiff[1] * 2);
	glVertex2f(secondMonster[1] + 250, 0);
	glVertex2f(secondMonster[1] + 70, 0);
	glEnd();

	glBegin(GL_QUADS); //tnt
	glVertex2f(firstTnt[0], 0);
	glVertex2f(firstTnt[0], firstTnt[3]);
	glVertex2f(firstTnt[1], firstTnt[3]);
	glVertex2f(firstTnt[1], 0);
	glVertex2f(firstTnt[0], 0);
	glEnd();
	
	glColor3f(1, 0, 0);
	glBegin(GL_LINES); //tnt word
	
	glVertex2f(firstTnt[0] + 8, firstTnt[3] - 5);
	glVertex2f(firstTnt[0] + 8, firstTnt[3] - 15);
	glVertex2f(firstTnt[0] +3, firstTnt[3] - 5);
	glVertex2f(firstTnt[0] + 12, firstTnt[3] - 5);

	glVertex2f(firstTnt[0] + 16, firstTnt[3] - 5);
	glVertex2f(firstTnt[0] + 16, firstTnt[3] - 15);

	glVertex2f(firstTnt[0] + 16, firstTnt[3] - 5);
	glVertex2f(firstTnt[0] + 22, firstTnt[3] - 15);

	glVertex2f(firstTnt[0] + 22, firstTnt[3] - 15);
	glVertex2f(firstTnt[0] + 22, firstTnt[3] - 5);

	glVertex2f(firstTnt[0] + 29, firstTnt[3] - 5);
	glVertex2f(firstTnt[0] + 29, firstTnt[3] - 15);
	glVertex2f(firstTnt[0] + 24, firstTnt[3] - 5);
	glVertex2f(firstTnt[0] + 34, firstTnt[3] - 5);



	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_QUADS); // floor under ceiling
	glVertex2f(secondMonster[1] + 250, 0);
	glVertex2f(secondMonster[1] + 250, normalHeight);
	glVertex2f(1280,normalHeight);
	glVertex2f(1280, 0);
	glVertex2f(secondMonster[1] + 250, 0);
	glEnd();

	glBegin(GL_QUADS); // ceiling
	glVertex2f(secondMonster[1] + 300, normalHeight + 100);
	glVertex2f(secondMonster[1] + 300,  720);
	glVertex2f(1280, 720);
	glVertex2f(1280, normalHeight + 100);
	glVertex2f(secondMonster[1] + 300, normalHeight + 100);
	glEnd();

	glBegin(GL_QUADS); //first obstacle
	glVertex2f(120, 200);
	glVertex2f(120, 240);
	glVertex2f(140, 240);
	glVertex2f(140, 200);
	glVertex2f(120, 200);
	glEnd();

	glFlush();
}





void main(int argc , char** argv){

	glutInit(&argc, argv); // Initialize GLUT.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.

	glutInitWindowPosition(50, 50); // Set top-left display-window position.

	glutInitWindowSize(1280, 720); // Set display-window width and height.

	glutCreateWindow("Building"); // Create display window.

	init(); // Execute initialization procedure.

	glutDisplayFunc(game); // Send graphics to display window.

	glutMainLoop(); // Display everything and wait.


}