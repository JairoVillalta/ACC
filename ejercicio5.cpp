#include <GL/gl.h> //Incluya la libreria de OpenGL
#include <GL/glut.h> //Incluye la librería de GLUT
#include <math.h> // Incluye la librería math para operaciones matemáticas.

//Función donde dibujamos el plano, no retorna nada	
void plano(void)
{
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    
	//Línea vertical
	glVertex3f(11.0f,0.0f,0.0f);
    glVertex3f(-11.0f,0.0f,0.0f);
    
    //Línea horizontal  
    glVertex3f(0.0f,11.0f,0.0f);
    glVertex3f(0.0f,-11.0f,0.0f);
    
    glEnd();
}

//Función donde dibujamos la grafica de la tangente desde -3PI hasta 3PI
void tangente(void)
{ 
	
	float x, y;
   
   //condición que va desde -3PI hasta 3PI incrementando en 0.00551
    for (x=-3*M_PI; x<3*M_PI; x+=0.00551)
    {
	
     glBegin(GL_LINES);
	 glColor3f(0.0f, 1.0f, 0.0f);
	 y=tan(x);
	 glVertex2f(x,y);
	}	
     glEnd();
     
}

//Función que genera y contiene los parámetros de dibujo a mostrar en pantalla.	
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    plano(); //Llama a la función plano donde contiene el dibujo del plano
    tangente(); //Llama a la función de tangente para mostrar la grafica
    glFlush ();	// Fuerza la ejecución de comandos GL en un tiempo finito	
}

//Función init que inicializa la vista de la ventana
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    glOrtho(-11.0, 11.0, -11.0, 11.0, -11.0, 11.0); 
}


int main(int argc, char** argv)
{
	//  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc, argv); 
    
    // Establece opciones de la ventana de visualización.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (800, 600); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejercicio 5"); 
    
    //Funciones de retrollamada.
    init (); 
    glutDisplayFunc(display);
    
    // Pasar el control de eventos a GLUT
    glutMainLoop();
    
    // Regresar al sistema operativo
    return 0; // 
}

