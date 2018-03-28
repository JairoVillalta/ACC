#include <GL/gl.h> //Incluya la libreria de OpenGL
#include <GL/glut.h> //Incluye la librería de GLUT
#include <math.h> // Incluye la librería math para operaciones matemáticas.

//Función donde dibujamos el plano, no retorna nada	
void plano(void)
{
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    
	//Línea vertical
	glVertex3f(5.0f,0.0f,0.0f);
    glVertex3f(-5.0f,0.0f,0.0f);
    
    //Línea horizontal  
    glVertex3f(0.0f,11.0f,0.0f);
    glVertex3f(0.0f,-3.0f,0.0f);
    
    glEnd();
}

//Función donde dibujamos la recta, aplicando la fórmula dada
void recta(void)
{ 
    float x, y;  
   
   //for del eje x desde -3 hasta 1 aumentando en 0.03333
    for(x=-3.0; x<=1.0; x+=0.03333)
    {
       y= ((3*x)+7);
       
       //Primitiva puntos de color azul para el resto de la recta                
       glPointSize(2);
       glBegin(GL_POINTS);
       glColor3f(0.0f, 0.0f, 1.0f);
       glVertex3f(x,y,0.0f);
       glEnd();
	}

    //for del eje x desde -3 hasta 1 aumentando en 0.3333
    for(x=-3.0; x<=1.0; x+=0.3333)
    { 
       y= ((3*x)+7);
     
       //Primitiva puntos de color rojo para los puntos encontrados
       glPointSize(4);
       glBegin(GL_POINTS);
       glColor3f(1.0f, 0.0f, 0.0f);
       glVertex3f(x,y,0.0f);
       glEnd();
	}
    
}

//Función que genera y contiene los parámetros de dibujo a mostrar en pantalla.	
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    plano(); //Llama a la función plano donde contiene el dibujo del plano
    recta(); //Llama a la función de la recta para mostrar la grafica
    glFlush ();	// Fuerza la ejecución de comandos GL en un tiempo finito	
}

//Función init que inicializa la vista de la ventana
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    glOrtho(-7.0,7.0, -4.0, 12.0, -5.0, 10.0); 
}


int main(int argc, char** argv)
{
	//  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc, argv); 
    
    // Establece opciones de la ventana de visualización.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize (800, 600); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejercicio 3"); 
    
    //Funciones de retrollamada.
    init (); 
    glutDisplayFunc(display);
    
    // Pasar el control de eventos a GLUT
    glutMainLoop();
    
    // Regresar al sistema operativo
    return 0; // 
}

