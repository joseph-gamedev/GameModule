#pragma once

#include "TestCanvas.h"
#include <iostream>
#include "Graphics.h"
#include "View.h"
#include "SDLImage.h"
#include "SDLAudioMusic.h"
#include "Application.h"
#include "SDLGraphics.h"

void TestCanvas::Initialize()
{
	m_img = nullptr;
	std::cout << "Initialize" << std::endl;
	m_application->GetView()->SetWindowFullScreen(false);
	auto font = m_application->GetGraphics()->CreateFont("E:\\GameFramework\\res\\FreeSans.ttf", 25);
	m_application->GetGraphics()->SetFont(font);
}

void TestCanvas::LoadContent()
{
	std::cout << "LoadContent" << std::endl;
	m_img = new SDLImage(nullptr, static_cast<SDLGraphics*>(m_application->GetGraphics()), "E:\\GameFramework\\res\\imageTest.jpg");
	m_img->Load();
	m_music = new SDLAudioMusic(nullptr, "E:\\GameFramework\\res\\TestMusic.wav");
	m_music->Load();
}

void TestCanvas::LoadComplete()
{
	std::cout << "LoadComplete" << std::endl;
	//m_music->Play(-1);
}

void TestCanvas::Update(float deltaTime)
{

}

void TestCanvas::Draw(Graphics* g)
{
	count++;
	count %= 10000;

	std::string text = std::to_string(count);

	g->ClearColor(255, 255, 255, 255);
	g->SetColor(255, 0, 0, 255);
	g->DrawRectangle(1, 1, 400, 400);
	//g->SetColor(0, 255, 0, 255);
	//g->DrawLine(1, 1, 100, 100);
	g->SetColor(0, 10, 0, 255);
	Vector2f arry[] = { Vector2f(15, 15), Vector2f(20, 50), Vector2f(200, 200) };
	g->DrawLines(arry,3);

	Vector2f size = m_application->GetGraphics()->GetWindowSize();

	Rectanglef r(10, 10, 200, 200);
	Rectanglef r1(0, 0, size.X, size.Y);
	g->DrawImage(m_img, NULL,&r1);
	g->DrawImage(m_img, NULL, &r);
	g->DrawText(text.c_str(), 50, 50, 50, 50);
	
}

void TestCanvas::Clear()
{
	std::cout << "Clear" << std::endl;
	if (m_img)
	{
		delete m_img;
		m_img = nullptr;
	}
}

void TestCanvas::OnKeyboardEvent(KeyboardKey key, InputEventType type, InputEventState state)
{
	
	if (key == KeyboardKey::KEY_D && /*type == InputEventType::INPUT_DOWN*/  state == InputEventState::INPUT_RELEASED)
	{
		std::cout << key << " :: pressed" << std::endl;
	}
}
void TestCanvas::OnMouseEvent(MouseButton button, InputEventType type, InputEventState state)
{
	std::cout << button << " :: pressed" << std::endl;
}

void TestCanvas::OnMouseMotion(int x, int y)
{
	std::cout << "x ::" << x <<" y" << y<< std::endl;
}