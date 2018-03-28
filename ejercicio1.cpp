#include <GL/gl.h> //Incluya la libreria de OpenGL
#include <GL/glut.h> //Incluye la librería de GLUT
#include <math.h> // Incluye la librería math para operaciones matemáticas

//Función donde dibujamos el plano, no retorna nada	
void plano(void)
{
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    
    //Línea vertical
    glVertex2f(0.0f,5.0f);
    glVertex2f(0.0f,-5.0f);
    
    //Línea horizontal
    glVertex2f(5.0f,0.0f);
    glVertex2f(-5.0f,0.0f);
      
    glEnd();
}

//Función donde no retorna nada y contiene el proceso del algoritmo de Bresenham
void bresenham(void){

//Declaramos las variables
double x=0, y=0, x1=-4, x2=4, y1=-4, y2=4;
double deltax,deltay,constantep,ultimo;
deltax=abs(x2-x1);
deltay=abs(y2-y1);
constantep=2*deltay-deltax;
	
	if(x1>x2)
	{
		x=x2;
		y=y2;
		ultimo=x1;
	}
	   else
	   {
	    	x=x1;
	    	y=y1;
	    	ultimo=x2;	
	   } 
	 
	 glBegin(GL_POINTS);
     glColor3f(0.0, 1.0, 1.0);
	 glVertex2f(x, y);
	 glEnd();
                
     while(x<ultimo)
     {
		x+=.1;
		if(constantep<0)
		{
			constantep+=2*deltay;
		}
		   else
		   {
		    	y+=.1;
		    	constantep+=2*(deltay-deltax);
		   }
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
     }
	
}

//Función que genera y contiene los parámetros de dibujo a mostrar en pantalla	
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    plano(); //Llama a la función plano donde contiene el dibujo del plano
    bresenham(); //Llama a la función Bresenham para mostrarlo
    glFlush ();	// Fuerza la ejecución de comandos GL en un tiempo finito	
}

//Función init que inicializa la vista de la ventana
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-6.0, 6.0, -6.0, 6.0, -6.0, 6.0); 
}

int main(int argc, char** argv)
{
	//  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc, argv); 
    
    // Establece opciones de la ventana de visualización
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    
    glutInitWindowSize (800, 600); // Tamaño de la ventana.
    glutInitWindowPosition (100, 100); // Posición de la ventana.
    glutCreateWindow ("Ejercicio 1"); // Crea la ventana y el nombre del mismo.
    
    //Funciones de retrollamada.
    init (); 
    glutDisplayFunc(display);
    
    // Pasar el control de eventos a GLUT
    glutMainLoop();
    
    // Regresar al sistema operativo
    return 0; // 
}

