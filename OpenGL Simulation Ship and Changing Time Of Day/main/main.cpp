#include<bits/stdc++.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
///For music
#include <Mmsystem.h>
#include<windows.h>
#include<fstream>

using namespace std;
#pragma comment(lib, "Winmm.lib")
#define int GLint
#define PI 3.1416

bool f=1;
float pos1=990,pos3=600,pos2=-100,speed1=2.9f, speed2=2.5f, speed3=1.95f, spin=0.0f,cpos1=200,cpos2=400,cpos3=-250,cpos4=50,cpos5=490,sp1=2.0f;
float sun_x=620 ,sun_y=310,sp_x=0.5f,sp_y=1.0f,plane_x=0.0f, plane_speed=4.5f;

///Circle
void circle(GLfloat x, GLfloat y, GLfloat rad){
    GLint triangle_amt=60,i;
    GLfloat t_pi=2*PI;
    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(43,78,88);
    glVertex2f(x,y);
    for(i=0;i<=triangle_amt;i++){
        GLfloat dx=rad*cos(i*t_pi/triangle_amt), dy=rad*sin(i*t_pi/triangle_amt);
        ///cout<<"---"<<x<<" "<<y<<" "<<dx<<" "<<dy<<"---"<<endl;
        glVertex2f(x+dx,y+dy);
    }
    glEnd();
}
///Cloud Model-1 Structure
void cloudModel1(){
    if(f)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(320,210,15);///Left
    circle(340,225,16);///Top
    circle(360,210,16);///Right
    ///Bottom
    circle(330, 210, 16);
    circle(340, 210, 16);
    circle(350, 210, 16);

    glPopMatrix();

}
///Cloud Model-2 Structure
void cloudModel2(){
    if(f)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();
}
///Cloud Model-3 Structure
void cloudModel3(){

    glColor3f(1.25,0.924,0.930);

    glPushMatrix();
    circle(300,200,15);///Left
    circle(320,210,15);///Top_Left
    circle(340,220,16);///Top
    circle(360, 210, 15);///Top_Right
    circle(380,200,15);///Right
    circle(360,190,20);///Bottom_Right
    circle(320,190,20);///Bottom_Left
    circle(340,190,20);///Bottom
    glPopMatrix();
}


