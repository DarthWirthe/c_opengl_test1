#include <GL/gl.h>
#include <windows.h>
#include <math.h>

#include "camera.h"

struct SCamera camera = {0, 0, 1.7, 0, 0};

void CameraApply()
{
    glRotatef(-camera.xrot, 1, 0, 0);
    glRotatef(-camera.zrot, 0, 0, 1);
    glTranslatef(-camera.x, -camera.y, -camera.z);
}

void CameraRotation(float x, float z)
{
    camera.zrot += z;
    if (camera.zrot < 0) camera.zrot += 360;
    if (camera.zrot > 360) camera.zrot -= 360;
    camera.xrot += x;
    if (camera.xrot < 0) camera.xrot = 0;
    if (camera.xrot > 180) camera.xrot = 180;
}

void Camera_MoveByMouse(int centerX, int centerY, float speed)
{
    POINT cursor;
    POINT base = {centerX, centerY};
    GetCursorPos(&cursor);
    CameraRotation( (base.y - cursor.y) / 5.0, (base.x - cursor.x) / 5.0);
    SetCursorPos(base.x, base.y);
}

void Camera_MoveDirection(int forwardMove, int sideMove, float speed)
{
    float angle = -camera.zrot / 180 * M_PI;
    if (forwardMove > 0)
        angle += sideMove > 0 ? M_PI_4 : (sideMove < 0 ? -M_PI_4 : 0);
    if (forwardMove < 0)
        angle += M_PI + (sideMove > 0 ? -M_PI_4 : (sideMove < 0 ? M_PI_4 : 0));
    if (forwardMove == 0)
    {
        angle += sideMove > 0 ? M_PI_2 : -M_PI_2;
        if (sideMove == 0)
            speed = 0;
    }

    if (speed != 0)
    {
        camera.x += sin(angle) * speed;
        camera.y += cos(angle) * speed;
    }


}


