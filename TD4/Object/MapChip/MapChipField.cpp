#include "MapChipField.h"
#include<assert.h>


void MapChipField::ResetMapChipData()
{
	//マップチップデータのリセット
	mapChipData_.data.clear();
	mapChipData_.data.resize(kNumBlockVirtical);
	for (std::vector<MapChipType>& mapChipDataline : mapChipData_.data)
	{
		mapChipDataline.resize(kNumBlockHorizontal);
	}
}

void MapChipField::LoadMapChipCsv(const std::string& filePath)
{
	//マップチップデータをリセット
	ResetMapChipData();

	//ファイルを開く
	std::ifstream file;
	file.open(filePath);
	assert(file.is_open());

	//マップチップCSV
	std::stringstream mapChipCsv;
	//ファイルの内容を文字ストリームにコピー
	mapChipCsv << file.rdbuf();
	//ファイルを閉じる
	file.close();
	//CSVからマップチップデータを読み込む
	for (uint32_t i = 0; i < kNumBlockVirtical; ++i)
	{
		std::string line;
		getline(mapChipCsv, line);

		//1行文の文字列を文字ストリームに変換して解析しやすくする
		std::istringstream line_stream(line);

		for (uint32_t j = 0; j < kNumBlockHorizontal; ++j)
		{
			std::string word;
			getline(line_stream, word, ',');

			if (mapChipTable.contains(word))
			{
				mapChipData_.data[i][j] = mapChipTable[word];
			}
		}
	}

}

MapChipType MapChipField::GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex)
{
	//範囲外の場合空白チップを返す
	if (xIndex < 0 || kNumBlockHorizontal - 1 < xIndex)
	{
		return MapChipType::kBlank;
	}
	if (yIndex < 0 || kNumBlockVirtical - 1 < yIndex)
	{
		return MapChipType::kBlank;
	}

	return mapChipData_.data[yIndex][xIndex];
}

Vector3 MapChipField::GetMapChipPositionByIndex(uint32_t xIndex, uint32_t yIndex)
{
	return Vector3(kBlockWidth * xIndex, kBlockHeight * (kNumBlockVirtical - 1 - yIndex), 0);
}
