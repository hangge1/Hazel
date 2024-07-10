#pragma once

#include "Hazel.h"
#include "Hazel/Core/Layer.h"

class  ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer();
	~ExampleLayer() = default;

	void OnAttach(){}

	void OnDetach(){}

	void OnUpdate(Hazel::Timestep ts);

	virtual void OnImGuiRender() override;

	void OnEvent(Hazel::Event& event);

private:
	Hazel::ShaderLibrary m_ShaderLibrary;
	Hazel::Ref<Hazel::VertexArray> m_VertexArray;

	Hazel::Ref<Hazel::Texture2D> m_Texture;
	Hazel::Ref<Hazel::Texture2D> m_ChernoLogoTexture;

	Hazel::OrthographicCameraController m_CameraController;
};