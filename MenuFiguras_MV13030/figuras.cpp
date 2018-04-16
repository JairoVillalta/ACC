//Jairo Ariel Martinez Villalta
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

//Declaramos variables
GLfloat tetX=300, tetY=-300;//variables para el traslado de la figura
int id_menu[1]; // vector donde almacenaremos el id de la imagen a imprimir

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;

void init(void)
{
	GLfloat light_position[] = { -2.0, 1.0, 1.0, 0.0 };
    // Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    // Queremos que se dibujen las caras frontales
    // y con un color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

//funcion que controla los matariales 
void color(float q, float w, float e, float r, float t, float y, float u, float i, float o, float p)
{
	
GLfloat mat_ambient[] = { q, w, e, p };
GLfloat mat_diffuse[] = { r, t, y, p };
GLfloat mat_specular[] = { u, i, o, p };
GLfloat shine[] = {27.8974f};

glPushMatrix();
glTranslatef(tetX, tetY, 0.0);
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shine);
}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
    // Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
    // "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
    // Usamos proyeccion ortogonal
    glOrtho(0, 600, -600, 0, -600, 600);
    // Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
    // "Limpiamos" la matriz
    glLoadIdentity();
}

void menu(int opc){
    id_menu[1]=opc; // En el vector, en su campo 1, se almacenara el id de la imagen
    glClear (GL_COLOR_BUFFER_BIT);
    switch(opc)// Se muestra la imagen elegida segun el caso
    { 
       case 1:
           //Material plata
           color(0.19225f, 0.19225f, 0.19225f,0.50754f, 0.50754f, 0.50754f,0.508273f, 0.508273f, 0.508273f,0.4f);
           glutSolidSphere (90,50,60);
           //glPopMatrix();
           break;
       
       case 2:
           //Material Brass "Laton"
           color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f, 0.21794872f);
           glutSolidCube (120.0);
           //glPopMatrix();
           break;
       
       case 3:
           //Material bronce
           color(0.2125f, 0.1275f, 0.054f, 0.714f, 0.4284f, 0.18144f, 0.393548f, 0.271906f, 0.166721f, 0.2f);
           glutSolidTorus (50, 100.0, 50, 50);
           //glPopMatrix();
           break;    
           
       case 4:
           //Material esmeralda
           color(0.0215f, 0.1745f, 0.0215f, 0.07568f, 0.61424f, 0.07568f, 0.633f, 0.727811f, 0.633f, 0.6f);
           glutSolidIcosahedron ();
           //glPopMatrix();
           break;
       
       case 5:
           //Material perla 
           color(0.25f, 0.20725f, 0.20725f, 1.0f, 0.829f, 0.829f, 0.296648f, 0.296648f, 0.296648f, 0.088f);
           glutSolidOctahedron ();
           //glPopMatrix();
           break;
       
       case 6:
           //Material oro
           color(0.24725f, 0.1995f, 0.0745f, 0.75164f, 0.60648f, 0.22648f, 0.628281f, 0.555802f, 0.366065f, 0.4f);
           glutSolidTetrahedron ();
           //glPopMatrix();
           break;
       
       case 7:
           //Material Green Rubber "Verde Caucho"
           color(0.0f, 0.05, 0.0f, 0.4f, 0.5f, 0.4f, 0.04f, 0.7f, 0.04f, 0.078125f);
           glutSolidDodecahedron ();
           //glPopMatrix();
           break;
       
       case 8:
           //Material Red Rubber "Rojo Caucho"
           color(0.05f, 0.0, 0.0f, 0.5f, 0.4f, 0.4f, 0.7f, 0.04f, 0.04f, 0.078125f);
           glRotated(90, -1.0, 0.0, 0.0);
           glutSolidCone (100.0, 130.0,70.0,0.0);
           //glPopMatrix();
           break;
       
       case 9:
           //Material turquesa
           color(0.1f, 0.18725f, 0.1745f, 0.396f, 0.74151f, 0.69102f, 0.297254f, 0.30829f, 0.306678f, 0.1f);
           glutSolidTeapot (125.0);
           //glPopMatrix();
           break;                      
       
       case 10:
		   exit(0);
   }
   glutPostRedisplay();
   glFlush();
}

void display(void)
{

    // "Limpiamos" el frame buffer con el color de "Clear", en este caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    // Haciendo uso del metodo menu, pasandoles como paramentro el id
    menu(id_menu[1]);
    glLoadIdentity();
    
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    
    // Rotacion de 25 grados en torno al eje x
    glRotated(30.0, 1.0, 0.0, 0.0);
    // Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0); 
    glutSwapBuffers();
}

//funcion para determinar la pisicion del mouse y trasladar el objeto
void moveMouse(int button, int state, int x, int y) 
{
	//Si se presiona clic izquierdo la posicion del mouse se envia a
	//los parametros de traslacion de la figura(tetX, tetY)
	if((button==GLUT_RIGHT_BUTTON)&(state==GLUT_DOWN))
		{
			tetX=x;
			tetY=y*-1;
		}
}

//Funcion para redibujar el objeto mientras el mouse se mueve al mantener presionado clic izquierdo
void mouseMotion(int x, int y) 
{
		tetX=x;
		tetY=y*-1;
	glutPostRedisplay();
}

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 50;
 
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 50;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 50;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 50;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 30;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 30;
 
    //  Solicitar actualización de visualización
    glutPostRedisplay();
 
}
 
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 'x' :
        X += 20.1f;
        break;
    case 'X' :
        X -= 20.1f;
        break;
    case 'y' :
        Y += 20.1f;
        break;
    case 'Y' :
        Y -= 20.1f;
        break;
    case 'z':
        Z -= 20.1f;
        break;
    case 'Z':
        Z += 20.1f;
        break;
    case 'q':
        exit(0);			// exit
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 900 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (600, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (10, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Figuras Solidas con Materiales Y Traslación");
// Inicializamos el sistema
    init();
    // CREACION DEL MENU PARA ELEGIR ALGUNA IMAGEN
    glutCreateMenu(menu);
      glutAddMenuEntry("Esfera",1);
      glutAddMenuEntry("Cubo",2);
      glutAddMenuEntry("Toro",3);
      glutAddMenuEntry("Icosaedro",4);
      glutAddMenuEntry("Octaedro",5);
      glutAddMenuEntry("Tetraedro",6);
      glutAddMenuEntry("Dodecaedro",7);
      glutAddMenuEntry("Cono",8);
      glutAddMenuEntry("Tetera",9);
      glutAddMenuEntry("Salir",10);      

    glutAttachMenu(GLUT_RIGHT_BUTTON); // Eligiendo con el click derecho del raton
    //Funciones de retrollamada
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(moveMouse);
	glutMotionFunc(mouseMotion);	
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    //Para volver al sistema operativo
    return 0;
}
