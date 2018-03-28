#include <GL/gl.h> //Incluya la libreria de OpenGL
#include <GL/glut.h> //Incluye la librería de GLUT
#include <math.h> // Incluye la librería math para operaciones matemáticas.

//Función donde dibujamos el plano, no retorna nada	
void plano(void)
{
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    
	//Línea vertical
	glVertex3f(20.0f,0.0f,0.0f);
    glVertex3f(-16.0f,0.0f,0.0f);
    
    //Línea horizontal  
    glVertex3f(0.0f,9.0f,0.0f);
    glVertex3f(0.0f,-5.0f,0.0f);
    
    glEnd();
}

//Función donde dibujamos el algoritmo de furrier desde -3PI hasta 5PI
void furrier(void)
{ 
	
	
  float t=0, k=5;
  float x=0, y=0;
  float ft =0;
   
   //condición que va desde -2PI hasta 6PI incrementando en PI
    for(t=-(2*M_PI) ; t<= (6*M_PI) ; t+=M_PI)
    {
	
	 x=t;
	 ft = k + ((4*k)/M_PI)*((sin(x))+ (1/3*sin(3*x)) + (1/5*sin(5*x)));
	 
	 glPointSize(10);
     glBegin(GL_LINES);
	 glColor3f(0.0f, 1.0f, 0.0f);
	 glVertex2f(x, ft);
	 glVertex2f(x, 0.0f);
	 glVertex2f(x, ft);		
	}	
     glEnd();
}

//Función que genera y contiene los parámetros de dibujo a mostrar en pantalla.	
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    plano(); //Llama a la función plano donde contiene el dibujo del plano
    furrier(); //Llama a la función de furrier para mostrar la grafica
    glFlush ();	// Fuerza la ejecución de comandos GL en un tiempo finito	
}

//Función init que inicializa la vista de la ventana
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    glOrtho(-25.0,25.0, -16.0, 16.0, -16.0, 16.0); 
}


int main(int argc, char** argv)
{
	//  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc, argv); 
    
    // Establece opciones de la ventana de visualización.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (800, 600); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejercicio 4"); 
    
    //Funciones de retrollamada.
    init (); 
    glutDisplayFunc(display);
    
    // Pasar el control de eventos a GLUT
    glutMainLoop();
    
    // Regresar al sistema operativo
    return 0; // 
}

