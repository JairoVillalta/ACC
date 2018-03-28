#include <GL/gl.h> //Incluya la libreria de OpenGL
#include <GL/glut.h> //Incluye la librería de GLUT
#include <math.h> // Incluye la librería math para operaciones matemáticas.

//Función donde dibujamos el plano, no retorna nada	
void plano(void)
{
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    
	//Línea vertical
    glVertex3f(0.0f,5.0f,0.0f);
    glVertex3f(0.0f,-5.0f,0.0f);
    
    //Línea horizontal  
    glVertex3f(5.0f,0.0f,0.0f);
    glVertex3f(-5.0f,-0.0f,0.0f);
    
    glEnd();
}

//Función donde dibujamos la parabola, aplicando la fórmula dada
void parabola(void)
{ 
    float x=0, y=0, i=0;  
    
   
    // for que va desde -3.5 hasta 2.5 aumentando en 0.1
    for(i=-3.5 ; i<= 2.5 ; i+=0.1)
    {
	
	 x=i;
	 
	 y= ((2*x*x) + (3*x) -2); 
	 
	 //Primitiva de puntos para dibujar la parábola de color azul
	 glPointSize(3); 
	 glBegin(GL_POINTS);
	 glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex2f(x, y);
	 glEnd();
    			
	}	
    
}

//Función que genera y contiene los parámetros de dibujo a mostrar en pantalla.	
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    plano(); //Llama a la función plano donde contiene el dibujo del plano
    parabola(); //Llama a la función parabola para mostrar la grafica
    glFlush ();	// Fuerza la ejecución de comandos GL en un tiempo finito	
}

//Función init que inicializa la vista de la ventana
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    glOrtho(-7.0, 7.0, -7.0, 7.0, -7.0, 7.0); 
}


int main(int argc, char** argv)
{
	//  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc, argv); 
    
    // Establece opciones de la ventana de visualización.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (800, 600); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejercicio 2"); 
    
    //Funciones de retrollamada.
    init (); 
    glutDisplayFunc(display);
    
    // Pasar el control de eventos a GLUT
    glutMainLoop();
    
    // Regresar al sistema operativo
    return 0; // 
}

