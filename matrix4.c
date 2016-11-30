/*
 Copyright (c) 2016 Tim Gover
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do
 so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include "matrix4.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

matrix4f matrix4f_identity(matrix4f m)
{
    m[0][0] = 1.f;
    m[0][1] = 0.f;
    m[0][2] = 0.f;
    m[0][3] = 0.f;
    
    m[1][0] = 0.f;
    m[1][1] = 1.f;
    m[1][2] = 0.f;
    m[1][3] = 0.f;

    m[2][0] = 0.f;
    m[2][1] = 0.f;
    m[2][2] = 1.f;
    m[2][3] = 0.f;

    m[3][0] = 0.f;
    m[3][1] = 0.f;
    m[3][2] = 0.f;
    m[3][3] = 1.f;
    return m;
}

matrix4f matrix4f_scaling(matrix4f m, float scale)
{
    m[0][0] = scale;
    m[0][1] = 0.f;
    m[0][2] = 0.f;
    m[0][3] = 0.f;
    
    m[1][0] = 0.f;
    m[1][1] = scale;
    m[1][2] = 0.f;
    m[1][3] = 0.f;
    
    m[2][0] = 0.f;
    m[2][1] = 0.f;
    m[2][2] = scale;
    m[2][3] = 0.f;
    
    m[3][0] = 0.f;
    m[3][1] = 0.f;
    m[3][2] = 0.f;
    m[3][3] = 1.f;
    return m;
}

matrix4f matrix4f_translation(matrix4f m, vector3f v)
{
    m[0][0] = 1.f;
    m[0][1] = 0.f;
    m[0][2] = 0.f;
    m[0][3] = 0.f;
    
    m[1][0] = 0.f;
    m[1][1] = 1.f;
    m[1][2] = 0.f;
    m[1][3] = 0.f;
    
    m[2][0] = 0.f;
    m[2][1] = 0.f;
    m[2][2] = 1.f;
    m[2][3] = 0.f;
    
    m[3][0] = v[0];
    m[3][1] = v[1];
    m[3][2] = v[2];
    m[3][3] = 1.f;
    return m;
}

matrix4f matrix4f_rotation_x(matrix4f m, float rad)
{
    float cos_r = cos(rad);
    float sin_r = sin(rad);
    
    m[0][0] = 1.f;
    m[0][1] = 0.f;
    m[0][2] = 0.f;
    m[0][3] = 0.f;
    
    m[1][0] = 0.f;
    m[1][1] = cos_r;
    m[1][2] = sin_r;
    m[1][3] = 0.f;
    
    m[2][0] = 0.f;
    m[2][1] = -sin_r;
    m[2][2] = cos_r;
    m[2][3] = 0.f;
    
    m[3][0] = 0.f;
    m[3][1] = 0.f;
    m[3][2] = 0.f;
    m[3][3] = 1.f;
    
    return m;
}

matrix4f matrix4f_rotation_y(matrix4f m, float rad)
{
    float cos_r = cos(rad);
    float sin_r = sin(rad);
    
    m[0][0] = cos_r;
    m[0][1] = 0.f;
    m[0][2] = -sin_r;
    m[0][3] = 0.f;
    
    m[1][0] = 0.f;
    m[1][1] = 1.f;
    m[1][2] = 0.f;
    m[1][3] = 0.f;
    
    m[2][0] = sin_r;
    m[2][1] = 0.f;
    m[2][2] = cos_r;
    m[2][3] = 0.f;
    
    m[3][0] = 0.f;
    m[3][1] = 0.f;
    m[3][2] = 0.f;
    m[3][3] = 1.f;

    return m;
}

matrix4f matrix4f_rotation_z(matrix4f m, float rad)
{
    float cos_r = cos(rad);
    float sin_r = sin(rad);
    
    m[0][0] = cos_r;
    m[0][1] = sin_r;
    m[0][2] = 0.f;
    m[0][3] = 0.f;
    
    m[1][0] = -sin_r;
    m[1][1] = cos_r;
    m[1][2] = 0.f;
    m[1][3] = 0.f;
    
    m[2][0] = 0.f;
    m[2][1] = 0.f;
    m[2][2] = 1.f;
    m[2][3] = 0.f;
    
    m[3][0] = 0.f;
    m[3][1] = 0.f;
    m[3][2] = 0.f;
    m[3][3] = 1.f;
    return m;
}

matrix4f matrix4f_orthographic(matrix4f m, float left, float right, float top, float bottom, float near, float far)
{
    m[0][0] = 2.f / (right - left);
    m[0][1] = 0.f;
    m[0][2] = 0.f;
    m[0][3] = 0.f;
    
    m[1][0] = 0.f;
    m[1][1] = 2.f / (top - bottom);
    m[1][2] = 0.f;
    m[1][3] = 0.f;
    
    m[2][0] = 0.f;
    m[2][1] = 0.f;
    m[2][2] = -2.f / (far - near);
    m[2][3] = 0.f;
    
    m[3][0] = 0.f;
    m[3][1] = 0.f;
    m[3][2] = -((far + near) / (far -near));
    m[3][3] = 1.f;
    return m;
}

matrix4f matrix4f_orthographic_2d(matrix4f m, float left, float right, float top, float bottom)
{
    return matrix4f_orthographic(m, left, right, top, bottom, -1.f, 1.f);
}

matrix4f matrix4f_2d_viewport(matrix4f m, float width, float height)
{
    float aspect = width / height;
    return matrix4f_orthographic_2d(m, -1.f * aspect, 1.f * aspect, 1.f, -1.f);
}


/*
 *  0 4  8 12
 *  1 5  9 13
 *  2 6 10 14
 *  3 7 11 15
 *
 *  m1 = m1 * m2
 */

