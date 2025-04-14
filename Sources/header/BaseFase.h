#pragma once
#include<functional>

/*
 * Sakakura
 * フェーズの基底
 */
class BaseFase
{
public:
	inline BaseFase(){};
	inline ~BaseFase(){};

	/// <summary>
	/// 初期化
	/// </summary>
	inline virtual void Init() = 0;
	/// <summary>
	//// 処理のループ
	// </summary>
	void ProcLoop();
	/// <summary>
	/// 処理
	/// </summary>
	/// <returns>終了したか否か</returns>
	inline virtual bool Proc() = 0;
	/// <summary>
	/// 破棄
	/// </summary>
	inline virtual void Teardown() = 0;

	/// <summary>
	/// オブジェクトをセットするコールバック
	/// </summary>
	/// <param name="callbackSetObject"></param>
	inline void SetCallbackSetObject(std::function<void()> setObjectCallback) {
		SetObject = setObjectCallback;
	}
	/// <summary>
	/// オブジェクトを削除するコールバック
	/// </summary>
	/// <param name="callbackDeleteObject"></param>
	inline void SetCallbackDeleteObject(std::function<void()> deleteObjectCallback) {
		DeleteObject = deleteObjectCallback;
	}

protected:
	// オブジェクトをセットするコールバック
	std::function<void()> SetObject;
	// オブジェクトを破棄するコールバック
	std::function<void()> DeleteObject;

	/// <summary>
	/// 入力に応じた処理
	/// </summary>
	virtual void InputProc() = 0;
};