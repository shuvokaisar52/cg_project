#include<windows.h>
#include<cstdio>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI           3.14159265358979323846
#include <GL/gl.h>
#include <GL/glu.h>


int triangleAmount = 100;
int lineAmount = 100;

GLfloat twicePi = 2.0f * PI;

int i;
float carX = 0.20;  // Initial X position of the car
float jetX = 1.40;
float jetX2 = 1.55;
float jetX3 = 1.55;
float cloudX = 0.0;
float cloudX1 = 1.8;
float jetFireX = 1.0;
bool startMovingCar = true;  // Flag to control car movement
bool startMovingCloud = true;  // Flag to control cloud movement
bool startMovingJet = true;  // Flag to control cloud movement
bool startMoviningJetFire = true;  // Flag to control cloud movement




void sound1(int value)
{
    PlaySound("fighter_jet_behind_355465_V1.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound2(int value)
{
    PlaySound("fighter_jet_behind_355465_V2.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound3(int value)
{
    PlaySound("fighter_jet_behind_355465_V3.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}



void drawGrassBlade(float x, float y, float height, float baseWidth, float topWidth, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x - baseWidth/2, y);
    glVertex2f(x + baseWidth/2, y);
    glVertex2f(x + topWidth/2, y + height);
    glVertex2f(x - topWidth/2, y + height);
    glEnd();
}



///display 1 airport code
// ---------- Moving Objects ----------

GLfloat cloudXD1 = 0.0f;
GLfloat cloudX1D1 = 1.8f;
GLfloat speedD1 = 0.01f;

GLfloat position5 = 0.0f;  // Missile truck
GLfloat speed5 = 0.01f;

GLfloat position6 = 0.0f;  // Military car
GLfloat speed6 = 0.01f;



GLfloat position7 = 0.8f;  // Jet
GLfloat y7 = -1.3f;
GLfloat speed7 = 0.01f;
GLfloat speed8 = 0.015f;

int elapsedFrames = 0;



// Flag to start movement
bool startMoving = false;



// --------- Timer Function (Moves All Objects) ---------

void updateObjects(int value) {

    if (!startMoving) return;
    // ----- Move Clouds -----

    if (cloudXD1 < -1.8f) cloudXD1 = 1.8f;
    if (cloudX1D1 < -1.8f) cloudX1D1 = 1.8f;

    cloudXD1 -= speedD1;
    cloudX1D1 -= speedD1;

    // ----- Move Missile Truck -----

    if (position5 < -1.85f) position5 = 1.85f;
    position5 -= speed5;

    // ----- Move Military Car -----

    if (position6 < -1.85f) position6 = 1.85f;
    position6 -= speed6;

    // ----- Move Jet -----

    elapsedFrames++;

    if (position7 < -1.85f) {  // Reset jet if out of bounds
        position7 = 1.85f;
        y7 = -1.3f;
        elapsedFrames = 0;
    }
    if (elapsedFrames <= 49) {
        position7 -= speed7;
    }
    else if (y7 < 0.1f) {
        position7 -= speed7;
        y7 += speed8;
    }
    else {
        position7 -= speed7;
    }



    glutPostRedisplay();
    glutTimerFunc(60, updateObjects, 0); // ~60 FPS

}




///display 3 code
float jetXD3 = 1.40;
float jetX2D3 = 1.55;
float jetX3D3 = 1.55;
GLfloat cloudXD3 = 0.0f;
GLfloat cloudX1D3 = 1.8f;
GLfloat boatX = -0.5f;
GLfloat speedD3 = 0.01f;
bool startMovingBoatD3 = true;
bool startMovingJetD3 = true;
bool startMovingCloudD3 = true;





void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void timerD3(int value) {
    if (startMovingBoatD3) {
        boatX+=0.006;
        if (boatX < -1.8) {
            boatX = 1.80;
        }
    }
    if (startMovingCloudD3) {
        cloudXD3 -= 0.01;  // Decrement X position to move the cloud to the left
        if (cloudXD3 < -1.80) {
            cloudXD3 = 1.8;  // Reset cloud position when it goes off-screen
        }

        cloudX1D3 -= 0.01;  // Decrement X position to move the cloud to the left
        if (cloudX1D3 < -1.80) {
            cloudX1D3 = 1.8;  // Reset cloud position when it goes off-screen
        }
    }
    if (startMovingJetD3) {
        jetXD3 -= 0.0155;  // Decrement X position to move the cloud to the left
        if (jetXD3 < -1.80) {
            jetXD3 = 1.8;  // Reset cloud position when it goes off-screen
        }

        jetX2D3 -= 0.0155;  // Decrement X position to move the cloud to the left
        if (jetX2D3 < -1.80) {
            jetX2D3 = 1.8;  // Reset cloud position when it goes off-screen
        }

        jetX3D3 -= 0.0155;  // Decrement X position to move the cloud to the left
        if (jetX3D3 < -1.80) {
            jetX3D3 = 1.8;  // Reset cloud position when it goes off-screen
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, timerD3, 0);  // Call the timer function again after 16ms (approx. 60 FPS)

}


void timer(int value) {
    if (startMovingCar) {
        carX += 0.0025;
        if (carX > 1.8) {
            carX = -1.50;
        }
    }
    if (startMovingCloud) {
        cloudX -= 0.001;  // Decrement X position to move the cloud to the left
        if (cloudX < -1.80) {
            cloudX = 1.8;  // Reset cloud position when it goes off-screen
        }

        cloudX1 -= 0.001;  // Decrement X position to move the cloud to the left
        if (cloudX1 < -1.80) {
            cloudX1 = 1.8;  // Reset cloud position when it goes off-screen
        }
    }
    if (startMovingJet) {
        jetX -= 0.0032;  // Decrement X position to move the cloud to the left
        if (jetX < -1.80) {
            jetX = 1.8;  // Reset cloud position when it goes off-screen
        }

        jetX2 -= 0.0032;  // Decrement X position to move the cloud to the left
        if (jetX2 < -1.80) {
            jetX2 = 1.8;  // Reset cloud position when it goes off-screen
        }

        jetX3 -= 0.0032;  // Decrement X position to move the cloud to the left
        if (jetX3 < -1.80) {
            jetX3 = 1.8;  // Reset cloud position when it goes off-screen
        }
    }
    if (startMoviningJetFire) {
        jetFireX += 0.005;  // Decrement X position to move the cloud to the left
        if (jetFireX < 1.5) {
            jetFireX = 1.0;  // Reset cloud position when it goes off-screen
        }
    }
    glutPostRedisplay();
    glutTimerFunc(15, timer, 0);  // Call the timer function again after 16ms (approx. 60 FPS)
}

///___________________________________________________Voids___________________________________________________///


void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
}



///___________________________________________________start___________________________________________________///

void village_design(){
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // ================= SKY =================
    glBegin(GL_QUADS);
    glColor3f(0.35f, 0.65f, 1.00f);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glColor3f(0.68f, 0.86f, 1.00f);
    glVertex2f(1, -0.30f);
    glVertex2f(-1, -0.30f);
    glEnd();


    //------------------Sun---------------------
glColor3f(1.0f, 1.0f, 0.3f); // bright center
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.7f, 0.8f); // center after transformation
    for (int i = 0; i <= 50; i++) {
        glColor3f(1.0f, 0.9f, 0.4f); // edge softer yellow
        glVertex2f(
            0.1f * cosf(2.0f * 3.14159f * i / 50) - 0.7f,
            0.1f * sinf(2.0f * 3.14159f * i / 50) + 0.8f
        );
    }
glEnd();


    // ================= GROUND =================
    glColor3f(0.30f, 0.70f, 0.30f);
    glBegin(GL_QUADS);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.5f);
    glVertex2f(-1, -0.5f);
    glEnd();

    // ================= RIVER (Straight Area with Curvy Water) =================
    glColor3f(0.20f, 0.50f, 0.90f);
    glBegin(GL_QUADS);
    glVertex2f(-1, -0.5f);
    glVertex2f(1, -0.5f);
    glVertex2f(1, -0.3f);
    glVertex2f(-1, -0.3f);
    glEnd();

    glColor3f(0.3f, 0.6f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 100; i++) {
        float x = -1.0f + (2.0f * i / 100.0f);
        glVertex2f(x, -0.4f + 0.01f * sinf(x * 12.0f));
    }
    glEnd();


    // ================= INLINE GRASS DRAWING =================

    // --- New Grass Patches on the Far Bank ---
    // This grass will appear behind the buildings on the other side of the river.
    float farGrassY = 0.15f; // This variable is not used, causing the warning
    for (float x = -1.0f; x < 1.0f; x += 0.008f) {
        float height = 0.02f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 0.03f));
        float rotation = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 30.0f)) - 15.0f;

        glPushMatrix();
        glTranslatef(x, -0.50f, 0.0f);
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);
        drawGrassBlade(0, 0, height, 0.005f, 0.001f, 0.20f, 0.55f, 0.20f);
        glPopMatrix();
    }


// ================= BOAT =================
glPushMatrix();
glTranslatef(boatX, 0.0f, 0.0f);

   glColor3ub(0, 0, 0); // Black
glBegin(GL_POLYGON);
    glVertex2d(0.04,-0.326);
    glVertex2d(0.19,-0.398);
    glVertex2d(0.36,-0.326);
    glVertex2d(0.245,-0.35);
    glVertex2d(0.135,-0.35);
    glVertex2d(0.04,-0.326);
glEnd();

glColor3ub(0, 0, 0); // Black
glBegin(GL_POLYGON);
    glVertex2d(0.04,-0.326);
    glVertex2d(0.06,-0.374);
    glVertex2d(0.09,-0.414);
    glVertex2d(0.305,-0.414);
    glVertex2d(0.335,-0.382);
    glVertex2d(0.36,-0.326);
glEnd();

glColor3f(0.51, 0.25, 0.16);
glBegin(GL_POLYGON);
    glVertex2d(0.04,-0.326);
    glVertex2d(0.16,-0.342);
    glVertex2d(0.27,-0.342);
    glVertex2d(0.36,-0.326);
    glVertex2d(0.245,-0.35);
    glVertex2d(0.135,-0.35);
glEnd();

glLineWidth(4);
glColor3ub(0, 0, 0); // Black
glBegin(GL_LINES);
    glVertex2d(0.2,-0.038);
    glVertex2d(0.2,-0.358);
glEnd();

glColor3ub(220, 220, 220);
glBegin(GL_POLYGON);
    glVertex2d(0.155,-0.23);
    glVertex2d(0.145,-0.334);
    glVertex2d(0.17,-0.326);
    glVertex2d(0.2,-0.326);
    glVertex2d(0.19,-0.262);
glEnd();

glColor3ub(220, 220, 220);
glBegin(GL_QUADS);
    glVertex2d(0.155,-0.23);
    glVertex2d(0.19,-0.262);
    glVertex2d(0.19,-0.158);
    glVertex2d(0.18,-0.118);
glEnd();

glColor3ub(220, 220, 220);
glBegin(GL_TRIANGLES);
    glVertex2d(0.18,-0.118);
    glVertex2d(0.19,-0.158);
    glVertex2d(0.2,-0.054);
glEnd();

glColor3ub(220, 220, 220);
glBegin(GL_POLYGON);
    glVertex2d(0.2,-0.062);
    glVertex2d(0.23,-0.134);
    glVertex2d(0.29,-0.246);
    glVertex2d(0.2,-0.326);
glEnd();

glColor3ub(220, 220, 220);
glBegin(GL_POLYGON);
    glVertex2d(0.2,-0.326);
    glVertex2d(0.29,-0.246);
    glVertex2d(0.345,-0.31);
    glVertex2d(0.3,-0.326);
    glVertex2d(0.255,-0.334);
glEnd();

glLineWidth(2);
glColor3ub(0, 0, 0); // Black
glBegin(GL_LINES);
    glVertex2d(0.345,-0.31);
    glVertex2d(0.36,-0.326);
glEnd();




// Boat hull (black)
// Boatman (Majhi)
    // Body

     glColor3f(0.87f, 0.02f, 0.07f);  // Black
glBegin(GL_QUADS);
    glVertex2d(0.075, -0.336);
    glVertex2d(0.07, -0.32);
    glVertex2d(0.085, -0.312);
    glVertex2d(0.085, -0.328);
glEnd();

// Head (Body and Head Polygon)
glColor3f(1.0f, 0.81f, 0.37f); // Black
glBegin(GL_POLYGON);
    glVertex2d(0.085, -0.328);
    glVertex2d(0.085, -0.312);
    glVertex2d(0.095, -0.328);
    glVertex2d(0.095, -0.336);
    glVertex2d(0.09, -0.336);
glEnd();

// Arms
glColor3f(0.87f, 0.02f, 0.07f);  // Black
// Arm 1
glBegin(GL_POLYGON);
    glVertex2d(0.075, -0.336);
    glVertex2d(0.07, -0.32);
    glVertex2d(0.06, -0.328);
glEnd();

// Arm 2
glColor3f(0.87f, 0.02f, 0.07f);  // Black
glBegin(GL_POLYGON);
    glVertex2d(0.07, -0.32);
    glVertex2d(0.06, -0.32);
    glVertex2d(0.06, -0.328);
glEnd();

// Arm Quad
glColor3f(0.87f, 0.02f, 0.07f);  // Black
glBegin(GL_QUADS);
    glVertex2d(0.07, -0.32);
    glVertex2d(0.075, -0.312);
    glVertex2d(0.065, -0.296);
    glVertex2d(0.06, -0.32);
glEnd();

// Head continuation
glColor3f(1.0f, 0.81f, 0.37f); // Black
glBegin(GL_POLYGON);
    glVertex2d(0.075, -0.312);
    glVertex2d(0.08, -0.312);
    glVertex2d(0.08, -0.304);
glEnd();

// Head line loops
glColor3f(1.0f, 0.81f, 0.37f); // Black
// Head Line Loop 1
glBegin(GL_LINE_LOOP);
    glVertex2d(0.08, -0.312);
    glVertex2d(0.085, -0.312);
    glVertex2d(0.095, -0.304);
    glVertex2d(0.095, -0.312);
glEnd();

// Head Line Loop 2
glColor3f(1.0f, 0.81f, 0.37f); // Black
glBegin(GL_LINE_LOOP);
    glVertex2d(0.095, -0.312);
    glVertex2d(0.095, -0.304);
    glVertex2d(0.08, -0.312);
glEnd();

// Shoulder Quad
glColor3f(0.87f, 0.02f, 0.07f);  // Black
glBegin(GL_QUADS);
    glVertex2d(0.065, -0.296);
    glVertex2d(0.07, -0.296);
    glVertex2d(0.08, -0.304);
    glVertex2d(0.075, -0.312);
glEnd();

// Neck/Body Polygon
glColor3f(0.87f, 0.02f, 0.07f);  // Black
glBegin(GL_POLYGON);
    glVertex2d(0.085, -0.328);
    glVertex2d(0.08, -0.304);
    glVertex2d(0.08, -0.296);
    glVertex2d(0.07, -0.296);
glEnd();

// Additional head line loops
glColor3f(1.0f, 0.81f, 0.37f); // Black
// Head Line Loop 3
glBegin(GL_LINE_LOOP);
    glVertex2d(0.08, -0.304);
    glVertex2d(0.09, -0.296);
glEnd();

// Head Line Loop 4
glColor3f(1.0f, 0.81f, 0.37f);// Black
glBegin(GL_LINE_LOOP);
    glVertex2d(0.08, -0.304);
    glVertex2d(0.09, -0.296);
glEnd();


   // Circle for the boatman's head (filled with black)
float centerX = -0.0311f + 0.1f;  // 0.0689
float centerY = 0.16264f - 0.45f; // -0.28736
float radius = 0.00675f;          // Keep radius same

glColor3f(1.0f, 0.81f, 0.37f); // Set color
int numSegments = 100; // Number of segments for the circle
glBegin(GL_POLYGON); // Use GL_POLYGON to fill the circle

for (int i = 0; i < numSegments; i++) {
    float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
    float x = radius * cosf(theta);
    float y = radius * sinf(theta);
    glVertex2f(x + centerX, y + centerY);
}

glEnd();

    // Additional line details
glLineWidth(4);
glColor3ub(101, 67, 33); // deep brown
glBegin(GL_LINES);
glEnd();

// Final line
glLineWidth(4);
glColor3ub(101, 67, 33); // deep brown
glBegin(GL_LINES);
    glVertex2d(0.09, -0.25);   // Start of line
    glVertex2d(0.04, -0.41);   // End of line (paddle)
glEnd();

glPopMatrix();

  /*   // ================= V-SHAPED BIRDS =================

    // ======================== Bird 1 (Left side) ========================
glColor3f(0.1f, 0.1f, 0.1f); // Dark gray

// Body
glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++) {
    float theta = 2.0f * 3.1415926f * float(i) / 100.0f;
    float x = (0.05f * cosf(theta) - 0.6f) * 0.15f;
    float y = (0.08f * sinf(theta) + 1.9f) * 0.15f;
    glVertex2f(x, y);
}
glEnd();

// Left wing
glBegin(GL_TRIANGLES);
glVertex2f((-0.05f - 0.6f) * 0.15f, (0.08f + 1.9f) * 0.15f);
glVertex2f((-0.2f - 0.6f) * 0.15f, (0.2f + 1.9f) * 0.15f);
glVertex2f((-0.05f - 0.6f) * 0.15f, (0.0f + 1.9f) * 0.15f);
glEnd();

// Right wing
glBegin(GL_TRIANGLES);
glVertex2f((0.05f - 0.6f) * 0.15f, (0.08f + 1.9f) * 0.15f);
glVertex2f((0.2f - 0.6f) * 0.15f, (0.2f + 1.9f) * 0.15f);
glVertex2f((0.05f - 0.6f) * 0.15f, (0.0f + 1.9f) * 0.15f);
glEnd();

// Tail
glBegin(GL_TRIANGLES);
glVertex2f((0.0f - 0.6f) * 0.15f, (-0.08f + 1.9f) * 0.15f);
glVertex2f((-0.05f - 0.6f) * 0.15f, (-0.15f + 1.9f) * 0.15f);
glVertex2f((0.05f - 0.6f) * 0.15f, (-0.15f + 1.9f) * 0.15f);
glEnd();


// ======================== Bird 2 (Center of V) ========================
glColor3f(0.1f, 0.1f, 0.1f);

// Body
glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++) {
    float theta = 2.0f * 3.1415926f * float(i) / 100.0f;
    float x = (0.05f * cosf(theta) - 0.2f) * 0.15f;
    float y = (0.08f * sinf(theta) + 1.7f) * 0.15f;
    glVertex2f(x, y);
}
glEnd();

// Left wing
glBegin(GL_TRIANGLES);
glVertex2f((-0.05f - 0.2f) * 0.15f, (0.08f + 1.7f) * 0.15f);
glVertex2f((-0.2f - 0.2f) * 0.15f, (0.2f + 1.7f) * 0.15f);
glVertex2f((-0.05f - 0.2f) * 0.15f, (0.0f + 1.7f) * 0.15f);
glEnd();

// Right wing
glBegin(GL_TRIANGLES);
glVertex2f((0.05f - 0.2f) * 0.15f, (0.08f + 1.7f) * 0.15f);
glVertex2f((0.2f - 0.2f) * 0.15f, (0.2f + 1.7f) * 0.15f);
glVertex2f((0.05f - 0.2f) * 0.15f, (0.0f + 1.7f) * 0.15f);
glEnd();

// Tail
glBegin(GL_TRIANGLES);
glVertex2f((0.0f - 0.2f) * 0.15f, (-0.08f + 1.7f) * 0.15f);
glVertex2f((-0.05f - 0.2f) * 0.15f, (-0.15f + 1.7f) * 0.15f);
glVertex2f((0.05f - 0.2f) * 0.15f, (-0.15f + 1.7f) * 0.15f);
glEnd();


// ======================== Bird 3 (Right side) ========================
glColor3f(0.1f, 0.1f, 0.1f);

// Body
glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++) {
    float theta = 2.0f * 3.1415926f * float(i) / 100.0f;
    float x = (0.05f * cosf(theta) + 0.2f) * 0.15f;
    float y = (0.08f * sinf(theta) + 1.9f) * 0.15f;
    glVertex2f(x, y);
}
glEnd();

// Left wing
glBegin(GL_TRIANGLES);
glVertex2f((-0.05f + 0.2f) * 0.15f, (0.08f + 1.9f) * 0.15f);
glVertex2f((-0.2f + 0.2f) * 0.15f, (0.2f + 1.9f) * 0.15f);
glVertex2f((-0.05f + 0.2f) * 0.15f, (0.0f + 1.9f) * 0.15f);
glEnd();

// Right wing
glBegin(GL_TRIANGLES);
glVertex2f((0.05f + 0.2f) * 0.15f, (0.08f + 1.9f) * 0.15f);
glVertex2f((0.2f + 0.2f) * 0.15f, (0.2f + 1.9f) * 0.15f);
glVertex2f((0.05f + 0.2f) * 0.15f, (0.0f + 1.9f) * 0.15f);
glEnd();

// Tail
glBegin(GL_TRIANGLES);
glVertex2f((0.0f + 0.2f) * 0.15f, (-0.08f + 1.9f) * 0.15f);
glVertex2f((-0.05f + 0.2f) * 0.15f, (-0.15f + 1.9f) * 0.15f);
glVertex2f((0.05f + 0.2f) * 0.15f, (-0.15f + 1.9f) * 0.15f);
glEnd();

*/

    // Main Road

    glColor3f(0.25f, 0.52f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(0.7f, -0.56f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-1.0f, -0.94f);
    glVertex2f(0.9f, -0.56f);
    glEnd();


    //Mosque Road
    glColor3f(0.25f, 0.52f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(-0.66f, -0.56f);
    glVertex2f(-0.56f, -0.56f);
    glVertex2f(-0.56f, -0.76f);
    glVertex2f(-0.66f, -0.76f);
    glEnd();

    // ================= DENSE SMALL CORN FIELD =================
    glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(0.65f, -0.98f);
    glVertex2f(0.98f, -0.98f);
    glVertex2f(0.98f, -0.7f);
    glVertex2f(0.65f, -0.7f);
glEnd();

// Grid of trees
for (int col = 0; col < 12; col++) {
    for (int row = 0; row < 6; row++) {
        // Tree trunk
        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f) - 0.002f, -0.98f + row * ((-0.7f + 0.98f) / 5.0f));
            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f) + 0.002f, -0.98f + row * ((-0.7f + 0.98f) / 5.0f));
            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f) + 0.002f, -0.98f + row * ((-0.7f + 0.98f) / 5.0f) + 0.05f);
            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f) - 0.002f, -0.98f + row * ((-0.7f + 0.98f) / 5.0f) + 0.05f);
        glEnd();

        // Tree leaves (triangle)
        glColor3f(0.0f, 0.7f, 0.0f);
        glBegin(GL_TRIANGLES);
            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f), -0.98f + row * ((-0.7f + 0.98f) / 5.0f) + 0.04f);
            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f) - 0.02f, -0.98f + row * ((-0.7f + 0.98f) / 5.0f) + 0.012f);
            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f), -0.98f + row * ((-0.7f + 0.98f) / 5.0f) + 0.012f);

            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f), -0.98f + row * ((-0.7f + 0.98f) / 5.0f) + 0.04f);
            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f) + 0.02f, -0.98f + row * ((-0.7f + 0.98f) / 5.0f) + 0.012f);
            glVertex2f(0.65f + col * ((0.98f - 0.65f) / 11.0f), -0.98f + row * ((-0.7f + 0.98f) / 5.0f) + 0.012f);
        glEnd();

        // Tree fruit (small circle)
        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        for (int k = 0; k < 20; k++) {
            float angle = 2.0f * PI * k / 20;
            glVertex2f(
                0.65f + col * ((0.98f - 0.65f) / 11.0f) + 0.01f * cosf(angle),
                -0.98f + row * ((-0.7f + 0.98f) / 5.0f) + 0.05f + 0.01f * sinf(angle)
            );
        }
        glEnd();
    }
}




    // ================= MOSQUE =================
glColor3f(0.85f, 0.70f, 0.50f);
glBegin(GL_QUADS);
glVertex2f(-0.88f, -0.60f);
glVertex2f(-0.32f, -0.60f);
glVertex2f(-0.32f, -0.55f);
glVertex2f(-0.88f, -0.55f);
glEnd();
glColor3f(0.88f, 0.74f, 0.54f);
glBegin(GL_QUADS);
glVertex2f(-0.866f, -0.55f);
glVertex2f(-0.334f, -0.55f);
glVertex2f(-0.334f, -0.52f);
glVertex2f(-0.866f, -0.52f);
glEnd();
glColor3f(0.85f, 0.70f, 0.50f);
glBegin(GL_QUADS);
glVertex2f(-0.852f, -0.52f);
glVertex2f(-0.348f, -0.52f);
glVertex2f(-0.348f, -0.50f);
glVertex2f(-0.852f, -0.50f);
glEnd();
glColor3f(0.95f, 0.95f, 0.95f);
glBegin(GL_QUADS);
glVertex2f(-0.852f, -0.50f);
glVertex2f(-0.348f, -0.50f);
glVertex2f(-0.348f, -0.03f);
glVertex2f(-0.852f, -0.03f);
glEnd();
// ================= NEW MOSQUE DOOR DESIGN =================
glColor3f(0.55f, 0.35f, 0.20f);
glBegin(GL_QUADS);
glVertex2f(-0.685f, -0.50f);
glVertex2f(-0.515f, -0.50f);
glVertex2f(-0.515f, -0.20f);
glVertex2f(-0.685f, -0.20f);
glEnd();
glBegin(GL_POLYGON);
for (int i = 0; i <= 30; i++) {
    float angle = PI * i / 30;
    glVertex2f(-0.60f + (0.15f / 2.0f + 0.01f) * cosf(angle), -0.50f + 0.35f - 0.05f + (0.05f + 0.01f) * sinf(angle));
}
glEnd();
glColor3f(0.40f, 0.20f, 0.05f);
glBegin(GL_QUADS);
glVertex2f(-0.675f, -0.50f);
glVertex2f(-0.525f, -0.50f);
glVertex2f(-0.525f, -0.20f);
glVertex2f(-0.675f, -0.20f);
glEnd();
glBegin(GL_POLYGON);
for (int i = 0; i <= 30; i++) {
    float angle = PI * i / 30;
    glVertex2f(-0.60f + (0.15f / 2.0f) * cosf(angle), -0.50f + 0.35f - 0.05f + 0.05f * sinf(angle));
}
glEnd();
glColor3f(0.85f, 0.7f, 0.5f);
glBegin(GL_QUADS);
glVertex2f(-0.62f, -0.38f);
glVertex2f(-0.58f, -0.38f);
glVertex2f(-0.58f, -0.35f);
glVertex2f(-0.62f, -0.35f);
glEnd();
glColor3f(0.6f, 0.35f, 0.15f);
glBegin(GL_QUADS);
glVertex2f(-0.66f, -0.45f);
glVertex2f(-0.63f, -0.45f);
glVertex2f(-0.63f, -0.25f);
glVertex2f(-0.66f, -0.25f);
glEnd();
glBegin(GL_QUADS);
glVertex2f(-0.57f, -0.45f);
glVertex2f(-0.54f, -0.45f);
glVertex2f(-0.54f, -0.25f);
glVertex2f(-0.57f, -0.25f);
glEnd();
// ================= END NEW DOOR DESIGN =================
// Mosque Stairs
glColor3f(0.6f, 0.6f, 0.6f);
glBegin(GL_QUADS);
glVertex2f(-0.60f - 0.1f, -0.50f);
glVertex2f(-0.60f + 0.1f, -0.50f);
glVertex2f(-0.60f + 0.1f, -0.55f);
glVertex2f(-0.60f - 0.1f, -0.55f);
glEnd();
// Mosque Windows (Restored)
glColor3f(0.7f, 0.9f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(-0.8035f, -0.35f);
glVertex2f(-0.7235f, -0.35f);
glVertex2f(-0.7235f, -0.20f);
glVertex2f(-0.8035f, -0.20f);
glEnd();
glColor3f(0.3f, 0.5f, 0.6f);
glLineWidth(2.0f);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.8035f, -0.35f);
glVertex2f(-0.7235f, -0.35f);
glVertex2f(-0.7235f, -0.20f);
glVertex2f(-0.8035f, -0.20f);
glEnd();
glLineWidth(1.5f);
glBegin(GL_LINES);
glVertex2f(-0.7635f, -0.35f);
glVertex2f(-0.7635f, -0.20f);
glVertex2f(-0.8035f, -0.275f);
glVertex2f(-0.7235f, -0.275f);
glEnd();
glColor3f(0.7f, 0.9f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(-0.4765f, -0.35f);
glVertex2f(-0.3965f, -0.35f);
glVertex2f(-0.3965f, -0.20f);
glVertex2f(-0.4765f, -0.20f);
glEnd();
glColor3f(0.3f, 0.5f, 0.6f);
glLineWidth(2.0f);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.4765f, -0.35f);
glVertex2f(-0.3965f, -0.35f);
glVertex2f(-0.3965f, -0.20f);
glVertex2f(-0.4765f, -0.20f);
glEnd();
glLineWidth(1.5f);
glBegin(GL_LINES);
glVertex2f(-0.4365f, -0.35f);
glVertex2f(-0.4365f, -0.20f);
glVertex2f(-0.4765f, -0.275f);
glVertex2f(-0.3965f, -0.275f);
glEnd();
// ================= END WINDOWS =================
// Mosque border
glColor3f(0, 0, 0);
glLineWidth(2.0f);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.852f, -0.50f);
glVertex2f(-0.348f, -0.50f);
glVertex2f(-0.348f, -0.03f);
glVertex2f(-0.852f, -0.03f);
glEnd();
// =================Domes=======================
glColor3f(0.00f, 0.55f, 0.35f);
glBegin(GL_POLYGON);
for (int i = 0; i <= 60; i++) {
    float t = PI * i / 60;
    glVertex2f(-0.60f + 0.28f * 0.7f * cosf(t), -0.03f + 0.28f * 0.7f * sinf(t));
}
glVertex2f(-0.60f, -0.03f + 0.3f * 0.7f * 1.15f);
glEnd();
glColor3f(0, 0, 0);
glLineWidth(2.0f);
glBegin(GL_LINE_STRIP);
for (int i = 0; i <= 60; i++) {
    float t = PI * i / 60;
    glVertex2f(-0.60f + 0.28f * 0.7f * cosf(t), -0.03f + 0.28f * 0.7f * sinf(t));
}
glEnd();
glColor3f(0.00f, 0.55f, 0.35f);
glBegin(GL_POLYGON);
for (int i = 0; i <= 48; i++) {
    float t = PI * i / 48;
    glVertex2f(-0.60f - 0.23f * 0.7f + 0.17f * 0.7f * cosf(t), -0.07f + 0.17f * 0.7f * sinf(t));
}
glVertex2f(-0.60f - 0.23f * 0.7f, -0.07f + 0.17f * 0.7f * 1.15f);
glEnd();
glColor3f(0, 0, 0);
glLineWidth(2.0f);
glBegin(GL_LINE_STRIP);
for (int i = 0; i <= 48; i++) {
    float t = PI * i / 48;
    glVertex2f(-0.60f - 0.23f * 0.7f + 0.17f * 0.7f * cosf(t), -0.07f + 0.17f * 0.7f * sinf(t));
}
glEnd();
glColor3f(0.00f, 0.55f, 0.35f);
glBegin(GL_POLYGON);
for (int i = 0; i <= 48; i++) {
    float t = PI * i / 48;
    glVertex2f(-0.60f + 0.23f * 0.7f + 0.17f * 0.7f * cosf(t), -0.07f + 0.17f * 0.7f * sinf(t));
}
glVertex2f(-0.60f + 0.23f * 0.7f, -0.07f + 0.17f * 0.7f * 1.15f);
glEnd();
glColor3f(0, 0, 0);
glLineWidth(2.0f);
glBegin(GL_LINE_STRIP);
for (int i = 0; i <= 48; i++) {
    float t = PI * i / 48;
    glVertex2f(-0.60f + 0.23f * 0.7f + 0.17f * 0.7f * cosf(t), -0.07f + 0.17f * 0.7f * sinf(t));
}
glEnd();
glColor3f(0.90f, 0.88f, 0.80f);
glBegin(GL_POLYGON);
glVertex2f(-0.98f, -0.60f);
glVertex2f(-0.92f, -0.60f);
glVertex2f(-0.92f, -0.04f);
glVertex2f(-0.98f, -0.04f);
glEnd();
glColor3f(0.80f, 0.68f, 0.55f);
glBegin(GL_QUADS);
glVertex2f(-0.9675f, -0.60f);
glVertex2f(-0.9625f, -0.60f);
glVertex2f(-0.9625f, -0.04f);
glVertex2f(-0.9675f, -0.04f);
glEnd();
glBegin(GL_QUADS);
glVertex2f(-0.9525f, -0.60f);
glVertex2f(-0.9475f, -0.60f);
glVertex2f(-0.9475f, -0.04f);
glVertex2f(-0.9525f, -0.04f);
glEnd();
glBegin(GL_QUADS);
glVertex2f(-0.9375f, -0.60f);
glVertex2f(-0.9325f, -0.60f);
glVertex2f(-0.9325f, -0.04f);
glVertex2f(-0.9375f, -0.04f);
glEnd();
float positions[3] = {0.15f, 0.35f, 0.50f};
for (int i = 0; i < 3; i++) {
    float cy = -0.60f + 0.8f * 0.7f * positions[i];
    glColor3f(0.80f, 0.68f, 0.55f);
    glBegin(GL_QUADS);
    glVertex2f(-0.60f - 0.5f * 0.7f - 0.03f, cy - 0.01f * 0.5f);
    glVertex2f(-0.60f - 0.5f * 0.7f + 0.03f, cy - 0.01f * 0.5f);
    glVertex2f(-0.60f - 0.5f * 0.7f + 0.03f, cy + 0.01f * 0.5f);
    glVertex2f(-0.60f - 0.5f * 0.7f - 0.03f, cy + 0.01f * 0.5f);
    glEnd();
}
float windowCols[3] = {0.25f, 0.42f, 0.65f};
for (int i = 0; i < 3; i++) {
    float wy = -0.60f + 0.8f * 0.7f * windowCols[i];
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.60f - 0.5f * 0.7f - 0.015f * 0.5f, wy - 0.8f * 0.7f * 0.08f * 0.5f);
    glVertex2f(-0.60f - 0.5f * 0.7f + 0.015f * 0.5f, wy - 0.8f * 0.7f * 0.08f * 0.5f);
    glVertex2f(-0.60f - 0.5f * 0.7f + 0.015f * 0.5f, wy + 0.8f * 0.7f * 0.08f * 0.5f);
    glVertex2f(-0.60f - 0.5f * 0.7f - 0.015f * 0.5f, wy + 0.8f * 0.7f * 0.08f * 0.5f);
    glEnd();
}
glColor3f(0.85f, 0.70f, 0.50f);
glBegin(GL_QUADS);
glVertex2f(-0.985f, -0.292f);
glVertex2f(-0.915f, -0.292f);
glVertex2f(-0.915f, -0.264f);
glVertex2f(-0.985f, -0.264f);
glEnd();
glColor3f(0.35f, 0.35f, 0.35f);
glBegin(GL_TRIANGLES);
glVertex2f(-1.00f, -0.04f);
glVertex2f(-0.90f, -0.04f);
glVertex2f(-0.95f, 0.06f);
glEnd();
// Right Minaret
glColor3f(0.90f, 0.88f, 0.80f);
glBegin(GL_POLYGON);
glVertex2f(-0.28f, -0.60f);
glVertex2f(-0.22f, -0.60f);
glVertex2f(-0.22f, -0.04f);
glVertex2f(-0.28f, -0.04f);
glEnd();
glColor3f(0.80f, 0.68f, 0.55f);
glBegin(GL_QUADS);
glVertex2f(-0.2675f, -0.60f);
glVertex2f(-0.2625f, -0.60f);
glVertex2f(-0.2625f, -0.04f);
glVertex2f(-0.2675f, -0.04f);
glEnd();
glBegin(GL_QUADS);
glVertex2f(-0.2525f, -0.60f);
glVertex2f(-0.2475f, -0.60f);
glVertex2f(-0.2475f, -0.04f);
glVertex2f(-0.2525f, -0.04f);
glEnd();
glBegin(GL_QUADS);
glVertex2f(-0.2375f, -0.60f);
glVertex2f(-0.2325f, -0.60f);
glVertex2f(-0.2325f, -0.04f);
glVertex2f(-0.2375f, -0.04f);
glEnd();
for (int i = 0; i < 3; i++) {
    float cy = -0.60f + 0.8f * 0.7f * positions[i];
    glColor3f(0.80f, 0.68f, 0.55f);
    glBegin(GL_QUADS);
    glVertex2f(-0.60f + 0.5f * 0.7f - 0.03f, cy - 0.01f * 0.5f);
    glVertex2f(-0.60f + 0.5f * 0.7f + 0.03f, cy - 0.01f * 0.5f);
    glVertex2f(-0.60f + 0.5f * 0.7f + 0.03f, cy + 0.01f * 0.5f);
    glVertex2f(-0.60f + 0.5f * 0.7f - 0.03f, cy + 0.01f * 0.5f);
    glEnd();
}
for (int i = 0; i < 3; i++) {
    float wy = -0.60f + 0.8f * 0.7f * windowCols[i];
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-0.60f + 0.5f * 0.7f - 0.015f * 0.5f, wy - 0.8f * 0.7f * 0.08f * 0.5f);
    glVertex2f(-0.60f + 0.5f * 0.7f + 0.015f * 0.5f, wy - 0.8f * 0.7f * 0.08f * 0.5f);
    glVertex2f(-0.60f + 0.5f * 0.7f + 0.015f * 0.5f, wy + 0.8f * 0.7f * 0.08f * 0.5f);
    glVertex2f(-0.60f + 0.5f * 0.7f - 0.015f * 0.5f, wy + 0.8f * 0.7f * 0.08f * 0.5f);
    glEnd();
}
glColor3f(0.85f, 0.70f, 0.50f);
glBegin(GL_QUADS);
glVertex2f(-0.285f, -0.292f);
glVertex2f(-0.215f, -0.292f);
glVertex2f(-0.215f, -0.264f);
glVertex2f(-0.285f, -0.264f);
glEnd();
glColor3f(0.35f, 0.35f, 0.35f);
glBegin(GL_TRIANGLES);
glVertex2f(-0.30f, -0.04f);
glVertex2f(-0.20f, -0.04f);
glVertex2f(-0.25f, 0.06f);
glEnd();


     //=========================Tree(sir)=====================

