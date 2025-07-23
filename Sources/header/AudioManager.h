#pragma once
#include "Const.h"

// âπÇÃçƒê∂
class AudioManager
{
public:

	static AudioManager& Instance()
	{
		static AudioManager instance;
		return instance;
	}

	AudioManager() = default;
	~AudioManager() = default;

	void Init();
	void DeleteSound();

	void PlayBGM(BGM bgm);
	void StopBGM(BGM bgm);
	void PlaySE(SE se);
	void StopSE(SE se);
	void SetVolume(float volume);
	float GetVolume() const;

private:
	void LoadSound();

	std::vector<int> _bgmHandles;
	std::vector<int> _seHandles;
};

