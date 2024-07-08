
#include <memory>

#include <Hazel.h>

#include "imgui.h"
#include "Hazel/Layer.h"
#include "Hazel/Events/ApplicationEvent.h"


#include "Platform/OpenGL/OpenGLShader.h"
#include "Platform/OpenGL/OpenGLTexture.h"

#include "glm/ext.hpp"

class HAZEL_API ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Hazel::Layer("ExampleLayer"),
		  m_CameraController(1280.0f / 720.0f)
	{
		//==================================================================
		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		m_VertexArray.reset(Hazel::VertexArray::Create());

		Hazel::Ref<Hazel::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Hazel::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		Hazel::BufferLayout layout = {
			{ Hazel::ShaderDataType::Float3, "a_Position" },
			{ Hazel::ShaderDataType::Float2, "a_TexCoord" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[6] = { 0, 1, 2, 2, 3, 0 };
		Hazel::Ref<Hazel::IndexBuffer> indexBuffer;
		indexBuffer.reset(Hazel::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);


		m_Shader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
		m_ChernoLogoTexture = Hazel::Texture2D::Create("assets/textures/ChernoLogo.png");

		std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_Shader)->Bind();
		std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_Shader)->UploadUniformInt("u_Texture", 0);
	}
	~ExampleLayer(){}

	void OnAttach()
	{

	}

	void OnDetach()
	{

	}

	void OnUpdate(Hazel::Timestep ts)
	{
		m_CameraController.OnUpdate(ts);


		Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Hazel::RenderCommand::Clear();


		Hazel::Renderer::BeginScene(m_CameraController.GetCamera());

		m_Shader->Bind();

		m_Texture->Bind();
		Hazel::Renderer::Submit(m_Shader, m_VertexArray);

		m_ChernoLogoTexture->Bind();
		Hazel::Renderer::Submit(m_Shader, m_VertexArray, glm::translate(glm::mat4(1.0f),glm::vec3(2.0f,0.0f,0.0f)));

		Hazel::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Text");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Hazel::Event& event)
	{
		m_CameraController.OnEvent(event);
	}
private:
	Hazel::ShaderLibrary m_ShaderLibrary;
	Hazel::Ref<Hazel::Shader> m_Shader;
	Hazel::Ref<Hazel::VertexArray> m_VertexArray;

	Hazel::Ref<Hazel::Shader> m_BlueShader;
	Hazel::Ref<Hazel::VertexArray> m_SquareVA;

	Hazel::Ref<Hazel::Texture2D> m_Texture;
	Hazel::Ref<Hazel::Texture2D> m_ChernoLogoTexture;
	

	Hazel::OrthographicCameraController m_CameraController;
};

class Sandbox : public Hazel::Application
{
public:

	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}