glColor3f(0.27f, 0.18f, 0.06f);
glBegin(GL_QUADS);
glVertex2f(0.376f, -0.528f);
glVertex2f(0.394f, -0.51f);
glVertex2f(0.4165f, -0.492f);
glVertex2f(0.4255f, -0.528f);
glVertex2f(0.4255f, -0.528f);
glVertex2f(0.4525f, -0.51f);
glVertex2f(0.466f, -0.555f);
glVertex2f(0.4525f, -0.546f);
glVertex2f(0.4525f, -0.528f);
glVertex2f(0.466f, -0.492f);
glVertex2f(0.511f, -0.537f);
glVertex2f(0.4885f, -0.546f);
glVertex2f(0.4075f, -0.528f);
glVertex2f(0.4165f, -0.456f);
glVertex2f(0.466f, -0.447f);
glVertex2f(0.4795f, -0.528f);
glVertex2f(0.4165f, -0.456f);
glVertex2f(0.466f, -0.447f);
glVertex2f(0.466f, -0.393f);
glVertex2f(0.421f, -0.393f);
glVertex2f(0.421f, -0.393f);
glVertex2f(0.466f, -0.393f);
glVertex2f(0.466f, -0.357f);
glVertex2f(0.412f, -0.357f);
glVertex2f(0.466f, -0.393f);
glVertex2f(0.4795f, -0.357f);
glVertex2f(0.484f, -0.384f);
glVertex2f(0.466f, -0.42f);
glEnd();
glColor3f(0.27f, 0.18f, 0.06f);
glBegin(GL_POLYGON);
glVertex2f(0.421f, -0.366f);
glVertex2f(0.3985f, -0.339f);
glVertex2f(0.3985f, -0.321f);
glVertex2f(0.4435f, -0.366f);
glVertex2f(0.4345f, -0.366f);
glEnd();
glColor3f(0.27f, 0.18f, 0.06f);
glBegin(GL_POLYGON);
glVertex2f(0.4255f, -0.357f);
glVertex2f(0.421f, -0.312f);
glVertex2f(0.4165f, -0.285f);
glVertex2f(0.4345f, -0.258f);
glVertex2f(0.4525f, -0.366f);
glEnd();
glColor3f(0.27f, 0.18f, 0.06f);
glBegin(GL_POLYGON);
glVertex2f(0.4435f, -0.366f);
glVertex2f(0.448f, -0.312f);
glVertex2f(0.457f, -0.258f);
glVertex2f(0.4705f, -0.267f);
glVertex2f(0.4525f, -0.375f);
glEnd();
glColor3f(0.27f, 0.18f, 0.06f);
glBegin(GL_POLYGON);
glVertex2f(0.457f, -0.384f);
glVertex2f(0.448f, -0.348f);
glVertex2f(0.4795f, -0.294f);
glVertex2f(0.4885f, -0.276f);
glVertex2f(0.493f, -0.285f);
glEnd();
// Leaf circles (all manually, 100 segments)
glColor3f(0.27f, 0.61f, 0.31f);
// Circle 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.3805f, -0.33f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.3805f + 0.018f * cosf(theta), -0.33f + 0.036f * sinf(theta));
}
glEnd();
// Circle 2
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.3445f, -0.33f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.3445f + 0.018f * cosf(theta), -0.33f + 0.036f * sinf(theta));
}
glEnd();
// Circle 3
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.3265f, -0.303f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.3265f + 0.018f * cosf(theta), -0.303f + 0.036f * sinf(theta));
}
glEnd();
// Circle 4
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.3265f, -0.222f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.3265f + 0.0225f * cosf(theta), -0.222f + 0.045f * sinf(theta));
}
glEnd();
// Circle 5
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.3715f, -0.186f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.3715f + 0.036f * cosf(theta), -0.186f + 0.072f * sinf(theta));
}
glEnd();
// Circle 6
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.4075f, -0.114f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.4075f + 0.036f * cosf(theta), -0.114f + 0.072f * sinf(theta));
}
glEnd();
// Circle 7
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.421f, -0.042f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.421f + 0.0225f * cosf(theta), -0.042f + 0.045f * sinf(theta));
}
glEnd();
// Circle 8
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.4705f, -0.042f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.4705f + 0.0315f * cosf(theta), -0.042f + 0.063f * sinf(theta));
}
glEnd();
// Circle 9
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.511f, -0.15f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.511f + 0.045f * cosf(theta), -0.15f + 0.09f * sinf(theta));
}
glEnd();
// Circle 10
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.556f, -0.177f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.556f + 0.0225f * cosf(theta), -0.177f + 0.045f * sinf(theta));
}
glEnd();
// Circle 11
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.5425f, -0.249f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.5425f + 0.0225f * cosf(theta), -0.249f + 0.045f * sinf(theta));
}
glEnd();
// Circle 12
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.5065f, -0.267f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.5065f + 0.0225f * cosf(theta), -0.267f + 0.045f * sinf(theta));
}
glEnd();
// Circle 13
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.5065f, -0.321f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.5065f + 0.0225f * cosf(theta), -0.321f + 0.045f * sinf(theta));
}
glEnd();
// Circle 14
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.385f, -0.249f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.385f + 0.045f * cosf(theta), -0.249f + 0.09f * sinf(theta));
}
glEnd();
// Circle 15
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.466f, -0.15f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.466f + 0.0675f * cosf(theta), -0.15f + 0.135f * sinf(theta));
}
glEnd();
// Circle 16
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.376f, -0.231f);
for(int i=0; i<=100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(0.376f + 0.045f * cosf(theta), -0.231f + 0.09f * sinf(theta));
}
glEnd();


      // ==========House===========

   glColor3f(0.45f, 0.47f, 0.50f); //main
glBegin(GL_QUADS);
glVertex2f(0.58f, -0.246f);
glVertex2f(0.90f, -0.246f);
glVertex2f(0.99f, -0.326f);
glVertex2f(0.50f, -0.326f);
glEnd();
glColor3f(0.68f, 0.54f, 0.44f);
glBegin(GL_QUADS);
glVertex2f(0.53f, -0.326f);
glVertex2f(0.53f, -0.502f);
glVertex2f(0.96f, -0.486f);
glVertex2f(0.96f, -0.326f);
glEnd();
glColor3f(0.29f, 0.32f, 0.35f);
glBegin(GL_QUADS);
glVertex2f(0.53f, -0.486f);
glVertex2f(0.47f, -0.55f);
glVertex2f(1.02f, -0.55f);
glVertex2f(0.96f, -0.486f);
glEnd();
glColor3f(0.35f, 0.26f, 0.09f); //door
glBegin(GL_QUADS);
glVertex2f(0.71f, -0.342f);
glVertex2f(0.71f, -0.486f);
glVertex2f(0.77f, -0.486f);
glVertex2f(0.77f, -0.342f);
glEnd();
glColor3f(0.0f, 0.0f, 0.0f); //door
glBegin(GL_LINE_LOOP);
glVertex2f(0.71f, -0.342f);
glVertex2f(0.71f, -0.486f);
glVertex2f(0.77f, -0.486f);
glVertex2f(0.77f, -0.342f);
glEnd();
glColor3f(0.16f, 0.11f, 0.04f); //door
glBegin(GL_QUADS);
glVertex2f(0.735f, -0.342f);
glVertex2f(0.735f, -0.486f);
glVertex2f(0.745f, -0.486f);
glVertex2f(0.745f, -0.342f);
glEnd();
glColor3f(0.12f, 0.13f, 0.16f);
glBegin(GL_QUADS);
glVertex2f(0.47f, -0.55f);
glVertex2f(0.47f, -0.582f);
glVertex2f(1.02f, -0.582f);
glVertex2f(1.02f, -0.55f);
glEnd();
glColor3f(0.45f, 0.47f, 0.50f); //2nd chal
glBegin(GL_QUADS);
glVertex2f(0.61f, -0.07f);
glVertex2f(0.55f, -0.15f);
glVertex2f(0.93f, -0.15f);
glVertex2f(0.84f, -0.07f);
glEnd();
glColor3f(0.68f, 0.54f, 0.44f);
glBegin(GL_QUADS);
glVertex2f(0.89f, -0.246f);
glVertex2f(0.89f, -0.15f);
glVertex2f(0.59f, -0.15f);
glVertex2f(0.59f, -0.246f);
glEnd();
glColor3f(0.12f, 0.07f, 0.02f);
glBegin(GL_QUADS);
glVertex2f(0.72f, -0.182f);
glVertex2f(0.75f, -0.182f);
glVertex2f(0.75f, -0.246f);
glVertex2f(0.72f, -0.246f);
glEnd();
glColor3f(0.12f, 0.07f, 0.02f);
glBegin(GL_QUADS);
glVertex2f(0.57f, -0.374f);
glVertex2f(0.57f, -0.438f);
glVertex2f(0.60f, -0.438f);
glVertex2f(0.60f, -0.374f);
glEnd();
glColor3f(0.12f, 0.07f, 0.02f);
glBegin(GL_QUADS);
glVertex2f(0.66f, -0.374f);
glVertex2f(0.66f, -0.438f);
glVertex2f(0.69f, -0.438f);
glVertex2f(0.69f, -0.374f);
glEnd();
glColor3f(0.12f, 0.07f, 0.02f);
glBegin(GL_QUADS);
glVertex2f(0.79f, -0.374f);
glVertex2f(0.79f, -0.438f);
glVertex2f(0.82f, -0.438f);
glVertex2f(0.82f, -0.374f);
glEnd();
glColor3f(0.12f, 0.07f, 0.02f);
glBegin(GL_QUADS);
glVertex2f(0.89f, -0.374f);
glVertex2f(0.89f, -0.438f);
glVertex2f(0.92f, -0.438f);
glVertex2f(0.92f, -0.374f);
glEnd();
glColor3f(0.12f, 0.07f, 0.02f);
glBegin(GL_QUADS);
glVertex2f(0.63f, -0.182f);
glVertex2f(0.63f, -0.23f);
glVertex2f(0.66f, -0.23f);
glVertex2f(0.66f, -0.182f);
glEnd();
glColor3f(0.12f, 0.07f, 0.02f);
glBegin(GL_QUADS);
glVertex2f(0.83f, -0.182f);
glVertex2f(0.83f, -0.23f);
glVertex2f(0.86f, -0.23f);
glVertex2f(0.86f, -0.182f);
glEnd();
//bar
glColor3f(0.26f, 0.09f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.52f, -0.326f);
glVertex2f(0.52f, -0.534f);
glVertex2f(0.53f, -0.534f);
glVertex2f(0.53f, -0.326f);
glEnd();
glColor3f(0.26f, 0.09f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.64f, -0.326f);
glVertex2f(0.64f, -0.534f);
glVertex2f(0.65f, -0.534f);
glVertex2f(0.65f, -0.326f);
glEnd();
glColor3f(0.26f, 0.09f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.84f, -0.326f);
glVertex2f(0.84f, -0.534f);
glVertex2f(0.85f, -0.534f);
glVertex2f(0.85f, -0.326f);
glEnd();
glColor3f(0.26f, 0.09f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.96f, -0.326f);
glVertex2f(0.96f, -0.534f);
glVertex2f(0.97f, -0.534f);
glVertex2f(0.97f, -0.326f);
glEnd();


    //=======================Gorur Gari========================


     // Outer circle (tire)
    glLineWidth(8);
    glColor3f(0.51, 0.25, 0.16); // Black for the tire
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * 3.1415926f * i / 100.0f;
        glVertex2f(0.06f * cosf(theta) + 0.33f, 0.10f * sinf(theta) + -0.76f);
    }
    glEnd();
    // Spokes
    glColor3f(0.51, 0.25, 0.16); // Grey for spokes
    glBegin(GL_LINES);
    for (int i = 0; i < 8; i++) {
        float theta = 2.0f * 3.1415926f * i / 8.0f;
        glVertex2f(0.33f, -0.76f); // Center
        glVertex2f(0.33f + 0.06f * cosf(theta), -0.76f + 0.10f * sinf(theta)); // Spoke end
    }
    glEnd();

    // --- Remaining QUADS (assuming other parts of the vehicle body) ---
    glColor3f(0.31f, 0.49f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(0.188f, -0.85f);
    glVertex2f(0.19f, -0.83f);
    glVertex2f(0.356f, -0.93f);
    glVertex2f(0.362f, -0.90f);
    glEnd();

    glColor3f(0.31f, 0.49f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(0.26f, -1.0f);
    glVertex2f(0.284f, -1.01f);
    glVertex2f(0.464f, -0.77f);
    glVertex2f(0.446f, -0.75f);
    glEnd();

    glColor3f(0.31f, 0.49f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(0.134f, -0.9f);
    glVertex2f(0.144f, -0.92f);
    glVertex2f(0.319f, -0.76f);
    glVertex2f(0.29f, -0.75f);
    glEnd();


       // --- First set of QUADS (assuming part of the vehicle body) ---
    glColor3f(0.2f, 0.27f, 0.09f);
    glBegin(GL_QUADS);
    glVertex2f(0.272f, -0.76f);
    glVertex2f(0.416f, -0.81f);
    glVertex2f(0.542f, -0.66f);
    glVertex2f(0.422f, -0.64f);
    glEnd();



// Outer circle (tire)
    glLineWidth(8);
    glColor3f(0.51, 0.25, 0.16); // Brown tire
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * 3.1415926f * i / 100.0f;
        glVertex2f(0.06f * cosf(theta) + 0.47f, 0.10f * sinf(theta) - 0.78f);
    }
    glEnd();
    // Spokes
    glColor3f(0.51, 0.25, 0.16); // Brown for spokes
    glBegin(GL_LINES);
    for (int i = 0; i < 8; i++) {
        float theta = 2.0f * 3.1415926f * i / 8.0f;
        glVertex2f(0.47f, -0.78f); // Center
        glVertex2f(0.47f + 0.06f * cosf(theta), -0.78f + 0.10f * sinf(theta)); // Spoke end
    }
    glEnd();
    // White ring (middle)
    glLineWidth(5);
    glColor3f(1.0, 1.0, 1.0); // White color
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * 3.1415926f * i / 100.0f;
        glVertex2f(0.008f * cosf(theta) + 0.47f, 0.008f * sinf(theta) - 0.78f); // Slightly smaller radius
    }
    glEnd();








glPushMatrix();
glTranslatef(cloudX, 0.0f, 0.0f);

glColor3f(1.0f, 1.0f, 1.0f);

// Cloud 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f((-0.6f - 0.3f)*0.7f, (0.6f + 0.3f)*0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.6f + 0.09f * cosf(theta)) - 0.3f)*0.7f, ((0.6f + 0.09f * sinf(theta)) + 0.3f)*0.6f);
}
glEnd();

// Second circle
glBegin(GL_TRIANGLE_FAN);
glVertex2f((-0.07f - 0.6f - 0.3f) * 0.7f, (-0.02f + 0.6f + 0.3f) * 0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.67f + 0.06f * cosf(theta)) - 0.3f) * 0.7f, ((0.58f + 0.06f * sinf(theta)) + 0.3f) * 0.6f);
}
glEnd();

// Third circle
glBegin(GL_TRIANGLE_FAN);
glVertex2f((0.07f - 0.6f - 0.3f) * 0.7f, (-0.02f + 0.6f + 0.3f) * 0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.53f + 0.06f * cosf(theta)) - 0.3f) * 0.7f, ((0.58f + 0.06f * sinf(theta)) + 0.3f) * 0.6f);
}
glEnd();

// Fourth circle
glBegin(GL_TRIANGLE_FAN);
glVertex2f((-0.05f - 0.6f - 0.3f) * 0.7f, (0.05f + 0.6f + 0.3f) * 0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.65f + 0.04f * cosf(theta)) - 0.3f) * 0.7f, ((0.65f + 0.04f * sinf(theta)) + 0.3f) * 0.6f);
}
glEnd();

// Fifth circle
glBegin(GL_TRIANGLE_FAN);
glVertex2f((0.05f - 0.6f - 0.3f) * 0.7f, (0.05f + 0.6f + 0.3f) * 0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.55f + 0.04f * cosf(theta)) - 0.3f) * 0.7f, ((0.65f + 0.04f * sinf(theta)) + 0.3f) * 0.6f);
}
glEnd();


// Cloud 2
glColor3f(1.0f, 1.0f, 1.0f);

// Circle 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.6f, 0.88f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.6f + 0.063f * cosf(theta), 0.88f + 0.054f * sinf(theta));
}
glEnd();

// Circle 2
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.551f, 0.868f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.551f + 0.042f * cosf(theta), 0.868f + 0.036f * sinf(theta));
}
glEnd();

// Circle 3
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.649f, 0.868f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.649f + 0.042f * cosf(theta), 0.868f + 0.036f * sinf(theta));
}
glEnd();

// Circle 4
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.565f, 0.91f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.565f + 0.028f * cosf(theta), 0.91f + 0.024f * sinf(theta));
}
glEnd();

// Circle 5
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.635f, 0.91f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.635f + 0.028f * cosf(theta), 0.91f + 0.024f * sinf(theta));
}
glEnd();



// Cloud 3
glColor3f(1.0f, 1.0f, 1.0f);

// Circle 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.4f, 0.65f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.4f + 0.063f * cosf(theta), 0.65f + 0.054f * sinf(theta));
}
glEnd();

// Circle 2
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.351f, 0.638f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.351f + 0.042f * cosf(theta), 0.638f + 0.036f * sinf(theta));
}
glEnd();

// Circle 3
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.449f, 0.638f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.449f + 0.042f * cosf(theta), 0.638f + 0.036f * sinf(theta));
}
glEnd();

// Circle 4
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.365f, 0.68f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.365f + 0.028f * cosf(theta), 0.68f + 0.024f * sinf(theta));
}
glEnd();

// Circle 5
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.435f, 0.68f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.435f + 0.028f * cosf(theta), 0.68f + 0.024f * sinf(theta));
}
glEnd();



// Cloud 4
glColor3f(1.0f, 1.0f, 1.0f);

// Circle 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.45f, 0.8f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.45f + 0.063f * cosf(theta), 0.8f + 0.054f * sinf(theta));
}
glEnd();

// Circle 2
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.499f, 0.788f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.499f + 0.042f * cosf(theta), 0.788f + 0.036f * sinf(theta));
}
glEnd();

// Circle 3
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.401f, 0.788f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.401f + 0.042f * cosf(theta), 0.788f + 0.036f * sinf(theta));
}
glEnd();

// Circle 4
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.485f, 0.83f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.485f + 0.028f * cosf(theta), 0.83f + 0.024f * sinf(theta));
}
glEnd();

// Circle 5
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.415f, 0.83f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.415f + 0.028f * cosf(theta), 0.83f + 0.024f * sinf(theta));
}
glEnd();



//cloud 5
glColor3f(1.0f, 1.0f, 1.0f);

// Circle 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.0f, 0.7f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.063f * cosf(theta), 0.054f * sinf(theta) + 0.7f);
}
glEnd();

// Circle 2
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.049f, 0.688f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.049f + 0.042f * cosf(theta), 0.688f + 0.036f * sinf(theta));
}
glEnd();

// Circle 3
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.049f, 0.688f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.049f + 0.042f * cosf(theta), 0.688f + 0.036f * sinf(theta));
}
glEnd();

// Circle 4
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.035f, 0.73f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.035f + 0.028f * cosf(theta), 0.73f + 0.024f * sinf(theta));
}
glEnd();

// Circle 5
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.035f, 0.73f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.035f + 0.028f * cosf(theta), 0.73f + 0.024f * sinf(theta));
}
glEnd();


glPopMatrix();







glPushMatrix();
glTranslatef(cloudX1, 0.0f, 0.0f);

glColor3f(1.0f, 1.0f, 1.0f);

// Cloud 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f((-0.6f - 0.3f)*0.7f, (0.6f + 0.3f)*0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.6f + 0.09f * cosf(theta)) - 0.3f)*0.7f, ((0.6f + 0.09f * sinf(theta)) + 0.3f)*0.6f);
}
glEnd();

// Second circle
glBegin(GL_TRIANGLE_FAN);
glVertex2f((-0.07f - 0.6f - 0.3f) * 0.7f, (-0.02f + 0.6f + 0.3f) * 0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.67f + 0.06f * cosf(theta)) - 0.3f) * 0.7f, ((0.58f + 0.06f * sinf(theta)) + 0.3f) * 0.6f);
}
glEnd();

// Third circle
glBegin(GL_TRIANGLE_FAN);
glVertex2f((0.07f - 0.6f - 0.3f) * 0.7f, (-0.02f + 0.6f + 0.3f) * 0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.53f + 0.06f * cosf(theta)) - 0.3f) * 0.7f, ((0.58f + 0.06f * sinf(theta)) + 0.3f) * 0.6f);
}
glEnd();

// Fourth circle
glBegin(GL_TRIANGLE_FAN);
glVertex2f((-0.05f - 0.6f - 0.3f) * 0.7f, (0.05f + 0.6f + 0.3f) * 0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.65f + 0.04f * cosf(theta)) - 0.3f) * 0.7f, ((0.65f + 0.04f * sinf(theta)) + 0.3f) * 0.6f);
}
glEnd();

// Fifth circle
glBegin(GL_TRIANGLE_FAN);
glVertex2f((0.05f - 0.6f - 0.3f) * 0.7f, (0.05f + 0.6f + 0.3f) * 0.6f); // center
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846f * float(i) / 100.0f;
    glVertex2f(((-0.55f + 0.04f * cosf(theta)) - 0.3f) * 0.7f, ((0.65f + 0.04f * sinf(theta)) + 0.3f) * 0.6f);
}
glEnd();


// Cloud 2
glColor3f(1.0f, 1.0f, 1.0f);

// Circle 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.6f, 0.88f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.6f + 0.063f * cosf(theta), 0.88f + 0.054f * sinf(theta));
}
glEnd();

// Circle 2
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.551f, 0.868f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.551f + 0.042f * cosf(theta), 0.868f + 0.036f * sinf(theta));
}
glEnd();

// Circle 3
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.649f, 0.868f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.649f + 0.042f * cosf(theta), 0.868f + 0.036f * sinf(theta));
}
glEnd();

// Circle 4
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.565f, 0.91f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.565f + 0.028f * cosf(theta), 0.91f + 0.024f * sinf(theta));
}
glEnd();

// Circle 5
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.635f, 0.91f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.635f + 0.028f * cosf(theta), 0.91f + 0.024f * sinf(theta));
}
glEnd();



// Cloud 3
glColor3f(1.0f, 1.0f, 1.0f);

// Circle 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.4f, 0.65f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.4f + 0.063f * cosf(theta), 0.65f + 0.054f * sinf(theta));
}
glEnd();

// Circle 2
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.351f, 0.638f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.351f + 0.042f * cosf(theta), 0.638f + 0.036f * sinf(theta));
}
glEnd();

// Circle 3
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.449f, 0.638f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.449f + 0.042f * cosf(theta), 0.638f + 0.036f * sinf(theta));
}
glEnd();

// Circle 4
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.365f, 0.68f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.365f + 0.028f * cosf(theta), 0.68f + 0.024f * sinf(theta));
}
glEnd();

// Circle 5
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.435f, 0.68f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.435f + 0.028f * cosf(theta), 0.68f + 0.024f * sinf(theta));
}
glEnd();



// Cloud 4
glColor3f(1.0f, 1.0f, 1.0f);

// Circle 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.45f, 0.8f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.45f + 0.063f * cosf(theta), 0.8f + 0.054f * sinf(theta));
}
glEnd();

// Circle 2
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.499f, 0.788f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.499f + 0.042f * cosf(theta), 0.788f + 0.036f * sinf(theta));
}
glEnd();

// Circle 3
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.401f, 0.788f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.401f + 0.042f * cosf(theta), 0.788f + 0.036f * sinf(theta));
}
glEnd();

// Circle 4
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.485f, 0.83f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.485f + 0.028f * cosf(theta), 0.83f + 0.024f * sinf(theta));
}
glEnd();

// Circle 5
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.415f, 0.83f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.415f + 0.028f * cosf(theta), 0.83f + 0.024f * sinf(theta));
}
glEnd();



//cloud 5
glColor3f(1.0f, 1.0f, 1.0f);

// Circle 1
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.0f, 0.7f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.063f * cosf(theta), 0.054f * sinf(theta) + 0.7f);
}
glEnd();

// Circle 2
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.049f, 0.688f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.049f + 0.042f * cosf(theta), 0.688f + 0.036f * sinf(theta));
}
glEnd();

// Circle 3
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.049f, 0.688f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.049f + 0.042f * cosf(theta), 0.688f + 0.036f * sinf(theta));
}
glEnd();

// Circle 4
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.035f, 0.73f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(-0.035f + 0.028f * cosf(theta), 0.73f + 0.024f * sinf(theta));
}
glEnd();

// Circle 5
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0.035f, 0.73f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159265358979323846 * i / 100.0f;
    glVertex2f(0.035f + 0.028f * cosf(theta), 0.73f + 0.024f * sinf(theta));
}
glEnd();


glPopMatrix();



     /*glPushMatrix();
    glTranslatef(0.20f, -0.75f, 0.0f);   // shift plane position
    glScalef(0.50f, 0.80f, 0.0f);      // scale plane

    glPopMatrix();*/










// ======================================
// || Mini Plane in gluOrtho2D (-1,1)  ||
// ======================================
glPushMatrix();
glTranslatef(jetXD3, 0.0f, 0.0f);   // shift plane position

