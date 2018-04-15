//Jairo Ariel MArtinez Villalta MV13030

#include <GL/gl.h> //Incluya la libreria de OpenGL
#include <GL/glut.h> //Incluye la librería de GLUT
#include <math.h> // Incluye la librería math para operaciones matemáticas.

void Circulos(GLfloat xp1, GLfloat yp1, GLfloat anguloI, GLfloat anguloF,float ra, float r, float g, float b)
{  
 
  glColor3f(r,g,b);
  glBegin(GL_POLYGON);
  GLfloat cx=xp1;
  GLfloat cy=yp1;
  GLfloat angulo;
  for (GLfloat i=anguloI; i<anguloF; i+=0.01){
    angulo= i*M_PI/180.0f;
    cx=ra*cos(angulo)+xp1;
    cy=ra*sin(angulo)+yp1;
    glVertex2f(cx,cy);
  }
   glEnd();
}

//Función donde dibujamos el logo, no retorna nada	
void logo(void)
{
	Circulos(0,0, 0,360,2, 0,0,0);
    Circulos(0,1.5, 0,360,1, 1.0,1.0,1.0);
    Circulos(-0.7,-1.7, 0,360,0.7, 1.0,1.0,1.0);
    Circulos(0.7,-1.7, 0,360,0.7, 1.0,1.0,1.0);
    Circulos(0,-2.5, 0,360,0.7, 1.0,1.0,1.0);
    Circulos(-1.6,-0.7, 0,360,0.7, 1.0,1.0,1.0);
    Circulos(-1.6,-0.9, 0,360,0.7, 1.0,1.0,1.0);
    Circulos(1.6,-0.7, 0,360,0.7, 1.0,1.0,1.0);
    Circulos(1.6,-0.9, 0,360,0.7, 1.0,1.0,1.0);

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3,0);
    glVertex2f(-0.1,1.4);
    glVertex2f(0,0);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0.3,0);
    glVertex2f(0.1,1.4);
    glVertex2f(0,0);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1,0);
    glVertex2f(-0.1,1);
    glVertex2f(0.1,1);
    glVertex2f(0.1,0);
    glEnd();

	glEnd();
	
}

//Función que genera y contiene los parámetros de dibujo a mostrar en pantalla.	
void display(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    logo();//Llama a la función logo donde contiene el logo de Batman 
    glFlush ();	// Fuerza la ejecución de comandos GL en un tiempo finito	
}

//Función init que inicializa la vista de la ventana
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    glOrtho(-2.5, 2.5, -2.5, 2.5, -2.5, 2.5); 
}


int main(int argc, char** argv)
{
	//  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc, argv); 
    
    // Establece opciones de la ventana de visualización.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (800, 600); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Batman Logo"); 
    
    //Funciones de retrollamada.
    init (); 
    glutDisplayFunc(display);
    
    // Pasar el control de eventos a GLUT
    glutMainLoop();
    
    // Regresar al sistema operativo
    return 0; // 
}
