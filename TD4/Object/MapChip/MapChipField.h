#pragma once
#include <cstdint>
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include<sstream>
#include<Novice.h>
#include<3d/Model.h>


//マップチップの種類
enum class MapChipType
{
	kBlank,	//空白
	kBlock, //ブロック
};

namespace
{
	//マップチップ番号対照表
	std::map<std::string, MapChipType>mapChipTable =
	{
		{"0",MapChipType::kBlank},
		{"1",MapChipType::kBlock},
	};
}

struct MapChipData
{
	std::vector<std::vector<MapChipType>> data;
};

struct Vector3
{
	float x;
	float y;
	float z;
};

/// <summary>
/// マップチップ
/// </summary>
class MapChipField
{
public:

	/// <summary>
	/// マップチップデータのリセット
	/// </summary>
	void ResetMapChipData();

	/// <summary>
	/// CSVファイルの読み込み
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void LoadMapChipCsv(const std::string& filePath);

	/// <summary>
	/// マップチップ種別の取得
	/// </summary>
	/// <param name="xIndex">横の番号</param>
	/// <param name="yIndex">縦の番号</param>
	/// <returns>マップチップの種類</returns>
	MapChipType GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex);

	/// <summary>
	/// マップチップ座標の取得
	/// </summary>
	/// <param name="xIndex">横の番号</param>
	/// <param name="yIndex">縦の番号</param>
	/// <returns>座標</returns>
	Vector3 GetMapChipPositionByIndex(uint32_t xIndex, uint32_t yIndex);

	/*****ゲッター*****/
	uint32_t GetNumBlockVirtical() { return kNumBlockVirtical; }
	uint32_t GetNumBlockHorizontal() { return kNumBlockHorizontal; }


private:

	//ブロックサイズ
	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeight = 1.0f;

	//ブロックの総数
	static inline const uint32_t kNumBlockVirtical = 20;
	static inline const uint32_t kNumBlockHorizontal = 100;

	//マップチップデータ
	MapChipData mapChipData_;

};

