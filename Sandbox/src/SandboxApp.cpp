
#include <memory>

#include <imgui.h>
#include <glm/ext.hpp>

#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

#include "Hazel/Events/ApplicationEvent.h"

#include "Platform/OpenGL/OpenGLShader.h"
#include "Platform/OpenGL/OpenGLTexture.h"

#include "Sandbox2D.h"

class Sandbox : public Hazel::Application
{
public:

	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}