///Big hill- Structure
void hill_big(){
    glBegin(GL_POLYGON);
    //glColor3ub(96, 118, 130);
    glVertex2i(70,70);
    glVertex2i(200,225);
    glVertex2i(330,70);
    glEnd();
    ///snow
    glBegin(GL_POLYGON);
    if(f)glColor3f(255,255,255);
    else glColor3ub(172, 174, 176);
    glVertex2i(200,225);
    glVertex2i(230,190);
    glVertex2i(220,180);
    glVertex2i(200,190);
    glVertex2i(190,180);
    glVertex2i(170,190);
    glEnd();

}
///Small_hill- Structure
void hill_small(){
    ///Hill_Small
	glBegin(GL_POLYGON);
    ///glColor3f(0.11, 0.23, 0.36);
	glVertex2i(250, 100);
	glVertex2i(310, 175);
	glVertex2i(370, 100);
	glEnd();

    ///Hill_Small_Snow
	glBegin(GL_POLYGON);
    if(f)glColor3f(255,255,255);
    else glColor3ub(172, 174, 176);
    glVertex2i(290, 150);
	glVertex2i(310, 175);
	glVertex2i(330, 150);
	glVertex2i(325, 140);
	glVertex2i(310, 150);
	glVertex2i(300, 140);
	glEnd();
}
///Tilla Structure
void tillaModel1(){

	glBegin(GL_POLYGON);
	if(f)glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
	glVertex2i(125, 70);
	glVertex2i(150, 80);
	glVertex2i(160, 90);
	glVertex2i(170, 90);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(300, 110);
	glVertex2i(300, 70);
	glEnd();
}
///Tilla Model 2- Structure
void tillaModel2(){
    if(f)glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
    glPushMatrix();
    circle(430,90,30);
    circle(420,87,30);
    circle(410,80,30);
    circle(400,80,30);
    circle(390,70,30);
    circle(445,80,30);
    circle(455,75,30);
    circle(465,70,30);
    circle(470,65,30);
    circle(480,60,30);
    circle(485,55,20);
    glPopMatrix();
}
///House Structure
void house(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);
	glEnd();
    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);
	glEnd();
    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();
    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();
    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);
	glEnd();
    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);
	glEnd();
    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);
	glEnd();
    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();

}
///House 2 structure
void house2(){
    ///body
    glTranslatef(50,100,0);
    glColor3ub(64, 73, 237);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(100,0);
    glVertex2i(100,49);
    glVertex2i(0,49);
    glEnd();
    ///roof
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2i(0,50);
    glVertex2i(105,50);
    glVertex2i(105,60);
    glVertex2i(0,67);
    glEnd();
    ///window1
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(15,7);
    glVertex2i(35,7);
    glVertex2i(35,25);
    glVertex2i(15,25);
    glEnd();
    ///window2
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(78,7);
    glVertex2i(95,7);
    glVertex2i(95,25);
    glVertex2i(78,25);
    glEnd();
    ///door
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(42,0);
    glVertex2i(68,0);
    glVertex2i(68,33);
    glVertex2i(42,33);
    glEnd();
    ///extra design
    glBegin(GL_POLYGON);
    glColor3ub(224, 169, 121);
    glVertex2i(-20,0);
    glVertex2i(0,0);
    glVertex2i(0,70);
    glVertex2i(-20,70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 38, 224);
    glVertex2i(-20,70);
    glVertex2i(0,70);
    glVertex2i(-5,80);
    glVertex2i(-25,80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(224, 169, 121);
    glVertex2i(-25,10);
    glVertex2i(-20,0);
    glVertex2i(-20,70);
    glVertex2i(-25,80);
    glEnd();
}

void lampB(){
    glTranslatef(50,100,0);
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(10,0);
    glVertex2i(10,49);
    glVertex2i(0,49);
    glEnd();
}

///Field Model
void field(){
    ///Field
	glBegin(GL_POLYGON);
    if(f)glColor3f(0.533, 1.293, 0.0);
    else glColor3ub(17, 102, 30);
	glVertex2i(0, 200);
	glVertex2i(0, 220);
	glVertex2i(1000, 220);
	glVertex2i(1000, 200);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	if(f) glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
	glVertex2i(0, 180);
	glVertex2i(1000, 180);
	glVertex2i(1000,200);
	glVertex2i(0, 200);

	glEnd();


}
///Tree Model
void treeModel1(){
    if(f) glColor3ub(0, 173, 36);
    else glColor3ub(17, 102, 30);
    circle(110,110,15);
    circle(110,100,15);
    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(109,70);
    glVertex2i(109,90);
    glVertex2i(111,90);
    glVertex2i(111,70);
    glEnd();
}

void treeModel2(){
    if(f) glColor3ub(0, 173, 36);
    else glColor3ub(17, 102, 30);
    circle(130,130,5);
    circle(125,126,5);
    circle(135,126,5);
    circle(130,125,5);

    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(129,110);
    glVertex2i(129,124);
    glVertex2i(131,124);
    glVertex2i(131,110);
    glEnd();
}
void treeModel3(){
    if(f) glColor3ub(0, 173, 36);
    else glColor3ub(17, 102, 30);
    glBegin(GL_POLYGON);
    glVertex2i(125,123);
    glVertex2i(133,145);
    glVertex2i(141,123);
    glEnd();

    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(132,110);
    glVertex2i(132,124);
    glVertex2i(134,124);
    glVertex2i(134,110);
    glEnd();
}
void Stand_Model(){
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 100);
    glVertex2i(380, 200);
    glVertex2i(375, 200);
    glEnd();

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(380, 197);
    glVertex2i(403, 197);
    glVertex2i(403, 200);
    glVertex2i(380, 200);
    glEnd();

    glColor3f(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(392, 193);
    glVertex2i(403, 193);
    glVertex2i(403, 197);
    glVertex2i(392, 197);
    glEnd();
}
void pole(){
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Stand_Model();
    glPopMatrix();
    }
///Windmill stand structure
void Windmill_Stand_Model(){
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();

}
///Windmill blade  Structure
void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///Boat Structure
void boat1(){
    glTranslatef(50,100,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(20,0);
    glVertex2i(70,0);
    glVertex2i(90,20);
    glVertex2i(0,20);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(20,20);
    glVertex2i(45,20);
    glVertex2i(45,40);

    glVertex2i(47,20);
    glVertex2i(72,20);
    glVertex2i(47,38);
    glEnd();

}
void car1(){
    glTranslatef(50,100,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(20,0);
    glVertex2i(115,0);
    glVertex2i(100,20);
    glVertex2i(85,20);
    glVertex2i(75,35);
    glVertex2i(50,35);
    glVertex2i(40,20);
    glVertex2i(30,20);
    glVertex2i(20,0);
    glEnd();


    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(52,22);
    glVertex2i(61,22);
    glVertex2i(61,33);
    glVertex2i(52,33);
    glVertex2i(43,22);
    glEnd();

     glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(63,22);
    glVertex2i(80,22);
    glVertex2i(73,33);
    glVertex2i(63,33);
    glEnd();

    circle(40,0,7);
    circle(90,0,7);

}

void car2(){
    glTranslatef(50,100,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(20,0);
    glVertex2i(115,0);
    glVertex2i(113,20);
    glVertex2i(80,20);
    glVertex2i(80,35);
    glVertex2i(65,35);
    glVertex2i(68,20);
    glVertex2i(35,20);
    glVertex2i(20,0);
    glEnd();


    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(68,22);
    glVertex2i(76,22);
    glVertex2i(76,33);
    glVertex2i(67,33);
    glVertex2i(53,22);
    glEnd();



    circle(40,0,7);
    circle(95,0,7);

}

/// Windmill Structure
void Windmill(){
    ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    if(f)glColor3f(0.11, 0.23, 0.36);
    else glColor3ub(107, 130, 199);
    circle(380,250,10);

    ///Windmill_Rotary_Blades
    if(f)glColor3f(0.11, 0.23, 0.36);
    else glColor3ub(107, 130, 199);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();

}
///Object Creation

///`Right Side_ Big Hill 1
void rightBigHill1(){
    glPushMatrix();
    glTranslatef(600,150,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(0,0,0);
    hill_big();
    glPopMatrix();
}
///Right Side- Big Hill 2
void rightBigHill2(){
    glPushMatrix();
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(31, 40, 66);
    glTranslatef(550,130,0);
    hill_big();
    glPopMatrix();
}
///Left Side- Small Hill
void leftSmallHill(){
    glPushMatrix();
    glTranslatef(0,120,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(31, 40, 66);
    hill_small();
    glPopMatrix();
}
///Right Side-House
void rightHouse(){
    glPushMatrix();
    glTranslatef(400,150,0);
    house();
    glPopMatrix();
}
///Left Side house
void leftHouse(){
    glPushMatrix();
    glTranslatef(420,120,0);
    house2();
    glPopMatrix();
}

///Right Side- Tilla
void rightTillaL(){
    glPushMatrix();
    glTranslatef(400,150,0);
    tillaModel1();
    glPopMatrix();
}
///Left Side- Tilla
void leftTillaL(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel1();
    glPopMatrix();
}
///Right Side- Tilla
void rightTillaR(){
    glPushMatrix();
    glTranslatef(500,150,0);
    tillaModel2();
    glPopMatrix();
}
///Right Side- Wind Mill
void rightWindmMill(){
    glPushMatrix();
    glTranslatef(530,150,0);
    Windmill();
    glPopMatrix();
}
///Left Side- Wind Mill
void leftWindMill(){
    glPushMatrix();
    glTranslatef(0,150,0);
    Windmill();
    glPopMatrix();
}
void pole1(){
    glPushMatrix();
    glTranslatef(30,120,0);
    pole();
    glPopMatrix();
}

void pole2(){
    glPushMatrix();
    glTranslatef(-130,120,0);
    pole();
    glPopMatrix();
}

void pole3(){
    glPushMatrix();
    glTranslatef(-300,120,0);
    pole();
    glPopMatrix();
}

void pole4(){
    glPushMatrix();
    glTranslatef(230,120,0);
    pole();
    glPopMatrix();
}

void pole5(){
    glPushMatrix();
    glTranslatef(480,120,0);
    pole();
    glPopMatrix();
}
///Left Side- Big Hill
void leftHillBig(){
    glPushMatrix();
    glTranslatef(0,130,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(0,0,0);
    hill_big();
    glPopMatrix();
}
///Left Side Tilla
void leftTillaL1(){
    glPushMatrix();
    glTranslatef(-140,150,0);
    tillaModel1();
    glPopMatrix();
}
///Left Side Tilla
void leftTillaR(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel2();
    glPopMatrix();
}
///Boat1

///Boat2
void carB(){
    glPushMatrix();
    glTranslatef(pos2,42,0);
    car1();
    glPopMatrix();
}
///Boat3
void boatC(){
    glPushMatrix();
    glTranslatef(pos3,-70,0);
    boat1();
    glPopMatrix();
}
void carA(){
    glPushMatrix();
    glTranslatef(pos1,-11,0);
    car2();
    glPopMatrix();
}

///tree1
void tree1(){
    glPushMatrix();
    glTranslatef(0,188,0);
    treeModel1();
    glPopMatrix();
}
///tree2
void tree2(){
    glPushMatrix();
    glTranslatef(-60,146,0);
    treeModel2();
    glPopMatrix();
}
///tree3
void tree3(){
    glPushMatrix();
    glTranslatef(-110,130,0);
    treeModel3();
    glPopMatrix();
}
///tree4
void tree4(){
    glPushMatrix();
    glTranslatef(300,160,0);
    treeModel2();
    glPopMatrix();
}
///tree5
void tree5(){
    glPushMatrix();
    glTranslatef(530,150,0);
    treeModel1();
    glPopMatrix();
}
///tree6
void tree6(){
    glPushMatrix();
    glTranslatef(455,142,0);
    treeModel3();
    glPopMatrix();
}
///tree7
void tree7(){
    glPushMatrix();
    glTranslatef(200,110,0);
    treeModel2();
    glPopMatrix();
}

///Sky
void sky(){
    glPushMatrix();
    if(f)glColor3ub(157, 216, 250);
    else glColor3ub(4, 11, 51);
    glBegin(GL_POLYGON);
    glVertex2i(0,250);
    glVertex2i(1000,250);
    glVertex2i(1000,500);
    glVertex2i(0,500);
    glEnd();
    glPopMatrix();
}
///Water
void water(){
    if(f)glColor3ub(107, 117, 255);
    else glColor3ub(0, 10, 143);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(1000,0);
    glVertex2i(1000,250);
    glVertex2i(0,250);
    glEnd();
    glPopMatrix();

}
///Sun
void sun(){
    if(f){
        glPushMatrix();
        glColor3ub(252, 212, 64);
        glTranslatef(sun_x,sun_y,0.0);
        circle(0,0,30);
        glPopMatrix();
    }
}
///Moon
void moon(){
    if(!f){
        glPushMatrix();
        glColor3ub(248, 248, 255);
        circle(620,360,30);
        glColor3ub(4, 11, 51);
        circle(630,380,30);
        glPopMatrix();
    }
}
///Star
void star(){
    if(!f){
        glPushMatrix();
        glColor3ub(255,255,255);
        glPointSize(4);
        glBegin(GL_POINTS);

        glVertex2i(100,400);
        glVertex2i(120,420);
        glVertex2i(150,450);
        glVertex2i(170,470);
        glVertex2i(200,430);
        glVertex2i(230,470);
        glVertex2i(350,460);
        glVertex2i(900,400);
        glVertex2i(580,470);
        glVertex2i(840,460);
        glVertex2i(750,400);
        glVertex2i(950,400);
        glVertex2i(760,420);
        glVertex2i(690,450);
        glVertex2i(550,470);
        glVertex2i(790,430);
        glVertex2i(830,470);
        glVertex2i(690,460);
        glVertex2i(590,400);
        glVertex2i(490,430);
        glVertex2i(330,470);
        glVertex2i(390,460);
        glVertex2i(460,400);
        glVertex2i(490,330);
        glVertex2i(330,370);
        glVertex2i(390,360);
        glVertex2i(460,300);
        glVertex2i(990,230);
        glVertex2i(930,370);
        glVertex2i(990,360);
        glVertex2i(960,300);
        glVertex2i(160,300);
        glVertex2i(190,230);
        glVertex2i(30,370);
        glVertex2i(290,360);
        glVertex2i(260,300);
        glVertex2i(0,300);
        glVertex2i(90,230);
        glVertex2i(130,370);
        glVertex2i(60,360);
        glVertex2i(80,300);
        glVertex2i(570,200);
        glVertex2i(600,230);
        glVertex2i(630,270);
        glVertex2i(590,260);
        glVertex2i(680,200);
        glEnd();

        glPopMatrix();
    }
}

///cloud1
void cloud1(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos1,170,0);
        cloudModel1();
        glPopMatrix();
    }
}
///cloud2
void cloud2(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos2,270,0);
        cloudModel2();
        glPopMatrix();
    }
}
///cloud3
void cloud3(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos3,200,0);
        cloudModel3();
        glPopMatrix();
    }
}
///cloud4
void cloud4(){
    glPushMatrix();
    glTranslatef(cpos4,250,0);
    cloudModel2();
    glPopMatrix();
}

///cloud5
void cloud5(){
    glPushMatrix();
    glTranslatef(cpos5,220,0);
    cloudModel1();
    glPopMatrix();
}

///Airplane Design
void airPlane(){
    glPushMatrix();
    glTranslatef(plane_x,370,0);

    ///body
    if(f)glColor3ub(196, 190, 0);
    else glColor3ub(0, 51, 2);
    glBegin(GL_POLYGON);
    glVertex2i(100,100);
    glVertex2i(135,100);
    glVertex2i(135,112);
    glVertex2i(100,112);
    glEnd();
    ///Windows
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(107,104);
    glVertex2i(115,104);
    glVertex2i(115,110);
    glVertex2i(107,110);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(122,104);
    glVertex2i(130,104);
    glVertex2i(130,110);
    glVertex2i(122,110);
    glEnd();
    ///Head
    if(f)glColor3ub(255,0,0);
    else glColor3ub(82, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(135,100);
    glVertex2i(155,102);
    glVertex2i(135,112);
    glEnd();
    ///Pakha
    glBegin(GL_POLYGON);
    if(f)glColor3ub(255,0,0);
    glVertex2i(100,112);
    glVertex2i(110,112);
    glVertex2i(103,120);
    glVertex2i(100,120);
    glEnd();

    glPopMatrix();


}
void road(){
    ///Field
	glBegin(GL_POLYGON);
	 glColor3ub(96, 118, 130);
	glVertex2i(0, 80);
	glVertex2i(0, 180);
	glVertex2i(1000, 80);
	glVertex2i(1000, 180);
	glVertex2i(0, 180);


	glEnd();


}
void roadstrip(){

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(30, 135);
	glVertex2i(30, 125);
	glVertex2i(80, 135);
	glVertex2i(80, 125);
	glVertex2i(30, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(120, 135);
	glVertex2i(120, 125);
	glVertex2i(170, 135);
	glVertex2i(170, 125);
	glVertex2i(120, 125);
	glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(210, 135);
	glVertex2i(210, 125);
	glVertex2i(260, 135);
	glVertex2i(260, 125);
	glVertex2i(210, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(300, 135);
	glVertex2i(300, 125);
	glVertex2i(350, 135);
	glVertex2i(350, 125);
	glVertex2i(300, 125);
	glEnd();

    glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(390, 135);
	glVertex2i(390, 125);
	glVertex2i(440, 135);
	glVertex2i(440, 125);
	glVertex2i(390, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(480, 135);
	glVertex2i(480, 125);
	glVertex2i(530, 135);
	glVertex2i(530, 125);
	glVertex2i(480, 125);
	glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(570, 135);
	glVertex2i(570, 125);
	glVertex2i(620, 135);
	glVertex2i(620, 125);
	glVertex2i(570, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(660, 135);
	glVertex2i(660, 125);
	glVertex2i(710, 135);
	glVertex2i(710, 125);
	glVertex2i(660, 125);
	glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(750, 135);
	glVertex2i(750, 125);
	glVertex2i(800, 135);
	glVertex2i(800, 125);
	glVertex2i(750, 125);
	glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(840, 135);
	glVertex2i(840, 125);
	glVertex2i(890, 135);
	glVertex2i(890, 125);
	glVertex2i(840, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(930, 135);
	glVertex2i(930, 125);
	glVertex2i(980, 135);
	glVertex2i(980, 125);
	glVertex2i(930, 125);
	glEnd();
}

///Main
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0,0.0,1.0);

	sky();
	water();
	star();
	sun();
    moon();
    road();
    roadstrip();
    cloud1();
    cloud2();
    cloud3();
    cloud4();
    cloud5();
    airPlane();
    rightTillaL();
    rightWindmMill();
    rightBigHill1();
    rightBigHill2();
    rightTillaR();
    rightHouse();
    leftTillaL1();
    leftHillBig();
    leftSmallHill();
    leftWindMill();
    leftTillaR();
    leftHouse();
    pole1();
    pole2();
    pole3();
    pole4();
    pole5();
    field();
    carB();
    boatC();
    carA();



    tree1();
    tree2();
    tree3();
    tree4();
    tree5();
    tree6();
    tree7();
	glFlush();
}

void init(void){
	glClearColor(0.65, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void update(int value){
    ///spin+=0.1;
    ///Boat Control
    if(pos1<20)pos1=1000;
    if(pos2>980)pos2=-100;
    if(pos3<10)pos3=1000;
    pos1-=speed1;
    pos2+=speed2;
    pos3-=speed3;
    ///Cloud Control
    if(cpos1>750)cpos1=-320;
    if(cpos2<-350)cpos2=650;
    if(cpos3>750)cpos3=-320;
    if(cpos4>750)cpos4=-320;
    if(cpos5<-350)cpos5=650;
    cpos1+=sp1;
    cpos2-=sp1;
    cpos3+=sp1;
    cpos4+=sp1;
    cpos5-=sp1;
    ///Sun Control
    if(sun_y>480){
        sun_x=650;
        sun_y=290;
        f=0;
    }
    sun_x-=sp_x;
    sun_y+=sp_y;
    ///AirPlane Control
    if(plane_x>1000){
        plane_x=-100;
    }
    plane_x+=plane_speed;

    glutTimerFunc(100, update, 0);
    glutPostRedisplay();

}
void windMill_start(){
    spin+=0.1;
    glutPostRedisplay();
}

void handleMouse(int key, int state, int x, int y){
    switch (key){
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN){
                glutIdleFunc(windMill_start);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN){
                glutIdleFunc(NULL);
            }
            break;
        default:
            break;
    }
}
void handleKeypress(unsigned char key, int x, int y){
	switch (key){
        case 'd':
            f=1;
            break;
        case 'n':
            f=0;
            break;
        glutPostRedisplay();
	}
}
void credit(){

    cout<<"------------------------------------------------------"<<endl;
    cout<<"Computer Graphics-  Project"<<endl;
    cout<<"\t 1. CHAITHRA B C [1EW20CS025]"<<endl;
    cout<<"\t 2. CHANDAN B RAM [1EW20CS026]"<<endl;
    cout<<"------------------------------------------------------"<<endl;

}
int main(int argc, char** argv){
    credit();
    ///Music Background
    PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
    ///system("pause");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("CG Project- Smart Village");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
}
#include<bits/stdc++.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
///For music
#include <Mmsystem.h>
#include<windows.h>
#include<fstream>

using namespace std;
#pragma comment(lib, "Winmm.lib")
#define int GLint
#define PI 3.1416

bool f=1;
float pos1=990,pos3=600,pos2=-100,speed1=2.9f, speed2=2.5f, speed3=1.95f, spin=0.0f,cpos1=200,cpos2=400,cpos3=-250,cpos4=50,cpos5=490,sp1=2.0f;
float sun_x=620 ,sun_y=310,sp_x=0.5f,sp_y=1.0f,plane_x=0.0f, plane_speed=4.5f;

///Circle
void circle(GLfloat x, GLfloat y, GLfloat rad){
    GLint triangle_amt=60,i;
    GLfloat t_pi=2*PI;
    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(43,78,88);
    glVertex2f(x,y);
    for(i=0;i<=triangle_amt;i++){
        GLfloat dx=rad*cos(i*t_pi/triangle_amt), dy=rad*sin(i*t_pi/triangle_amt);
        ///cout<<"---"<<x<<" "<<y<<" "<<dx<<" "<<dy<<"---"<<endl;
        glVertex2f(x+dx,y+dy);
    }
    glEnd();
}
///Cloud Model-1 Structure
void cloudModel1(){
    if(f)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(320,210,15);///Left
    circle(340,225,16);///Top
    circle(360,210,16);///Right
    ///Bottom
    circle(330, 210, 16);
    circle(340, 210, 16);
    circle(350, 210, 16);

    glPopMatrix();

}
///Cloud Model-2 Structure
void cloudModel2(){
    if(f)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();
}
///Cloud Model-3 Structure
void cloudModel3(){

    glColor3f(1.25,0.924,0.930);

    glPushMatrix();
    circle(300,200,15);///Left
    circle(320,210,15);///Top_Left
    circle(340,220,16);///Top
    circle(360, 210, 15);///Top_Right
    circle(380,200,15);///Right
    circle(360,190,20);///Bottom_Right
    circle(320,190,20);///Bottom_Left
    circle(340,190,20);///Bottom
    glPopMatrix();
}


///Big hill- Structure
void hill_big(){
    glBegin(GL_POLYGON);
    //glColor3ub(96, 118, 130);
    glVertex2i(70,70);
    glVertex2i(200,225);
    glVertex2i(330,70);
    glEnd();
    ///snow
    glBegin(GL_POLYGON);
    if(f)glColor3f(255,255,255);
    else glColor3ub(172, 174, 176);
    glVertex2i(200,225);
    glVertex2i(230,190);
    glVertex2i(220,180);
    glVertex2i(200,190);
    glVertex2i(190,180);
    glVertex2i(170,190);
    glEnd();

}
///Small_hill- Structure
void hill_small(){
    ///Hill_Small
	glBegin(GL_POLYGON);
    ///glColor3f(0.11, 0.23, 0.36);
	glVertex2i(250, 100);
	glVertex2i(310, 175);
	glVertex2i(370, 100);
	glEnd();

    ///Hill_Small_Snow
	glBegin(GL_POLYGON);
    if(f)glColor3f(255,255,255);
    else glColor3ub(172, 174, 176);
    glVertex2i(290, 150);
	glVertex2i(310, 175);
	glVertex2i(330, 150);
	glVertex2i(325, 140);
	glVertex2i(310, 150);
	glVertex2i(300, 140);
	glEnd();
}
///Tilla Structure
void tillaModel1(){

	glBegin(GL_POLYGON);
	if(f)glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
	glVertex2i(125, 70);
	glVertex2i(150, 80);
	glVertex2i(160, 90);
	glVertex2i(170, 90);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(300, 110);
	glVertex2i(300, 70);
	glEnd();
}
///Tilla Model 2- Structure
void tillaModel2(){
    if(f)glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
    glPushMatrix();
    circle(430,90,30);
    circle(420,87,30);
    circle(410,80,30);
    circle(400,80,30);
    circle(390,70,30);
    circle(445,80,30);
    circle(455,75,30);
    circle(465,70,30);
    circle(470,65,30);
    circle(480,60,30);
    circle(485,55,20);
    glPopMatrix();
}
///House Structure
void house(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);
	glEnd();
    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);
	glEnd();
    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();
    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();
    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);
	glEnd();
    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);
	glEnd();
    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);
	glEnd();
    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();

}
///House 2 structure
void house2(){
    ///body
    glTranslatef(50,100,0);
    glColor3ub(64, 73, 237);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(100,0);
    glVertex2i(100,49);
    glVertex2i(0,49);
    glEnd();
    ///roof
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2i(0,50);
    glVertex2i(105,50);
    glVertex2i(105,60);
    glVertex2i(0,67);
    glEnd();
    ///window1
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(15,7);
    glVertex2i(35,7);
    glVertex2i(35,25);
    glVertex2i(15,25);
    glEnd();
    ///window2
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(78,7);
    glVertex2i(95,7);
    glVertex2i(95,25);
    glVertex2i(78,25);
    glEnd();
    ///door
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(42,0);
    glVertex2i(68,0);
    glVertex2i(68,33);
    glVertex2i(42,33);
    glEnd();
    ///extra design
    glBegin(GL_POLYGON);
    glColor3ub(224, 169, 121);
    glVertex2i(-20,0);
    glVertex2i(0,0);
    glVertex2i(0,70);
    glVertex2i(-20,70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 38, 224);
    glVertex2i(-20,70);
    glVertex2i(0,70);
    glVertex2i(-5,80);
    glVertex2i(-25,80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(224, 169, 121);
    glVertex2i(-25,10);
    glVertex2i(-20,0);
    glVertex2i(-20,70);
    glVertex2i(-25,80);
    glEnd();
}

void lampB(){
    glTranslatef(50,100,0);
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(10,0);
    glVertex2i(10,49);
    glVertex2i(0,49);
    glEnd();
}

///Field Model
void field(){
    ///Field
	glBegin(GL_POLYGON);
    if(f)glColor3f(0.533, 1.293, 0.0);
    else glColor3ub(17, 102, 30);
	glVertex2i(0, 200);
	glVertex2i(0, 220);
	glVertex2i(1000, 220);
	glVertex2i(1000, 200);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	if(f) glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
	glVertex2i(0, 180);
	glVertex2i(1000, 180);
	glVertex2i(1000,200);
	glVertex2i(0, 200);

	glEnd();


}
///Tree Model
void treeModel1(){
    if(f) glColor3ub(0, 173, 36);
    else glColor3ub(17, 102, 30);
    circle(110,110,15);
    circle(110,100,15);
    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(109,70);
    glVertex2i(109,90);
    glVertex2i(111,90);
    glVertex2i(111,70);
    glEnd();
}

void treeModel2(){
    if(f) glColor3ub(0, 173, 36);
    else glColor3ub(17, 102, 30);
    circle(130,130,5);
    circle(125,126,5);
    circle(135,126,5);
    circle(130,125,5);

    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(129,110);
    glVertex2i(129,124);
    glVertex2i(131,124);
    glVertex2i(131,110);
    glEnd();
}
void treeModel3(){
    if(f) glColor3ub(0, 173, 36);
    else glColor3ub(17, 102, 30);
    glBegin(GL_POLYGON);
    glVertex2i(125,123);
    glVertex2i(133,145);
    glVertex2i(141,123);
    glEnd();

    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(132,110);
    glVertex2i(132,124);
    glVertex2i(134,124);
    glVertex2i(134,110);
    glEnd();
}
void Stand_Model(){
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 100);
    glVertex2i(380, 200);
    glVertex2i(375, 200);
    glEnd();

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(380, 197);
    glVertex2i(403, 197);
    glVertex2i(403, 200);
    glVertex2i(380, 200);
    glEnd();

    glColor3f(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(392, 193);
    glVertex2i(403, 193);
    glVertex2i(403, 197);
    glVertex2i(392, 197);
    glEnd();
}
void pole(){
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Stand_Model();
    glPopMatrix();
    }
///Windmill stand structure
void Windmill_Stand_Model(){
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();

}
///Windmill blade  Structure
void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///Boat Structure
void boat1(){
    glTranslatef(50,100,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(20,0);
    glVertex2i(70,0);
    glVertex2i(90,20);
    glVertex2i(0,20);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(20,20);
    glVertex2i(45,20);
    glVertex2i(45,40);

    glVertex2i(47,20);
    glVertex2i(72,20);
    glVertex2i(47,38);
    glEnd();

}
void car1(){
    glTranslatef(50,100,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(20,0);
    glVertex2i(115,0);
    glVertex2i(100,20);
    glVertex2i(85,20);
    glVertex2i(75,35);
    glVertex2i(50,35);
    glVertex2i(40,20);
    glVertex2i(30,20);
    glVertex2i(20,0);
    glEnd();


    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(52,22);
    glVertex2i(61,22);
    glVertex2i(61,33);
    glVertex2i(52,33);
    glVertex2i(43,22);
    glEnd();

     glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(63,22);
    glVertex2i(80,22);
    glVertex2i(73,33);
    glVertex2i(63,33);
    glEnd();

    circle(40,0,7);
    circle(90,0,7);

}

void car2(){
    glTranslatef(50,100,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(20,0);
    glVertex2i(115,0);
    glVertex2i(113,20);
    glVertex2i(80,20);
    glVertex2i(80,35);
    glVertex2i(65,35);
    glVertex2i(68,20);
    glVertex2i(35,20);
    glVertex2i(20,0);
    glEnd();


    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(68,22);
    glVertex2i(76,22);
    glVertex2i(76,33);
    glVertex2i(67,33);
    glVertex2i(53,22);
    glEnd();



    circle(40,0,7);
    circle(95,0,7);

}

/// Windmill Structure
void Windmill(){
    ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    if(f)glColor3f(0.11, 0.23, 0.36);
    else glColor3ub(107, 130, 199);
    circle(380,250,10);

    ///Windmill_Rotary_Blades
    if(f)glColor3f(0.11, 0.23, 0.36);
    else glColor3ub(107, 130, 199);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();

}
///Object Creation

///`Right Side_ Big Hill 1
void rightBigHill1(){
    glPushMatrix();
    glTranslatef(600,150,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(0,0,0);
    hill_big();
    glPopMatrix();
}
///Right Side- Big Hill 2
void rightBigHill2(){
    glPushMatrix();
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(31, 40, 66);
    glTranslatef(550,130,0);
    hill_big();
    glPopMatrix();
}
///Left Side- Small Hill
void leftSmallHill(){
    glPushMatrix();
    glTranslatef(0,120,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(31, 40, 66);
    hill_small();
    glPopMatrix();
}
///Right Side-House
void rightHouse(){
    glPushMatrix();
    glTranslatef(400,150,0);
    house();
    glPopMatrix();
}
///Left Side house
void leftHouse(){
    glPushMatrix();
    glTranslatef(420,120,0);
    house2();
    glPopMatrix();
}

///Right Side- Tilla
void rightTillaL(){
    glPushMatrix();
    glTranslatef(400,150,0);
    tillaModel1();
    glPopMatrix();
}
///Left Side- Tilla
void leftTillaL(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel1();
    glPopMatrix();
}
///Right Side- Tilla
void rightTillaR(){
    glPushMatrix();
    glTranslatef(500,150,0);
    tillaModel2();
    glPopMatrix();
}
///Right Side- Wind Mill
void rightWindmMill(){
    glPushMatrix();
    glTranslatef(530,150,0);
    Windmill();
    glPopMatrix();
}
///Left Side- Wind Mill
void leftWindMill(){
    glPushMatrix();
    glTranslatef(0,150,0);
    Windmill();
    glPopMatrix();
}
void pole1(){
    glPushMatrix();
    glTranslatef(30,120,0);
    pole();
    glPopMatrix();
}

void pole2(){
    glPushMatrix();
    glTranslatef(-130,120,0);
    pole();
    glPopMatrix();
}

void pole3(){
    glPushMatrix();
    glTranslatef(-300,120,0);
    pole();
    glPopMatrix();
}

void pole4(){
    glPushMatrix();
    glTranslatef(230,120,0);
    pole();
    glPopMatrix();
}

void pole5(){
    glPushMatrix();
    glTranslatef(480,120,0);
    pole();
    glPopMatrix();
}
///Left Side- Big Hill
void leftHillBig(){
    glPushMatrix();
    glTranslatef(0,130,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(0,0,0);
    hill_big();
    glPopMatrix();
}
///Left Side Tilla
void leftTillaL1(){
    glPushMatrix();
    glTranslatef(-140,150,0);
    tillaModel1();
    glPopMatrix();
}
///Left Side Tilla
void leftTillaR(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel2();
    glPopMatrix();
}
///Boat1

///Boat2
void carB(){
    glPushMatrix();
    glTranslatef(pos2,42,0);
    car1();
    glPopMatrix();
}
///Boat3
void boatC(){
    glPushMatrix();
    glTranslatef(pos3,-70,0);
    boat1();
    glPopMatrix();
}
void carA(){
    glPushMatrix();
    glTranslatef(pos1,-11,0);
    car2();
    glPopMatrix();
}

///tree1
void tree1(){
    glPushMatrix();
    glTranslatef(0,188,0);
    treeModel1();
    glPopMatrix();
}
///tree2
void tree2(){
    glPushMatrix();
    glTranslatef(-60,146,0);
    treeModel2();
    glPopMatrix();
}
///tree3
void tree3(){
    glPushMatrix();
    glTranslatef(-110,130,0);
    treeModel3();
    glPopMatrix();
}
///tree4
void tree4(){
    glPushMatrix();
    glTranslatef(300,160,0);
    treeModel2();
    glPopMatrix();
}
///tree5
void tree5(){
    glPushMatrix();
    glTranslatef(530,150,0);
    treeModel1();
    glPopMatrix();
}
///tree6
void tree6(){
    glPushMatrix();
    glTranslatef(455,142,0);
    treeModel3();
    glPopMatrix();
}
///tree7
void tree7(){
    glPushMatrix();
    glTranslatef(200,110,0);
    treeModel2();
    glPopMatrix();
}

///Sky
void sky(){
    glPushMatrix();
    if(f)glColor3ub(157, 216, 250);
    else glColor3ub(4, 11, 51);
    glBegin(GL_POLYGON);
    glVertex2i(0,250);
    glVertex2i(1000,250);
    glVertex2i(1000,500);
    glVertex2i(0,500);
    glEnd();
    glPopMatrix();
}
///Water
void water(){
    if(f)glColor3ub(107, 117, 255);
    else glColor3ub(0, 10, 143);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(1000,0);
    glVertex2i(1000,250);
    glVertex2i(0,250);
    glEnd();
    glPopMatrix();

}
///Sun
void sun(){
    if(f){
        glPushMatrix();
        glColor3ub(252, 212, 64);
        glTranslatef(sun_x,sun_y,0.0);
        circle(0,0,30);
        glPopMatrix();
    }
}
///Moon
void moon(){
    if(!f){
        glPushMatrix();
        glColor3ub(248, 248, 255);
        circle(620,360,30);
        glColor3ub(4, 11, 51);
        circle(630,380,30);
        glPopMatrix();
    }
}
///Star
void star(){
    if(!f){
        glPushMatrix();
        glColor3ub(255,255,255);
        glPointSize(4);
        glBegin(GL_POINTS);

        glVertex2i(100,400);
        glVertex2i(120,420);
        glVertex2i(150,450);
        glVertex2i(170,470);
        glVertex2i(200,430);
        glVertex2i(230,470);
        glVertex2i(350,460);
        glVertex2i(900,400);
        glVertex2i(580,470);
        glVertex2i(840,460);
        glVertex2i(750,400);
        glVertex2i(950,400);
        glVertex2i(760,420);
        glVertex2i(690,450);
        glVertex2i(550,470);
        glVertex2i(790,430);
        glVertex2i(830,470);
        glVertex2i(690,460);
        glVertex2i(590,400);
        glVertex2i(490,430);
        glVertex2i(330,470);
        glVertex2i(390,460);
        glVertex2i(460,400);
        glVertex2i(490,330);
        glVertex2i(330,370);
        glVertex2i(390,360);
        glVertex2i(460,300);
        glVertex2i(990,230);
        glVertex2i(930,370);
        glVertex2i(990,360);
        glVertex2i(960,300);
        glVertex2i(160,300);
        glVertex2i(190,230);
        glVertex2i(30,370);
        glVertex2i(290,360);
        glVertex2i(260,300);
        glVertex2i(0,300);
        glVertex2i(90,230);
        glVertex2i(130,370);
        glVertex2i(60,360);
        glVertex2i(80,300);
        glVertex2i(570,200);
        glVertex2i(600,230);
        glVertex2i(630,270);
        glVertex2i(590,260);
        glVertex2i(680,200);
        glEnd();

        glPopMatrix();
    }
}

///cloud1
void cloud1(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos1,170,0);
        cloudModel1();
        glPopMatrix();
    }
}
///cloud2
void cloud2(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos2,270,0);
        cloudModel2();
        glPopMatrix();
    }
}
///cloud3
void cloud3(){
    if(f){
        glPushMatrix();
        glTranslatef(cpos3,200,0);
        cloudModel3();
        glPopMatrix();
    }
}
///cloud4
void cloud4(){
    glPushMatrix();
    glTranslatef(cpos4,250,0);
    cloudModel2();
    glPopMatrix();
}

///cloud5
void cloud5(){
    glPushMatrix();
    glTranslatef(cpos5,220,0);
    cloudModel1();
    glPopMatrix();
}

///Airplane Design
void airPlane(){
    glPushMatrix();
    glTranslatef(plane_x,370,0);

    ///body
    if(f)glColor3ub(196, 190, 0);
    else glColor3ub(0, 51, 2);
    glBegin(GL_POLYGON);
    glVertex2i(100,100);
    glVertex2i(135,100);
    glVertex2i(135,112);
    glVertex2i(100,112);
    glEnd();
    ///Windows
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2i(107,104);
    glVertex2i(115,104);
    glVertex2i(115,110);
    glVertex2i(107,110);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(122,104);
    glVertex2i(130,104);
    glVertex2i(130,110);
    glVertex2i(122,110);
    glEnd();
    ///Head
    if(f)glColor3ub(255,0,0);
    else glColor3ub(82, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(135,100);
    glVertex2i(155,102);
    glVertex2i(135,112);
    glEnd();
    ///Pakha
    glBegin(GL_POLYGON);
    if(f)glColor3ub(255,0,0);
    glVertex2i(100,112);
    glVertex2i(110,112);
    glVertex2i(103,120);
    glVertex2i(100,120);
    glEnd();

    glPopMatrix();


}
void road(){
    ///Field
	glBegin(GL_POLYGON);
	 glColor3ub(96, 118, 130);
	glVertex2i(0, 80);
	glVertex2i(0, 180);
	glVertex2i(1000, 80);
	glVertex2i(1000, 180);
	glVertex2i(0, 180);


	glEnd();


}
void roadstrip(){

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(30, 135);
	glVertex2i(30, 125);
	glVertex2i(80, 135);
	glVertex2i(80, 125);
	glVertex2i(30, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(120, 135);
	glVertex2i(120, 125);
	glVertex2i(170, 135);
	glVertex2i(170, 125);
	glVertex2i(120, 125);
	glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(210, 135);
	glVertex2i(210, 125);
	glVertex2i(260, 135);
	glVertex2i(260, 125);
	glVertex2i(210, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(300, 135);
	glVertex2i(300, 125);
	glVertex2i(350, 135);
	glVertex2i(350, 125);
	glVertex2i(300, 125);
	glEnd();

    glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(390, 135);
	glVertex2i(390, 125);
	glVertex2i(440, 135);
	glVertex2i(440, 125);
	glVertex2i(390, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(480, 135);
	glVertex2i(480, 125);
	glVertex2i(530, 135);
	glVertex2i(530, 125);
	glVertex2i(480, 125);
	glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(570, 135);
	glVertex2i(570, 125);
	glVertex2i(620, 135);
	glVertex2i(620, 125);
	glVertex2i(570, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(660, 135);
	glVertex2i(660, 125);
	glVertex2i(710, 135);
	glVertex2i(710, 125);
	glVertex2i(660, 125);
	glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(750, 135);
	glVertex2i(750, 125);
	glVertex2i(800, 135);
	glVertex2i(800, 125);
	glVertex2i(750, 125);
	glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(840, 135);
	glVertex2i(840, 125);
	glVertex2i(890, 135);
	glVertex2i(890, 125);
	glVertex2i(840, 125);
    glEnd();

	glBegin(GL_POLYGON);
	 glColor3ub(225, 225, 1225);
	glVertex2i(930, 135);
	glVertex2i(930, 125);
	glVertex2i(980, 135);
	glVertex2i(980, 125);
	glVertex2i(930, 125);
	glEnd();
}

///Main
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0,0.0,1.0);

	sky();
	water();
	star();
	sun();
    moon();
    road();
    roadstrip();
    cloud1();
    cloud2();
    cloud3();
    cloud4();
    cloud5();
    airPlane();
    rightTillaL();
    rightWindmMill();
    rightBigHill1();
    rightBigHill2();
    rightTillaR();
    rightHouse();
    leftTillaL1();
    leftHillBig();
    leftSmallHill();
    leftWindMill();
    leftTillaR();
    leftHouse();
    pole1();
    pole2();
    pole3();
    pole4();
    pole5();
    field();
    carB();
    boatC();
    carA();



    tree1();
    tree2();
    tree3();
    tree4();
    tree5();
    tree6();
    tree7();
	glFlush();
}

void init(void){
	glClearColor(0.65, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void update(int value){
    ///spin+=0.1;
    ///Boat Control
    if(pos1<20)pos1=1000;
    if(pos2>980)pos2=-100;
    if(pos3<10)pos3=1000;
    pos1-=speed1;
    pos2+=speed2;
    pos3-=speed3;
    ///Cloud Control
    if(cpos1>750)cpos1=-320;
    if(cpos2<-350)cpos2=650;
    if(cpos3>750)cpos3=-320;
    if(cpos4>750)cpos4=-320;
    if(cpos5<-350)cpos5=650;
    cpos1+=sp1;
    cpos2-=sp1;
    cpos3+=sp1;
    cpos4+=sp1;
    cpos5-=sp1;
    ///Sun Control
    if(sun_y>480){
        sun_x=650;
        sun_y=290;
        f=0;
    }
    sun_x-=sp_x;
    sun_y+=sp_y;
    ///AirPlane Control
    if(plane_x>1000){
        plane_x=-100;
    }
    plane_x+=plane_speed;

    glutTimerFunc(100, update, 0);
    glutPostRedisplay();

}
void windMill_start(){
    spin+=0.1;
    glutPostRedisplay();
}

void handleMouse(int key, int state, int x, int y){
    switch (key){
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN){
                glutIdleFunc(windMill_start);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN){
                glutIdleFunc(NULL);
            }
            break;
        default:
            break;
    }
}
void handleKeypress(unsigned char key, int x, int y){
	switch (key){
        case 'd':
            f=1;
            break;
        case 'n':
            f=0;
            break;
        glutPostRedisplay();
	}
}
void credit(){

    cout<<"------------------------------------------------------"<<endl;
    cout<<"Computer Graphics-  Project"<<endl;
    cout<<"\t 1. CHAITHRA B C [1EW20CS025]"<<endl;
    cout<<"\t 2. CHANDAN B RAM [1EW20CS026]"<<endl;
    cout<<"------------------------------------------------------"<<endl;

}
int main(int argc, char** argv){
    credit();
    ///Music Background
    PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
    ///system("pause");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("CG Project- Smart Village");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
}
