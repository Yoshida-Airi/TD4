#pragma once
#include"../Object/MapChip/MapChipField.h"
#include<vector>

class GamePlayScene
{
public:
	void Initialize();
	void Update();
	void Draw();

	/// <summary>
	/// ブロックの生成
	/// </summary>
	void GenerateBlocks();

private:

	//テクスチャ
	int MapBlockTexture;	//マップチップブロック用

	//マップチップ
	MapChipField* mapChipField_;
	
	

};

