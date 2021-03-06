#include "GSCredit.h"
#include "Camera.h"


GSCredit::GSCredit() {
}


GSCredit::~GSCredit()
{
}



void GSCredit::Init()
{
    auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
    auto texture = ResourceManagers::GetInstance()->GetTexture("BGCar5.tga");

    // background
    auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
    m_background = std::make_shared<Sprite2D>(model, shader, texture);
    m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
    m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

    // close button
    texture = ResourceManagers::GetInstance()->GetTexture("btn_prev.tga");
    std::shared_ptr<GameButton> buttonClose = std::make_shared<GameButton>(model, shader, texture);
    buttonClose->Set2DPosition(Globals::screenWidth - 50, 50);
    buttonClose->SetSize(50, 50);
    buttonClose->SetOnClick([]()
        {
            GameStateMachine::GetInstance()->PopState();
        });
    m_listButton.push_back(buttonClose);

    // Panel Credit
    texture = ResourceManagers::GetInstance()->GetTexture("EndGame.tga");
    m_panelCredits = std::make_shared<Sprite2D>(model, shader, texture);
    m_panelCredits->Set2DPosition(Globals::screenWidth / 2, 300);
    m_panelCredits->SetSize(450, 400);


   
    // credit text
    shader = ResourceManagers::GetInstance()->GetShader("TextShader");
    std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Niagaraphobia-Bro3.ttf");
    m_textGameName = std::make_shared< Text>(shader, font, "Nguyen Duc Minh - Hust", TextColor:: BLACK, 1.0f);
    m_textGameName1 = std::make_shared< Text>(shader, font, "Shooting Game", TextColor::BLACK, 1.0f);
    m_textGameName2 = std::make_shared< Text>(shader, font, "Use W-S-A-D to control player", TextColor::BLACK, 1.0f);
    m_textGameName3 = std::make_shared< Text>(shader, font, "If Player & Obstacle collision: Game Over", TextColor::BLACK, 1.0f);
    m_textGameName4 = std::make_shared< Text>(shader, font, "Collect Coins to get more score ", TextColor::BLACK, 1.0f);
    m_textGameName->Set2DPosition(Vector2(145, 210));
    m_textGameName1->Set2DPosition(Vector2(145, 240));
    m_textGameName2->Set2DPosition(Vector2(145, 270));
    m_textGameName3->Set2DPosition(Vector2(145, 300));
    m_textGameName4->Set2DPosition(Vector2(145, 330));

}

void GSCredit::Exit()
{
}


void GSCredit::Pause()
{
}

void GSCredit::Resume()
{
}


void GSCredit::HandleEvents()
{
}

void GSCredit::HandleKeyEvents(int key, bool bIsPressed)
{
   
}

void GSCredit::HandleTouchEvents(int x, int y, bool bIsPressed)
{
    for (auto button : m_listButton)
    {
        if (button->HandleTouchEvents(x, y, bIsPressed))
        {
            break;
        }
    }
}

void GSCredit::HandleMouseMoveEvents(int x, int y)
{
}

void GSCredit::Update(float deltaTime)
{
    m_background->Update(deltaTime);
    for (auto it : m_listButton)
    {
        it->Update(deltaTime);
    }
}

void GSCredit::Draw()
{
    m_background->Draw();
    m_panelCredits->Draw();
    m_textGameName->Draw();
    m_textGameName1->Draw();
    m_textGameName2->Draw();
    m_textGameName3->Draw();
    m_textGameName4->Draw();
    for (auto it : m_listButton)
    {
        it->Draw();
    }
}
