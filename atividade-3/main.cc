#include <GL/glut.h>

#define WIDTH 700
#define HEIGHT 500

void init();
void display();
void mouse_motion(int x, int y);
void keyboard(unsigned char key, int x, int y);
void handle_menu(GLint op);
void handle_submenu1(GLint op);
void handle_submenu2(GLint op);

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividade 3 - Matheus Pires Vila Real");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(mouse_motion);
    glutMainLoop();
    
    return 0;
}

void init() {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) WIDTH, 0.0, (GLdouble) HEIGHT);

    GLint menu,
          submenu1,
          submenu2;
    submenu1 = glutCreateMenu(handle_submenu1);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("Verde", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Amarelo", 3);
    glutAddMenuEntry("Laranja", 4);
    glutAddMenuEntry("Rosa", 5);
    glutAddMenuEntry("Preto", 6);
    submenu2 = glutCreateMenu(handle_submenu2);
    glutAddMenuEntry("5",0);
    glutAddMenuEntry("7",1);
    glutAddMenuEntry("10",2);
    menu = glutCreateMenu(handle_menu);
    glutAddSubMenu("Cor",submenu1);
    glutAddSubMenu("Espessura",submenu2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void mouse_motion(GLint x, GLint y) {
    glBegin(GL_POINTS);
        glVertex2i(x, HEIGHT - y);
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'd':
        case 'D':
            glClear(GL_COLOR_BUFFER_BIT);
            glFlush();
            break;
    }
}

void handle_submenu1(GLint op) {
    switch(op) {
        case 0:
            glColor3f(1.0,0.0,0.0);
            break;
        case 1:
            glColor3f(0.0,1.0,0.0);
            break;
        case 2:
            glColor3f(0.0,0.0,1.0);
            break;
        case 3:
            glColor3f(1.0,1.0,0.0);
            break;
        case 4:
            glColor3f(1.0,0.5,0.0);
            break;
        case 5:
            glColor3f(1.0,0.0,1.0);
            break;
        case 6:
            glColor3f(0.0,0.0,0.0);
            break;
    }
}

void handle_submenu2(GLint op) {
    switch(op) {
        case 0:
            glPointSize(5.0);
            break;
        case 1:
            glPointSize(7.5);
            break;
        case 2:
            glPointSize(10);
            break;
    }
}

void handle_menu(GLint op) { };