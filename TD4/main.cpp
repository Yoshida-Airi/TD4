#include <Novice.h>
#include <memory>
#include "Player.h"
#include "InputHandler.h"
#include"Scene/GamePlayScene.h"

const char kWindowTitle[] = "TD4";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	std::unique_ptr<InputHandler> inputHandler = std::make_unique<InputHandler>();
	inputHandler->AssignMoveLeftCommand4PressKeyA();
	inputHandler->AssignMoveRightCommand4PressKeyD();
	inputHandler->AssignMoveUpCommand4PressKeyW();
	inputHandler->AssignMoveDownCommand4PressKeyS();

	ICommand* command_ = nullptr;
	std::unique_ptr<Player> player = std::make_unique<Player>();

	GamePlayScene* gamePlayScene = new GamePlayScene();
	gamePlayScene->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);


		///
		/// ↓更新処理ここから
		///

		command_ = inputHandler->HandleInput();

		if (command_) {
			command_->Exec(*player);
		}

		gamePlayScene->Update();

		///
		/// ↑更新処理ここまで
		///

		

		///
		/// ↓描画処理ここから
		///

		player->Draw();

		gamePlayScene->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