glLineWidth(2.0f); // thicker border for visibility
// ---------------- Body last part ----------------
glBegin(GL_QUADS); // fill
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.102f, 0.6988f);
glVertex2f(0.102f, 0.6708f);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.102f, 0.6988f);
glVertex2f(0.102f, 0.6708f);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glEnd();
// ---------------- Body middle ----------------
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glEnd();
// ---------------- Body front ----------------
glBegin(GL_POLYGON);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glEnd();
// ---------------- Nose ----------------
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34f, 0.36f);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glVertex2f(-0.108f, 0.6708f);
glVertex2f(-0.111f, 0.6652f);
glVertex2f(-0.108f, 0.6652f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glVertex2f(-0.108f, 0.6708f);
glVertex2f(-0.111f, 0.6652f);
glVertex2f(-0.108f, 0.6652f);
glEnd();
// ---------------- Ellipse (window) ----------------
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.021f + 0.0405f * cos(angle),
               0.696f + 0.0252f * sin(angle));
}
glEnd();
// border
glLineWidth(1);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.021f + 0.0405f * cos(angle),
               0.696f + 0.0252f * sin(angle));
}
glEnd();
//window last
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.0585f, 0.6904f);
glVertex2f(0.0195f, 0.6904f);
glVertex2f(0.0195f, 0.668f);
glVertex2f(-0.0585f, 0.668f);
glEnd();
//shadow
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.036f, 0.7184f);
glVertex2f(-0.036f, 0.6932f);
glVertex2f(-0.033f, 0.6932f);
glVertex2f(-0.033f, 0.7184f);
glEnd();
//2
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.0105f, 0.7184f);
glVertex2f(-0.0075f, 0.7184f);
glVertex2f(-0.0105f, 0.6932f);
glVertex2f(-0.0075f, 0.6932f);
glEnd();
// ---------------- Wing bottom ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(-0.0165f, 0.6764f);
glVertex2f(0.048f, 0.682f);
glVertex2f(0.0555f, 0.6148f);
glVertex2f(0.069f, 0.584f);
glVertex2f(0.051f, 0.5728f);
glVertex2f(-0.0165f, 0.6764f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.0165f, 0.6764f);
glVertex2f(0.048f, 0.682f);
glVertex2f(0.0555f, 0.6148f);
glVertex2f(0.069f, 0.584f);
glVertex2f(0.051f, 0.5728f);
glVertex2f(-0.0165f, 0.6764f);
glEnd();
// ---------------- Wing top ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.0495f, 0.7044f);
glVertex2f(0.051f, 0.7464f);
glVertex2f(0.0585f, 0.7688f);
glVertex2f(0.0375f, 0.7716f);
glVertex2f(-0.0105f, 0.7212f);
glVertex2f(0.018f, 0.71f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.0495f, 0.7044f);
glVertex2f(0.051f, 0.7464f);
glVertex2f(0.0585f, 0.7688f);
glVertex2f(0.0375f, 0.7716f);
glVertex2f(-0.0105f, 0.7212f);
glVertex2f(0.018f, 0.71f);
glEnd();
// ---------------- Back wings ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.066f, 0.7044f);
glVertex2f(0.093f, 0.766f);
glVertex2f(0.099f, 0.766f);
glVertex2f(0.093f, 0.6988f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.066f, 0.7044f);
glVertex2f(0.093f, 0.766f);
glVertex2f(0.099f, 0.766f);
glVertex2f(0.093f, 0.6988f);
glEnd();
// ---------------- Back wing details ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.093f, 0.7464f);
glVertex2f(0.099f, 0.7464f);
glVertex2f(0.0945f, 0.6764f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.093f, 0.7464f);
glVertex2f(0.099f, 0.7464f);
glVertex2f(0.0945f, 0.6764f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.0945f, 0.6764f);
glVertex2f(0.117f, 0.6484f);
glVertex2f(0.105f, 0.6512f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.0945f, 0.6764f);
glVertex2f(0.117f, 0.6484f);
glVertex2f(0.105f, 0.6512f);
glEnd();
// ---------------- Rockets ----------------
glBegin(GL_QUADS);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.0135f, 0.7296f);
glVertex2f(-0.0045f, 0.7352f);
glVertex2f(0.003f, 0.738f);
glVertex2f(-0.0075f, 0.724f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.015f, 0.7296f);
glVertex2f(-0.006f, 0.7352f);
glVertex2f(0.0045f, 0.738f);
glVertex2f(-0.009f, 0.724f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.015f, 0.64f);
glVertex2f(-0.0045f, 0.6512f);
glVertex2f(0.0f, 0.6512f);
glVertex2f(0.009f, 0.6344f);
glVertex2f(-0.0045f, 0.6344f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.015f, 0.64f);
glVertex2f(-0.0045f, 0.6512f);
glVertex2f(0.0f, 0.6512f);
glVertex2f(0.009f, 0.6344f);
glVertex2f(-0.0045f, 0.6344f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.015f, 0.6148f);
glVertex2f(0.006f, 0.6288f);
glVertex2f(0.0135f, 0.6288f);
glVertex2f(0.03f, 0.6064f);
glVertex2f(0.003f, 0.6064f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.015f, 0.6148f);
glVertex2f(0.006f, 0.6288f);
glVertex2f(0.0135f, 0.6288f);
glVertex2f(0.03f, 0.6064f);
glVertex2f(0.003f, 0.6064f);
glEnd();
//fire 1
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.696f);
glVertex2f(0.1125f, 0.6988f);
glVertex2f(0.1005f, 0.6848f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.696f);
glVertex2f(0.1125f, 0.6988f);
glVertex2f(0.1005f, 0.6848f);
glEnd();
//fire 2
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.6904f);
glVertex2f(0.117f, 0.6904f);
glVertex2f(0.1005f, 0.6764f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.6904f);
glVertex2f(0.117f, 0.6904f);
glVertex2f(0.1005f, 0.6764f);
glEnd();
//fire 3
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.6848f);
glVertex2f(0.1185f, 0.6792f);
glVertex2f(0.1005f, 0.6708f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.6848f);
glVertex2f(0.1185f, 0.6792f);
glVertex2f(0.1005f, 0.6708f);
glEnd();
//fire 4
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.682f);
glVertex2f(0.1125f, 0.6708f);
glVertex2f(0.1005f, 0.6736f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.682f);
glVertex2f(0.1125f, 0.6708f);
glVertex2f(0.1005f, 0.6736f);
glEnd();

glPopMatrix();








// ======================================
// || Mini Plane in gluOrtho2D (-1,1)  ||
// ======================================
glPushMatrix();
glTranslatef(jetX2D3, 0.0f, 0.0f);   // shift plane position

glLineWidth(2.0f); // thicker border for visibility
// ---------------- Body last part ----------------
glBegin(GL_QUADS); // fill
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.068f, 0.892f);
glVertex2f(0.068f, 0.872f);
glVertex2f(0.013f, 0.862f);
glVertex2f(0.012f, 0.9f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.068f, 0.892f);
glVertex2f(0.068f, 0.872f);
glVertex2f(0.013f, 0.862f);
glVertex2f(0.012f, 0.9f);
glEnd();
// ---------------- Body middle ----------------
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.013f, 0.862f);
glVertex2f(0.012f, 0.9f);
glVertex2f(-0.041f, 0.89f);
glVertex2f(-0.041f, 0.864f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.013f, 0.862f);
glVertex2f(0.012f, 0.9f);
glVertex2f(-0.041f, 0.89f);
glVertex2f(-0.041f, 0.864f);
glEnd();
// ---------------- Body front ----------------
glBegin(GL_POLYGON);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.041f, 0.89f);
glVertex2f(-0.041f, 0.864f);
glVertex2f(-0.056f, 0.864f);
glVertex2f(-0.0565f, 0.874f);
glVertex2f(-0.056f, 0.882f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.041f, 0.89f);
glVertex2f(-0.041f, 0.864f);
glVertex2f(-0.056f, 0.864f);
glVertex2f(-0.0565f, 0.874f);
glVertex2f(-0.056f, 0.882f);
glEnd();
// ---------------- Nose ----------------
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34f, 0.36f);
glVertex2f(-0.056f, 0.864f);
glVertex2f(-0.0565f, 0.874f);
glVertex2f(-0.056f, 0.882f);
glVertex2f(-0.072f, 0.872f);
glVertex2f(-0.074f, 0.868f);
glVertex2f(-0.072f, 0.868f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.056f, 0.864f);
glVertex2f(-0.0565f, 0.874f);
glVertex2f(-0.056f, 0.882f);
glVertex2f(-0.072f, 0.872f);
glVertex2f(-0.074f, 0.868f);
glVertex2f(-0.072f, 0.868f);
glEnd();
// ---------------- Ellipse (window) ----------------
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.014f + 0.027f * cos(angle),
               0.89f + 0.018f * sin(angle));
}
glEnd();
// border
glLineWidth(1);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.014f + 0.027f * cos(angle),
               0.89f + 0.018f * sin(angle));
}
glEnd();
//window last
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.039f, 0.886f);
glVertex2f(0.013f, 0.886f);
glVertex2f(0.013f, 0.87f);
glVertex2f(-0.039f, 0.87f);
glEnd();
//shadow
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.024f, 0.906f);
glVertex2f(-0.024f, 0.888f);
glVertex2f(-0.022f, 0.888f);
glVertex2f(-0.022f, 0.906f);
glEnd();
//2
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.007f, 0.906f);
glVertex2f(-0.005f, 0.906f);
glVertex2f(-0.007f, 0.888f);
glVertex2f(-0.005f, 0.888f);
glEnd();
// ---------------- Wing bottom ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(-0.011f, 0.876f);
glVertex2f(0.032f, 0.88f);
glVertex2f(0.037f, 0.832f);
glVertex2f(0.046f, 0.81f);
glVertex2f(0.034f, 0.802f);
glVertex2f(-0.011f, 0.876f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.011f, 0.876f);
glVertex2f(0.032f, 0.88f);
glVertex2f(0.037f, 0.832f);
glVertex2f(0.046f, 0.81f);
glVertex2f(0.034f, 0.802f);
glVertex2f(-0.011f, 0.876f);
glEnd();
// ---------------- Wing top ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.033f, 0.896f);
glVertex2f(0.034f, 0.926f);
glVertex2f(0.039f, 0.942f);
glVertex2f(0.025f, 0.944f);
glVertex2f(-0.007f, 0.908f);
glVertex2f(0.012f, 0.9f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.033f, 0.896f);
glVertex2f(0.034f, 0.926f);
glVertex2f(0.039f, 0.942f);
glVertex2f(0.025f, 0.944f);
glVertex2f(-0.007f, 0.908f);
glVertex2f(0.012f, 0.9f);
glEnd();
// ---------------- Back wings ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.044f, 0.896f);
glVertex2f(0.062f, 0.94f);
glVertex2f(0.066f, 0.94f);
glVertex2f(0.062f, 0.892f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.044f, 0.896f);
glVertex2f(0.062f, 0.94f);
glVertex2f(0.066f, 0.94f);
glVertex2f(0.062f, 0.892f);
glEnd();
// ---------------- Back wing details ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.04f, 0.874f);
glVertex2f(0.062f, 0.926f);
glVertex2f(0.066f, 0.926f);
glVertex2f(0.063f, 0.876f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.04f, 0.874f);
glVertex2f(0.062f, 0.926f);
glVertex2f(0.066f, 0.926f);
glVertex2f(0.063f, 0.876f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.04f, 0.874f);
glVertex2f(0.063f, 0.876f);
glVertex2f(0.078f, 0.856f);
glVertex2f(0.07f, 0.858f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.04f, 0.874f);
glVertex2f(0.063f, 0.876f);
glVertex2f(0.078f, 0.856f);
glVertex2f(0.07f, 0.858f);
glEnd();
// ---------------- Rockets ----------------
glBegin(GL_QUADS);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.009f, 0.914f);
glVertex2f(-0.003f, 0.918f);
glVertex2f(0.002f, 0.92f);
glVertex2f(-0.005f, 0.91f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.914f);
glVertex2f(-0.004f, 0.918f);
glVertex2f(0.003f, 0.92f);
glVertex2f(-0.006f, 0.91f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.01f, 0.85f);
glVertex2f(-0.003f, 0.858f);
glVertex2f(0.0f, 0.858f);
glVertex2f(0.006f, 0.846f);
glVertex2f(-0.003f, 0.846f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.85f);
glVertex2f(-0.003f, 0.858f);
glVertex2f(0.0f, 0.858f);
glVertex2f(0.006f, 0.846f);
glVertex2f(-0.003f, 0.846f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.01f, 0.832f);
glVertex2f(0.004f, 0.842f);
glVertex2f(0.009f, 0.842f);
glVertex2f(0.02f, 0.826f);
glVertex2f(0.002f, 0.826f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.832f);
glVertex2f(0.004f, 0.842f);
glVertex2f(0.009f, 0.842f);
glVertex2f(0.02f, 0.826f);
glVertex2f(0.002f, 0.826f);
glEnd();
//fire 1
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.89f);
glVertex2f(0.075f, 0.892f);
glVertex2f(0.067f, 0.882f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.89f);
glVertex2f(0.075f, 0.892f);
glVertex2f(0.067f, 0.882f);
glEnd();
//fire 2
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.886f);
glVertex2f(0.078f, 0.886f);
glVertex2f(0.067f, 0.876f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.886f);
glVertex2f(0.078f, 0.886f);
glVertex2f(0.067f, 0.876f);
glEnd();
//fire 3
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.882f);
glVertex2f(0.079f, 0.878f);
glVertex2f(0.067f, 0.872f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.882f);
glVertex2f(0.079f, 0.878f);
glVertex2f(0.067f, 0.872f);
glEnd();
//fire 4
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.88f);
glVertex2f(0.075f, 0.872f);
glVertex2f(0.067f, 0.874f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.88f);
glVertex2f(0.075f, 0.872f);
glVertex2f(0.067f, 0.874f);
glEnd();

glPopMatrix();








// ======================================
// || Mini Plane in gluOrtho2D (-1,1)  ||
// ======================================
glPushMatrix();
glTranslatef(jetX3D3, 0.0f, 0.0f);   // shift plane position

glLineWidth(2.0f); // thicker border for visibility
// ---------------- Body last part ----------------
glBegin(GL_QUADS); // fill
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.068f, 0.542f);
glVertex2f(0.068f, 0.522f);
glVertex2f(0.013f, 0.512f);
glVertex2f(0.012f, 0.55f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.068f, 0.542f);
glVertex2f(0.068f, 0.522f);
glVertex2f(0.013f, 0.512f);
glVertex2f(0.012f, 0.55f);
glEnd();
// ---------------- Body middle ----------------
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.013f, 0.512f);
glVertex2f(0.012f, 0.55f);
glVertex2f(-0.041f, 0.54f);
glVertex2f(-0.041f, 0.514f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.013f, 0.512f);
glVertex2f(0.012f, 0.55f);
glVertex2f(-0.041f, 0.54f);
glVertex2f(-0.041f, 0.514f);
glEnd();
// ---------------- Body front ----------------
glBegin(GL_POLYGON);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.041f, 0.54f);
glVertex2f(-0.041f, 0.514f);
glVertex2f(-0.056f, 0.514f);
glVertex2f(-0.0565f, 0.524f);
glVertex2f(-0.056f, 0.532f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.041f, 0.54f);
glVertex2f(-0.041f, 0.514f);
glVertex2f(-0.056f, 0.514f);
glVertex2f(-0.0565f, 0.524f);
glVertex2f(-0.056f, 0.532f);
glEnd();
// ---------------- Nose ----------------
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34f, 0.36f);
glVertex2f(-0.056f, 0.514f);
glVertex2f(-0.0565f, 0.524f);
glVertex2f(-0.056f, 0.532f);
glVertex2f(-0.072f, 0.522f);
glVertex2f(-0.074f, 0.518f);
glVertex2f(-0.072f, 0.518f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.056f, 0.514f);
glVertex2f(-0.0565f, 0.524f);
glVertex2f(-0.056f, 0.532f);
glVertex2f(-0.072f, 0.522f);
glVertex2f(-0.074f, 0.518f);
glVertex2f(-0.072f, 0.518f);
glEnd();
// ---------------- Ellipse (window) ----------------
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.014f + 0.027f * cos(angle),
               0.54f + 0.018f * sin(angle));
}
glEnd();
// border
glLineWidth(1);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.014f + 0.027f * cos(angle),
               0.54f + 0.018f * sin(angle));
}
glEnd();
//window last
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.039f, 0.536f);
glVertex2f(0.013f, 0.536f);
glVertex2f(0.013f, 0.52f);
glVertex2f(-0.039f, 0.52f);
glEnd();
//shadow
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.024f, 0.556f);
glVertex2f(-0.024f, 0.538f);
glVertex2f(-0.022f, 0.538f);
glVertex2f(-0.022f, 0.556f);
glEnd();
//2
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.007f, 0.556f);
glVertex2f(-0.005f, 0.556f);
glVertex2f(-0.007f, 0.538f);
glVertex2f(-0.005f, 0.538f);
glEnd();
// ---------------- Wing bottom ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(-0.011f, 0.526f);
glVertex2f(0.032f, 0.53f);
glVertex2f(0.037f, 0.482f);
glVertex2f(0.046f, 0.46f);
glVertex2f(0.034f, 0.452f);
glVertex2f(-0.011f, 0.526f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.011f, 0.526f);
glVertex2f(0.032f, 0.53f);
glVertex2f(0.037f, 0.482f);
glVertex2f(0.046f, 0.46f);
glVertex2f(0.034f, 0.452f);
glVertex2f(-0.011f, 0.526f);
glEnd();
// ---------------- Wing top ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.033f, 0.546f);
glVertex2f(0.034f, 0.576f);
glVertex2f(0.039f, 0.592f);
glVertex2f(0.025f, 0.594f);
glVertex2f(-0.007f, 0.558f);
glVertex2f(0.012f, 0.55f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.033f, 0.546f);
glVertex2f(0.034f, 0.576f);
glVertex2f(0.039f, 0.592f);
glVertex2f(0.025f, 0.594f);
glVertex2f(-0.007f, 0.558f);
glVertex2f(0.012f, 0.55f);
glEnd();
// ---------------- Back wings ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.044f, 0.546f);
glVertex2f(0.062f, 0.59f);
glVertex2f(0.066f, 0.59f);
glVertex2f(0.062f, 0.542f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.044f, 0.546f);
glVertex2f(0.062f, 0.59f);
glVertex2f(0.066f, 0.59f);
glVertex2f(0.062f, 0.542f);
glEnd();
// ---------------- Back wing details ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.04f, 0.524f);
glVertex2f(0.062f, 0.576f);
glVertex2f(0.066f, 0.576f);
glVertex2f(0.063f, 0.526f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.04f, 0.524f);
glVertex2f(0.062f, 0.576f);
glVertex2f(0.066f, 0.576f);
glVertex2f(0.063f, 0.526f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.04f, 0.524f);
glVertex2f(0.063f, 0.526f);
glVertex2f(0.078f, 0.506f);
glVertex2f(0.07f, 0.508f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.04f, 0.524f);
glVertex2f(0.063f, 0.526f);
glVertex2f(0.078f, 0.506f);
glVertex2f(0.07f, 0.508f);
glEnd();
// ---------------- Rockets ----------------
glBegin(GL_QUADS);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.009f, 0.564f);
glVertex2f(-0.003f, 0.568f);
glVertex2f(0.002f, 0.57f);
glVertex2f(-0.005f, 0.56f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.564f);
glVertex2f(-0.004f, 0.568f);
glVertex2f(0.003f, 0.57f);
glVertex2f(-0.006f, 0.56f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.01f, 0.5f);
glVertex2f(-0.003f, 0.508f);
glVertex2f(0.0f, 0.508f);
glVertex2f(0.006f, 0.496f);
glVertex2f(-0.003f, 0.496f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.5f);
glVertex2f(-0.003f, 0.508f);
glVertex2f(0.0f, 0.508f);
glVertex2f(0.006f, 0.496f);
glVertex2f(-0.003f, 0.496f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.01f, 0.482f);
glVertex2f(0.004f, 0.492f);
glVertex2f(0.009f, 0.492f);
glVertex2f(0.02f, 0.476f);
glVertex2f(0.002f, 0.476f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.482f);
glVertex2f(0.004f, 0.492f);
glVertex2f(0.009f, 0.492f);
glVertex2f(0.02f, 0.476f);
glVertex2f(0.002f, 0.476f);
glEnd();
//fire 1
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.54f);
glVertex2f(0.075f, 0.542f);
glVertex2f(0.067f, 0.532f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.54f);
glVertex2f(0.075f, 0.542f);
glVertex2f(0.067f, 0.532f);
glEnd();
//fire 2
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.536f);
glVertex2f(0.078f, 0.536f);
glVertex2f(0.067f, 0.526f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.536f);
glVertex2f(0.078f, 0.536f);
glVertex2f(0.067f, 0.526f);
glEnd();
//fire 3
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.532f);
glVertex2f(0.079f, 0.528f);
glVertex2f(0.067f, 0.522f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.532f);
glVertex2f(0.079f, 0.528f);
glVertex2f(0.067f, 0.522f);
glEnd();
//fire 4
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.53f);
glVertex2f(0.075f, 0.522f);
glVertex2f(0.067f, 0.524f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.53f);
glVertex2f(0.075f, 0.522f);
glVertex2f(0.067f, 0.524f);
glEnd();

glPopMatrix();


glFlush();
}



void display3(int b)
{
    glutDisplayFunc(village_design);

    // Start the timer ONCE
    static bool started3 = false;
    if (!started3) {
        glutTimerFunc(15, timerD3, 0);
        sound3(0);
        started3 = true;
    }
}









void aiub_design() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

///_________________________________________________SKY(1)___________________________________________________///

    glBegin(GL_QUADS);
    glColor3f(0.184, 0.702, 0.945);
    glVertex2f(-1.0f,1.00f);
    glColor3f(0.514, 0.792, 0.976);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glColor3f(0, 0.502, 0.757);
    glVertex2f(1.0f,1.00f);
    glEnd();

///_________________________________________________SUN___________________________________________________///
glColor3ub(243,149,0);

// circle
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.08f, 0.78f);  // translated center
    for(int i = 0; i <= triangleAmount; i++) {
        glColor3ub(250, 235, 0);
        glVertex2f(0.09f * cos(i * twicePi / triangleAmount) + 0.08f,
                   0.09f * sin(i * twicePi / triangleAmount) + 0.78f);
    }
glEnd();


///_________________________________________________Clouds 1___________________________________________________///
glPushMatrix();
glTranslatef(cloudX, 0.0, 0.0);

// cloud 1
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.76f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.76f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.72f, 0.88f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.72f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.88f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.73f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.73f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.68f, 0.88f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.68f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.88f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.69f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.69f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.65f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.65f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

// cloud 2
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.46f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.46f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.54f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.54f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.55f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.55f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.50f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.50f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.51f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.51f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.47f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.47f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

///_________________________________________________Clouds 3___________________________________________________///
glColor3f(1.0f, 1.0f, 1.0f);

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.44f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.44f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.48f, 0.88f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.48f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.88f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.47f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.47f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.52f, 0.88f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.52f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.88f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.51f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.51f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.55f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.55f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();


///_________________________________________________Clouds 4___________________________________________________///

glColor3f(1.0f, 1.0f, 1.0f);

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.62f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.62f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.66f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.66f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.65f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.65f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.70f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.70f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.69f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.69f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.73f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.73f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();



///_________________________________________________Clouds 5___________________________________________________///

glColor3f(1.0f, 1.0f, 1.0f);

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.08f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.08f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.04f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.04f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.05f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.05f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.00f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.00f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.01f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.01f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.03f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.03f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();


glPopMatrix();





///_________________________________________________Clouds 1___________________________________________________///
glPushMatrix();
glTranslatef(cloudX1, 0.0, 0.0);

// cloud 1
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.76f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.76f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.72f, 0.88f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.72f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.88f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.73f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.73f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.68f, 0.88f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.68f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.88f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.69f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.69f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.65f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.65f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

// cloud 2
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.46f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.46f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.54f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.54f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.55f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.55f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.50f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.50f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.51f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.51f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }

    glVertex2f(-0.47f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.47f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

///_________________________________________________Clouds 3___________________________________________________///
glColor3f(1.0f, 1.0f, 1.0f);

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.44f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.44f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.48f, 0.88f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.48f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.88f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.47f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.47f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.52f, 0.88f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.52f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.88f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.51f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.51f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.55f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.55f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();


///_________________________________________________Clouds 4___________________________________________________///

glColor3f(1.0f, 1.0f, 1.0f);

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.62f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.62f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.66f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.66f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.65f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.65f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.70f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.70f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.69f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.69f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.73f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.73f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();



///_________________________________________________Clouds 5___________________________________________________///

glColor3f(1.0f, 1.0f, 1.0f);

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.08f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.08f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.04f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.04f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.05f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.05f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.00f, 0.84f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.00f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.84f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.01f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(-0.01f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();

glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.03f, 0.80f);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(0.03f + 0.03f * cos(i * twicePi / triangleAmount),
                   0.80f + 0.03f * sin(i * twicePi / triangleAmount));
    }
glEnd();


glPopMatrix();



///_________________________________________________Soil(3)___________________________________________________///
glBegin(GL_QUADS);
glColor3f(0.244f, 0.192f, 0.0902f);
glVertex2f(-1.0f, -0.50f);

glColor3f(0.244f, 0.192f, 0.0902f);
glVertex2f(-0.18f, -0.50f);

glColor3f(0.85f, 0.75f, 0.55f);
glVertex2f(-0.18f, -0.30f);

glColor3f(0.85f, 0.75f, 0.55f);
glVertex2f(-1.0f, -0.30f);
glEnd();

///----------------------------Annex 1 Road---------------------------///
    // Base gray road
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.95f, -0.5f);
    glVertex2f(-0.95f, -0.3f);
    glVertex2f(-0.83f, -0.3f);
    glVertex2f(-0.83f, -0.5f);
    glEnd();
    // right white strip
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(-0.85f, -0.5f);
    glVertex2f(-0.83f, -0.5f);
    glVertex2f(-0.83f, -0.3f);
    glVertex2f(-0.85f, -0.3f);
    glEnd();

    // left white strip
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(-0.95f, -0.5f);
    glVertex2f(-0.93, -0.5f);
    glVertex2f(-0.93f, -0.3f);
    glVertex2f(-0.95f, -0.3f);
    glEnd();


///_________________________________________________Big ROAD___________________________________________________///

    // Base gray road
glColor3f(0.4f, 0.4f, 0.4f);
glBegin(GL_QUADS);
glVertex2f(-1.0f, -0.5f);
glVertex2f(-1.0f, -0.68f);
glVertex2f(1.0f, -0.68f);
glVertex2f(1.0f, -0.5f);
glEnd();

// Top white strip
glColor3f(0.9f, 0.9f, 0.9f);
glBegin(GL_QUADS);
glVertex2f(-0.85f, -0.5f);
glVertex2f(-0.85f, -0.53f);
glVertex2f(1.0f, -0.53f);
glVertex2f(1.0f, -0.5f);

//annex 1 road left sidebar top white strip
glVertex2f(-1.0f, -0.5f);
glVertex2f(-1.0f, -0.53f);
glVertex2f(-0.93f, -0.53f);
glVertex2f(-0.93f, -0.5f);
glEnd();

// Bottom gray strip
glColor3f(0.7f, 0.7f, 0.7f);
glBegin(GL_QUADS);
glVertex2f(-1.0f, -0.65f);
glVertex2f(-1.0f, -0.68f);
glVertex2f(0.065f, -0.68f);
glVertex2f(0.065f, -0.65f);
glEnd();

// bottom parking left sidebar
glColor3f(0.7f, 0.7f, 0.7f);
glBegin(GL_QUADS);
glVertex2f(0.25f, -0.65f);
glVertex2f(0.25f, -0.68f);
glVertex2f(1.0f, -0.68f);
glVertex2f(1.0f, -0.65f);
glEnd();

// Dashed middle line
glColor3f(1.0f, 1.0f, 1.0f);
float dashW = 0.04f;
float dashGap = 0.04f;
for(float x = -1.0f; x < 1.0f; x += dashW + dashGap) {
    glBegin(GL_QUADS);
    glVertex2f(x, -0.59f);
    glVertex2f(x, -0.6f);
    glVertex2f(x + dashW, -0.6f);
    glVertex2f(x + dashW, -0.59f);
    glEnd();
}



///_________________________________________________Small ROAD___________________________________________________///
// --- Vertical Road Base ---
glBegin(GL_QUADS);
glColor3f(0.4f, 0.4f, 0.4f); // asphalt
glVertex2f(0.05f, -1.0f);
glVertex2f(0.05f, -0.68f);
glVertex2f(0.25f, -0.68f);
glVertex2f(0.25f, -1.0f);
glEnd();

// --- Sidewalk / right Light Strip ---
glBegin(GL_QUADS);
glColor3f(0.7f, 0.7f, 0.7f); // bottom strip
glVertex2f(0.05f, -0.68f);
glVertex2f(0.065f, -0.68f);
glVertex2f(0.065f, -0.82f);
glVertex2f(0.05f, -0.82f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.7f, 0.7f, 0.7f); // bottom strip
glVertex2f(0.25f, -0.68f);
glVertex2f(0.265f, -0.68f);
glVertex2f(0.265f, -0.754f);
glVertex2f(0.25f, -0.754f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.7f, 0.7f, 0.7f); // bottom strip
glVertex2f(0.25f, -0.924f);
glVertex2f(0.265f, -0.924f);
glVertex2f(0.265f, -1.0f);
glVertex2f(0.25f, -1.0f);
glEnd();

// --- Dashed Line in Middle ---
glColor3f(1.0f, 1.0f, 1.0f);
float sdashW = 0.04f;   // width of dash
float sdashGap = 0.04f; // gap between dashes
for(float y = -0.68f; y > -1.0f; y -= sdashW + sdashGap) {
    glBegin(GL_QUADS);
    glVertex2f(0.155f, y);
    glVertex2f(0.162f, y);
    glVertex2f(0.162f, y - sdashW);
    glVertex2f(0.155f, y - sdashW);
    glEnd();
}









///_________ Swimming Pool (Flat Top View) ________///
// Swimming Pool (Flat Top View)
// --- Outer Pool Border (thicker gray ring) ---
glColor3f(0.2f, 0.6f, 0.9f); // water blue
glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= triangleAmount; i++) {
        float theta = i * twicePi / triangleAmount;
        float x = 0.4f * (0.32f * cos(theta)) + 0.265f; // 0.245 + 0.04
        float y = 0.15f * (0.32f * sin(theta)) + 0.305f;
        float x_new = x * 2.0f - 1.0f;
        float y_new = y * 2.0f - 1.0f;
        glVertex2f(x_new, y_new);
    }
glEnd();

// --- Pool Fill (Blue Water) ---
glColor3f(0.7f, 0.7f, 0.7f); // silver/gray
glBegin(GL_TRIANGLE_FAN);
    // Center point
    float x_center = 0.4f * 0.0f + 0.245f; // 0.245 + 0.04
    float y_center = 0.15f * 0.0f + 0.305f;
    float x_center_new = x_center * 2.0f - 1.0f;
    float y_center_new = y_center * 2.0f - 1.0f;
    glVertex2f(x_center_new, y_center_new); // Center
    for (int i = 0; i <= triangleAmount; i++) {
        float theta = i * twicePi / triangleAmount;
        float x = 0.4f * (0.25f * cos(theta)) + 0.265f; // 0.245 + 0.04
        float y = 0.15f * (0.25f * sin(theta)) + 0.305f;
        float x_new = x * 2.0f - 1.0f;
        float y_new = y * 2.0f - 1.0f;
        glVertex2f(x_new, y_new);
    }
glEnd();

// --- Inner Border (white/silver line touching water) ---
glLineWidth(10);
glColor3f(0.9f, 0.9f, 0.9f);
glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= triangleAmount; i++) {
        float theta = i * twicePi / triangleAmount;
        float x = 0.4f * (0.32f * cos(theta)) + 0.265f; // 0.245 + 0.04
        float y = 0.15f * (0.32f * sin(theta)) + 0.305f;
        float x_new = x * 2.0f - 1.0f;
        float y_new = y * 2.0f - 1.0f;
        glVertex2f(x_new, y_new);
    }
glEnd();


///_________________________________________________Annex(1)___________________________________________________///
//tower
// Tower vertical lines (tapered)
glLineWidth(3);
glBegin(GL_LINES);
glColor3f(0.4f, 0.4f, 0.45f);
glVertex2f(-0.842f, 0.10f);
glVertex2f(-0.832f, -0.30f);  // left side
glVertex2f(-0.81f, 0.10f);
glVertex2f(-0.82f, -0.30f);   // right side

glVertex2f(-0.842f, 0.10f);
glVertex2f(-0.81f, 0.10f);
glEnd();

// Diagonal crossbars
glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.5f, 0.5f, 0.55f);
glVertex2f(-0.838f, 0.10f); glVertex2f(-0.814f, -0.10f);
glVertex2f(-0.838f, -0.10f); glVertex2f(-0.814f, 0.10f);
glVertex2f(-0.838f, -0.10f); glVertex2f(-0.814f, -0.30f);
glVertex2f(-0.838f, -0.30f); glVertex2f(-0.814f, -0.10f);
glEnd();

// Horizontal level lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.5f, 0.5f, 0.55f);
glVertex2f(-0.842f, 0.0f); glVertex2f(-0.81f, 0.0f);
glVertex2f(-0.842f, -0.15f); glVertex2f(-0.81f, -0.15f);
glVertex2f(-0.842f, -0.25f); glVertex2f(-0.81f, -0.25f);
glEnd();

// Signal lights as small crosses
glLineWidth(2);
glBegin(GL_LINES);
glColor3f(1.0f, 0.2f, 0.2f); // red signals
// L1
glVertex2f(-0.862f, 0.0f); glVertex2f(-0.858f, 0.0f);
glVertex2f(-0.86f, -0.002f); glVertex2f(-0.86f, 0.002f);
// R1
glVertex2f(-0.79f, 0.06f); glVertex2f(-0.786f, 0.06f);
glVertex2f(-0.788f, 0.058f); glVertex2f(-0.788f, 0.062f);
// R2
glVertex2f(-0.79f, -0.06f); glVertex2f(-0.786f, -0.06f);
glVertex2f(-0.788f, -0.062f); glVertex2f(-0.788f, -0.058f);
glEnd();

