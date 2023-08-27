#version 330 core

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

in vec3 position;
in vec3 normal;
in vec2 texCoord;
in vec4 weights;      //每个骨骼对当前顶点的权重，最多4个
in ivec4 joints;      //当前顶点受哪些骨骼影响的数组 最多4个

uniform mat4 pose[120];         //每个关节的姿势矩阵
uniform mat4 invBindPose[120];  //每个关节的逆绑定矩阵

out vec3 norm;
out vec3 fragPos;
out vec2 uv;

void main() {
    //首先计算出蒙皮矩阵，姿势矩阵 x 绑定矩阵逆矩阵
    mat4 skin  = (pose[joints.x] *  invBindPose[joints.x]) * weights.x;
    skin += (pose[joints.y] *  invBindPose[joints.y]) * weights.y;
    skin += (pose[joints.z] * invBindPose[joints.z]) * weights.z;
    skin += (pose[joints.w] * invBindPose[joints.w]) * weights.w;

    //skin矩阵的作用是先将顶点用绑定矩阵逆矩阵变换到蒙皮空间，然后用姿势矩阵变换到当前姿势下的坐标
    //下面的这行矩阵乘法从右往左看

    gl_Position = projection * view * model * skin * vec4(position, 1.0);
    
    fragPos = vec3(model * skin * vec4(position, 1.0));
    norm = vec3(model * skin * vec4(normal, 0.0f));
    uv = texCoord;
}
