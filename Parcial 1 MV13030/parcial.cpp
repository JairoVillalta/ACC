//Jairo Ariel MArtinez Villalta MV13030

#include <GL/gl.h> //Incluya la libreria de OpenGL
#include <GL/glut.h> //Incluye la librería de GLUT
#include <math.h> // Incluye la librería math para operaciones matemáticas.

//Función donde dibujamos la cabeza del dinosaurio, no retorna nada	
void cabeza(void)
{
	glPointSize(1.5);
	glColor3f(0,0,0);
	
	//Cabeza
	
    glBegin(GL_POLYGON);
    glVertex2f(0.5f,1.5f);
	glVertex2f(1.5f,1.5f);
	glVertex2f(1.5f,1.0f);
	glVertex2f(0.5f,1.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.5f,1.75f);
	glVertex2f(2.5f,1.75f);
	glVertex2f(2.5f,1.5f);
	glVertex2f(0.5f,1.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.5f,2.0f);
	glVertex2f(1.75f,2.0f);
	glVertex2f(1.75f,1.75f);
	glVertex2f(0.5f,1.75f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.5f,3.0f);
	glVertex2f(3.25f,3.0f);
	glVertex2f(3.25f,2.0f);
	glVertex2f(0.5f,2.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.5f,3.25f);
	glVertex2f(1.25f,3.25f);
	glVertex2f(1.25f,3.0f);
	glVertex2f(0.5f,3.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(1.5f,3.25f);
	glVertex2f(3.25f,3.25f);
	glVertex2f(3.25f,3.0f);
	glVertex2f(1.5f,3.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.5f,3.5f);
	glVertex2f(3.25f,3.5f);
	glVertex2f(3.25f,3.25f);
	glVertex2f(0.5f,3.25f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.75f,3.75f);
	glVertex2f(3.0f,3.75f);
	glVertex2f(3.0f,3.5f);
	glVertex2f(0.75f,3.5f);
	glEnd();
		
	//Pata izquierda
	
	glBegin(GL_POLYGON);
    glVertex2f(-1.5f,-2.0f);
	glVertex2f(-0.5f,-2.0f);
	glVertex2f(-0.5f,-2.5f);
	glVertex2f(-1.5f,-2.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-1.5f,-2.5f);
	glVertex2f(-0.75f,-2.5f);
	glVertex2f(-0.75f,-2.75f);
	glVertex2f(-1.5f,-2.75f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-1.5f,-2.75f);
	glVertex2f(-1.0f,-2.75f);
	glVertex2f(-1.0f,-3.25f);
	glVertex2f(-1.5f,-3.25f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-1.5f,-3.25f);
	glVertex2f(-0.75f,-3.25f);
	glVertex2f(-0.75f,-3.5f);
	glVertex2f(-1.5f,-3.5f);
	glEnd();
	
	//Pata derecha
	
	glBegin(GL_POLYGON);
    glVertex2f(0.0f,-2.0f);
	glVertex2f(0.75f,-2.0f);
	glVertex2f(0.75f,-2.5f);
	glVertex2f(0.0f,-2.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.25f,-2.5f);
	glVertex2f(0.75f,-2.5f);
	glVertex2f(0.75f,-3.25f);
	glVertex2f(0.25f,-3.25f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.25f,-3.25f);
	glVertex2f(1.0f,-3.25f);
	glVertex2f(1.0f,-3.5f);
	glVertex2f(0.25f,-3.5f);
	glEnd();
}

//Función donde dibujamos el cuerpo del dinosaurio, no retorna nada	
void cuerpo(void)
{
	glPointSize(1.5);
	glColor3f(0,0,0);
	
	//Cuerpo
	
    glBegin(GL_POLYGON);
    glVertex2f(-3.75f,1.5f);
	glVertex2f(-3.5f,1.5f);
	glVertex2f(-3.5f,-1.0f);
	glVertex2f(-3.75f,-1.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-3.5f,0.5f);
	glVertex2f(-3.0f,0.5f);
	glVertex2f(-3.0f,-1.25f);
	glVertex2f(-3.5f,-1.25f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-3.0f,0.25f);
	glVertex2f(-2.5f,0.25f);
	glVertex2f(-2.5f,-1.5f);
	glVertex2f(-3.0f,-1.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-2.5f,0.0f);
	glVertex2f(-2.0f,0.0f);
	glVertex2f(-2.0f,-1.75f);
	glVertex2f(-2.5f,-1.75f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-2.0f,0.0f);
	glVertex2f(-1.5f,0.0f);
	glVertex2f(-1.5f,-2.0f);
	glVertex2f(-2.0f,-2.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-1.5f,0.25f);
	glVertex2f(-1.0f,0.25f);
	glVertex2f(-1.0f,-2.0f);
	glVertex2f(-1.5f,-2.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-1.0f,0.5f);
	glVertex2f(-0.5f,0.5f);
	glVertex2f(-0.5f,-2.0f);
	glVertex2f(-1.0f,-2.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(-0.5f,0.75f);
	glVertex2f(0.0f,0.75f);
	glVertex2f(0.0f,-2.0f);
	glVertex2f(-0.5f,-2.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.0f,1.0f);
	glVertex2f(1.5f,1.0f);
	glVertex2f(1.5f,-1.0f);
	glVertex2f(0.0f,-1.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.0f,-1.0f);
	glVertex2f(1.25f,-1.0f);
	glVertex2f(1.25f,-1.5f);
	glVertex2f(0.0f,-1.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.0f,-1.5f);
	glVertex2f(1.0f,-1.5f);
	glVertex2f(1.0f,-1.75f);
	glVertex2f(0.0f,-1.75f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.75f);
	glVertex2f(0.75f,-0.75f);
	glVertex2f(0.75f,-2.0f);
	glVertex2f(0.0f,-2.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(1.5f,0.5f);
	glVertex2f(2.25f,0.5f);
	glVertex2f(2.25f,0.25f);
	glVertex2f(1.5f,0.25f);
	glEnd();
	
	glBegin(GL_POLYGON);
    glVertex2f(2.0f,0.5f);
	glVertex2f(2.25f,0.5f);
	glVertex2f(2.25f,0.0f);
	glVertex2f(2.0f,0.0f);
	glEnd();
	
	//Lineas horizontales
	
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-4.5f,-2.5f);
	glVertex2f(-2.5f,-2.5f);
	glVertex2f(-2.5f,-2.75f);
	glVertex2f(-4.5f,-2.75f);
	glEnd();
	
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-3.25f,-3.0f);
	glVertex2f(-2.0f,-3.0f);
	glVertex2f(-2.0f,-3.25f);
	glVertex2f(-3.25f,-3.25f);
	glEnd();
	
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-4.75f,-3.5f);
	glVertex2f(-4.0f,-3.5f);
	glVertex2f(-4.0f,-3.75f);
	glVertex2f(-4.75f,-3.75f);
	glEnd();
	
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(1.25f,-2.5f);
	glVertex2f(4.0f,-2.5f);
	glVertex2f(4.0f,-2.75f);
	glVertex2f(1.25f,-2.75f);
	glEnd();
	
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(3.5f,-3.25f);
	glVertex2f(3.75f,-3.25f);
	glVertex2f(3.75f,-3.5f);
	glVertex2f(3.5f,-3.5f);
	glVertex2f(3.5f,-3.25f);
	glEnd();
	
}

//Función que genera y contiene los parámetros de dibujo a mostrar en pantalla.	
void display(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    cabeza(); //Llama a la función cabeza donde contiene la cabeza del dinosaurio de Firefox
    cuerpo();//Llama a la función cuerpo donde contiene el cuerpo del dinosaurio de Firefox 
    glFlush ();	// Fuerza la ejecución de comandos GL en un tiempo finito	
}

//Función init que inicializa la vista de la ventana
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    glOrtho(-6.0, 5.0, -5.0, 4.0, -5.0, 5.0); 
}


int main(int argc, char** argv)
{
	//  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc, argv); 
    
    // Establece opciones de la ventana de visualización.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (800, 600); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Dinosaurio"); 
    
    //Funciones de retrollamada.
    init (); 
    glutDisplayFunc(display);
    
    // Pasar el control de eventos a GLUT
    glutMainLoop();
    
    // Regresar al sistema operativo
    return 0; // 
}