// Antenna tip
glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.7f, 0.7f, 0.7f);
glVertex2f(-0.826f, 0.10f); glVertex2f(-0.826f, 0.15f);
glEnd();



///_________Annex 1 Body________///
glColor3f(0.54f, 0.29f, 0.24f);   // brick color

glBegin(GL_QUADS);
glColor3f(0.74f, 0.29f, 0.24f);
glVertex2f(-1.0f, -0.18f);
glVertex2f(-1.0f, -0.30f);
glVertex2f(-0.75f, -0.30f);
glVertex2f(-0.75f, -0.18f);
glEnd();


///_________Brick Wall design________///
glColor3f(1.0f, 1.0f, 1.0f); // black outlines (mortar lines)
glLineWidth(1.0f);

// Row 1 (top row)
glBegin(GL_LINE_LOOP);
glVertex2f(-1.0f, -0.18f); glVertex2f(-1.0f, -0.22f);
glVertex2f(-0.95f, -0.22f); glVertex2f(-0.95f, -0.18f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.95f, -0.18f); glVertex2f(-0.95f, -0.22f);
glVertex2f(-0.90f, -0.22f); glVertex2f(-0.90f, -0.18f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.90f, -0.18f); glVertex2f(-0.90f, -0.22f);
glVertex2f(-0.85f, -0.22f); glVertex2f(-0.85f, -0.18f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.85f, -0.18f); glVertex2f(-0.85f, -0.22f);
glVertex2f(-0.80f, -0.22f); glVertex2f(-0.80f, -0.18f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.80f, -0.18f); glVertex2f(-0.80f, -0.22f);
glVertex2f(-0.75f, -0.22f); glVertex2f(-0.75f, -0.18f);
glEnd();

// Row 2 (offset row)
glBegin(GL_LINE_LOOP);
glVertex2f(-1.0f, -0.22f); glVertex2f(-1.0f, -0.26f);
glVertex2f(-0.97f, -0.26f); glVertex2f(-0.97f, -0.22f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.97f, -0.22f); glVertex2f(-0.97f, -0.26f);
glVertex2f(-0.92f, -0.26f); glVertex2f(-0.92f, -0.22f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.92f, -0.22f); glVertex2f(-0.92f, -0.26f);
glVertex2f(-0.87f, -0.26f); glVertex2f(-0.87f, -0.22f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.87f, -0.22f); glVertex2f(-0.87f, -0.26f);
glVertex2f(-0.82f, -0.26f); glVertex2f(-0.82f, -0.22f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.82f, -0.22f); glVertex2f(-0.82f, -0.26f);
glVertex2f(-0.75f, -0.26f); glVertex2f(-0.75f, -0.22f);
glEnd();

// Row 3 (repeat top row)
glBegin(GL_LINE_LOOP);
glVertex2f(-1.0f, -0.26f); glVertex2f(-1.0f, -0.30f);
glVertex2f(-0.95f, -0.30f); glVertex2f(-0.95f, -0.26f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.95f, -0.26f); glVertex2f(-0.95f, -0.30f);
glVertex2f(-0.90f, -0.30f); glVertex2f(-0.90f, -0.26f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.90f, -0.26f); glVertex2f(-0.90f, -0.30f);
glVertex2f(-0.85f, -0.30f); glVertex2f(-0.85f, -0.26f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.85f, -0.26f); glVertex2f(-0.85f, -0.30f);
glVertex2f(-0.80f, -0.30f); glVertex2f(-0.80f, -0.26f);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2f(-0.80f, -0.26f); glVertex2f(-0.80f, -0.30f);
glVertex2f(-0.75f, -0.30f); glVertex2f(-0.75f, -0.26f);
glEnd();


//Annex 1 bottom stand
glBegin(GL_QUADS);
glColor3f(0.33f, 0.25f, 0.24f);   // earthy brick tone
glVertex2f(-1.0f, -0.30);
glVertex2f(-1.0f, -0.32f);
glVertex2f(-0.74f, -0.32f);
glVertex2f(-0.75f, -0.30f);

///_________Annex 1 Top________///
glColor3f(0.20f, 0.50f, 0.25f);   // leafy green roof
glVertex2f(-1.0f, -0.12f);
glVertex2f(-1.0f, -0.18f);
glVertex2f(-0.73f, -0.18f);
glVertex2f(-0.75f, -0.12f);

///_________Annex 1 Under Top________///
glColor3f(0.95f, 0.93f, 0.80f);   // light cream accent
glVertex2f(-1.155f, -0.18f);
glVertex2f(-1.155f, -0.188f);
glVertex2f(-0.75f, -0.188f);
glVertex2f(-0.75f, -0.18f);



///_________Annex 1 Windows________///
glColor3f(0.70f, 0.88f, 1.0f);    // reflective light blue
// Window 1
glVertex2f(-0.98f, -0.21f);
glVertex2f(-0.98f, -0.27f);
glVertex2f(-0.94f, -0.27f);
glVertex2f(-0.94f, -0.21f);
// Window 2
glVertex2f(-0.895f, -0.21f);
glVertex2f(-0.895f, -0.27f);
glVertex2f(-0.855f, -0.27f);
glVertex2f(-0.855f, -0.21f);
// Window 3
glVertex2f(-0.81f, -0.21f);
glVertex2f(-0.81f, -0.27f);
glVertex2f(-0.77f, -0.27f);
glVertex2f(-0.77f, -0.21f);
glEnd();


///_______________________________________________C Building (Shifted Right 50%)___________________________________________________///
GLfloat radius = 0.16f;
// === Circle with stronger gradient using primary color ===
glBegin(GL_TRIANGLE_FAN);
// Center (brighter for more visible shine)
glColor3f(0.92f, 0.91f, 0.88f); // brighter highlight
glVertex2f(-0.469f, 0.04f);
// Outer edge (primary color)
for(int i = 0; i <= triangleAmount; i++) {
    GLfloat angle = i * twicePi / triangleAmount;
    GLfloat x = 0.245f + radius * cos(angle);
    GLfloat y = 0.52f + radius * sin(angle);
    glColor3f(0.675f, 0.663f, 0.643f); // primary color
    glVertex2f(((x * 2.0f - 1.0f) * 0.9f - 0.01f), (y * 2.0f - 1.0f));
}
glEnd();
// === Circle Border ===
glColor3f(0.2f, 0.2f, 0.2f); // dark outline
glLineWidth(2.0f);
glBegin(GL_LINE_LOOP);
for(int i = 0; i <= triangleAmount; i++) {
    GLfloat angle = i * twicePi / triangleAmount;
    GLfloat x = 0.245f + radius * cos(angle);
    GLfloat y = 0.52f + radius * sin(angle);
    glVertex2f(((x * 2.0f - 1.0f) * 0.9f - 0.01f), (y * 2.0f - 1.0f));
}
glEnd();
glBegin(GL_QUADS);
glColor3f(0.4f, 0.6f, 0.8f);
glVertex2f(-0.7066f, 0.22f);
glVertex2f(-0.7372f, 0.16f);
glVertex2f(-0.2026f, 0.16f);
glVertex2f(-0.2332f, 0.22f);
glVertex2f(-0.7498f, 0.10f);
glVertex2f(-0.7570f, 0.04f);
glVertex2f(-0.1810f, 0.04f);
glVertex2f(-0.1882f, 0.10f);
glVertex2f(-0.7534f, -0.02f);
glVertex2f(-0.7372f, -0.08f);
glVertex2f(-0.2008f, -0.08f);
glVertex2f(-0.1846f, -0.02f);
glVertex2f(-0.7066f, -0.14f);
glVertex2f(-0.6598f, -0.20f);
glVertex2f(-0.2782f, -0.20f);
glVertex2f(-0.2314f, -0.14f);
glEnd();
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.5);
glBegin(GL_LINE_LOOP);
    glVertex2f(-0.7066f, 0.22f);
    glVertex2f(-0.7372f, 0.16f);
    glVertex2f(-0.2026f, 0.16f);
    glVertex2f(-0.2332f, 0.22f);
glEnd();
glBegin(GL_LINE_LOOP);
    glVertex2f(-0.7498f, 0.10f);
    glVertex2f(-0.7570f, 0.04f);
    glVertex2f(-0.1810f, 0.04f);
    glVertex2f(-0.1882f, 0.10f);
glEnd();
glBegin(GL_LINE_LOOP);
    glVertex2f(-0.7534f, -0.02f);
    glVertex2f(-0.7372f, -0.08f);
    glVertex2f(-0.2008f, -0.08f);
    glVertex2f(-0.1846f, -0.02f);
glEnd();
glBegin(GL_LINE_LOOP);
    glVertex2f(-0.7066f, -0.14f);
    glVertex2f(-0.6598f, -0.20f);
    glVertex2f(-0.2782f, -0.20f);
    glVertex2f(-0.2314f, -0.14f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.675f, 0.663f, 0.643f);
glVertex2f(-0.6166f, -0.24f);
glVertex2f(-0.6166f, -0.38f);
glVertex2f(-0.3214f, -0.38f);
glVertex2f(-0.3214f, -0.24f);
glEnd();
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(2);
glBegin(GL_LINE_LOOP);
    glVertex2f(-0.6166f, -0.24f);
    glVertex2f(-0.6166f, -0.38f);
    glVertex2f(-0.3214f, -0.38f);
    glVertex2f(-0.3214f, -0.24f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.294f, 0.525f, 0.71f);
glVertex2f(-0.6166f, -0.28f);
glVertex2f(-0.6166f, -0.34f);
glVertex2f(-0.3214f, -0.34f);
glVertex2f(-0.3214f, -0.28f);
glEnd();
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINE_LOOP);
    glVertex2f(-0.6166f, -0.28f);
    glVertex2f(-0.6166f, -0.34f);
    glVertex2f(-0.3214f, -0.34f);
    glVertex2f(-0.3214f, -0.28f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.9f, 0.9f, 0.9f);
glVertex2f(-0.5194f, -0.26f);
glVertex2f(-0.5194f, -0.38f);
glVertex2f(-0.4294f, -0.38f);
glVertex2f(-0.4294f, -0.26f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.5f, 0.8f, 1.0f);
glVertex2f(-0.5122f, -0.27f);
glVertex2f(-0.5122f, -0.33f);
glVertex2f(-0.4366f, -0.33f);
glVertex2f(-0.4366f, -0.27f);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f(0.8f, 1.0f, 1.0f);
glVertex2f(-0.5122f, -0.27f);
glVertex2f(-0.4780f, -0.27f);
glVertex2f(-0.5122f, -0.30f);
glEnd();
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.1f, 0.1f);
glVertex2f(-0.4510f, -0.33f);
for(int i = 0; i <= 30; i++) {
    float angle = i * 2.0f * 3.1415926f / 30;
    float x = 0.015f + 0.004f * cos(angle) + 0.245f;
    float y = 0.225f + 0.004f * sin(angle) + 0.11f;
    glVertex2f(((x * 2.0f - 1.0f) * 0.9f - 0.01f), (y * 2.0f - 1.0f));
}
glEnd();
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.7f, 0.7f, 0.7f);
glVertex2f(-0.4510f, -0.33f);
for(int i = 0; i <= 30; i++) {
    float angle = i * 2.0f * 3.1415926f / 30;
    float x = 0.015f + 0.002f * cos(angle) + 0.245f;
    float y = 0.225f + 0.002f * sin(angle) + 0.11f;
    glVertex2f(((x * 2.0f - 1.0f) * 0.9f - 0.01f), (y * 2.0f - 1.0f));
}
glEnd();
//top
glBegin(GL_QUADS);
glColor3f(0.3f, 0.3f, 0.3f);
glVertex2f(-0.6166f, -0.38f);
glVertex2f(-0.3214f, -0.38f);
glVertex2f(-0.2800f, -0.465f);
glVertex2f(-0.6580f, -0.465f);
glEnd();
//bottom
glBegin(GL_QUADS);
glColor3f(0.2f, 0.2f, 0.2f);
glVertex2f(-0.6580f, -0.46f);
glVertex2f(-0.2800f, -0.46f);
glVertex2f(-0.2800f, -0.50f);
glVertex2f(-0.6580f, -0.50f);
glEnd();
//left bar
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f);
glVertex2f(-0.6580f, -0.46f);
glVertex2f(-0.6490f, -0.46f);
glVertex2f(-0.6490f, -0.32f);
glVertex2f(-0.6580f, -0.32f);
glEnd();
//right bar
glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.1f);
glVertex2f(-0.2890f, -0.46f);
glVertex2f(-0.2800f, -0.46f);
glVertex2f(-0.2800f, -0.32f);
glVertex2f(-0.2890f, -0.32f);
glEnd();
//shelter
glBegin(GL_QUADS);
glColor3f(0.78f, 0.2f, 0.07f);
glVertex2f(-0.6940f, -0.32f);
glVertex2f(-0.6130f, -0.24f);
glVertex2f(-0.3250f, -0.24f);
glVertex2f(-0.2530f, -0.32f);
glEnd();




