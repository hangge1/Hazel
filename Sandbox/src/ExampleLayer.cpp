
#include "ExampleLayer.h"

#include "imgui.h"

ExampleLayer::ExampleLayer()
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

	m_VertexArray = Hazel::VertexArray::Create();

	Hazel::Ref<Hazel::VertexBuffer> vertexBuffer = Hazel::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
	Hazel::BufferLayout layout = {
		{ Hazel::ShaderDataType::Float3, "a_Position" },
		{ Hazel::ShaderDataType::Float2, "a_TexCoord" }
	};
	vertexBuffer->SetLayout(layout);
	m_VertexArray->AddVertexBuffer(vertexBuffer);

	uint32_t indices[6] = { 0, 1, 2, 2, 3, 0 };
	Hazel::Ref<Hazel::IndexBuffer> indexBuffer = Hazel::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
	m_VertexArray->SetIndexBuffer(indexBuffer);


	auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

	m_Texture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
	m_ChernoLogoTexture = Hazel::Texture2D::Create("assets/textures/ChernoLogo.png");

	textureShader->Bind();
	textureShader->SetInt("u_Texture", 0);
}

void ExampleLayer::OnUpdate(Hazel::Timestep ts)

{
	m_CameraController.OnUpdate(ts);


	Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	Hazel::RenderCommand::Clear();


	Hazel::Renderer::BeginScene(m_CameraController.GetCamera());

	auto textureShader = m_ShaderLibrary.Get("Texture");
	m_Texture->Bind();
	Hazel::Renderer::Submit(textureShader, m_VertexArray);

	m_ChernoLogoTexture->Bind();
	Hazel::Renderer::Submit(textureShader, m_VertexArray, glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 0.0f, 0.0f)));

	Hazel::Renderer::EndScene();
}

void ExampleLayer::OnImGuiRender()
{
	ImGui::Begin("Text");
	ImGui::Text("Hello World");
	ImGui::End();
}

void ExampleLayer::OnEvent(Hazel::Event& event)
{
	m_CameraController.OnEvent(event);
}