matrix4f matrix4f_product(matrix4f m1, const matrix4f m2)
{
    MATRIX4F(tmp);
    int row;
    int col;
    int i;
    
    for (row = 0; row < 4; row++)
        for (col = 0; col < 4; col++)
            for (i = 0; i < 4; i++)
                tmp[col][row] += (m1[i][row] * m2[col][i]);
    
    memcpy(m1, tmp, sizeof(tmp));
    return m1;
}

#define SWAPF(A,B) \
    do {float tmp = A; A = B, B = tmp; } while(0)

matrix4f matrix4f_transpose(matrix4f m)
{
    SWAPF(m[0][1], m[1][0]);
    SWAPF(m[0][2], m[2][0]);
    SWAPF(m[1][2], m[2][1]);
    SWAPF(m[0][3], m[3][0]);
    SWAPF(m[1][3], m[3][1]);
    SWAPF(m[2][3], m[3][2]);
    return m;
}

matrix4f matrix4f_swap(matrix4f m1, matrix4f m2)
{
    matrix4fa tmp;
    
    memcpy(tmp, m1, sizeof(tmp));
    memcpy(m1, m2, sizeof(tmp));
    memcpy(m2, tmp, sizeof(tmp));
    return m1;
}

void matrix4f_print(const matrix4f m)
{
    int i;
    for (i = 0; i < 4; i++)
        printf("% 5.3f% 5.3f% 5.3f% 5.3f\n", m[0][i], m[1][i], m[2][i], m[3][i]);
}

vector3f vector3f_normalize(vector3f v)
{
    float l = vector3f_length(v);
    v[0] /= l;
    v[1] /= l;
    v[2] /= l;
    
    return v;
}

float vector3f_length(const vector3f v)
{
    return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

float vector3f_dot(const vector3f v1, const vector3f v2)
{
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v1[2];
}

vector3f vector3d_cross(vector3f v1, const vector3f v2)
{
    float x = v1[1] * v2[2] - v2[1] * v2[2];
    float y = v1[2] * v2[0] - v2[2] * v1[0];
    float z = v1[0] * v2[1] - v2[0] * v1[1];
    
    v1[0] = x;
    v1[1] = y;
    v1[2] = z;
    
    return v1;
}

vector3f vector3f_add(vector3f v1, const vector3f v2)
{
    v1[0] += v2[0];
    v1[1] += v2[1];
    v1[2] += v2[2];
    
    return v1;
}

vector3f vector3f_sub(vector3f v1, const vector3f v2)
{
    v1[0] -= v2[0];
    v1[1] -= v2[1];
    v1[2] -= v2[2];
    
    return v1;
}

vector3f vector3f_mul(vector3f v, float f)
{
    v[0] *= f;
    v[1] *= f;
    v[2] *= f;
    
    return v;
}

vector3f vector3f_div(vector3f v, float f)
{
    v[0] /= f;
    v[1] /= f;
    v[2] /= f;
    
    return v;
}

int vector3f_equals(const vector3f v1, const vector3f v2)
{
    return v1[0] == v2[0] && v1[1] == v2[1] && v1[1] == v2[2];
}

vector3f vector3f_set(vector3f v, float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    
    return v;
}

vector3f vector3f_assign(vector3f v1, vector3f v2)
{
    v1[0] = v2[0];
    v1[1] = v2[1];
    v2[1] = v2[2];
    
    return v1;
}