///_________________________________________________Annex 9(Start)___________________________________________________///
// Floor 1 polygon
glBegin(GL_POLYGON);
glColor3f(0.70f, 0.695f, 0.705f);
glVertex2f(-0.18f, -0.5f);
glVertex2f(-0.18f, -0.38f);
glColor3f(0.80f, 0.795f, 0.805f);
glVertex2f(0.38f, -0.38f);
glVertex2f(0.38f, -0.5f);
glEnd();
// Floor 2 polygon
glBegin(GL_POLYGON);
glColor3f(0.70f, 0.695f, 0.705f);
glVertex2f(-0.18f, -0.38f);
glVertex2f(-0.18f, -0.26f);
glColor3f(0.80f, 0.795f, 0.805f);
glVertex2f(0.38f, -0.26f);
glVertex2f(0.38f, -0.38f);
glEnd();
// Floor 3 polygon
glBegin(GL_POLYGON);
glColor3f(0.70f, 0.695f, 0.705f);
glVertex2f(-0.18f, -0.26f);
glVertex2f(-0.18f, -0.14f);
glColor3f(0.80f, 0.795f, 0.805f);
glVertex2f(0.38f, -0.14f);
glVertex2f(0.38f, -0.26f);
glEnd();
// Floor 4 polygon
glBegin(GL_POLYGON);
glColor3f(0.70f, 0.695f, 0.705f);
glVertex2f(-0.18f, -0.14f);
glVertex2f(-0.18f, -0.02f);
glColor3f(0.80f, 0.795f, 0.805f);
glVertex2f(0.38f, -0.02f);
glVertex2f(0.38f, -0.14f);
glEnd();
// Floor borders
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.18f, -0.38f);
glVertex2f(0.38f, -0.38f);
glVertex2f(-0.18f, -0.26f);
glVertex2f(0.38f, -0.26f);
glVertex2f(-0.18f, -0.14f);
glVertex2f(0.38f, -0.14f);
glVertex2f(-0.18f, -0.02f);
glVertex2f(0.38f, -0.02f);
glEnd();
// Roof base layer
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f);
glVertex2f(-0.02f, -0.02f);
glVertex2f(-0.02f, 0.05f);
glVertex2f(0.22f, 0.05f);
glVertex2f(0.22f, -0.02f);
glEnd();
// Roof top layer
glBegin(GL_POLYGON);
glColor3f(0.85f, 0.85f, 0.85f);
glVertex2f(0.01f, 0.05f);
glVertex2f(0.01f, 0.08f);
glVertex2f(0.19f, 0.08f);
glVertex2f(0.19f, 0.05f);
glEnd();
// Corner highlights
glBegin(GL_LINES);
glColor3f(0.7f, 0.7f, 0.7f);
glLineWidth(2.0f);
glVertex2f(-0.02f, -0.02f);
glVertex2f(-0.02f, 0.05f);
glVertex2f(0.22f, -0.02f);
glVertex2f(0.22f, 0.05f);
glVertex2f(0.01f, 0.05f);
glVertex2f(0.01f, 0.08f);
glVertex2f(0.19f, 0.05f);
glVertex2f(0.19f, 0.08f);
glEnd();
// Roof texture lines
glBegin(GL_LINES);
glColor3f(0.75f, 0.75f, 0.75f);
glLineWidth(1.0f);
glVertex2f(-0.02f, 0.0f);
glVertex2f(0.22f, 0.0f);
glVertex2f(-0.02f, 0.02f);
glVertex2f(0.22f, 0.02f);
glVertex2f(0.01f, 0.06f);
glVertex2f(0.19f, 0.06f);
glEnd();
// Floor dividers
glBegin(GL_LINES);
glColor3f(0.5f, 0.5f, 0.5f);
glLineWidth(2.0f);
glVertex2f(-0.18f, -0.38f);
glVertex2f(0.38f, -0.38f);
glVertex2f(-0.18f, -0.26f);
glVertex2f(0.38f, -0.26f);
glVertex2f(-0.18f, -0.14f);
glVertex2f(0.38f, -0.14f);
glVertex2f(-0.18f, -0.02f);
glVertex2f(0.38f, -0.02f);
glEnd();
// Glass facade base
glBegin(GL_QUADS);
glColor3f(0.3f, 0.5f, 0.7f);
glVertex2f(0.04f, -0.5f);
glVertex2f(0.16f, -0.5f);
glColor3f(0.6f, 0.8f, 1.0f);
glVertex2f(0.16f, -0.02f);
glVertex2f(0.04f, -0.02f);
glEnd();
// Glass panels
for(int i = 0; i < 4; i++) {
    float y_bottom = i * 0.06f;
    float y_top = (i + 1) * 0.06f;
    // Main glass panel
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.6f, 0.8f);
    glVertex2f(0.044f, -0.5f + y_bottom * 2.0f);
    glVertex2f(0.156f, -0.5f + y_bottom * 2.0f);
    glVertex2f(0.156f, -0.5f + y_top * 2.0f);
    glVertex2f(0.044f, -0.5f + y_top * 2.0f);
    glEnd();
    // Inner glass panel
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.7f, 0.9f);
    glVertex2f(0.05f, -0.496f + y_bottom * 2.0f);
    glVertex2f(0.15f, -0.496f + y_bottom * 2.0f);
    glVertex2f(0.15f, -0.504f + y_top * 2.0f);
    glVertex2f(0.05f, -0.504f + y_top * 2.0f);
    glEnd();
    // Vertical glass lines
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glLineWidth(1.0f);
    glVertex2f(0.1f, -0.5f + y_bottom * 2.0f);
    glVertex2f(0.1f, -0.5f + y_top * 2.0f);
    glEnd();
}
// Top reflection
glBegin(GL_LINES);
glColor3f(0.85f, 0.95f, 1.0f);
glLineWidth(1.0f);
glVertex2f(0.044f, -0.02f);
glVertex2f(0.156f, -0.02f);
glEnd();
// Glass border
glBegin(GL_LINE_LOOP);
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(2.0f);
glVertex2f(0.04f, -0.5f);
glVertex2f(0.04f, -0.02f);
glVertex2f(0.16f, -0.02f);
glVertex2f(0.16f, -0.5f);
glEnd();
// Door base
glBegin(GL_POLYGON);
glColor3f(0.45f, 0.25f, 0.1f);
glVertex2f(0.04f, -0.5f);
glVertex2f(0.04f, -0.38f);
glVertex2f(0.16f, -0.38f);
glVertex2f(0.16f, -0.5f);
glEnd();
// Middle glass panel
glBegin(GL_POLYGON);
glColor3f(0.6f, 0.8f, 1.0f);
glVertex2f(0.084f, -0.5f);
glVertex2f(0.084f, -0.38f);
glVertex2f(0.116f, -0.38f);
glVertex2f(0.116f, -0.5f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.85f, 0.95f, 1.0f);
glVertex2f(0.084f, -0.38f);
glVertex2f(0.1f, -0.38f);
glVertex2f(0.084f, -0.44f);
glEnd();
// Door borders
glBegin(GL_LINE_LOOP);
glColor3f(0.2f, 0.15f, 0.1f);
glLineWidth(1.5f);
glVertex2f(0.04f, -0.5f);
glVertex2f(0.04f, -0.38f);
glVertex2f(0.16f, -0.38f);
glVertex2f(0.16f, -0.5f);
glEnd();
// Vertical divider
glBegin(GL_LINES);
glVertex2f(0.1f, -0.5f);
glVertex2f(0.1f, -0.38f);
glEnd();
// Small left glass door
glBegin(GL_POLYGON);
glColor3f(0.6f, 0.8f, 1.0f);
glVertex2f(-0.0752f, -0.5f);
glVertex2f(-0.0752f, -0.42f);
glVertex2f(-0.0452f, -0.42f);
glVertex2f(-0.0452f, -0.5f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.85f, 0.95f, 1.0f);
glVertex2f(-0.0752f, -0.42f);
glVertex2f(-0.0602f, -0.42f);
glVertex2f(-0.0752f, -0.46f);
glEnd();
// Glass door borders
glBegin(GL_LINE_LOOP);
glColor3f(0.2f, 0.15f, 0.1f);
glLineWidth(1.5f);
glVertex2f(-0.0752f, -0.5f);
glVertex2f(-0.0752f, -0.42f);
glVertex2f(-0.0452f, -0.42f);
glVertex2f(-0.0452f, -0.5f);
glEnd();
// Vertical divider
glBegin(GL_LINES);
glVertex2f(-0.0602f, -0.5f);
glVertex2f(-0.0602f, -0.42f);
glEnd();
// Floor 1 border
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(1);
glVertex2f(-0.18f, -0.38f);
glVertex2f(0.38f, -0.38f);
glEnd();
// Floor 2 border
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(1);
glVertex2f(-0.18f, -0.26f);
glVertex2f(0.38f, -0.26f);
glEnd();
// Floor 3 border
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(1);
glVertex2f(-0.18f, -0.14f);
glVertex2f(0.38f, -0.14f);
glEnd();
// Floor 4 border
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(1);
glVertex2f(-0.18f, -0.02f);
glVertex2f(0.38f, -0.02f);
glEnd();
// Ground floor window 1
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(0.24f, -0.48f);
glVertex2f(0.24f, -0.4f);
glVertex2f(0.18f, -0.4f);
glVertex2f(0.18f, -0.48f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(0.18f, -0.4f);
glVertex2f(0.21f, -0.4f);
glVertex2f(0.18f, -0.44f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.24f, -0.48f);
glVertex2f(0.24f, -0.4f);
glVertex2f(0.18f, -0.4f);
glVertex2f(0.18f, -0.48f);
glEnd();
// Middle vertical line
glBegin(GL_LINES);
glVertex2f(0.21f, -0.48f);
glVertex2f(0.21f, -0.4f);
glEnd();
// Ground floor window 2
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(0.35f, -0.48f);
glVertex2f(0.35f, -0.4f);
glVertex2f(0.29f, -0.4f);
glVertex2f(0.29f, -0.48f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(0.29f, -0.4f);
glVertex2f(0.32f, -0.4f);
glVertex2f(0.29f, -0.44f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.35f, -0.48f);
glVertex2f(0.35f, -0.4f);
glVertex2f(0.29f, -0.4f);
glVertex2f(0.29f, -0.48f);
glEnd();
// Middle vertical line
glBegin(GL_LINES);
glVertex2f(0.32f, -0.48f);
glVertex2f(0.32f, -0.4f);
glEnd();
// Floor 1 window 1
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(-0.04f, -0.36f);
glVertex2f(-0.04f, -0.28f);
glVertex2f(0.02f, -0.28f);
glVertex2f(0.02f, -0.36f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(-0.04f, -0.28f);
glVertex2f(-0.01f, -0.28f);
glVertex2f(-0.04f, -0.31f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.04f, -0.36f);
glVertex2f(-0.04f, -0.28f);
glVertex2f(0.02f, -0.28f);
glVertex2f(0.02f, -0.36f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.01f, -0.28f);
glVertex2f(-0.01f, -0.36f);
glEnd();
// Floor 1 window 2
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(-0.15f, -0.36f);
glVertex2f(-0.15f, -0.28f);
glVertex2f(-0.09f, -0.28f);
glVertex2f(-0.09f, -0.36f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(-0.15f, -0.28f);
glVertex2f(-0.12f, -0.28f);
glVertex2f(-0.15f, -0.31f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.15f, -0.36f);
glVertex2f(-0.15f, -0.28f);
glVertex2f(-0.09f, -0.28f);
glVertex2f(-0.09f, -0.36f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.12f, -0.28f);
glVertex2f(-0.12f, -0.36f);
glEnd();
// Floor 1 window 3
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(0.24f, -0.36f);
glVertex2f(0.24f, -0.28f);
glVertex2f(0.18f, -0.28f);
glVertex2f(0.18f, -0.36f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(0.18f, -0.28f);
glVertex2f(0.21f, -0.28f);
glVertex2f(0.18f, -0.31f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.24f, -0.36f);
glVertex2f(0.24f, -0.28f);
glVertex2f(0.18f, -0.28f);
glVertex2f(0.18f, -0.36f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.21f, -0.28f);
glVertex2f(0.21f, -0.36f);
glEnd();
// Floor 1 window 4
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(0.35f, -0.36f);
glVertex2f(0.35f, -0.28f);
glVertex2f(0.29f, -0.28f);
glVertex2f(0.29f, -0.36f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(0.29f, -0.28f);
glVertex2f(0.32f, -0.28f);
glVertex2f(0.29f, -0.31f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.35f, -0.36f);
glVertex2f(0.35f, -0.28f);
glVertex2f(0.29f, -0.28f);
glVertex2f(0.29f, -0.36f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.32f, -0.28f);
glVertex2f(0.32f, -0.36f);
glEnd();
// Floor 2 window 1
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(-0.04f, -0.24f);
glVertex2f(-0.04f, -0.16f);
glVertex2f(0.02f, -0.16f);
glVertex2f(0.02f, -0.24f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(-0.04f, -0.16f);
glVertex2f(-0.01f, -0.16f);
glVertex2f(-0.04f, -0.19f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.04f, -0.24f);
glVertex2f(-0.04f, -0.16f);
glVertex2f(0.02f, -0.16f);
glVertex2f(0.02f, -0.24f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.01f, -0.16f);
glVertex2f(-0.01f, -0.24f);
glEnd();
// Floor 2 window 2
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(-0.15f, -0.24f);
glVertex2f(-0.15f, -0.16f);
glVertex2f(-0.09f, -0.16f);
glVertex2f(-0.09f, -0.24f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(-0.15f, -0.16f);
glVertex2f(-0.12f, -0.16f);
glVertex2f(-0.15f, -0.19f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.15f, -0.24f);
glVertex2f(-0.15f, -0.16f);
glVertex2f(-0.09f, -0.16f);
glVertex2f(-0.09f, -0.24f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.12f, -0.16f);
glVertex2f(-0.12f, -0.24f);
glEnd();
// Floor 2 window 3
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(0.24f, -0.24f);
glVertex2f(0.24f, -0.16f);
glVertex2f(0.18f, -0.16f);
glVertex2f(0.18f, -0.24f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(0.18f, -0.16f);
glVertex2f(0.21f, -0.16f);
glVertex2f(0.18f, -0.19f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.24f, -0.24f);
glVertex2f(0.24f, -0.16f);
glVertex2f(0.18f, -0.16f);
glVertex2f(0.18f, -0.24f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.21f, -0.16f);
glVertex2f(0.21f, -0.24f);
glEnd();
// Floor 2 window 4
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(0.35f, -0.24f);
glVertex2f(0.35f, -0.16f);
glVertex2f(0.29f, -0.16f);
glVertex2f(0.29f, -0.24f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(0.29f, -0.16f);
glVertex2f(0.32f, -0.16f);
glVertex2f(0.29f, -0.19f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.35f, -0.24f);
glVertex2f(0.35f, -0.16f);
glVertex2f(0.29f, -0.16f);
glVertex2f(0.29f, -0.24f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.32f, -0.16f);
glVertex2f(0.32f, -0.24f);
glEnd();
// Floor 3 window 1
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(-0.04f, -0.12f);
glVertex2f(-0.04f, -0.04f);
glVertex2f(0.02f, -0.04f);
glVertex2f(0.02f, -0.12f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(-0.04f, -0.04f);
glVertex2f(-0.01f, -0.04f);
glVertex2f(-0.04f, -0.07f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.04f, -0.12f);
glVertex2f(-0.04f, -0.04f);
glVertex2f(0.02f, -0.04f);
glVertex2f(0.02f, -0.12f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.01f, -0.04f);
glVertex2f(-0.01f, -0.12f);
glEnd();
// Floor 3 window 2
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(-0.15f, -0.12f);
glVertex2f(-0.15f, -0.04f);
glVertex2f(-0.09f, -0.04f);
glVertex2f(-0.09f, -0.12f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(-0.15f, -0.04f);
glVertex2f(-0.12f, -0.04f);
glVertex2f(-0.15f, -0.07f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.15f, -0.12f);
glVertex2f(-0.15f, -0.04f);
glVertex2f(-0.09f, -0.04f);
glVertex2f(-0.09f, -0.12f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(-0.12f, -0.04f);
glVertex2f(-0.12f, -0.12f);
glEnd();
// Floor 3 window 3
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(0.24f, -0.12f);
glVertex2f(0.24f, -0.04f);
glVertex2f(0.18f, -0.04f);
glVertex2f(0.18f, -0.12f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(0.18f, -0.04f);
glVertex2f(0.21f, -0.04f);
glVertex2f(0.18f, -0.07f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.24f, -0.12f);
glVertex2f(0.24f, -0.04f);
glVertex2f(0.18f, -0.04f);
glVertex2f(0.18f, -0.12f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.21f, -0.04f);
glVertex2f(0.21f, -0.12f);
glEnd();
// Floor 3 window 4
glBegin(GL_POLYGON);
glColor3f(0.8f, 0.9f, 1.0f);
glVertex2f(0.35f, -0.12f);
glVertex2f(0.35f, -0.04f);
glVertex2f(0.29f, -0.04f);
glVertex2f(0.29f, -0.12f);
glEnd();
// Glass shine
glBegin(GL_TRIANGLES);
glColor3f(0.9f, 1.0f, 1.0f);
glVertex2f(0.29f, -0.04f);
glVertex2f(0.32f, -0.04f);
glVertex2f(0.29f, -0.07f);
glEnd();
// Black border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.35f, -0.12f);
glVertex2f(0.35f, -0.04f);
glVertex2f(0.29f, -0.04f);
glVertex2f(0.29f, -0.12f);
glEnd();
// Middle black border
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(1.0f);
glVertex2f(0.32f, -0.04f);
glVertex2f(0.32f, -0.12f);
glEnd();
// ----------------- Signboard "Annex 9" -----------------
// Black text for Annex 9
glColor3f(0.0f, 0.0f, 0.0f);
renderBitmapString(0.06f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Annex 9");



///_________________________________________________D building(Start)___________________________________________________///

// ----------------- Roof Base -----------------
glColor3f(0.35f, 0.35f, 0.35f); // dark gray base
glBegin(GL_POLYGON);
    glVertex2f(0.7f, 0.2616f);
    glVertex2f(0.7f, 0.3348f);
    glVertex2f(0.88f, 0.3348f);
    glVertex2f(0.88f, 0.2616f);
glEnd();
// ----------------- Roof Layer 1 (slightly lighter) -----------------
glColor3f(0.45f, 0.45f, 0.45f); // lighter gray edge
glBegin(GL_POLYGON);
    glVertex2f(0.71f, 0.3348f);
    glVertex2f(0.71f, 0.348f);
    glVertex2f(0.87f, 0.348f);
    glVertex2f(0.87f, 0.3348f);
glEnd();
// ----------------- Roof Layer 2 (railing / parapet) -----------------
glColor3f(0.1f, 0.1f, 0.1f); // almost black railing
glBegin(GL_POLYGON);
    glVertex2f(0.705f, 0.348f);
    glVertex2f(0.705f, 0.355f);
    glVertex2f(0.875f, 0.355f);
    glVertex2f(0.875f, 0.348f);
glEnd();
glColor3f(0.3f, 0.3f, 0.3f); // dark metallic gray
glBegin(GL_POLYGON);
    glVertex2f(0.751f, 0.355f);
    glVertex2f(0.751f, 0.385f);
    glVertex2f(0.831f, 0.385f);
    glVertex2f(0.831f, 0.355f);
glEnd();
// ----------------- Roof Tiles / Panels Lines -----------------
glColor3f(0.0f, 0.0f, 0.0f); // pure black panel lines
glLineWidth(1.5f);
glBegin(GL_LINES);
    glVertex2f(0.71f, 0.3348f); glVertex2f(0.87f, 0.3348f);
    glVertex2f(0.71f, 0.3414f); glVertex2f(0.87f, 0.3414f);
    glVertex2f(0.71f, 0.348f); glVertex2f(0.87f, 0.348f);
glEnd();
// ---------------- Building Body ----------------
glBegin(GL_QUADS);
glColor3f(0.196f, 0.376f, 0.51f);
glVertex2f(0.9f, -0.5f);
glVertex2f(0.9f, 0.32f);
glVertex2f(1.0f, 0.32f);
glVertex2f(1.0f, -0.5f);
// ---------------- Body 2 ----------------
glColor3f(0.765f, 0.761f, 0.769f);
glVertex2f(0.48f, -0.5f);
glVertex2f(0.48f, 0.26f);
glVertex2f(0.96f, 0.26f);
glVertex2f(0.96f, -0.5f);
// ---------------- 3 ----------------
glColor3f(0.4f, 0.6f, 0.8f);
glVertex2f(0.48f, 0.19f);
glVertex2f(0.48f, 0.23f);
glVertex2f(0.96f, 0.23f);
glVertex2f(0.96f, 0.19f);
// ---------------- 4 ----------------
glVertex2f(0.48f, 0.16f);
glVertex2f(0.48f, 0.12f);
glVertex2f(0.96f, 0.12f);
glVertex2f(0.96f, 0.16f);
// ---------------- 5 ----------------
glVertex2f(0.5f, 0.09f);
glVertex2f(0.5f, -0.01f);
glVertex2f(0.96f, -0.01f);
glVertex2f(0.96f, 0.09f);
// ---------------- 6 ----------------
glVertex2f(0.48f, -0.04f);
glVertex2f(0.48f, 0.09f);
glVertex2f(0.5f, 0.09f);
glVertex2f(0.5f, -0.01f);
// ---------------- 7 ----------------
glVertex2f(0.5f, -0.08f);
glVertex2f(0.96f, -0.08f);
glVertex2f(0.96f, -0.04f);
glVertex2f(0.5f, -0.04f);
// ---------------- 8 ----------------
glVertex2f(0.52f, -0.12f);
glVertex2f(0.52f, -0.22f);
glVertex2f(0.96f, -0.22f);
glVertex2f(0.96f, -0.12f);
// ---------------- 9 ----------------
glColor3f(0.4f, 0.6f, 0.8f);
glVertex2f(0.5f, -0.12f);
glVertex2f(0.5f, -0.25f);
glVertex2f(0.52f, -0.22f);
glVertex2f(0.52f, -0.12f);
// ---------------- 10 ----------------
glVertex2f(0.52f, -0.25f);
glVertex2f(0.52f, -0.29f);
glVertex2f(0.96f, -0.29f);
glVertex2f(0.96f, -0.25f);
// ---------------- 11 ----------------
glVertex2f(0.52f, -0.32f);
glVertex2f(0.52f, -0.36f);
glVertex2f(0.96f, -0.36f);
glVertex2f(0.96f, -0.32f);
// ---------------- 12 ----------------
glVertex2f(0.52f, -0.39f);
glVertex2f(0.52f, -0.44f);
glVertex2f(0.96f, -0.44f);
glVertex2f(0.96f, -0.39f);
// ---------------- 13 ----------------
glVertex2f(0.52f, -0.476f);
glVertex2f(0.52f, -0.5f);
glVertex2f(0.96f, -0.5f);
glVertex2f(0.96f, -0.476f);
// ---------------- 14 ----------------
glColor3f(0.765f, 0.761f, 0.769f);
glVertex2f(0.36f, 0.21f);
glVertex2f(0.36f, -0.5f);
glVertex2f(0.48f, -0.5f);
glVertex2f(0.48f, 0.26f);
// ---------------- 15 ----------------
glColor3f(0.4f, 0.6f, 0.8f);
glVertex2f(0.38f, 0.188f);
glVertex2f(0.38f, -0.5f);
glVertex2f(0.464f, -0.5f);
glVertex2f(0.464f, 0.22f);
// ---------------- 16 ----------------
glVertex2f(0.46f, -0.1f);
glVertex2f(0.46f, -0.5f);
glVertex2f(0.486f, -0.5f);
glVertex2f(0.486f, -0.06f);
// ---------------- 17 ----------------
glVertex2f(0.46f, -0.33f);
glVertex2f(0.46f, -0.5f);
glVertex2f(0.506f, -0.5f);
glVertex2f(0.506f, -0.27f);
glEnd();
// ---------------- D Building Border ----------------
glLineWidth(1.4);
glBegin(GL_LINES);
glColor3f(0.0, 0.0, 0.0);
// ---------------- 7th Floor ----------------
glVertex2f(0.96f, 0.006f);
glVertex2f(0.5f, 0.006f);
glVertex2f(0.5f, 0.006f);
glVertex2f(0.48f, -0.022f);
glVertex2f(0.5f, 0.006f);
glVertex2f(0.5f, 0.00f);
glVertex2f(0.62f, 0.006f);
glVertex2f(0.62f, 0.00f);
glVertex2f(0.74f, 0.006f);
glVertex2f(0.74f, 0.00f);
glVertex2f(0.86f, 0.006f);
glVertex2f(0.86f, 0.00f);
// ---------------- 5th Floor ----------------
glVertex2f(0.52f, -0.204f);
glVertex2f(0.96f, -0.204f);
glVertex2f(0.52f, -0.204f);
glVertex2f(0.5f, -0.23f);
glVertex2f(0.52f, -0.204f);
glVertex2f(0.52f, -0.22f);
glVertex2f(0.62f, -0.204f);
glVertex2f(0.62f, -0.22f);
glVertex2f(0.74f, -0.204f);
glVertex2f(0.74f, -0.22f);
glVertex2f(0.86f, -0.204f);
glVertex2f(0.86f, -0.22f);
// ---------------- D Window (1) ----------------
glVertex2f(0.974f, 0.22f);
glVertex2f(0.974f, 0.18f);
glVertex2f(0.986f, 0.18f);
glVertex2f(0.986f, 0.22f);
glVertex2f(0.986f, 0.22f);
glVertex2f(0.974f, 0.22f);
glVertex2f(0.974f, 0.18f);
glVertex2f(0.986f, 0.18f);
// ---------------- D Window (2) ----------------
glVertex2f(0.974f, 0.14f);
glVertex2f(0.974f, 0.1f);
glVertex2f(0.986f, 0.1f);
glVertex2f(0.986f, 0.14f);
glVertex2f(0.986f, 0.14f);
glVertex2f(0.974f, 0.14f);
glVertex2f(0.974f, 0.1f);
glVertex2f(0.986f, 0.1f);
// ---------------- D Window (3) ----------------
glVertex2f(0.974f, 0.06f);
glVertex2f(0.974f, 0.02f);
glVertex2f(0.986f, 0.02f);
glVertex2f(0.986f, 0.06f);
glVertex2f(0.974f, 0.06f);
glVertex2f(0.986f, 0.06f);
glVertex2f(0.974f, 0.02f);
glVertex2f(0.986f, 0.02f);
// ---------------- D Window (4) ----------------
glVertex2f(0.974f, -0.02f);
glVertex2f(0.974f, -0.06f);
glVertex2f(0.986f, -0.06f);
glVertex2f(0.986f, -0.02f);
glVertex2f(0.986f, -0.02f);
glVertex2f(0.974f, -0.02f);
glVertex2f(0.974f, -0.06f);
glVertex2f(0.986f, -0.06f);
// ---------------- D Window (5) ----------------
glVertex2f(0.974f, -0.1f);
glVertex2f(0.974f, -0.14f);
glVertex2f(0.986f, -0.14f);
glVertex2f(0.986f, -0.1f);
glVertex2f(0.986f, -0.1f);
glVertex2f(0.974f, -0.1f);
glVertex2f(0.974f, -0.14f);
glVertex2f(0.986f, -0.14f);
// ---------------- D Window (6) ----------------
glVertex2f(0.974f, -0.18f);
glVertex2f(0.974f, -0.22f);
glVertex2f(0.986f, -0.22f);
glVertex2f(0.986f, -0.18f);
glVertex2f(0.986f, -0.18f);
glVertex2f(0.974f, -0.18f);
glVertex2f(0.974f, -0.22f);
glVertex2f(0.986f, -0.22f);
// ---------------- D Window (7) ----------------
glVertex2f(0.974f, -0.26f);
glVertex2f(0.974f, -0.3f);
glVertex2f(0.986f, -0.3f);
glVertex2f(0.986f, -0.26f);
glVertex2f(0.986f, -0.26f);
glVertex2f(0.974f, -0.26f);
glVertex2f(0.974f, -0.3f);
glVertex2f(0.986f, -0.3f);
// ---------------- D Window (8) ----------------
glVertex2f(0.974f, -0.34f);
glVertex2f(0.974f, -0.38f);
glVertex2f(0.986f, -0.38f);
glVertex2f(0.986f, -0.34f);
glVertex2f(0.986f, -0.34f);
glVertex2f(0.974f, -0.34f);
glVertex2f(0.974f, -0.38f);
glVertex2f(0.986f, -0.38f);
// ---------------- D Window (9) ----------------
glVertex2f(0.974f, -0.42f);
glVertex2f(0.974f, -0.46f);
glVertex2f(0.986f, -0.46f);
glVertex2f(0.986f, -0.42f);
glVertex2f(0.986f, -0.42f);
glVertex2f(0.974f, -0.42f);
glVertex2f(0.974f, -0.46f);
glVertex2f(0.986f, -0.46f);
// ---------------- 1 ----------------
glVertex2f(0.9f, 0.26f);
glVertex2f(0.9f, 0.32f);
glVertex2f(0.9f, 0.32f);
glVertex2f(1.0f, 0.32f);
glVertex2f(0.96f, -0.5f);
glVertex2f(0.96f, 0.26f);
// ---------------- Body 2 ----------------
glVertex2f(0.48f, 0.26f);
glVertex2f(0.96f, 0.26f);
// ---------------- 3 ----------------
glVertex2f(0.48f, 0.19f);
glVertex2f(0.96f, 0.19f);
glVertex2f(0.48f, 0.23f);
glVertex2f(0.96f, 0.23f);
// ---------------- 4 ----------------
glVertex2f(0.48f, 0.16f);
glVertex2f(0.96f, 0.16f);
glVertex2f(0.48f, 0.12f);
glVertex2f(0.96f, 0.12f);
// ---------------- 5 ----------------
glVertex2f(0.5f, 0.09f);
glVertex2f(0.96f, 0.09f);
glVertex2f(0.5f, -0.01f);
glVertex2f(0.96f, -0.01f);
// ---------------- 6 ----------------
glVertex2f(0.48f, -0.04f);
glVertex2f(0.5f, -0.01f);
glVertex2f(0.48f, 0.09f);
glVertex2f(0.5f, 0.09f);
// ---------------- 7 ----------------
glVertex2f(0.5f, -0.08f);
glVertex2f(0.96f, -0.08f);
glVertex2f(0.96f, -0.04f);
glVertex2f(0.5f, -0.04f);
glVertex2f(0.5f, -0.08f);
glVertex2f(0.5f, -0.04f);
// ---------------- 8 ----------------
glVertex2f(0.52f, -0.12f);
glVertex2f(0.96f, -0.12f);
glVertex2f(0.52f, -0.22f);
glVertex2f(0.96f, -0.22f);
// ---------------- 9 ----------------
glVertex2f(0.5f, -0.12f);
glVertex2f(0.52f, -0.12f);
glVertex2f(0.5f, -0.25f);
glVertex2f(0.52f, -0.22f);
glVertex2f(0.5f, -0.12f);
glVertex2f(0.5f, -0.25f);
// ---------------- 10 ----------------
glVertex2f(0.52f, -0.25f);
glVertex2f(0.96f, -0.25f);
glVertex2f(0.52f, -0.29f);
glVertex2f(0.96f, -0.29f);
glVertex2f(0.52f, -0.29f);
glVertex2f(0.52f, -0.25f);
// ---------------- 11 ----------------
glVertex2f(0.52f, -0.32f);
glVertex2f(0.96f, -0.32f);
glVertex2f(0.52f, -0.36f);
glVertex2f(0.96f, -0.36f);
glVertex2f(0.52f, -0.36f);
glVertex2f(0.52f, -0.32f);
// ---------------- 12 ----------------
glVertex2f(0.52f, -0.39f);
glVertex2f(0.96f, -0.39f);
glVertex2f(0.52f, -0.44f);
glVertex2f(0.96f, -0.44f);
glVertex2f(0.52f, -0.44f);
glVertex2f(0.52f, -0.39f);
// ---------------- 13 ----------------
glVertex2f(0.52f, -0.476f);
glVertex2f(0.96f, -0.476f);
glVertex2f(0.52f, -0.5f);
glVertex2f(0.96f, -0.5f);
glVertex2f(0.52f, -0.476f);
glVertex2f(0.52f, -0.5f);
// ---------------- 14 ----------------
glVertex2f(0.36f, 0.21f);
glVertex2f(0.36f, -0.5f);
glVertex2f(0.48f, -0.04f);
glVertex2f(0.48f, 0.26f);
glVertex2f(0.36f, 0.21f);
glVertex2f(0.48f, 0.26f);
// ---------------- 15 ----------------
glVertex2f(0.38f, 0.188f);
glVertex2f(0.38f, -0.5f);
glVertex2f(0.464f, -0.094f);
glVertex2f(0.464f, 0.22f);
glVertex2f(0.38f, 0.188f);
glVertex2f(0.464f, 0.22f);
glVertex2f(0.38f, -0.5f);
glVertex2f(0.464f, -0.5f);
glVertex2f(0.464f, -0.094f);
glVertex2f(0.486f, -0.06f);
// ---------------- 16 ----------------
glVertex2f(0.486f, -0.3f);
glVertex2f(0.486f, -0.06f);
// ---------------- 17 ----------------
glVertex2f(0.485f, -0.3f);
glVertex2f(0.506f, -0.27f);
glVertex2f(0.506f, -0.5f);
glVertex2f(0.506f, -0.27f);
glEnd();
// ---------------- D Windows (Quads) ----------------
glBegin(GL_QUADS);
glColor3f(0.298f, 0.51f, 0.671f);
// ---------------- D Window (1) ----------------
glVertex2f(0.974f, 0.22f);
glVertex2f(0.974f, 0.18f);
glVertex2f(0.986f, 0.18f);
glVertex2f(0.986f, 0.22f);
// ---------------- D Window (2) ----------------
glVertex2f(0.974f, 0.14f);
glVertex2f(0.974f, 0.1f);
glVertex2f(0.986f, 0.1f);
glVertex2f(0.986f, 0.14f);
// ---------------- D Window (3) ----------------
glVertex2f(0.974f, 0.06f);
glVertex2f(0.974f, 0.02f);
glVertex2f(0.986f, 0.02f);
glVertex2f(0.986f, 0.06f);
// ---------------- D Window (4) ----------------
glVertex2f(0.974f, -0.02f);
glVertex2f(0.974f, -0.06f);
glVertex2f(0.986f, -0.06f);
glVertex2f(0.986f, -0.02f);
// ---------------- D Window (5) ----------------
glVertex2f(0.974f, -0.1f);
glVertex2f(0.974f, -0.14f);
glVertex2f(0.986f, -0.14f);
glVertex2f(0.986f, -0.1f);
// ---------------- D Window (6) ----------------
glVertex2f(0.974f, -0.18f);
glVertex2f(0.974f, -0.22f);
glVertex2f(0.986f, -0.22f);
glVertex2f(0.986f, -0.18f);
// ---------------- D Window (7) ----------------
glVertex2f(0.974f, -0.26f);
glVertex2f(0.974f, -0.3f);
glVertex2f(0.986f, -0.3f);
glVertex2f(0.986f, -0.26f);
// ---------------- D Window (8) ----------------
glVertex2f(0.974f, -0.34f);
glVertex2f(0.974f, -0.38f);
glVertex2f(0.986f, -0.38f);
glVertex2f(0.986f, -0.34f);
// ---------------- D Window (9) ----------------
glVertex2f(0.974f, -0.42f);
glVertex2f(0.974f, -0.46f);
glVertex2f(0.986f, -0.46f);
glVertex2f(0.986f, -0.42f);
glEnd();
///______________________________________________________D 7th & 5th Tree___________________________________________________///

///_________D 7th Tree 1________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(3.5f, 0.88f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 2________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(3.8f, 0.88f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();

///_________D 7th Tree 3________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(4.1f, 0.88f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 4________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(4.4f, 0.88f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();



///_________D 7th Tree 5________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(4.7f, 0.88f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 6________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(5.0f, 0.88f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 7________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(5.3f, 0.88f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 8________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(5.6f, 0.88f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();



///D building 5th floor tree///


///_________D 7th Tree 1________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(3.6f, -0.16f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 2________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(3.9f, -0.16f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();

///_________D 7th Tree 3________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(4.2f, -0.16f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 4________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(4.5f, -0.16f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();



///_________D 7th Tree 5________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(4.8f, -0.16f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 6________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(5.1f, -0.16f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 7________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(5.4f, -0.16f, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();


///_________D 7th Tree 8________///
///_________BODY________///
glPushMatrix();
glScalef(0.20, 0.20, 0.0);
glTranslatef(5.6f, -0.16, 0.0);

/// Trunk (unchanged)
glBegin(GL_POLYGON);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.92f, -0.935f);
glVertex2f(-0.92f, -0.815f);
glVertex2f(-0.9f, -0.815f);
glVertex2f(-0.9f, -0.935f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.42f, 0.235f, 0.012f);
glVertex2f(-0.9f, -0.9f);
glVertex2f(-0.9f, -0.884f);
glVertex2f(-0.884f, -0.87f);
glVertex2f(-0.92f, -0.92f);
glVertex2f(-0.92f, -0.904f);
glVertex2f(-0.944f, -0.89f);
glEnd();

///_________LEAVES (Redesigned Top Part)________///

/// Center top leaf cluster
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.2f, 0.55f, 0.1f);
glVertex2f(-0.91f, -0.76f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.05f * cos(i * twicePi / triangleAmount)),
               -0.76f + (0.05f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Left side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.1f, 0.6f, 0.1f);
glVertex2f(-0.95f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.95f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Right side leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.25f, 0.7f, 0.2f);
glVertex2f(-0.87f, -0.78f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.87f + (0.035f * cos(i * twicePi / triangleAmount)),
               -0.78f + (0.035f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper left leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18f, 0.55f, 0.15f);
glVertex2f(-0.94f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.94f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Upper right leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.65f, 0.2f);
glVertex2f(-0.88f, -0.72f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.88f + (0.03f * cos(i * twicePi / triangleAmount)),
               -0.72f + (0.03f * sin(i * twicePi / triangleAmount)));
}
glEnd();

/// Top crown leaf
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.15f, 0.5f, 0.1f);
glVertex2f(-0.91f, -0.68f);
for(int i = 0; i <= triangleAmount; i++) {
    glVertex2f(-0.91f + (0.025f * cos(i * twicePi / triangleAmount)),
               -0.68f + (0.025f * sin(i * twicePi / triangleAmount)));
}
glEnd();

glPopMatrix();



///______________________________________________________CARDD___________________________________________________///

///........................................Bus-1
   glPushMatrix();
    glTranslatef(carX, 0.08, 0.0);  // Move the car horizontally

    glBegin(GL_QUADS);
    glColor3f(0.14f,0.25f,0.12f);
    glVertex2f(-0.66f,-0.65f);
    glVertex2f(-0.66f,-0.55f);
    glVertex2f(-0.46f,-0.55f);
    glVertex2f(-0.46f,-0.65f);

    ///Front Side Extra Part
    glVertex2f(-0.46f,-0.65f);
    glVertex2f(-0.454f,-0.65f);
    glVertex2f(-0.454f,-0.60f);
    glVertex2f(-0.46f,-0.59f);

    ///Window Slide Green Part
    glColor3f(0.00f,0.0f,0.0f);
    glVertex2f(-0.654f,-0.59f);
    glVertex2f(-0.654f,-0.554f);
    glVertex2f(-0.464f,-0.554f);
    glVertex2f(-0.464f,-0.59f);

    ///Windows
    glColor3f(0.6f, 0.8f, 1.0f); // light blue glass
    //1
    glVertex2f(-0.65f,-0.586f);
    glVertex2f(-0.65f,-0.558f);
    glVertex2f(-0.623f,-0.558f);
    glVertex2f(-0.623f,-0.586f);
    //2
    glVertex2f(-0.618f,-0.586f);
    glVertex2f(-0.618f,-0.558f);
    glVertex2f(-0.59f,-0.558f);
    glVertex2f(-0.59f,-0.586f);
    //3
    glVertex2f(-0.586f,-0.586f);
    glVertex2f(-0.586f,-0.558f);
    glVertex2f(-0.556f,-0.558f);
    glVertex2f(-0.556f,-0.586f);
    //4
    glVertex2f(-0.51f,-0.586f);
    glVertex2f(-0.51f,-0.558f);
    glVertex2f(-0.484f,-0.558f);
    glVertex2f(-0.484f,-0.586f);
    //5
    glVertex2f(-0.48f,-0.586f);
    glVertex2f(-0.48f,-0.558f);
    glVertex2f(-0.468f,-0.558f);
    glVertex2f(-0.468f,-0.586f);

    ///Door
    glColor3f(0.2f, 0.5f, 0.8f);
    glVertex2f(-0.55f,-0.65f);
    glVertex2f(-0.55f,-0.566f);
    glVertex2f(-0.514f,-0.566f);
    glVertex2f(-0.514f,-0.65f);
    glEnd();

    ///Bus Door Line
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.532f,-0.65f);
    glVertex2f(-0.532f,-0.562f);

    ///Side Mirror Stand
    glColor3f(0.14f,0.25f,0.12f);
    glVertex2f(-0.46f,-0.56f);
    glVertex2f(-0.446f,-0.56f);
    glEnd();

    ///Side Mirror
    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.446f,-0.56f);
    glVertex2f(-0.446f,-0.59f);
    glEnd();

    ///Bus Tire Right
    GLfloat A50=-0.486f; GLfloat P50=-0.65f; GLfloat O50 =0.016f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A50, P50);
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A50 + (O50 * cos(i *  twicePi/ triangleAmount)),
                        P50 + (O50 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();

    ///Bus Tire Alloy Right
    GLfloat A51=-0.486f; GLfloat P51=-0.65f; GLfloat O51 =0.008f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A51, P51);
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A51 + (O51 * cos(i *  twicePi/ triangleAmount)),
                        P51 + (O51 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();

    ///Bus Tire Left
    GLfloat A52=-0.632f; GLfloat P52=-0.65f; GLfloat O52 =0.016f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A52, P52);
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A52 + (O52 * cos(i *  twicePi/ triangleAmount)),
                        P52 + (O52 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();

    ///Bus Tire Alloy Left
    GLfloat A53=-0.632f; GLfloat P53=-0.65f; GLfloat O53 =0.008f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A53, P53);
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A53 + (O53 * cos(i *  twicePi/ triangleAmount)),
                        P53 + (O53 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
glPopMatrix();





/// ------------------------------------------------AIUB Parking System---------------------------------------///

// --- Background (parking ground) ---
// --- Parking area ---
glBegin(GL_QUADS);
    glColor3f(0.47f, 0.45f, 0.47f);
    glVertex2f(-1.0f, -0.68f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-0.1f, -1.0f);
    glVertex2f(-0.1f, -0.68f);
glEnd();

//green field
glBegin(GL_QUADS);
    glColor3f(0.0f, 0.75f, 0.0f); // asphalt
    glVertex2f(-0.1f, -0.68f);
    glVertex2f(-0.1f, -0.82f);
    glVertex2f(0.05f, -0.82f);
    glVertex2f(0.05f, -0.68f);
glEnd();

// Parking road
glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f); // asphalt
    glVertex2f(-0.1f, -0.82f);
    glVertex2f(-0.1f, -1.0f);
    glVertex2f(0.05f, -1.0f);
    glVertex2f(0.05f, -0.82f);
glEnd();

// Left arrow (top half, horizontally centered)
glColor3f(1.0f, 1.0f, 1.0f); // white
glBegin(GL_QUADS); // stem
    glVertex2f(-0.035f, -0.89f); // bottom-left
    glVertex2f(-0.035f, -0.88f); // top-left
    glVertex2f(0.0f, -0.88f);    // top-right
    glVertex2f(0.0f, -0.89f);    // bottom-right
glEnd();

glBegin(GL_TRIANGLES); // head
    glVertex2f(-0.035f, -0.90f); // left
    glVertex2f(-0.035f, -0.87f); // top-left
    glVertex2f(-0.05f, -0.885f); // tip
glEnd();

// Right arrow (bottom half, horizontally centered)
glColor3f(1.0f, 1.0f, 1.0f); // white
glBegin(GL_QUADS); // stem
    glVertex2f(-0.035f, -0.95f); // bottom-left
    glVertex2f(-0.035f, -0.94f); // top-left
    glVertex2f(0.0f, -0.94f);    // top-right
    glVertex2f(0.0f, -0.95f);    // bottom-right
glEnd();

glBegin(GL_TRIANGLES); // head
    glVertex2f(0.0f, -0.96f);    // right
    glVertex2f(0.0f, -0.93f);    // top-right
    glVertex2f(0.015f, -0.945f); // tip
glEnd();

// Top border
glColor3f(0.70f, 0.70f, 0.70f); // black border
glLineWidth(8.0f); // thickness
glBegin(GL_LINES);
    glVertex2f(-0.1f, -0.82f);
    glVertex2f(0.065f, -0.82f);
glEnd();

// --- Top Border Trees with Right Shadow ---
glBegin(GL_QUADS);

// Tree 1
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-1.0f, -0.66f); glVertex2f(-0.95f, -0.66f); glVertex2f(-0.935f, -0.63f); glVertex2f(-0.985f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.95f, -0.66f); glVertex2f(-0.935f, -0.63f); glVertex2f(-0.935f, -0.655f); glVertex2f(-0.95f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-1.0f, -0.68f); glVertex2f(-0.95f, -0.68f); glVertex2f(-0.95f, -0.66f); glVertex2f(-1.0f, -0.66f);

// Tree 2
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.92f, -0.66f); glVertex2f(-0.87f, -0.66f); glVertex2f(-0.855f, -0.63f); glVertex2f(-0.905f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.87f, -0.66f); glVertex2f(-0.855f, -0.63f); glVertex2f(-0.855f, -0.655f); glVertex2f(-0.87f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.92f, -0.68f); glVertex2f(-0.87f, -0.68f); glVertex2f(-0.87f, -0.66f); glVertex2f(-0.92f, -0.66f);

// Tree 3
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.84f, -0.66f); glVertex2f(-0.79f, -0.66f); glVertex2f(-0.775f, -0.63f); glVertex2f(-0.825f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.79f, -0.66f); glVertex2f(-0.775f, -0.63f); glVertex2f(-0.775f, -0.655f); glVertex2f(-0.79f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.84f, -0.68f); glVertex2f(-0.79f, -0.68f); glVertex2f(-0.79f, -0.66f); glVertex2f(-0.84f, -0.66f);

// Tree 4
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.76f, -0.66f); glVertex2f(-0.71f, -0.66f); glVertex2f(-0.695f, -0.63f); glVertex2f(-0.745f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.71f, -0.66f); glVertex2f(-0.695f, -0.63f); glVertex2f(-0.695f, -0.655f); glVertex2f(-0.71f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.76f, -0.68f); glVertex2f(-0.71f, -0.68f); glVertex2f(-0.71f, -0.66f); glVertex2f(-0.76f, -0.66f);

// Tree 5
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.68f, -0.66f); glVertex2f(-0.63f, -0.66f); glVertex2f(-0.615f, -0.63f); glVertex2f(-0.665f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.63f, -0.66f); glVertex2f(-0.615f, -0.63f); glVertex2f(-0.615f, -0.655f); glVertex2f(-0.63f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.68f, -0.68f); glVertex2f(-0.63f, -0.68f); glVertex2f(-0.63f, -0.66f); glVertex2f(-0.68f, -0.66f);

// Tree 6
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.60f, -0.66f); glVertex2f(-0.55f, -0.66f); glVertex2f(-0.535f, -0.63f); glVertex2f(-0.585f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.55f, -0.66f); glVertex2f(-0.535f, -0.63f); glVertex2f(-0.535f, -0.655f); glVertex2f(-0.55f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.60f, -0.68f); glVertex2f(-0.55f, -0.68f); glVertex2f(-0.55f, -0.66f); glVertex2f(-0.60f, -0.66f);

// Tree 7
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.52f, -0.66f); glVertex2f(-0.47f, -0.66f); glVertex2f(-0.455f, -0.63f); glVertex2f(-0.505f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.47f, -0.66f); glVertex2f(-0.455f, -0.63f); glVertex2f(-0.455f, -0.655f); glVertex2f(-0.47f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.52f, -0.68f); glVertex2f(-0.47f, -0.68f); glVertex2f(-0.47f, -0.66f); glVertex2f(-0.52f, -0.66f);

// Tree 8
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.44f, -0.66f); glVertex2f(-0.39f, -0.66f); glVertex2f(-0.375f, -0.63f); glVertex2f(-0.425f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.39f, -0.66f); glVertex2f(-0.375f, -0.63f); glVertex2f(-0.375f, -0.655f); glVertex2f(-0.39f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.44f, -0.68f); glVertex2f(-0.39f, -0.68f); glVertex2f(-0.39f, -0.66f); glVertex2f(-0.44f, -0.66f);

// Tree 9
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.36f, -0.66f); glVertex2f(-0.31f, -0.66f); glVertex2f(-0.295f, -0.63f); glVertex2f(-0.345f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.31f, -0.66f); glVertex2f(-0.295f, -0.63f); glVertex2f(-0.295f, -0.655f); glVertex2f(-0.31f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.36f, -0.68f); glVertex2f(-0.31f, -0.68f); glVertex2f(-0.31f, -0.66f); glVertex2f(-0.36f, -0.66f);

// Tree 10
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.28f, -0.66f); glVertex2f(-0.23f, -0.66f); glVertex2f(-0.215f, -0.63f); glVertex2f(-0.265f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.23f, -0.66f); glVertex2f(-0.215f, -0.63f); glVertex2f(-0.215f, -0.655f); glVertex2f(-0.23f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.28f, -0.68f); glVertex2f(-0.23f, -0.68f); glVertex2f(-0.23f, -0.66f); glVertex2f(-0.28f, -0.66f);

// Tree 11
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(-0.20f, -0.66f); glVertex2f(-0.15f, -0.66f); glVertex2f(-0.135f, -0.63f); glVertex2f(-0.185f, -0.63f);
glColor3f(0.0f, 0.45f, 0.0f);
glVertex2f(-0.15f, -0.66f); glVertex2f(-0.135f, -0.63f); glVertex2f(-0.135f, -0.655f); glVertex2f(-0.15f, -0.68f);
glColor3f(0.0f, 0.25f, 0.0f);
glVertex2f(-0.20f, -0.68f); glVertex2f(-0.15f, -0.68f); glVertex2f(-0.15f, -0.66f); glVertex2f(-0.20f, -0.66f);

glEnd();

//parking car design

//car 1
glLineWidth(1.0f);
glBegin(GL_QUADS);
glColor3f(0.64f, 0.26f, 0.15f);
glVertex2f(-0.90f, -0.75f);
glVertex2f(-0.90f, -0.76f);
glVertex2f(-0.74f, -0.76f);
glVertex2f(-0.74f, -0.75f);
glEnd();

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.90f, -0.75f);
glVertex2f(-0.90f, -0.76f);
glVertex2f(-0.74f, -0.76f);
glVertex2f(-0.74f, -0.75f);
glEnd();

glColor3f(0.64f, 0.26f, 0.15f);
glBegin(GL_QUADS);
glVertex2f(-0.90f, -0.75f);
glVertex2f(-0.86f, -0.72f);
glVertex2f(-0.79f, -0.72f);
glVertex2f(-0.74f, -0.75f);
glEnd();

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.90f, -0.75f);
glVertex2f(-0.86f, -0.72f);
glVertex2f(-0.79f, -0.72f);
glVertex2f(-0.74f, -0.75f);
glEnd();

glColor3f(0.64f, 0.26f, 0.15f);
glBegin(GL_POLYGON);
glVertex2f(-0.90f, -0.76f);
glVertex2f(-0.90f, -0.79f);
glVertex2f(-0.75f, -0.79f);
glVertex2f(-0.74f, -0.78f);
glVertex2f(-0.74f, -0.76f);
glEnd();

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.90f, -0.76f);
glVertex2f(-0.90f, -0.79f);
glVertex2f(-0.75f, -0.79f);
glVertex2f(-0.74f, -0.78f);
glVertex2f(-0.74f, -0.76f);
glEnd();

glColor3f(0.64f, 0.26f, 0.15f);
glBegin(GL_QUADS);
glVertex2f(-0.96f, -0.76f);
glVertex2f(-0.96f, -0.79f);
glVertex2f(-0.90f, -0.79f);
glVertex2f(-0.90f, -0.75f);
glEnd();

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.96f, -0.76f);
glVertex2f(-0.96f, -0.79f);
glVertex2f(-0.90f, -0.79f);
glVertex2f(-0.90f, -0.75f);
glEnd();

