#include "GamePlayScene.h"
#include <cstdint>

void GamePlayScene::Initialize()
{
	//テクスチャ読み込み
	MapBlockTexture = Novice::LoadTexture("Block.png");

	//マップチップ
	mapChipField_ = new MapChipField;
	mapChipField_->LoadMapChipCsv("NoviceResources/CSV/stage1.csv");
}

void GamePlayScene::Update()
{
	
}

void GamePlayScene::Draw()
{
	//ブロックの生成
	GenerateBlocks();
}

void GamePlayScene::GenerateBlocks()
{
	const uint32_t kNumBlockHorizontal = 20;
	const uint32_t kNumBlockVirtical = 100;

	for (uint32_t i = 0; i < kNumBlockHorizontal;++i)
	{
		for (uint32_t j = 0; j < kNumBlockVirtical; ++j)
		if (mapChipField_->GetMapChipTypeByIndex(j, i) == MapChipType::kBlock)
		{
			Novice::DrawSpriteRect(j*64, i*64, 0, 0, 64, 64, MapBlockTexture, 1, 1, 0.0f, WHITE);
		}
	}
}
