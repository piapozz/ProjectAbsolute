#include "../header/AudioManager.h"

void AudioManager::Init()
{
	LoadSound();
}

void AudioManager::LoadSound()
{
	// BGMÇÃì«Ç›çûÇ›
	_bgmHandles.resize((int)BGM::MAX);
	for (int i = 0; i < (int)BGM::MAX; ++i)
	{
		_bgmHandles[i] = LoadSoundMem(BGMFilePath[i].c_str());
	}
	// SEÇÃì«Ç›çûÇ›
	_seHandles.resize((int)SE::MAX);
	for (int i = 0; i < (int)SE::MAX; ++i)
	{
		_seHandles[i] = LoadSoundMem(SEFilePath[i].c_str());
	}
}

void AudioManager::PlayBGM(BGM bgm)
{
	if (bgm < BGM::INVALID || bgm >= BGM::MAX) return;
	PlaySoundMem(_bgmHandles[(int)bgm], DX_PLAYTYPE_LOOP);
}

void AudioManager::StopBGM(BGM bgm)
{
	if (bgm < BGM::INVALID || bgm >= BGM::MAX) return;
	StopSoundMem(_bgmHandles[(int)bgm]);
}

void AudioManager::PlaySE(SE se)
{
	if (se < SE::INVALID || se >= SE::MAX) return;
	PlaySoundMem(_seHandles[(int)se], DX_PLAYTYPE_BACK);
}

void AudioManager::StopSE(SE se)
{
	if (se < SE::INVALID || se >= SE::MAX) return;
	StopSoundMem(_seHandles[(int)se]);
}

void AudioManager::SetVolume(float volume)
{
	for (int i = 0; i < (int)BGM::MAX; ++i)
	{
		SetVolumeSoundMem(volume, _bgmHandles[i]);
	}
	for (int i = 0; i < (int)SE::MAX; ++i)
	{
		SetVolumeSoundMem(volume, _seHandles[i]);
	}
}

float AudioManager::GetVolume() const
{
	if (_bgmHandles.empty()) return 0.0f;
	int volume = GetVolumeSoundMem(_bgmHandles[0]);
	return static_cast<float>(volume);
}

void AudioManager::DeleteSound()
{
	for (int handle : _bgmHandles)
	{
		DeleteSoundMem(handle);
	}
	_bgmHandles.clear();
	for (int handle : _seHandles)
	{
		DeleteSoundMem(handle);
	}
	_seHandles.clear();
}