// ==================== Wheel ====================

// Wheel 1
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.93f, -0.79f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(-0.93f + 0.02f * cosf(theta), -0.79f + 0.02f * sinf(theta));
}
glEnd();

glColor3f(0.7f, 0.7f, 0.7f);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.93f, -0.79f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(-0.93f + 0.012f * cosf(theta), -0.79f + 0.012f * sinf(theta));
}
glEnd();

// Wheel 2
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.775f, -0.785f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(-0.775f + 0.02f * cosf(theta), -0.785f + 0.02f * sinf(theta));
}
glEnd();

glColor3f(0.7f, 0.7f, 0.7f);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(-0.775f, -0.785f);
for (int i = 0; i <= 100; i++) {
    float theta = 2.0f * 3.14159f * i / 100;
    glVertex2f(-0.775f + 0.012f * cosf(theta), -0.785f + 0.012f * sinf(theta));
}
glEnd();

// Front window
glColor3f(0.39f, 0.59f, 0.72f);
glBegin(GL_QUADS);
glVertex2f(-0.86f, -0.725f);
glVertex2f(-0.83f, -0.725f);
glVertex2f(-0.83f, -0.745f);
glVertex2f(-0.89f, -0.745f);
glEnd();

// Rear window
glColor3f(0.39f, 0.59f, 0.72f);
glBegin(GL_QUADS);
glVertex2f(-0.825f, -0.725f);
glVertex2f(-0.825f, -0.745f);
glVertex2f(-0.76f, -0.745f);
glVertex2f(-0.79f, -0.725f);
glEnd();




//car 2
///........................................Bus-1
// ----- Bus Body -----
glBegin(GL_QUADS);
    glColor3f(0.66f, 0.75f, 0.90f);
    // Main rectangle
    glVertex2f(-0.44f,-0.80f); glVertex2f(-0.44f,-0.70f);
    glVertex2f(-0.64f,-0.70f); glVertex2f(-0.64f,-0.80f);
    // Front extra part
    glVertex2f(-0.64f,-0.80f); glVertex2f(-0.646f,-0.80f);
    glVertex2f(-0.646f,-0.75f); glVertex2f(-0.64f,-0.74f);
    // Window slide green part
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.446f,-0.74f); glVertex2f(-0.446f,-0.704f);
    glVertex2f(-0.636f,-0.704f); glVertex2f(-0.636f,-0.74f);
    // Windows
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex2f(-0.45f,-0.736f); glVertex2f(-0.45f,-0.708f);
    glVertex2f(-0.477f,-0.708f); glVertex2f(-0.477f,-0.736f);

    glVertex2f(-0.482f,-0.736f); glVertex2f(-0.482f,-0.708f);
    glVertex2f(-0.51f,-0.708f); glVertex2f(-0.51f,-0.736f);

    glVertex2f(-0.514f,-0.736f); glVertex2f(-0.514f,-0.708f);
    glVertex2f(-0.544f,-0.708f); glVertex2f(-0.544f,-0.736f);

    glVertex2f(-0.59f,-0.736f); glVertex2f(-0.59f,-0.708f);
    glVertex2f(-0.616f,-0.708f); glVertex2f(-0.616f,-0.736f);

    glVertex2f(-0.62f,-0.736f); glVertex2f(-0.62f,-0.708f);
    glVertex2f(-0.632f,-0.708f); glVertex2f(-0.632f,-0.736f);

    // Door
    glColor3f(0.2f, 0.5f, 0.8f);
    glVertex2f(-0.55f,-0.80f); glVertex2f(-0.55f,-0.716f);
    glVertex2f(-0.586f,-0.716f); glVertex2f(-0.586f,-0.80f);
glEnd();

// ----- Bus Door Line -----
glLineWidth(1.5f);
glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.568f,-0.80f); glVertex2f(-0.568f,-0.712f);
    // Side mirror stand
    glColor3f(0.14f, 0.25f, 0.12f);
    glVertex2f(-0.64f,-0.71f); glVertex2f(-0.654f,-0.71f);
glEnd();

// ----- Side Mirror -----
glLineWidth(6.0f);
glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.654f,-0.71f); glVertex2f(-0.654f,-0.74f);
glEnd();

// ----- Bus Tires -----
GLfloat tires[4][3] = {
    {-0.614f,-0.80f,0.016f}, // Right tire
    {-0.614f,-0.80f,0.008f}, // Right alloy
    {-0.468f,-0.80f,0.016f}, // Left tire
    {-0.468f,-0.80f,0.008f}  // Left alloy
};

for(int t=0; t<4; t++){
    glColor3f(t%2==0?0.0f:1.0f, t%2==0?0.0f:1.0f, t%2==0?0.0f:1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(tires[t][0], tires[t][1]);
        for(int i=0; i <= triangleAmount; i++){
            glVertex2f(
                tires[t][0] + tires[t][2]*cos(i*twicePi/triangleAmount),
                tires[t][1] + tires[t][2]*sin(i*twicePi/triangleAmount)
            );
        }
    glEnd();
}


///_________________________________________________DOWN LAMP POST ___________________________________________________///
glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.935f, -0.68f);
glVertex2f(-0.935f, -0.52f);
glVertex2f(-0.935f, -0.52f);
glVertex2f(-0.925f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.925f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.845f, -0.68f);
glVertex2f(-0.845f, -0.52f);
glVertex2f(-0.845f, -0.52f);
glVertex2f(-0.835f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.835f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.775f, -0.68f);
glVertex2f(-0.775f, -0.52f);
glVertex2f(-0.775f, -0.52f);
glVertex2f(-0.765f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.765f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.695f, -0.68f);
glVertex2f(-0.695f, -0.52f);
glVertex2f(-0.695f, -0.52f);
glVertex2f(-0.685f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.685f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.615f, -0.68f);
glVertex2f(-0.615f, -0.52f);
glVertex2f(-0.615f, -0.52f);
glVertex2f(-0.605f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.605f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.535f, -0.68f);
glVertex2f(-0.535f, -0.52f);
glVertex2f(-0.535f, -0.52f);
glVertex2f(-0.525f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.525f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.455f, -0.68f);
glVertex2f(-0.455f, -0.52f);
glVertex2f(-0.455f, -0.52f);
glVertex2f(-0.445f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.445f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.375f, -0.68f);
glVertex2f(-0.375f, -0.52f);
glVertex2f(-0.375f, -0.52f);
glVertex2f(-0.365f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.365f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.295f, -0.68f);
glVertex2f(-0.295f, -0.52f);
glVertex2f(-0.295f, -0.52f);
glVertex2f(-0.285f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.285f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.215f, -0.68f);
glVertex2f(-0.215f, -0.52f);
glVertex2f(-0.215f, -0.52f);
glVertex2f(-0.205f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.205f, -0.54f);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.135f, -0.68f);
glVertex2f(-0.135f, -0.52f);
glVertex2f(-0.135f, -0.52f);
glVertex2f(-0.125f, -0.54f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(-0.125f, -0.54f);
glEnd();




// --- Parking slot dividers ---
glLineWidth(2.0f);
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);
    // Horizontal lines
    glVertex2f(-1.0f, -0.84f); glVertex2f(-0.1f, -0.84f);
    glVertex2f(-1.0f, -0.68f); glVertex2f(-0.1f, -0.68f);

    // Vertical lines
    glVertex2f(-0.7f, -1.0f); glVertex2f(-0.7f, -0.68f);
    glVertex2f(-0.4f, -1.0f); glVertex2f(-0.4f, -0.68f);
    glVertex2f(-0.1f, -1.0f); glVertex2f(-0.1f, -0.68f);
glEnd();

/// --- Guard Post with Shadow + Door + Small Windows ---
glPushMatrix();
glTranslatef(0.0f, 0.0f, 0.0f);
glScalef(0.6f, 1.0f, 1.0f);

// --- Guard Stand/Base ---
// left wall
glBegin(GL_QUADS);
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2f(-0.2f, -0.59f);
    glVertex2f(-0.1f, -0.65f);
    glVertex2f(-0.1f, -0.77f);
    glVertex2f(-0.2f, -0.72f);
glEnd();

// left bottom shadow
glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(-0.2f, -0.72f);
    glVertex2f(-0.1f, -0.77f);
    glVertex2f(-0.1f, -0.79f);
    glVertex2f(-0.2f, -0.74f);
glEnd();

// right wall
glBegin(GL_QUADS);
    glColor3f(0.85f, 0.45f, 0.15f);
    glVertex2f(-0.1f, -0.65f);
    glVertex2f(-0.02f, -0.61f);
    glVertex2f(-0.02f, -0.73f);
    glVertex2f(-0.1f, -0.77f);
glEnd();

// right bottom shadow
glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(-0.1f, -0.77f);
    glVertex2f(-0.02f, -0.73f);
    glVertex2f(-0.02f, -0.75f);
    glVertex2f(-0.1f, -0.79f);
glEnd();

// --- Roof ---
glBegin(GL_QUADS);
    glColor3f(0.35f, 0.35f, 0.35f); // main roof
    glVertex2f(-0.2f, -0.59f);
    glVertex2f(-0.1f, -0.55f);
    glVertex2f(0.02f, -0.61f);
    glVertex2f(-0.08f, -0.66f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f); // roof highlight
    glVertex2f(-0.19f, -0.59f);
    glVertex2f(-0.1f, -0.56f);
    glVertex2f(0.01f, -0.61f);
    glVertex2f(-0.08f, -0.65f);
glEnd();

// --- Door on Left Wall ---
glBegin(GL_QUADS);
    glColor3f(0.85f, 0.85f, 0.85f);   // light gray door
    glVertex2f(-0.185f, -0.635f);
    glVertex2f(-0.135f, -0.66f);
    glVertex2f(-0.135f, -0.753f);
    glVertex2f(-0.185f, -0.727f);
glEnd();

// door handle
glPointSize(4.0f);
glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.142f, -0.69f);
glEnd();


// --- Smaller Windows on Right Wall ---
// window 1 (top small)
glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(-0.075f, -0.67f);   // Y decreased by 0.01
    glVertex2f(-0.04f,  -0.65f);
    glVertex2f(-0.04f,  -0.68f);
    glVertex2f(-0.075f, -0.70f);
glEnd();

// window 2 (bottom small)
glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(-0.075f, -0.72f);   // Y decreased by 0.01
    glVertex2f(-0.04f,  -0.70f);
    glVertex2f(-0.04f,  -0.73f);
    glVertex2f(-0.075f, -0.75f);
glEnd();

glPopMatrix();



/*
///----------------------------------Parking Signboard Design--------------------------------------------------///

// === Signboard with Scale & Translate ===
glPushMatrix();

// Apply translation & scaling
glTranslatef(-0.35f, -0.55f, 0.0f);   // Move to position
glScalef(0.25f, 0.18f, 1.0f);       // Resize

// --- Signboard Background ---
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);  // Board
    glVertex2f(0.40f, -0.50f);
    glVertex2f(0.90f, -0.50f);
    glVertex2f(0.90f, -0.30f);
    glVertex2f(0.40f, -0.30f);
glEnd();

// --- Board Border ---
glLineWidth(2.0f);
glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);  // White border
    glVertex2f(0.40f, -0.50f);
    glVertex2f(0.90f, -0.50f);
    glVertex2f(0.90f, -0.30f);
    glVertex2f(0.40f, -0.30f);
glEnd();

// --- Signboard Sticks ---
glBegin(GL_QUADS);
    glColor3f(0.4f, 0.2f, 0.1f);  // Brown
    // Left stick
    glVertex2f(0.44f, -0.50f);
    glVertex2f(0.48f, -0.50f);
    glVertex2f(0.48f, -0.60f);
    glVertex2f(0.44f, -0.60f);

    // Right stick
    glVertex2f(0.82f, -0.50f);
    glVertex2f(0.86f, -0.50f);
    glVertex2f(0.86f, -0.60f);
    glVertex2f(0.82f, -0.60f);
glEnd();

// --- Text "AIUB Parking" ---
glColor3f(0.0f, 0.0f, 0.0f);
glRasterPos2f(0.48f, -0.44f);  // Inside board
const char* text = "AIUB Parking";
for (int i = 0; text[i] != '\0'; i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, text[i]);
}

glPopMatrix();
*/

 ///_________________________________________________FIELD(1)___________________________________________________///
// --- Soil quad ---
glBegin(GL_QUADS);
    glColor3f(0.69f, 0.851f, 0.31f);
    glVertex2f(0.595f, -0.68f);
    glColor3f(0.39f, 0.671f, 0.282f);
    glVertex2f(0.595f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glColor3f(0.69f, 0.851f, 0.31f);
    glVertex2f(1.0f, -0.68f);
glEnd();

// --- Field Border ---
glLineWidth(2);
glColor3f(1.0f, 1.0f, 0.8f);

glBegin(GL_LINE_LOOP);
    glVertex2f(0.595f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.68f);
    glVertex2f(0.595f, -0.68f);
glEnd();

// Middle line
glBegin(GL_LINES);
    glVertex2f(0.7975f, -1.0f);
    glVertex2f(0.7975f, -0.68f);
glEnd();

// Left D box
glBegin(GL_LINE_LOOP);
    glVertex2f(0.595f, -0.90f);
    glVertex2f(0.625f, -0.90f);
    glVertex2f(0.625f, -0.78f);
    glVertex2f(0.595f, -0.78f);
glEnd();

// Right D box
glBegin(GL_LINE_LOOP);
    glVertex2f(0.97f, -0.90f);
    glVertex2f(1.0f, -0.90f);
    glVertex2f(1.0f, -0.78f);
    glVertex2f(0.97f, -0.78f);
glEnd();

// Center circle
int centerTriangles = 50;
float cntrX = 0.7975f;
float cntrY = -0.84f;
float cntrRadius = 0.012f;

glBegin(GL_LINE_LOOP);
for(int i = 0; i <= centerTriangles; i++){
    glVertex2f(
        cntrX + cntrRadius * cos(i * 2 * M_PI / centerTriangles),
        cntrY + cntrRadius * sin(i * 2 * M_PI / centerTriangles)
    );
}
glEnd();




//basketball field
// --- Court background (wood floor) ---
glColor3f(0.93f, 0.85f, 0.55f);
glBegin(GL_QUADS);
    glVertex2f(0.3532f, -1.002f);
    glVertex2f(0.5932f, -1.002f);
    glVertex2f(0.5932f, -0.678f);
    glVertex2f(0.3532f, -0.678f);
glEnd();

// field road
glColor3f(0.40f, 0.40f, 0.40f);
glBegin(GL_QUADS);
    glVertex2f(0.25f, -0.926f);
    glVertex2f(0.3532f, -0.926f);
    glVertex2f(0.3532f, -0.754f);
    glVertex2f(0.25f, -0.754f);
glEnd();

// bottom border
glColor3f(0.7f, 0.7f, 0.7f);
glBegin(GL_QUADS);
    glVertex2f(0.25f, -0.926f);
    glVertex2f(0.3532f, -0.926f);
    glVertex2f(0.3532f, -0.910f);   // thin strip above bottom
    glVertex2f(0.25f, -0.910f);
glEnd();

// top border
glColor3f(0.7f, 0.7f, 0.7f);
glBegin(GL_QUADS);
    glVertex2f(0.25f, -0.770f);     // thin strip below top
    glVertex2f(0.3532f, -0.770f);
    glVertex2f(0.3532f, -0.754f);
    glVertex2f(0.25f, -0.754f);
glEnd();


// dashed horizontal line (white, centered, thin)
glColor3f(1.0f, 1.0f, 1.0f);

// dash 1
glBegin(GL_QUADS);
    glVertex2f(0.26f, -0.845f);
    glVertex2f(0.285f, -0.845f);
    glVertex2f(0.285f, -0.835f);
    glVertex2f(0.26f, -0.835f);
glEnd();

// dash 2
glBegin(GL_QUADS);
    glVertex2f(0.295f, -0.845f);
    glVertex2f(0.32f, -0.845f);
    glVertex2f(0.32f, -0.835f);
    glVertex2f(0.295f, -0.835f);
glEnd();

// dash 3
glBegin(GL_QUADS);
    glVertex2f(0.33f, -0.845f);
    glVertex2f(0.353f, -0.845f);
    glVertex2f(0.353f, -0.835f);
    glVertex2f(0.33f, -0.835f);
glEnd();



//field tree ground top
glColor3f(0.14f, 0.60f, 0.15f);
glBegin(GL_QUADS);
    glVertex2f(0.265f, -0.754f);
    glVertex2f(0.3532f, -0.754f);
    glVertex2f(0.3532f, -0.68f);
    glVertex2f(0.265f, -0.68f);
glEnd();


//top field lamp
glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.3052f, -0.72f);
glVertex2f(0.3052f, -0.56f);
glVertex2f(0.3052f, -0.56f);
glVertex2f(0.3152f, -0.58f);

glColor3f(0.1f, 0.10f, 0.10f);
glVertex2f(0.2952f, -0.72f);
glVertex2f(0.3152f, -0.72f);
glEnd();
glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(0.3152f, -0.58f);
glEnd();


//field tree ground bottom
glColor3f(0.14f, 0.60f, 0.15f);
glBegin(GL_QUADS);
    glVertex2f(0.265f, -1.0f);
    glVertex2f(0.3532f, -1.0f);
    glVertex2f(0.3532f, -0.926f);
    glVertex2f(0.265f, -0.926f);
glEnd();

//bottom field lamp
glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.3052f, -0.97f);
glVertex2f(0.3052f, -0.83f);
glVertex2f(0.3052f, -0.83f);
glVertex2f(0.3152f, -0.85f);

glColor3f(0.1f, 0.10f, 0.10f);
glVertex2f(0.2952f, -0.97f);
glVertex2f(0.3152f, -0.97f);
glEnd();

glPointSize(6.0);
glBegin(GL_POINTS);
glColor3f(0.992f, 0.875f, 0.424f);
glVertex2f(0.3152f, -0.85f);
glEnd();


// --- Center circle (inner) ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINE_LOOP);
    for(int i = 0; i <= 50; i++) {
        float theta = 2.0f * 3.14159265f * i / 50;
        glVertex2f((0.05f * cos(theta) * 0.19f + 0.25f * 0.19f) * 0.8f + 0.4412f,
                   (0.10f * sin(theta) * 0.18f) - 0.84f);
    }
glEnd();
// --- Center circle (outer) ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINE_LOOP);
    for(int i = 0; i <= 50; i++) {
        float theta = 2.0f * 3.14159265f * i / 50;
        glVertex2f((0.1f * cos(theta) * 0.19f + 0.25f * 0.19f) * 0.8f + 0.4412f,
                   (0.15f * sin(theta) * 0.18f) - 0.84f);
    }
glEnd();
// --- Center line ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);
    glVertex2f(0.3532f, -0.84f);
    glVertex2f(0.5932f, -0.84f);
glEnd();
// --- Bottom 3-point arc ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINE_STRIP);
    for(int i = 5; i <= 45; i++) {
        float theta = 3.14159265f * i / 50;
        glVertex2f((0.6f * cos(theta) * 0.19f + 0.22f * 0.19f) * 0.8f + 0.4412f,
                   (-0.82f * 0.18f + 0.6f * sin(theta) * 0.18f) - 0.84f);
    }
glEnd();
// --- Bottom side lines of 3-point area ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);
// bottom right
    glVertex2f(0.3880f, -0.9534f);
    glVertex2f(0.3880f, -1.002f);
// bottom left
    glVertex2f(0.5613f, -0.9534f);
    glVertex2f(0.5613f, -1.002f);
glEnd();
// --- Top 3-point arc ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINE_STRIP);
    for(int i = 5; i <= 45; i++) {
        float theta = 3.14159265f * i / 50;
        glVertex2f((0.6f * cos(theta) * 0.19f + 0.22f * 0.19f) * 0.8f + 0.4412f,
                   (0.82f * 0.18f - 0.6f * sin(theta) * 0.18f) - 0.84f);
    }
glEnd();
// --- Top side lines of 3-point area ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);
// top right
    glVertex2f(0.5613f, -0.7266f);
    glVertex2f(0.5613f, -0.678f);
// top left
    glVertex2f(0.3880f, -0.7266f);
    glVertex2f(0.3880f, -0.678f);
glEnd();
// --- Bottom key (paint) ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINE_LOOP);
    glVertex2f(0.5066f, -1.002f);
    glVertex2f(0.4487f, -1.002f);
    glVertex2f(0.4487f, -0.93f);
    glVertex2f(0.5066f, -0.93f);
glEnd();
// --- Under Bottom key (paint) ---
glColor3f(0.88f, 0.80f, 0.55f);
glBegin(GL_POLYGON);
    glVertex2f(0.4914f, -1.002f);
    glVertex2f(0.4639f, -1.002f);
    glVertex2f(0.4639f, -0.93f);
    glVertex2f(0.4914f, -0.93f);
glEnd();
// --- Under Bottom key semicircle ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= 50; i++) {
        float theta = 3.14159265f * i / 50;
        glVertex2f((0.08f * cos(theta) * 0.19f + 0.24f * 0.19f) * 0.8f + 0.4412f,
                   (0.15f * sin(theta) * 0.18f - 0.5f * 0.18f) - 0.84f);
    }
glEnd();
// --- Top key (paint) ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINE_LOOP);
    glVertex2f(0.4487f, -0.678f);
    glVertex2f(0.5066f, -0.678f);
    glVertex2f(0.5066f, -0.75f);
    glVertex2f(0.4487f, -0.75f);
glEnd();
// --- Under Top key (paint) ---
glColor3f(0.88f, 0.80f, 0.55f);
glBegin(GL_POLYGON);
    glVertex2f(0.4639f, -0.678f);
    glVertex2f(0.4914f, -0.678f);
    glVertex2f(0.4914f, -0.75f);
    glVertex2f(0.4639f, -0.75f);
glEnd();
// --- Under Top key semicircle ---
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= 50; i++) {
        float theta = 3.14159265f * i / 50;
        glVertex2f((0.08f * cos(theta) * 0.19f + 0.24f * 0.19f) * 0.8f + 0.4412f,
                   (-0.15f * sin(theta) * 0.18f + 0.5f * 0.18f) - 0.84f);
    }
glEnd();
// --- Bottom hoop ---
glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(0.4853f, -0.9876f);
    glVertex2f(0.4725f, -0.9876f);
    glVertex2f(0.4725f, -0.993f);
    glVertex2f(0.4853f, -0.993f);
glEnd();
// --- Bottom hoop stand ---
glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(0.4792f, -0.9876f);
    glVertex2f(0.4754f, -0.9876f);
    glVertex2f(0.4754f, -0.9768f);
    glVertex2f(0.4792f, -0.9768f);
glEnd();
// --- Bottom hoop net ---
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(0.4835f, -0.9768f);
    glVertex2f(0.4739f, -0.9768f);
    glVertex2f(0.4739f, -0.9732f);
    glVertex2f(0.4835f, -0.9732f);
glEnd();
// --- Top hoop ---
glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(0.4701f, -0.6924f);
    glVertex2f(0.4853f, -0.6924f);
    glVertex2f(0.4853f, -0.687f);
    glVertex2f(0.4701f, -0.687f);
glEnd();
// --- Top hoop stand ---
glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(0.4762f, -0.6924f);
    glVertex2f(0.4792f, -0.6924f);
    glVertex2f(0.4792f, -0.7032f);
    glVertex2f(0.4762f, -0.7032f);
glEnd();
// --- Top hoop net ---
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(0.4739f, -0.7032f);
    glVertex2f(0.4835f, -0.7032f);
    glVertex2f(0.4835f, -0.7068f);
    glVertex2f(0.4739f, -0.7068f);
glEnd();




// --- field net border ---
// vertical border lines
glColor3f(0, 0, 0);
glLineWidth(1.5);
glBegin(GL_LINES);
    glVertex2f(0.5920f, -1.0f);
    glVertex2f(0.5920f, -0.68f);
glEnd();

glColor3f(0.4, 0.4, 0.4);
glLineWidth(0.7);
glBegin(GL_LINES);
    glVertex2f(0.6070f, -1.0f);
    glVertex2f(0.6070f, -0.68f);
glEnd();


// horizontal stripes inside
glLineWidth(1.0);
glBegin(GL_LINES);
    glVertex2f(0.5920f, -1.0f);  glVertex2f(0.6070f, -1.0f);
    glVertex2f(0.5920f, -0.96f); glVertex2f(0.6070f, -0.96f);
    glVertex2f(0.5920f, -0.92f); glVertex2f(0.6070f, -0.92f);
    glVertex2f(0.5920f, -0.88f); glVertex2f(0.6070f, -0.88f);
    glVertex2f(0.5920f, -0.84f); glVertex2f(0.6070f, -0.84f);
    glVertex2f(0.5920f, -0.80f); glVertex2f(0.6070f, -0.80f);
    glVertex2f(0.5920f, -0.76f); glVertex2f(0.6070f, -0.76f);
    glVertex2f(0.5920f, -0.72f); glVertex2f(0.6070f, -0.72f);
    glVertex2f(0.5920f, -0.68f); glVertex2f(0.6070f, -0.68f);
glEnd();

// vertical stripes inside
glLineWidth(1.0);
glBegin(GL_LINES);
    glVertex2f(0.5920f, -1.0f); glVertex2f(0.5920f, -0.68f);
    glVertex2f(0.5950f, -1.0f); glVertex2f(0.5950f, -0.68f);
    glVertex2f(0.5980f, -1.0f); glVertex2f(0.5980f, -0.68f);
    glVertex2f(0.6010f, -1.0f); glVertex2f(0.6010f, -0.68f);
    glVertex2f(0.6040f, -1.0f); glVertex2f(0.6040f, -0.68f);
    glVertex2f(0.6070f, -1.0f); glVertex2f(0.6070f, -0.68f);
glEnd();




// ======================================
// || Mini Plane in gluOrtho2D (-1,1)  ||
// ======================================
glPushMatrix();
glTranslatef(jetX, 0.0f, 0.0f);   // shift plane position

glLineWidth(2.0f); // thicker border for visibility
// ---------------- Body last part ----------------
glBegin(GL_QUADS); // fill
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.102f, 0.6988f);
glVertex2f(0.102f, 0.6708f);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.102f, 0.6988f);
glVertex2f(0.102f, 0.6708f);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glEnd();
// ---------------- Body middle ----------------
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glEnd();
// ---------------- Body front ----------------
glBegin(GL_POLYGON);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glEnd();
// ---------------- Nose ----------------
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34f, 0.36f);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glVertex2f(-0.108f, 0.6708f);
glVertex2f(-0.111f, 0.6652f);
glVertex2f(-0.108f, 0.6652f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glVertex2f(-0.108f, 0.6708f);
glVertex2f(-0.111f, 0.6652f);
glVertex2f(-0.108f, 0.6652f);
glEnd();
// ---------------- Ellipse (window) ----------------
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.021f + 0.0405f * cos(angle),
               0.696f + 0.0252f * sin(angle));
}
glEnd();
// border
glLineWidth(1);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.021f + 0.0405f * cos(angle),
               0.696f + 0.0252f * sin(angle));
}
glEnd();
//window last
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.0585f, 0.6904f);
glVertex2f(0.0195f, 0.6904f);
glVertex2f(0.0195f, 0.668f);
glVertex2f(-0.0585f, 0.668f);
glEnd();
//shadow
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.036f, 0.7184f);
glVertex2f(-0.036f, 0.6932f);
glVertex2f(-0.033f, 0.6932f);
glVertex2f(-0.033f, 0.7184f);
glEnd();
//2
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.0105f, 0.7184f);
glVertex2f(-0.0075f, 0.7184f);
glVertex2f(-0.0105f, 0.6932f);
glVertex2f(-0.0075f, 0.6932f);
glEnd();
// ---------------- Wing bottom ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(-0.0165f, 0.6764f);
glVertex2f(0.048f, 0.682f);
glVertex2f(0.0555f, 0.6148f);
glVertex2f(0.069f, 0.584f);
glVertex2f(0.051f, 0.5728f);
glVertex2f(-0.0165f, 0.6764f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.0165f, 0.6764f);
glVertex2f(0.048f, 0.682f);
glVertex2f(0.0555f, 0.6148f);
glVertex2f(0.069f, 0.584f);
glVertex2f(0.051f, 0.5728f);
glVertex2f(-0.0165f, 0.6764f);
glEnd();
// ---------------- Wing top ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.0495f, 0.7044f);
glVertex2f(0.051f, 0.7464f);
glVertex2f(0.0585f, 0.7688f);
glVertex2f(0.0375f, 0.7716f);
glVertex2f(-0.0105f, 0.7212f);
glVertex2f(0.018f, 0.71f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.0495f, 0.7044f);
glVertex2f(0.051f, 0.7464f);
glVertex2f(0.0585f, 0.7688f);
glVertex2f(0.0375f, 0.7716f);
glVertex2f(-0.0105f, 0.7212f);
glVertex2f(0.018f, 0.71f);
glEnd();
// ---------------- Back wings ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.066f, 0.7044f);
glVertex2f(0.093f, 0.766f);
glVertex2f(0.099f, 0.766f);
glVertex2f(0.093f, 0.6988f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.066f, 0.7044f);
glVertex2f(0.093f, 0.766f);
glVertex2f(0.099f, 0.766f);
glVertex2f(0.093f, 0.6988f);
glEnd();
// ---------------- Back wing details ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.093f, 0.7464f);
glVertex2f(0.099f, 0.7464f);
glVertex2f(0.0945f, 0.6764f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.093f, 0.7464f);
glVertex2f(0.099f, 0.7464f);
glVertex2f(0.0945f, 0.6764f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.0945f, 0.6764f);
glVertex2f(0.117f, 0.6484f);
glVertex2f(0.105f, 0.6512f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.0945f, 0.6764f);
glVertex2f(0.117f, 0.6484f);
glVertex2f(0.105f, 0.6512f);
glEnd();
// ---------------- Rockets ----------------
glBegin(GL_QUADS);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.0135f, 0.7296f);
glVertex2f(-0.0045f, 0.7352f);
glVertex2f(0.003f, 0.738f);
glVertex2f(-0.0075f, 0.724f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.015f, 0.7296f);
glVertex2f(-0.006f, 0.7352f);
glVertex2f(0.0045f, 0.738f);
glVertex2f(-0.009f, 0.724f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.015f, 0.64f);
glVertex2f(-0.0045f, 0.6512f);
glVertex2f(0.0f, 0.6512f);
glVertex2f(0.009f, 0.6344f);
glVertex2f(-0.0045f, 0.6344f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.015f, 0.64f);
glVertex2f(-0.0045f, 0.6512f);
glVertex2f(0.0f, 0.6512f);
glVertex2f(0.009f, 0.6344f);
glVertex2f(-0.0045f, 0.6344f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.015f, 0.6148f);
glVertex2f(0.006f, 0.6288f);
glVertex2f(0.0135f, 0.6288f);
glVertex2f(0.03f, 0.6064f);
glVertex2f(0.003f, 0.6064f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.015f, 0.6148f);
glVertex2f(0.006f, 0.6288f);
glVertex2f(0.0135f, 0.6288f);
glVertex2f(0.03f, 0.6064f);
glVertex2f(0.003f, 0.6064f);
glEnd();
//fire 1
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.696f);
glVertex2f(0.1125f, 0.6988f);
glVertex2f(0.1005f, 0.6848f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.696f);
glVertex2f(0.1125f, 0.6988f);
glVertex2f(0.1005f, 0.6848f);
glEnd();
//fire 2
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.6904f);
glVertex2f(0.117f, 0.6904f);
glVertex2f(0.1005f, 0.6764f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.6904f);
glVertex2f(0.117f, 0.6904f);
glVertex2f(0.1005f, 0.6764f);
glEnd();
//fire 3
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.6848f);
glVertex2f(0.1185f, 0.6792f);
glVertex2f(0.1005f, 0.6708f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.6848f);
glVertex2f(0.1185f, 0.6792f);
glVertex2f(0.1005f, 0.6708f);
glEnd();
//fire 4
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.682f);
glVertex2f(0.1125f, 0.6708f);
glVertex2f(0.1005f, 0.6736f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.682f);
glVertex2f(0.1125f, 0.6708f);
glVertex2f(0.1005f, 0.6736f);
glEnd();

glPopMatrix();








// ======================================
// || Mini Plane in gluOrtho2D (-1,1)  ||
// ======================================
glPushMatrix();
glTranslatef(jetX2, 0.0f, 0.0f);   // shift plane position

