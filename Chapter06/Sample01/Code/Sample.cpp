#include "Sample.h"
#include "mat4.h"
#include "quat.h"
#include "Uniform.h"
#include "Draw.h"

static std::string vertexShader = R"(#version 410 core

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

layout (location=0) in vec3 position;
layout (location=1) in vec3 normal;
layout (location=2) in vec2 texCoord;

out vec3 fragPos;
out vec3 norm;
out vec2 uv;

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0);
    
    fragPos = vec3(model * vec4(position, 1.0));
    norm = vec3(model * vec4(normal, 0.0f));
    uv = texCoord;
}
)";

static std::string fragmentShader = R"(#version 410 core

in vec3 fragPos;
in vec3 norm;
in vec2 uv;

uniform vec3 light;
uniform sampler2D tex0;

layout(location=0) out vec4 FragColor;

void main() {
    vec4 diffuseColor = texture(tex0, uv);

    vec3 n = normalize(norm);
    vec3 l = normalize(light);
    float diffuseIntensity = clamp(dot(n, l) + 0.1, 0, 1);

    FragColor = diffuseColor * diffuseIntensity;
})";

void Sample::Initialize() {
	mRotation = 0.0f;
	mShader = new Shader();
    mShader->LoadFromSource(vertexShader, fragmentShader);
	mDisplayTexture = new Texture("../../../Chapter06/Sample01/Assets/uv.png");

	mVertexPositions = new Attribute<vec3>();
	mVertexNormals = new Attribute<vec3>();
	mVertexTexCoords = new Attribute<vec2>();
	mIndexBuffer = new IndexBuffer();

	std::vector<vec3> positions;
	positions.push_back(vec3(-1, -1, 0));
	positions.push_back(vec3(-1, 1, 0));
	positions.push_back(vec3(1, -1, 0));
	positions.push_back(vec3(1, 1, 0));
	mVertexPositions->Set(positions);

	std::vector<vec3> normals;
	normals.resize(4, vec3(0, 0, 1));
	mVertexNormals->Set(normals);

	std::vector<vec2> uvs;
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 1));
	uvs.push_back(vec2(1, 0));
	uvs.push_back(vec2(1, 1));
	mVertexTexCoords->Set(uvs);

	std::vector<unsigned int> indices;
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(2);
	indices.push_back(1);
	indices.push_back(3);
	mIndexBuffer->Set(indices);
}

void Sample::Update(float inDeltaTime) {
	mRotation += inDeltaTime * 45.0f;
	while (mRotation > 360.0f) {
		mRotation -= 360.0f;
	}
}

void Sample::Render(float inAspectRatio) {
	mat4 projection = perspective(60.0f, inAspectRatio, 0.01f, 1000.0f);
	mat4 view = lookAt(vec3(0, 0, -5), vec3(0, 0, 0), vec3(0, 1, 0));
	mat4 model = quatToMat4(angleAxis(mRotation * DEG2RAD, vec3(0, 0, 1)));

	mShader->Bind();

	mVertexPositions->BindTo(mShader->GetAttribute("position"));
	mVertexNormals->BindTo(mShader->GetAttribute("normal"));
	mVertexTexCoords->BindTo(mShader->GetAttribute("texCoord"));

	Uniform<mat4>::Set(mShader->GetUniform("model"), model);
	Uniform<mat4>::Set(mShader->GetUniform("view"), view);
	Uniform<mat4>::Set(mShader->GetUniform("projection"), projection);

	Uniform<vec3>::Set(mShader->GetUniform("light"), vec3(0, 0, 1));

	mDisplayTexture->Set(mShader->GetUniform("tex0"), 0);

	Draw(*mIndexBuffer, DrawMode::Triangles);

	mDisplayTexture->UnSet(0);

	mVertexPositions->UnBindFrom(mShader->GetAttribute("position"));
	mVertexNormals->UnBindFrom(mShader->GetAttribute("normal"));
	mVertexTexCoords->UnBindFrom(mShader->GetAttribute("texCoord"));

	mShader->UnBind();
}

void Sample::Shutdown() {
	delete mShader;
	delete mDisplayTexture;
	delete mVertexPositions;
	delete mVertexNormals;
	delete mVertexTexCoords;
	delete mIndexBuffer;
}
