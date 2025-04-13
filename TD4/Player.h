#pragma once
#include "Vector2.h"
class Player
{
public:
	Player();

	void Initialize();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
private:
	Vector2 pos;
	Vector2 rad;
	float speed;
};