glLineWidth(2.0f); // thicker border for visibility
// ---------------- Body last part ----------------
glBegin(GL_QUADS); // fill
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.068f, 0.892f);
glVertex2f(0.068f, 0.872f);
glVertex2f(0.013f, 0.862f);
glVertex2f(0.012f, 0.9f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.068f, 0.892f);
glVertex2f(0.068f, 0.872f);
glVertex2f(0.013f, 0.862f);
glVertex2f(0.012f, 0.9f);
glEnd();
// ---------------- Body middle ----------------
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.013f, 0.862f);
glVertex2f(0.012f, 0.9f);
glVertex2f(-0.041f, 0.89f);
glVertex2f(-0.041f, 0.864f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.013f, 0.862f);
glVertex2f(0.012f, 0.9f);
glVertex2f(-0.041f, 0.89f);
glVertex2f(-0.041f, 0.864f);
glEnd();
// ---------------- Body front ----------------
glBegin(GL_POLYGON);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.041f, 0.89f);
glVertex2f(-0.041f, 0.864f);
glVertex2f(-0.056f, 0.864f);
glVertex2f(-0.0565f, 0.874f);
glVertex2f(-0.056f, 0.882f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.041f, 0.89f);
glVertex2f(-0.041f, 0.864f);
glVertex2f(-0.056f, 0.864f);
glVertex2f(-0.0565f, 0.874f);
glVertex2f(-0.056f, 0.882f);
glEnd();
// ---------------- Nose ----------------
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34f, 0.36f);
glVertex2f(-0.056f, 0.864f);
glVertex2f(-0.0565f, 0.874f);
glVertex2f(-0.056f, 0.882f);
glVertex2f(-0.072f, 0.872f);
glVertex2f(-0.074f, 0.868f);
glVertex2f(-0.072f, 0.868f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.056f, 0.864f);
glVertex2f(-0.0565f, 0.874f);
glVertex2f(-0.056f, 0.882f);
glVertex2f(-0.072f, 0.872f);
glVertex2f(-0.074f, 0.868f);
glVertex2f(-0.072f, 0.868f);
glEnd();
// ---------------- Ellipse (window) ----------------
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.014f + 0.027f * cos(angle),
               0.89f + 0.018f * sin(angle));
}
glEnd();
// border
glLineWidth(1);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.014f + 0.027f * cos(angle),
               0.89f + 0.018f * sin(angle));
}
glEnd();
//window last
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.039f, 0.886f);
glVertex2f(0.013f, 0.886f);
glVertex2f(0.013f, 0.87f);
glVertex2f(-0.039f, 0.87f);
glEnd();
//shadow
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.024f, 0.906f);
glVertex2f(-0.024f, 0.888f);
glVertex2f(-0.022f, 0.888f);
glVertex2f(-0.022f, 0.906f);
glEnd();
//2
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.007f, 0.906f);
glVertex2f(-0.005f, 0.906f);
glVertex2f(-0.007f, 0.888f);
glVertex2f(-0.005f, 0.888f);
glEnd();
// ---------------- Wing bottom ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(-0.011f, 0.876f);
glVertex2f(0.032f, 0.88f);
glVertex2f(0.037f, 0.832f);
glVertex2f(0.046f, 0.81f);
glVertex2f(0.034f, 0.802f);
glVertex2f(-0.011f, 0.876f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.011f, 0.876f);
glVertex2f(0.032f, 0.88f);
glVertex2f(0.037f, 0.832f);
glVertex2f(0.046f, 0.81f);
glVertex2f(0.034f, 0.802f);
glVertex2f(-0.011f, 0.876f);
glEnd();
// ---------------- Wing top ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.033f, 0.896f);
glVertex2f(0.034f, 0.926f);
glVertex2f(0.039f, 0.942f);
glVertex2f(0.025f, 0.944f);
glVertex2f(-0.007f, 0.908f);
glVertex2f(0.012f, 0.9f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.033f, 0.896f);
glVertex2f(0.034f, 0.926f);
glVertex2f(0.039f, 0.942f);
glVertex2f(0.025f, 0.944f);
glVertex2f(-0.007f, 0.908f);
glVertex2f(0.012f, 0.9f);
glEnd();
// ---------------- Back wings ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.044f, 0.896f);
glVertex2f(0.062f, 0.94f);
glVertex2f(0.066f, 0.94f);
glVertex2f(0.062f, 0.892f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.044f, 0.896f);
glVertex2f(0.062f, 0.94f);
glVertex2f(0.066f, 0.94f);
glVertex2f(0.062f, 0.892f);
glEnd();
// ---------------- Back wing details ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.04f, 0.874f);
glVertex2f(0.062f, 0.926f);
glVertex2f(0.066f, 0.926f);
glVertex2f(0.063f, 0.876f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.04f, 0.874f);
glVertex2f(0.062f, 0.926f);
glVertex2f(0.066f, 0.926f);
glVertex2f(0.063f, 0.876f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.04f, 0.874f);
glVertex2f(0.063f, 0.876f);
glVertex2f(0.078f, 0.856f);
glVertex2f(0.07f, 0.858f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.04f, 0.874f);
glVertex2f(0.063f, 0.876f);
glVertex2f(0.078f, 0.856f);
glVertex2f(0.07f, 0.858f);
glEnd();
// ---------------- Rockets ----------------
glBegin(GL_QUADS);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.009f, 0.914f);
glVertex2f(-0.003f, 0.918f);
glVertex2f(0.002f, 0.92f);
glVertex2f(-0.005f, 0.91f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.914f);
glVertex2f(-0.004f, 0.918f);
glVertex2f(0.003f, 0.92f);
glVertex2f(-0.006f, 0.91f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.01f, 0.85f);
glVertex2f(-0.003f, 0.858f);
glVertex2f(0.0f, 0.858f);
glVertex2f(0.006f, 0.846f);
glVertex2f(-0.003f, 0.846f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.85f);
glVertex2f(-0.003f, 0.858f);
glVertex2f(0.0f, 0.858f);
glVertex2f(0.006f, 0.846f);
glVertex2f(-0.003f, 0.846f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.01f, 0.832f);
glVertex2f(0.004f, 0.842f);
glVertex2f(0.009f, 0.842f);
glVertex2f(0.02f, 0.826f);
glVertex2f(0.002f, 0.826f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.832f);
glVertex2f(0.004f, 0.842f);
glVertex2f(0.009f, 0.842f);
glVertex2f(0.02f, 0.826f);
glVertex2f(0.002f, 0.826f);
glEnd();
//fire 1
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.89f);
glVertex2f(0.075f, 0.892f);
glVertex2f(0.067f, 0.882f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.89f);
glVertex2f(0.075f, 0.892f);
glVertex2f(0.067f, 0.882f);
glEnd();
//fire 2
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.886f);
glVertex2f(0.078f, 0.886f);
glVertex2f(0.067f, 0.876f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.886f);
glVertex2f(0.078f, 0.886f);
glVertex2f(0.067f, 0.876f);
glEnd();
//fire 3
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.882f);
glVertex2f(0.079f, 0.878f);
glVertex2f(0.067f, 0.872f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.882f);
glVertex2f(0.079f, 0.878f);
glVertex2f(0.067f, 0.872f);
glEnd();
//fire 4
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.88f);
glVertex2f(0.075f, 0.872f);
glVertex2f(0.067f, 0.874f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.88f);
glVertex2f(0.075f, 0.872f);
glVertex2f(0.067f, 0.874f);
glEnd();

glPopMatrix();








// ======================================
// || Mini Plane in gluOrtho2D (-1,1)  ||
// ======================================
glPushMatrix();
glTranslatef(jetX3, 0.0f, 0.0f);   // shift plane position

glLineWidth(2.0f); // thicker border for visibility
// ---------------- Body last part ----------------
glBegin(GL_QUADS); // fill
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.068f, 0.542f);
glVertex2f(0.068f, 0.522f);
glVertex2f(0.013f, 0.512f);
glVertex2f(0.012f, 0.55f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.068f, 0.542f);
glVertex2f(0.068f, 0.522f);
glVertex2f(0.013f, 0.512f);
glVertex2f(0.012f, 0.55f);
glEnd();
// ---------------- Body middle ----------------
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.013f, 0.512f);
glVertex2f(0.012f, 0.55f);
glVertex2f(-0.041f, 0.54f);
glVertex2f(-0.041f, 0.514f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.013f, 0.512f);
glVertex2f(0.012f, 0.55f);
glVertex2f(-0.041f, 0.54f);
glVertex2f(-0.041f, 0.514f);
glEnd();
// ---------------- Body front ----------------
glBegin(GL_POLYGON);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.041f, 0.54f);
glVertex2f(-0.041f, 0.514f);
glVertex2f(-0.056f, 0.514f);
glVertex2f(-0.0565f, 0.524f);
glVertex2f(-0.056f, 0.532f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.041f, 0.54f);
glVertex2f(-0.041f, 0.514f);
glVertex2f(-0.056f, 0.514f);
glVertex2f(-0.0565f, 0.524f);
glVertex2f(-0.056f, 0.532f);
glEnd();
// ---------------- Nose ----------------
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34f, 0.36f);
glVertex2f(-0.056f, 0.514f);
glVertex2f(-0.0565f, 0.524f);
glVertex2f(-0.056f, 0.532f);
glVertex2f(-0.072f, 0.522f);
glVertex2f(-0.074f, 0.518f);
glVertex2f(-0.072f, 0.518f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.056f, 0.514f);
glVertex2f(-0.0565f, 0.524f);
glVertex2f(-0.056f, 0.532f);
glVertex2f(-0.072f, 0.522f);
glVertex2f(-0.074f, 0.518f);
glVertex2f(-0.072f, 0.518f);
glEnd();
// ---------------- Ellipse (window) ----------------
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.014f + 0.027f * cos(angle),
               0.54f + 0.018f * sin(angle));
}
glEnd();
// border
glLineWidth(1);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.014f + 0.027f * cos(angle),
               0.54f + 0.018f * sin(angle));
}
glEnd();
//window last
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.039f, 0.536f);
glVertex2f(0.013f, 0.536f);
glVertex2f(0.013f, 0.52f);
glVertex2f(-0.039f, 0.52f);
glEnd();
//shadow
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.024f, 0.556f);
glVertex2f(-0.024f, 0.538f);
glVertex2f(-0.022f, 0.538f);
glVertex2f(-0.022f, 0.556f);
glEnd();
//2
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.007f, 0.556f);
glVertex2f(-0.005f, 0.556f);
glVertex2f(-0.007f, 0.538f);
glVertex2f(-0.005f, 0.538f);
glEnd();
// ---------------- Wing bottom ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(-0.011f, 0.526f);
glVertex2f(0.032f, 0.53f);
glVertex2f(0.037f, 0.482f);
glVertex2f(0.046f, 0.46f);
glVertex2f(0.034f, 0.452f);
glVertex2f(-0.011f, 0.526f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.011f, 0.526f);
glVertex2f(0.032f, 0.53f);
glVertex2f(0.037f, 0.482f);
glVertex2f(0.046f, 0.46f);
glVertex2f(0.034f, 0.452f);
glVertex2f(-0.011f, 0.526f);
glEnd();
// ---------------- Wing top ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.033f, 0.546f);
glVertex2f(0.034f, 0.576f);
glVertex2f(0.039f, 0.592f);
glVertex2f(0.025f, 0.594f);
glVertex2f(-0.007f, 0.558f);
glVertex2f(0.012f, 0.55f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.033f, 0.546f);
glVertex2f(0.034f, 0.576f);
glVertex2f(0.039f, 0.592f);
glVertex2f(0.025f, 0.594f);
glVertex2f(-0.007f, 0.558f);
glVertex2f(0.012f, 0.55f);
glEnd();
// ---------------- Back wings ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.044f, 0.546f);
glVertex2f(0.062f, 0.59f);
glVertex2f(0.066f, 0.59f);
glVertex2f(0.062f, 0.542f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.044f, 0.546f);
glVertex2f(0.062f, 0.59f);
glVertex2f(0.066f, 0.59f);
glVertex2f(0.062f, 0.542f);
glEnd();
// ---------------- Back wing details ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.04f, 0.524f);
glVertex2f(0.062f, 0.576f);
glVertex2f(0.066f, 0.576f);
glVertex2f(0.063f, 0.526f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.04f, 0.524f);
glVertex2f(0.062f, 0.576f);
glVertex2f(0.066f, 0.576f);
glVertex2f(0.063f, 0.526f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.04f, 0.524f);
glVertex2f(0.063f, 0.526f);
glVertex2f(0.078f, 0.506f);
glVertex2f(0.07f, 0.508f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.04f, 0.524f);
glVertex2f(0.063f, 0.526f);
glVertex2f(0.078f, 0.506f);
glVertex2f(0.07f, 0.508f);
glEnd();
// ---------------- Rockets ----------------
glBegin(GL_QUADS);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.009f, 0.564f);
glVertex2f(-0.003f, 0.568f);
glVertex2f(0.002f, 0.57f);
glVertex2f(-0.005f, 0.56f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.564f);
glVertex2f(-0.004f, 0.568f);
glVertex2f(0.003f, 0.57f);
glVertex2f(-0.006f, 0.56f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.01f, 0.5f);
glVertex2f(-0.003f, 0.508f);
glVertex2f(0.0f, 0.508f);
glVertex2f(0.006f, 0.496f);
glVertex2f(-0.003f, 0.496f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.5f);
glVertex2f(-0.003f, 0.508f);
glVertex2f(0.0f, 0.508f);
glVertex2f(0.006f, 0.496f);
glVertex2f(-0.003f, 0.496f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.01f, 0.482f);
glVertex2f(0.004f, 0.492f);
glVertex2f(0.009f, 0.492f);
glVertex2f(0.02f, 0.476f);
glVertex2f(0.002f, 0.476f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.01f, 0.482f);
glVertex2f(0.004f, 0.492f);
glVertex2f(0.009f, 0.492f);
glVertex2f(0.02f, 0.476f);
glVertex2f(0.002f, 0.476f);
glEnd();
//fire 1
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.54f);
glVertex2f(0.075f, 0.542f);
glVertex2f(0.067f, 0.532f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.54f);
glVertex2f(0.075f, 0.542f);
glVertex2f(0.067f, 0.532f);
glEnd();
//fire 2
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.536f);
glVertex2f(0.078f, 0.536f);
glVertex2f(0.067f, 0.526f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.536f);
glVertex2f(0.078f, 0.536f);
glVertex2f(0.067f, 0.526f);
glEnd();
//fire 3
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.532f);
glVertex2f(0.079f, 0.528f);
glVertex2f(0.067f, 0.522f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.532f);
glVertex2f(0.079f, 0.528f);
glVertex2f(0.067f, 0.522f);
glEnd();
//fire 4
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.067f, 0.53f);
glVertex2f(0.075f, 0.522f);
glVertex2f(0.067f, 0.524f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.067f, 0.53f);
glVertex2f(0.075f, 0.522f);
glVertex2f(0.067f, 0.524f);
glEnd();

glPopMatrix();

///--------------field top design





//grass
glColor3f(0.12f, 0.38f, 0.08f); // dark green
glLineWidth(1.0f);

glBegin(GL_LINES);

glVertex2f(0.262f, -0.754f); glVertex2f(0.264f, -0.731f);
// blade 5
glVertex2f(0.266f, -0.754f); glVertex2f(0.268f, -0.724f);
// blade 6
glVertex2f(0.27f, -0.754f); glVertex2f(0.272f, -0.742f);
// blade 7
glVertex2f(0.274f, -0.754f); glVertex2f(0.276f, -0.725f);
// blade 8
glVertex2f(0.278f, -0.754f); glVertex2f(0.28f, -0.735f);
// blade 9
glVertex2f(0.282f, -0.754f); glVertex2f(0.284f, -0.724f);
// blade 10
glVertex2f(0.286f, -0.754f); glVertex2f(0.288f, -0.732f);
// blade 11
glVertex2f(0.29f, -0.754f); glVertex2f(0.292f, -0.727f);
// blade 12
glVertex2f(0.294f, -0.754f); glVertex2f(0.296f, -0.729f);
// blade 13
glVertex2f(0.298f, -0.754f); glVertex2f(0.3f, -0.722f);
// blade 14
glVertex2f(0.302f, -0.754f); glVertex2f(0.304f, -0.735f);
// blade 15
glVertex2f(0.306f, -0.754f); glVertex2f(0.308f, -0.724f);
// blade 16
glVertex2f(0.31f, -0.754f); glVertex2f(0.312f, -0.733f);
// blade 17
glVertex2f(0.314f, -0.754f); glVertex2f(0.316f, -0.726f);
// blade 18
glVertex2f(0.318f, -0.754f); glVertex2f(0.32f, -0.731f);
// blade 19
glVertex2f(0.322f, -0.754f); glVertex2f(0.324f, -0.723f);
// blade 20
glVertex2f(0.326f, -0.754f); glVertex2f(0.328f, -0.734f);
// blade 21
glVertex2f(0.33f, -0.754f); glVertex2f(0.332f, -0.725f);
// blade 22
glVertex2f(0.334f, -0.754f); glVertex2f(0.336f, -0.729f);
// blade 23
glVertex2f(0.338f, -0.754f); glVertex2f(0.34f, -0.722f);
// blade 24
glVertex2f(0.342f, -0.754f); glVertex2f(0.344f, -0.733f);
// blade 25
glVertex2f(0.346f, -0.754f); glVertex2f(0.348f, -0.724f);
// blade 26
glVertex2f(0.35f, -0.754f); glVertex2f(0.352f, -0.732f);

glEnd();

glutTimerFunc(13000,display3,0);


glFlush(); // Render now
}


void display2(int b)
{
    glutDisplayFunc(aiub_design);

    // Start the timer ONCE
    static bool started = false;
    if (!started) {
        glutTimerFunc(15, timer, 0);
        sound2(0);
        started = true;
    }
}

















void airport(){
     glClear(GL_COLOR_BUFFER_BIT);

    // ---------------- Background ----------------
    // Sky
    glBegin(GL_QUADS);
        glColor3f(143/255.0f, 198/255.0f, 218/255.0f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glColor3f(0/255.0f, 128/255.0f, 255/255.0f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f(-1.0f,  1.0f);
    glEnd();

    // Ground
    glBegin(GL_QUADS);
    //glColor3f(0.4f, 0.4f, 0.4f);  // black

    glColor3f(0.0f, 0.0f, 0.0f);  // black
    glVertex2f(-1.0f, -1.0f);     // (0,0)
    glVertex2f( 1.0f, -1.0f);     // (1400,0)
    glVertex2f( 1.0f, -0.5588f);  // (1400,150)
    glVertex2f(-1.0f, -0.5588f);  // (0,150)
    glEnd();

//------------------Sun---------------------

glPushMatrix();
int triangleAmount = 50;
const GLfloat twicePi = 2.0f * 3.14159f;
glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.3f); // bright center
    float centerX = (0.0f * 0.1f) - 0.7f;
    float centerY = (0.0f * 0.1f) + 0.8f;
    glVertex2f(centerX, centerY); // center
    for(int i = 0; i <= triangleAmount; i++) {
        glColor3f(1.0f, 0.9f, 0.4f); // edge softer yellow
        float oldX = cos(i * twicePi / triangleAmount);
        float oldY = sin(i * twicePi / triangleAmount);
        float newX = (oldX * 0.1f) - 0.7f;
        float newY = (oldY * 0.1f) + 0.8f;
        glVertex2f(newX, newY);
    }
glEnd();

glPopMatrix();






glPushMatrix();

glTranslatef(cloudXD1,0.0f,0.0f);



    // ---------------- Clouds ----------------



//Big cloud 1



glColor3f(225/255.0f, 240/255.0f, 239/255.0f);



for (int k = 0; k < 3; ++k) {

    float xOff = (k == 0 ? 0.0f : (k == 1 ? 0.03f : 0.06f));

    float yOff = (k == 1 ? 0.015f : 0.0f);



    glBegin(GL_TRIANGLE_FAN);

    glVertex2f((xOff * 2.6f) - 0.4f, (yOff * 1.7f) + 0.72f); // center



    for (int i = 0; i <= 100; i++) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f(((xOff + 0.03f * cosf(ang)) * 2.6f) - 0.4f,

                   ((yOff + 0.03f * sinf(ang)) * 1.7f) + 0.72f);

    }

    glEnd();

}















//Big cloud 2





glColor3f(225/255.0f, 240/255.0f, 239/255.0f);



for (int k = 0; k < 3; ++k) {

    glBegin(GL_TRIANGLE_FAN);



    glVertex2f(((k == 0 ? 0.0f : (k == 1 ? 0.03f : 0.06f)) * 2.6f) + 0.4f,

               ((k == 1 ? 0.015f : 0.0f) * 1.7f) + 0.72f);



    for (int i = 0; i <= 100; i++) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f((((k == 0 ? 0.0f : (k == 1 ? 0.03f : 0.06f)) + 0.03f * cosf(ang)) * 2.6f) + 0.4f,

                   (((k == 1 ? 0.015f : 0.0f) + 0.03f * sinf(ang)) * 1.7f) + 0.72f);

    }

    glEnd();

}









// Mini cloud 2 chain



for (int k = 0; k < 5; ++k) {

    glBegin(GL_TRIANGLE_FAN);



    // Center vertex

    glVertex2f(

        ((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f) * 0.5f) + 0.2f,

        ((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f) * 0.5f) + 0.2f

    );



    for (int i = 0; i <= 100; ++i) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f(

            (((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f)

              + 0.08f * cosf(ang)) * 0.5f) + 0.2f,

            (((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f)

              + 0.08f * sinf(ang)) * 0.5f) + 0.2f

        );

    }



    glEnd();

}





// Mini cloud 3 chain





for (int k = 0; k < 5; ++k) {

    glBegin(GL_TRIANGLE_FAN);



    // Center vertex

    glVertex2f(

        ((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f) * 0.5f) + 0.9f,

        ((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f) * 0.5f) + 0.2f

    );



    for (int i = 0; i <= 100; ++i) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f(

            (((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f)

               + 0.08f * cosf(ang)) * 0.5f) + 0.9f,

            (((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f)

               + 0.08f * sinf(ang)) * 0.5f) + 0.2f

        );

    }



    glEnd();

}











//mini cloud 1 chain ------------





for (int k = 0; k < 5; ++k) {

    glBegin(GL_TRIANGLE_FAN);



    // Center vertex

    glVertex2f(

        ((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f) * 0.5f) - 0.68f,

        ((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f) * 0.5f) + 0.15f

    );



    for (int i = 0; i <= 100; ++i) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f(

            (((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f)

               + 0.08f * cosf(ang)) * 0.5f) - 0.68f,

            (((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f)

               + 0.08f * sinf(ang)) * 0.5f) + 0.15f

        );

    }



    glEnd();

}
glPopMatrix();













glPushMatrix();

glTranslatef(cloudX1D1,0.0f,0.0f);


//Big cloud 1

glColor3f(225/255.0f, 240/255.0f, 239/255.0f);



for (int k = 0; k < 3; ++k) {

    float xOff = (k == 0 ? 0.0f : (k == 1 ? 0.03f : 0.06f));

    float yOff = (k == 1 ? 0.015f : 0.0f);



    glBegin(GL_TRIANGLE_FAN);

    glVertex2f((xOff * 2.6f) - 0.4f, (yOff * 1.7f) + 0.72f); // center



    for (int i = 0; i <= 100; i++) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f(((xOff + 0.03f * cosf(ang)) * 2.6f) - 0.4f,

                   ((yOff + 0.03f * sinf(ang)) * 1.7f) + 0.72f);

    }

    glEnd();

}




//Big cloud 2
glColor3f(225/255.0f, 240/255.0f, 239/255.0f);

for (int k = 0; k < 3; ++k) {

    glBegin(GL_TRIANGLE_FAN);



    glVertex2f(((k == 0 ? 0.0f : (k == 1 ? 0.03f : 0.06f)) * 2.6f) + 0.4f,

               ((k == 1 ? 0.015f : 0.0f) * 1.7f) + 0.72f);



    for (int i = 0; i <= 100; i++) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f((((k == 0 ? 0.0f : (k == 1 ? 0.03f : 0.06f)) + 0.03f * cosf(ang)) * 2.6f) + 0.4f,

                   (((k == 1 ? 0.015f : 0.0f) + 0.03f * sinf(ang)) * 1.7f) + 0.72f);

    }

    glEnd();

}


// Mini cloud 2 chain

for (int k = 0; k < 5; ++k) {

    glBegin(GL_TRIANGLE_FAN);



    // Center vertex

    glVertex2f(

        ((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f) * 0.5f) + 0.2f,

        ((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f) * 0.5f) + 0.2f

    );



    for (int i = 0; i <= 100; ++i) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f(

            (((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f)

              + 0.08f * cosf(ang)) * 0.5f) + 0.2f,

            (((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f)

              + 0.08f * sinf(ang)) * 0.5f) + 0.2f

        );

    }



    glEnd();

}


// Mini cloud 3 chain


for (int k = 0; k < 5; ++k) {

    glBegin(GL_TRIANGLE_FAN);



    // Center vertex

    glVertex2f(

        ((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f) * 0.5f) + 0.9f,

        ((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f) * 0.5f) + 0.2f

    );



    for (int i = 0; i <= 100; ++i) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f(

            (((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f)

               + 0.08f * cosf(ang)) * 0.5f) + 0.9f,

            (((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f)

               + 0.08f * sinf(ang)) * 0.5f) + 0.2f

        );

    }



    glEnd();

}



//mini cloud 1 chain ------------
for (int k = 0; k < 5; ++k) {

    glBegin(GL_TRIANGLE_FAN);



    // Center vertex

    glVertex2f(

        ((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f) * 0.5f) - 0.68f,

        ((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f) * 0.5f) + 0.15f

    );



    for (int i = 0; i <= 100; ++i) {

        float ang = 2.0f * 3.1416f * i / 100.0f;

        glVertex2f(

            (((k == 0 ? -0.3f : k == 1 ? -0.2f : k == 2 ? -0.25f : k == 3 ? -0.1f : -0.15f)

               + 0.08f * cosf(ang)) * 0.5f) - 0.68f,

            (((k == 0 || k == 1 || k == 3 ? 0.6f : 0.65f)

               + 0.08f * sinf(ang)) * 0.5f) + 0.15f

        );

    }



    glEnd();

}


glPopMatrix();








// ---------------- Runway & Ground Details ----------------
    // Runway dashes
    for (int x = 0; x <= 1500; x += 100) {
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f((x / 750.0f) - 1.0f, -0.77f);
    glVertex2f(((x + 50) / 750.0f) - 1.0f, -0.77f);
    glEnd();
}





//------------------Building-----------------------

glPushMatrix();

//left side
glBegin(GL_QUADS);
glColor3f(0.094f, 0.294f, 0.427f);
glVertex2f(-0.96f, -0.56f);
glVertex2f(-0.96f, -0.444f);
glVertex2f(-0.71f, -0.212f);
glVertex2f(-0.71f, -0.56f);
glEnd();

//main rectangle box
glBegin(GL_QUADS);
glColor3f(0.094f, 0.294f, 0.427f);
glVertex2f(-0.71f, -0.038f);
glVertex2f(-0.64f, -0.038f);
glVertex2f(-0.64f, -0.56f);
glVertex2f(-0.71f, -0.56f);
glEnd();

//right side
glBegin(GL_QUADS);
glColor3f(0.094f, 0.294f, 0.427f);
glVertex2f(-0.64f, -0.56f);
glVertex2f(-0.64f, -0.212f);
glVertex2f(-0.36f, -0.473f);
glVertex2f(-0.36f, -0.56f);
glEnd();

//upper left side
glBegin(GL_QUADS);
glColor3f(0.094f, 0.294f, 0.427f);
glVertex2f(-0.89f, -0.154f);
glVertex2f(-0.71f, -0.154f);
glVertex2f(-0.71f, -0.212f);
glVertex2f(-0.85f, -0.357f);
glEnd();

//upper right side
glBegin(GL_QUADS);
glColor3f(0.094f, 0.294f, 0.427f);
glVertex2f(-0.64f, -0.154f);
glVertex2f(-0.46f, -0.154f);
glVertex2f(-0.50f, -0.357f);
glVertex2f(-0.64f, -0.212f);
glEnd();

//border
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.96f, -0.444f);
glVertex2f(-0.95f, -0.444f);
glVertex2f(-0.95f, -0.56f);
glVertex2f(-0.96f, -0.56f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.96f, -0.444f);
glVertex2f(-0.71f, -0.212f);
glVertex2f(-0.71f, -0.241f);
glVertex2f(-0.95f, -0.444f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.85f, -0.357f);
glVertex2f(-0.89f, -0.154f);
glVertex2f(-0.88f, -0.154f);
glVertex2f(-0.85f, -0.328f);
glEnd();

glBegin(GL_QUADS); //problm
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.89f, -0.154f);
glVertex2f(-0.71f, -0.154f);
glVertex2f(-0.71f, -0.183f);
glVertex2f(-0.88f, -0.183f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.71f, -0.125f);
glVertex2f(-0.64f, -0.125f);
glVertex2f(-0.64f, -0.096f);
glVertex2f(-0.71f, -0.096f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.64f, -0.154f);
glVertex2f(-0.46f, -0.154f);
glVertex2f(-0.47f, -0.183f);
glVertex2f(-0.64f, -0.183f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.46f, -0.154f);
glVertex2f(-0.50f, -0.357f);
glVertex2f(-0.50f, -0.328f);
glVertex2f(-0.47f, -0.154f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.36f, -0.473f);
glVertex2f(-0.36f, -0.56f);
glVertex2f(-0.37f, -0.56f);
glVertex2f(-0.37f, -0.473f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.36f, -0.473f);
glVertex2f(-0.36f, -0.56f);
glVertex2f(-0.37f, -0.56f);
glVertex2f(-0.37f, -0.473f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.36f, -0.473f);
glVertex2f(-0.64f, -0.212f);
glVertex2f(-0.64f, -0.241f);
glVertex2f(-0.37f, -0.473f);
glEnd();

