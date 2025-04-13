#include "Player.h"
#include "Novice.h"

Player::Player()
{
	Initialize();
}

void Player::Initialize()
{
	pos.x = 100.0f;
	pos.y = 100.0f;
	rad.x = 15.0f;
	rad.y = 15.0f;
	speed = 2.0f;
}

void Player::Update()
{
}

void Player::Draw()
{
	Novice::DrawEllipse((int)pos.x, (int)pos.y, (int)rad.x, (int)rad.y, 0.0f, RED, kFillModeSolid);
}

void Player::MoveRight()
{
	pos.x += speed;
}

void Player::MoveLeft()
{
	pos.x -= speed;
}

void Player::MoveUp()
{
	pos.y -= speed;
}

void Player::MoveDown()
{
	pos.y += speed;
}
