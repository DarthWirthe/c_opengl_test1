#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

struct SCamera {
    float x, y, z;
    float xrot, zrot;
} camera;

void CameraApply();
void CameraRotation(float x, float z);
void Camera_MoveByMouse(int centerX, int centerY, float speed);
void Camera_MoveDirection(int forwardMove, int sideMove, float speed);

#endif // CAMERA_H_INCLUDED