//line...
// White line in OpenGL
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex2f(-0.88f, -0.386f);
glVertex2f(-0.88f, -0.56f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex2f(-0.79f, -0.299f);
glVertex2f(-0.79f, -0.56f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex2f(-0.71f, -0.212f);
glVertex2f(-0.71f, -0.56f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex2f(-0.64f, -0.212f);
glVertex2f(-0.64f, -0.56f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex2f(-0.57f, -0.299f);
glVertex2f(-0.57f, -0.56f);

glVertex2f(-0.47f, -0.386f);
glVertex2f(-0.47f, -0.56f);
glEnd();

//shade line
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(0.5f);
glBegin(GL_LINES);
glVertex2f(-0.70f, -0.125f);
glVertex2f(-0.70f, -0.56f);

glVertex2f(-0.68f, -0.125f);
glVertex2f(-0.68f, -0.56f);

glVertex2f(-0.66f, -0.125f);
glVertex2f(-0.66f, -0.56f);

glVertex2f(-0.71f, -0.183f);
glVertex2f(-0.64f, -0.183f);

glVertex2f(-0.71f, -0.270f);
glVertex2f(-0.64f, -0.270f);

glVertex2f(-0.71f, -0.386f);
glVertex2f(-0.64f, -0.386f);

glVertex2f(-0.71f, -0.473f);
glVertex2f(-0.64f, -0.473f);

glVertex2f(-0.73f, -0.56f);
glVertex2f(-0.73f, -0.154f);

glVertex2f(-0.76f, -0.56f);
glVertex2f(-0.76f, -0.154f);

glVertex2f(-0.81f, -0.56f);
glVertex2f(-0.81f, -0.154f);

glVertex2f(-0.85f, -0.154f);
glVertex2f(-0.85f, -0.56f);

glVertex2f(-0.91f, -0.415f);
glVertex2f(-0.91f, -0.56f);


glVertex2f(-0.95f, -0.473f);
glVertex2f(-0.71f, -0.473f);

glVertex2f(-0.88f, -0.386f);
glVertex2f(-0.71f, -0.386f);

glVertex2f(-0.78f, -0.270f);
glVertex2f(-0.86f, -0.270f);

//right side shade
glVertex2f(-0.64f, -0.183f); //prob
glVertex2f(-0.47f, -0.183f);

glVertex2f(-0.57f, -0.270f);
glVertex2f(-0.49f, -0.270f);

glVertex2f(-0.64f, -0.386f);
glVertex2f(-0.47f, -0.386f);

glVertex2f(-0.64f, -0.473f);
glVertex2f(-0.37f, -0.473f);

glVertex2f(-0.62f, -0.154f);
glVertex2f(-0.62f, -0.56f);

glVertex2f(-0.59f, -0.154f);
glVertex2f(-0.59f, -0.56f);

glVertex2f(-0.54f, -0.154f);
glVertex2f(-0.54f, -0.56f);

glVertex2f(-0.50f, -0.154f);
glVertex2f(-0.50f, -0.56f);

glVertex2f(-0.44f, -0.415f);
glVertex2f(-0.44f, -0.56f);

glVertex2f(-0.40f, -0.444f);
glVertex2f(-0.40f, -0.56f);

glVertex2f(-0.58f, -0.270f);
glVertex2f(-0.49f, -0.270f);

glEnd();
glPopMatrix();



//Misssile Truck...


// --------------------- Realistic Missile Truck -----------------------
glPushMatrix();
glTranslatef(position5,0.0f, 0.0f);

// ---- Base Body  ----
glColor3f(0.65f, 0.55f, 0.35f); // military brown
glBegin(GL_POLYGON);
    glVertex2f(0.3301f, -0.932f);
    glVertex2f(0.7085f, -0.932f);
    glVertex2f(0.7085f, -0.824f);
    glVertex2f(0.3301f, -0.824f);
glEnd();
// Shading strip (bottom shadow)
glColor3f(0.45f, 0.38f, 0.2f);
glBegin(GL_POLYGON);
    glVertex2f(0.3301f, -0.932f);
    glVertex2f(0.7085f, -0.932f);
    glVertex2f(0.7085f, -0.908f);
    glVertex2f(0.3301f, -0.908f);
glEnd();
// ---- Cabin (rounded front, more 3D look) ----
glColor3f(0.7f, 0.6f, 0.3f); // golden brown
glBegin(GL_POLYGON);
    glVertex2f(0.2914f, -0.932f);
    glVertex2f(0.3946f, -0.932f);
    glVertex2f(0.3946f, -0.752f);
    glVertex2f(0.2914f, -0.788f);
glEnd();
// Cabin roof highlight
glColor3f(0.8f, 0.7f, 0.4f);
glBegin(GL_POLYGON);
    glVertex2f(0.2914f, -0.788f);
    glVertex2f(0.3946f, -0.752f);
    glVertex2f(0.3946f, -0.77f);
    glVertex2f(0.2914f, -0.806f);
glEnd();
// ---- Cabin Window (realistic glass look) ----
glColor3f(0.0f, 0.0f, 0.0f); // black border
glBegin(GL_POLYGON);
    glVertex2f(0.30645f, -0.884f);
    glVertex2f(0.37525f, -0.866f);
    glVertex2f(0.37525f, -0.77f);
    glVertex2f(0.30645f, -0.794f);
glEnd();
glBegin(GL_POLYGON); // main glass gradient
    glColor3f(0.25f, 0.75f, 1.0f);
    glVertex2f(0.3086f, -0.878f);
    glVertex2f(0.3731f, -0.86f);
    glColor3f(0.05f, 0.45f, 0.75f);
    glVertex2f(0.3731f, -0.776f);
    glVertex2f(0.3086f, -0.8f);
glEnd();
// ---- Missile Body (tapered rectangle) ----
glColor3f(0.45f, 0.55f, 0.65f);
glBegin(GL_POLYGON);
    glVertex2f(0.386f, -0.824f);
    glVertex2f(0.6956f, -0.824f);
    glVertex2f(0.6956f, -0.758f);
    glVertex2f(0.386f, -0.758f);
glEnd();
// ---- Missile Nose  ----
glColor3f(0.45f, 0.55f, 0.65f);
glBegin(GL_POLYGON);
    glVertex2f(0.6956f, -0.824f);
    glVertex2f(0.6956f, -0.758f);
    glVertex2f(0.73645f, -0.782f);
    glVertex2f(0.7386f, -0.791f);
    glVertex2f(0.73645f, -0.8f);
    glVertex2f(0.7042f, -0.761f);
    glVertex2f(0.7042f, -0.821f);
glEnd();
// Top highlight
glColor3f(0.6f, 0.65f, 0.7f);
glBegin(GL_POLYGON);
    glVertex2f(0.70205f, -0.767f);
    glVertex2f(0.7343f, -0.782f);
    glVertex2f(0.7042f, -0.761f);
glEnd();
// Bottom shadow
glColor3f(0.35f, 0.45f, 0.55f);
glBegin(GL_POLYGON);
    glVertex2f(0.70205f, -0.821f);
    glVertex2f(0.7343f, -0.8f);
    glVertex2f(0.7042f, -0.821f);
glEnd();
// Vertical metallic lines
glColor3f(0.65f, 0.70f, 0.75f);
for (float x = 0.23f; x <= 0.91f; x += 0.07f) {
    glBegin(GL_LINES);
        glVertex2f(x * 0.43f + 0.3f, -0.821f);
        glVertex2f(x * 0.43f + 0.3f, -0.767f);
    glEnd();
}
// ---- Wheels (6 wheels) ----
for (float x = 0.15f; x <= 0.9f; x += 0.15f) {
    glColor3f(0.05f, 0.05f, 0.05f); // outer tire
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f((x + 0.05f * cos(theta)) * 0.43f + 0.3f, (0.2f + 0.05f * sin(theta)) * 0.6f - 1.04f);
        }
    glEnd();
    glColor3f(0.3f, 0.3f, 0.3f); // inner rim
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f((x + 0.025f * cos(theta)) * 0.43f + 0.3f, (0.2f + 0.025f * sin(theta)) * 0.6f - 1.04f);
        }
    glEnd();
}


glPopMatrix();





//Watch Tower....

glPushMatrix();

// First quad
glBegin(GL_QUADS);
glColor3f(201/255.0f, 227/255.0f, 249/255.0f);
glVertex2f(-0.291f, -0.53f);
glVertex2f(-0.172f, -0.53f);
glVertex2f(-0.172f, -0.562f);
glVertex2f(-0.291f, -0.562f);
glEnd();

glBegin(GL_QUADS);
glColor3f(221/255.0f, 241/255.0f, 250/255.0f);
glVertex2f(-0.284f, -0.434f);
glVertex2f(-0.179f, -0.434f);
glVertex2f(-0.179f, -0.53f);
glVertex2f(-0.284f, -0.53f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.094f, 0.294f, 0.427f);
glVertex2f(-0.27f, -0.434f);
glVertex2f(-0.27f, -0.114f);
glVertex2f(-0.193f, -0.114f);
glVertex2f(-0.193f, -0.434f);
glEnd();

glBegin(GL_QUADS);
glColor3f(193/255.0f, 226/255.0f, 245/255.0f);
glVertex2f(-0.284f, -0.066f);
glVertex2f(-0.179f, -0.066f);
glVertex2f(-0.179f, -0.114f);
glVertex2f(-0.284f, -0.114f);
glEnd();

glBegin(GL_QUADS);
glColor3f(218/255.0f, 241/255.0f, 253/255.0f);
glVertex2f(-0.291f, -0.018f);
glVertex2f(-0.172f, -0.018f);
glVertex2f(-0.172f, -0.082f);
glVertex2f(-0.291f, -0.082f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.094f, 0.294f, 0.427f);
glVertex2f(-0.27f, 0.062f);
glVertex2f(-0.193f, 0.062f);
glVertex2f(-0.193f, -0.018f);
glVertex2f(-0.27f, -0.018f);
glEnd();

glBegin(GL_QUADS);
glColor3f(238/255.0f, 249/255.0f, 253/255.0f);
glVertex2f(-0.284f, 0.078f);
glVertex2f(-0.172f, 0.078f);
glVertex2f(-0.172f, 0.062f);
glVertex2f(-0.284f, 0.062f);
glEnd();

glBegin(GL_QUADS);
glColor3f(198/255.0f, 228/255.0f, 242/255.0f);
glVertex2f(-0.277f, 0.11f);
glVertex2f(-0.179f, 0.11f);
glVertex2f(-0.179f, 0.078f);
glVertex2f(-0.277f, 0.078f);
glEnd();

glBegin(GL_QUADS);
glColor3f(76/255.0f, 145/255.0f, 181/255.0f);
glVertex2f(-0.298f, 0.238f);
glVertex2f(-0.158f, 0.238f);
glVertex2f(-0.179f, 0.11f);
glVertex2f(-0.277f, 0.11f);
glEnd();

// Inner dex
glBegin(GL_QUADS);
glColor3f(0.25f, 0.75f, 1.0f);
//glColor3f(0.094f, 0.294f, 0.427f);
glVertex2f(-0.27f, 0.206f);
glVertex2f(-0.186f, 0.206f);
glVertex2f(-0.186f, 0.142f);
glVertex2f(-0.27f, 0.142f);
glEnd();

//border
glBegin(GL_LINE_LOOP);
glColor3f(0.0f, 0.0f, 0.0f);
//glColor3f(0.094f, 0.294f, 0.427f);
glVertex2f(-0.27f, 0.206f);
glVertex2f(-0.186f, 0.206f);
glVertex2f(-0.186f, 0.142f);
glVertex2f(-0.27f, 0.142f);
glEnd();

glBegin(GL_QUADS);
glColor3f(238/255.0f, 252/255.0f, 252/255.0f);
glVertex2f(-0.298f, 0.254f);
glVertex2f(-0.158f, 0.254f);
glVertex2f(-0.158f, 0.238f);
glVertex2f(-0.298f, 0.238f);
glEnd();

glBegin(GL_QUADS);
glColor3f(162/255.0f, 210/255.0f, 238/255.0f);
glVertex2f(-0.27f, 0.302f);
glVertex2f(-0.186f, 0.302f);
glVertex2f(-0.186f, 0.254f);
glVertex2f(-0.27f, 0.254f);
glEnd();

glBegin(GL_QUADS);
glColor3f(220/255.0f, 241/255.0f, 250/255.0f);
glVertex2f(-0.249f, 0.318f);
glVertex2f(-0.207f, 0.318f);
glVertex2f(-0.207f, 0.302f);
glVertex2f(-0.249f, 0.302f);
glEnd();

glBegin(GL_QUADS);

glColor3f(69/255.0f, 149/255.0f, 180/255.0f);
glVertex2f(-0.256f, 0.35f);
glVertex2f(-0.2f, 0.35f);
glVertex2f(-0.207f, 0.318f);
glVertex2f(-0.249f, 0.318f);
glEnd();

// White line
glColor3f(1.0f, 1.0f, 1.0f);
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex2f(-0.228f, 0.35f);
glVertex2f(-0.228f, 0.43f);
glEnd();

// Red circle on top
float circleCx = -0.228f;
float circleCy = 0.43f;
float radius = 0.011f;
int segments = 50;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(circleCx, circleCy); // center
for(int i = 0; i <= segments; i++) {
    float angle = 2.0f * M_PI * i / segments;
    glVertex2f(circleCx + radius * cos(angle),
               circleCy + radius * sin(angle));
}
glEnd();

// Optional border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINE_LOOP);
for(int i = 0; i <= segments; i++) {
    float angle = 2.0f * M_PI * i / segments;
    glVertex2f(circleCx + radius * cos(angle),
               circleCy + radius * sin(angle));
}
glEnd();


glPopMatrix();




// ----------------- Hangar -----------------
glPushMatrix();

// --------Main Body ------------
glColor3f(160/255.0f, 174/255.0f, 199/255.0f);

//glColor3f(0.6f, 0.6f, 0.6f);//orginal side color
glBegin(GL_POLYGON);
    glVertex2f(0.37f, -0.56f);
    glVertex2f(0.37f, -0.20f);
    glVertex2f(0.97f, -0.20f);
    glVertex2f(0.97f, -0.56f);
glEnd();
// ------------Roof -----------
glColor3f(94/255.0f, 105/255.0f, 124/255.0f);
//glColor3f(0.7f, 0.7f, 0.7f);//original color
glBegin(GL_POLYGON);//chata shape
    glVertex2f(0.37f, -0.20f);
    glVertex2f(0.97f, -0.20f);
    for(int i = 0; i <= 40; i++) {
        float t = (float)i / 40.0f;
        float x = (-0.5f + t * 1.0f) * 0.6f + 0.67f;
        float y = (0.6f + 0.25f * sin(t * 3.14159f)) * 0.6f - 0.56f;
        glVertex2f(x, y);
    }
    glVertex2f(0.37f, -0.20f);
glEnd();
// ---------Black Board ---------------
/*glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.562f, -0.158f);
    glVertex2f(0.562f, -0.08f);
    glVertex2f(0.778f, -0.08f);
    glVertex2f(0.778f, -0.158f);
glEnd();

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
    glVertex2f(0.562f, -0.178f);
    glVertex2f(0.562f, -0.1f);
    glVertex2f(0.778f, -0.1f);
    glVertex2f(0.778f, -0.178f);
glEnd();*/




// -------------- Text on Sign --------------
glColor3f(1.0f, 1.0f, 1.0f);
glRasterPos3f(0.59f, -0.153f, 0.0f);
const char *text = "HANGAR";
for (const char *c = text; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
}
// --------------Sliding Door-----------
glColor3f(0.3f, 0.3f, 0.3f);
glBegin(GL_POLYGON);
    glVertex2f(0.40f, -0.56f);
    glVertex2f(0.40f, -0.26f);
    glVertex2f(0.94f, -0.26f);
    glVertex2f(0.94f, -0.56f);
glEnd();
// -------------Door Separation Lines ------------
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(2.0f);
glBegin(GL_LINES);
    for(float x = -0.35f; x <= 0.35f; x += 0.2f) {
        glVertex2f(x * 0.6f + 0.67f, -0.56f);
        glVertex2f(x * 0.6f + 0.67f, -0.26f);
    }
glEnd();
// -----------------Lock System ------------------
glColor3f(0.7f, 0.5f, 0.2f); // lock body
glBegin(GL_POLYGON);
    glVertex2f(0.64f, -0.44f);
    glVertex2f(0.64f, -0.35f);
    glVertex2f(0.70f, -0.35f);
    glVertex2f(0.70f, -0.44f);
glEnd();
// Keyhole (circle)
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
for(int i = 0; i < 40; i++) {
    float theta = 2.0f * 3.14159f * i / 40;
    float x = (0.02f * cos(theta)) * 0.6f + 0.67f;
    float y = (0.275f + 0.02f * sin(theta)) * 0.6f - 0.56f;
    glVertex2f(x, y);
}
glEnd();

glPopMatrix();




//-------------------military car -------------------

glPushMatrix();
glTranslatef(position6,0.0f, 0.0f);

//left side
glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.365f, -0.8615f);
glVertex2f(-0.3695f, -0.8615f);
glVertex2f(-0.3695f, -0.833f);
glVertex2f(-0.365f, -0.852f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.3695f, -0.833f);
glVertex2f(-0.3695f, -0.8235f);
glVertex2f(-0.3695f, -0.8235f);
glVertex2f(-0.365f, -0.814f);
glVertex2f(-0.365f, -0.852f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.365f, -0.814f);
glVertex2f(-0.365f, -0.852f);
glVertex2f(-0.3605f, -0.8425f);
glVertex2f(-0.3605f, -0.833f);
glVertex2f(-0.3605f, -0.8425f);
glEnd();

glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.365f, -0.814f);
glVertex2f(-0.3605f, -0.8425f);
glVertex2f(-0.356f, -0.833f);
glVertex2f(-0.3515f, -0.833f);
glEnd();

glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.365f, -0.814f);
glVertex2f(-0.329f, -0.8045f);
glVertex2f(-0.329f, -0.833f);
glVertex2f(-0.3515f, -0.833f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.329f, -0.8045f);
glVertex2f(-0.3155f, -0.8045f);
glVertex2f(-0.32f, -0.833f);
glVertex2f(-0.32f, -0.833f);
glVertex2f(-0.329f, -0.833f);
glEnd();

glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.3155f, -0.8045f);
glVertex2f(-0.2975f, -0.795f);
glVertex2f(-0.3065f, -0.8805f);
glVertex2f(-0.32f, -0.833f);
glEnd();

glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.3065f, -0.8805f);
glVertex2f(-0.2975f, -0.795f);
glVertex2f(-0.194f, -0.8045f);
glVertex2f(-0.1985f, -0.8805f);
glEnd();

glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.2975f, -0.795f);
glVertex2f(-0.2885f, -0.7475f);
glVertex2f(-0.1715f, -0.7475f);
glVertex2f(-0.194f, -0.8045f);
glEnd();

glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.284f, -0.738f);
glVertex2f(-0.194f, -0.738f);
glVertex2f(-0.1715f, -0.7475f);
glVertex2f(-0.2885f, -0.7475f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.194f, -0.8045f);
glVertex2f(-0.176f, -0.833f);
glVertex2f(-0.1805f, -0.8425f);
glVertex2f(-0.194f, -0.8805f);
glVertex2f(-0.1985f, -0.8805f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.194f, -0.8045f);
glVertex2f(-0.1175f, -0.8045f);
glVertex2f(-0.14f, -0.833f);
glVertex2f(-0.1445f, -0.833f);
glVertex2f(-0.176f, -0.833f);
glEnd();

glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.1715f, -0.7475f);
glVertex2f(-0.122f, -0.776f);
glVertex2f(-0.1175f, -0.8045f);
glVertex2f(-0.194f, -0.8045f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 109/255.0f);
glVertex2f(-0.1175f, -0.8045f);
glVertex2f(-0.14f, -0.833f);
glVertex2f(-0.131f, -0.871f);
glVertex2f(-0.122f, -0.871f);
glVertex2f(-0.1175f, -0.8615f);
glEnd();

//Glass
glBegin(GL_QUADS);
glColor3f(181/255.0f, 206/255.0f, 215/255.0f);
glVertex2f(-0.284f, -0.757f);
glVertex2f(-0.257f, -0.757f);
glVertex2f(-0.257f, -0.795f);
glVertex2f(-0.284f, -0.795f);
glEnd();

glBegin(GL_QUADS);
glColor3f(181/255.0f, 206/255.0f, 215/255.0f);
glVertex2f(-0.2345f, -0.757f);
glVertex2f(-0.2075f, -0.757f);
glVertex2f(-0.2075f, -0.795f);
glVertex2f(-0.2345f, -0.795f);
glEnd();

//upper missile part
glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 102/255.0f);
glVertex2f(-0.284f, -0.738f);
glVertex2f(-0.275f, -0.7285f);
glVertex2f(-0.2705f, -0.719f);
glVertex2f(-0.2705f, -0.7095f);
glVertex2f(-0.2255f, -0.738f);
glEnd();

glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 102/255.0f);
glVertex2f(-0.2705f, -0.7095f);
glVertex2f(-0.2615f, -0.7095f);
glVertex2f(-0.2255f, -0.7095f);
glVertex2f(-0.2255f, -0.738f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 102/255.0f);
glVertex2f(-0.2255f, -0.7095f);
glVertex2f(-0.2165f, -0.7095f);
glVertex2f(-0.2165f, -0.719f);
glVertex2f(-0.2165f, -0.738f);
glVertex2f(-0.2255f, -0.738f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 102/255.0f);
glVertex2f(-0.2255f, -0.7095f);
glVertex2f(-0.2255f, -0.6905f);
glVertex2f(-0.221f, -0.6905f);
glVertex2f(-0.2165f, -0.6905f);
glVertex2f(-0.2165f, -0.7095f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(111/255.0f, 119/255.0f, 102/255.0f);
glVertex2f(-0.2525f, -0.7f);
glVertex2f(-0.2435f, -0.7f);
glVertex2f(-0.239f, -0.7f);
glVertex2f(-0.239f, -0.7095f);
glVertex2f(-0.2525f, -0.7095f);
glEnd();

//car chaka ar paser sado..
glBegin(GL_POLYGON);
glColor3f(71/255.0f, 78/255.0f, 64/255.0f);
glVertex2f(-0.3605f, -0.8425f);
glVertex2f(-0.356f, -0.833f);
glVertex2f(-0.3515f, -0.833f);
glVertex2f(-0.329f, -0.833f);
glVertex2f(-0.329f, -0.8425f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(71/255.0f, 78/255.0f, 64/255.0f);
glVertex2f(-0.329f, -0.8425f);
glVertex2f(-0.329f, -0.833f);
glVertex2f(-0.32f, -0.833f);
glVertex2f(-0.3245f, -0.8425f);
glVertex2f(-0.3245f, -0.8425f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(71/255.0f, 78/255.0f, 64/255.0f);
glVertex2f(-0.3245f, -0.8425f);
glVertex2f(-0.32f, -0.833f);
glVertex2f(-0.32f, -0.833f);
glVertex2f(-0.3065f, -0.8805f);
glVertex2f(-0.311f, -0.89f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(71/255.0f, 78/255.0f, 64/255.0f);
glVertex2f(-0.311f, -0.89f);
glVertex2f(-0.3065f, -0.8805f);
glVertex2f(-0.194f, -0.8805f);
glVertex2f(-0.194f, -0.89f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(71/255.0f, 78/255.0f, 64/255.0f);
glVertex2f(-0.1805f, -0.8425f);
glVertex2f(-0.176f, -0.833f);
glVertex2f(-0.1445f, -0.833f);
glVertex2f(-0.149f, -0.8425f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(71/255.0f, 78/255.0f, 64/255.0f);
glVertex2f(-0.149f, -0.8425f);
glVertex2f(-0.1445f, -0.833f);
glVertex2f(-0.14f, -0.833f);
glVertex2f(-0.14f, -0.8425f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(71/255.0f, 78/255.0f, 64/255.0f);
glVertex2f(-0.14f, -0.833f);
glVertex2f(-0.14f, -0.8425f);
glVertex2f(-0.1355f, -0.871f);
glVertex2f(-0.131f, -0.871f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(71/255.0f, 78/255.0f, 64/255.0f);
glVertex2f(-0.131f, -0.871f);
glVertex2f(-0.122f, -0.871f);
glVertex2f(-0.1265f, -0.871f);
glVertex2f(-0.1355f, -0.871f);
glEnd();

//car ar samner hook...
glBegin(GL_QUADS);
glColor3f(52/255.0f, 51/255.0f, 54/255.0f);
glVertex2f(-0.374f, -0.852f);
glVertex2f(-0.3695f, -0.852f);
glVertex2f(-0.3695f, -0.8615f);
glVertex2f(-0.374f, -0.8615f);
glEnd();

glBegin(GL_QUADS);
glColor3f(52/255.0f, 51/255.0f, 54/255.0f);
glVertex2f(-0.3785f, -0.871f);
glVertex2f(-0.374f, -0.871f);
glVertex2f(-0.374f, -0.8235f);
glVertex2f(-0.3785f, -0.8235f);
glEnd();

//missile front
glBegin(GL_QUADS);
glColor3f(111/255.0f, 119/255.0f, 102/255.0f);
glVertex2f(-0.2705f, -0.719f);
glVertex2f(-0.3335f, -0.719f);
glVertex2f(-0.329f, -0.7285f);
glVertex2f(-0.275f, -0.7285f);
glEnd();

//car line shedo...
glColor3f(72/255.0f, 78/255.0f, 66/255.0f);
glLineWidth(3.0f);
glBegin(GL_LINES);
glVertex2f(-0.2885f, -0.7475f);
glVertex2f(-0.248f, -0.7475f);

glVertex2f(-0.248f, -0.7475f);
glVertex2f(-0.248f, -0.871f);

glVertex2f(-0.248f, -0.871f);
glVertex2f(-0.2885f, -0.871f);

glVertex2f(-0.2885f, -0.871f);
glVertex2f(-0.2885f, -0.7475f);

glVertex2f(-0.2435f, -0.871f);
glVertex2f(-0.203f, -0.871f);

glVertex2f(-0.203f, -0.871f);
glVertex2f(-0.1895f, -0.795f);

glVertex2f(-0.1895f, -0.795f);
glVertex2f(-0.1985f, -0.7475f);

glVertex2f(-0.1985f, -0.7475f);
glVertex2f(-0.2435f, -0.7475f);

glVertex2f(-0.2435f, -0.7475f);
glVertex2f(-0.2435f, -0.871f);
glEnd();

//car ar chaka
//pechoner chaka
glColor3f(0.1f, 0.1f, 0.1f); // outer dark wheel
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.1625f, -0.8995f);  // center
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        glVertex2f(-0.1625f + 0.027f * cosf(angle), -0.8995f + 0.057f * sinf(angle));
    }
glEnd();

// --------Inner Hub ---------
glColor3f(0.5f, 0.5f, 0.5f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.1625f, -0.8995f);
    for (int i = 0; i <= 50; i++) {
        float angle = 2.0f * 3.1416f * i / 50;
        glVertex2f(-0.1625f + 0.0135f * cosf(angle), -0.8995f + 0.0285f * sinf(angle));
    }
glEnd();

//samner chaka..
glColor3f(0.1f, 0.1f, 0.1f); // dark outer wheel
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.347f, -0.8995f); // center
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100.0f;
        glVertex2f(-0.3425f + 0.027f * cosf(angle), -0.8995f + 0.057f * sinf(angle));
    }
glEnd();

// ---------- Inner Hub ---------
glColor3f(0.5f, 0.5f, 0.5f); // lighter inner hub
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.347f, -0.8995f); // center
    for (int i = 0; i <= 50; i++) {
        float angle = 2.0f * 3.1416f * i / 50.0f;
        glVertex2f(-0.3425f + 0.0135f * cosf(angle), -0.8995f + 0.0285f * sinf(angle));
    }
glEnd();


glPopMatrix();



//-------------------------military jeet------------------------

glPushMatrix();
glTranslatef(position7, y7, 0.0f);   // shift plane position

glLineWidth(2.0f); // thicker border for visibility
// ---------------- Body last part ----------------
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.102f, 0.6988f);
glVertex2f(0.102f, 0.6708f);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.102f, 0.6988f);
glVertex2f(0.102f, 0.6708f);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glEnd();
// ---------------- Body middle ----------------
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.0195f, 0.6568f);
glVertex2f(0.018f, 0.71f);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glEnd();
// ---------------- Body front ----------------
glBegin(GL_POLYGON);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.0615f, 0.696f);
glVertex2f(-0.0615f, 0.6596f);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glEnd();
// ---------------- Nose ----------------
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34f, 0.36f);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glVertex2f(-0.108f, 0.6708f);
glVertex2f(-0.111f, 0.6652f);
glVertex2f(-0.108f, 0.6652f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.084f, 0.6596f);
glVertex2f(-0.08475f, 0.6736f);
glVertex2f(-0.084f, 0.6848f);
glVertex2f(-0.108f, 0.6708f);
glVertex2f(-0.111f, 0.6652f);
glVertex2f(-0.108f, 0.6652f);
glEnd();
// ---------------- Ellipse (window) ----------------
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.021f + 0.0405f * cos(angle),
               0.696f + 0.0252f * sin(angle));
}
glEnd();
// border
glLineWidth(1);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 200; i++) {
    float angle = 2.0f * M_PI * i / 200;
    glVertex2f(-0.021f + 0.0405f * cos(angle),
               0.696f + 0.0252f * sin(angle));
}
glEnd();
//window last
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.0585f, 0.6904f);
glVertex2f(0.0195f, 0.6904f);
glVertex2f(0.0195f, 0.668f);
glVertex2f(-0.0585f, 0.668f);
glEnd();
//shadow
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.036f, 0.7184f);
glVertex2f(-0.036f, 0.6932f);
glVertex2f(-0.033f, 0.6932f);
glVertex2f(-0.033f, 0.7184f);
glEnd();
//2
glBegin(GL_QUADS);
glColor3f(0.48f, 0.49f, 0.5f);
glVertex2f(-0.0105f, 0.7184f);
glVertex2f(-0.0075f, 0.7184f);
glVertex2f(-0.0105f, 0.6932f);
glVertex2f(-0.0075f, 0.6932f);
glEnd();
// ---------------- Wing bottom ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(-0.0165f, 0.6764f);
glVertex2f(0.048f, 0.682f);
glVertex2f(0.0555f, 0.6148f);
glVertex2f(0.069f, 0.584f);
glVertex2f(0.051f, 0.5728f);
glVertex2f(-0.0165f, 0.6764f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.0165f, 0.6764f);
glVertex2f(0.048f, 0.682f);
glVertex2f(0.0555f, 0.6148f);
glVertex2f(0.069f, 0.584f);
glVertex2f(0.051f, 0.5728f);
glVertex2f(-0.0165f, 0.6764f);
glEnd();
// ---------------- Wing top ----------------
glBegin(GL_POLYGON);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.0495f, 0.7044f);
glVertex2f(0.051f, 0.7464f);
glVertex2f(0.0585f, 0.7688f);
glVertex2f(0.0375f, 0.7716f);
glVertex2f(-0.0105f, 0.7212f);
glVertex2f(0.018f, 0.71f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.0495f, 0.7044f);
glVertex2f(0.051f, 0.7464f);
glVertex2f(0.0585f, 0.7688f);
glVertex2f(0.0375f, 0.7716f);
glVertex2f(-0.0105f, 0.7212f);
glVertex2f(0.018f, 0.71f);
glEnd();
// ---------------- Back wings ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.066f, 0.7044f);
glVertex2f(0.093f, 0.766f);
glVertex2f(0.099f, 0.766f);
glVertex2f(0.093f, 0.6988f);
glEnd();
// border
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.066f, 0.7044f);
glVertex2f(0.093f, 0.766f);
glVertex2f(0.099f, 0.766f);
glVertex2f(0.093f, 0.6988f);
glEnd();
// ---------------- Back wing details ----------------
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.093f, 0.7464f);
glVertex2f(0.099f, 0.7464f);
glVertex2f(0.0945f, 0.6764f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.093f, 0.7464f);
glVertex2f(0.099f, 0.7464f);
glVertex2f(0.0945f, 0.6764f);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.58f, 0.58f, 0.6f);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.0945f, 0.6764f);
glVertex2f(0.117f, 0.6484f);
glVertex2f(0.105f, 0.6512f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.06f, 0.6736f);
glVertex2f(0.0945f, 0.6764f);
glVertex2f(0.117f, 0.6484f);
glVertex2f(0.105f, 0.6512f);
glEnd();
// ---------------- Rockets ----------------
glBegin(GL_QUADS);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.0135f, 0.7296f);
glVertex2f(-0.0045f, 0.7352f);
glVertex2f(0.003f, 0.738f);
glVertex2f(-0.0075f, 0.724f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.015f, 0.7296f);
glVertex2f(-0.006f, 0.7352f);
glVertex2f(0.0045f, 0.738f);
glVertex2f(-0.009f, 0.724f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.015f, 0.64f);
glVertex2f(-0.0045f, 0.6512f);
glVertex2f(0.0f, 0.6512f);
glVertex2f(0.009f, 0.6344f);
glVertex2f(-0.0045f, 0.6344f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.015f, 0.64f);
glVertex2f(-0.0045f, 0.6512f);
glVertex2f(0.0f, 0.6512f);
glVertex2f(0.009f, 0.6344f);
glVertex2f(-0.0045f, 0.6344f);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.34f, 0.34, 0.36);
glVertex2f(-0.015f, 0.6148f);
glVertex2f(0.006f, 0.6288f);
glVertex2f(0.0135f, 0.6288f);
glVertex2f(0.03f, 0.6064f);
glVertex2f(0.003f, 0.6064f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(-0.015f, 0.6148f);
glVertex2f(0.006f, 0.6288f);
glVertex2f(0.0135f, 0.6288f);
glVertex2f(0.03f, 0.6064f);
glVertex2f(0.003f, 0.6064f);
glEnd();
//fire 1
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.696f);
glVertex2f(0.1125f, 0.6988f);
glVertex2f(0.1005f, 0.6848f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.696f);
glVertex2f(0.1125f, 0.6988f);
glVertex2f(0.1005f, 0.6848f);
glEnd();
//fire 2
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.6904f);
glVertex2f(0.117f, 0.6904f);
glVertex2f(0.1005f, 0.6764f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.6904f);
glVertex2f(0.117f, 0.6904f);
glVertex2f(0.1005f, 0.6764f);
glEnd();
//fire 3
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.6848f);
glVertex2f(0.1185f, 0.6792f);
glVertex2f(0.1005f, 0.6708f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.6848f);
glVertex2f(0.1185f, 0.6792f);
glVertex2f(0.1005f, 0.6708f);
glEnd();
//fire 4
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.25f, 0.0f);
glVertex2f(0.1005f, 0.682f);
glVertex2f(0.1125f, 0.6708f);
glVertex2f(0.1005f, 0.6736f);
glEnd();
glLineWidth(1);
glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(0.1005f, 0.682f);
glVertex2f(0.1125f, 0.6708f);
glVertex2f(0.1005f, 0.6736f);
glEnd();

glPopMatrix();

//glutTimerFunc(13000,display2,0);


glFlush();
}

// --------- Keyboard Function (Start Movement on Enter) ---------

void keyboard(unsigned char key, int x, int y) {

    if (key == 13 && !startMoving) {

        startMoving = true;
        sound1(0);
        glutTimerFunc(30, updateObjects, 0); // Start the timer
        glutTimerFunc(13000, display2, 0);
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1500, 900); // Set the window's initial width & height
    glutInitWindowPosition(0, 0);  // Set the window's initial position according to the monitor
    glutCreateWindow("The Project : Rocket");
    glutDisplayFunc(airport);

    glutKeyboardFunc(keyboard);

    init();
    glutMainLoop();
    return 0;
}
