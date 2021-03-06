#pragma once
class rVoiceoverInstance : public rSoundInstance
{
public:
	rVoiceoverInstance();
	rVoiceoverInstance(char * filename);
	rVoiceoverInstance(const char * filename);
	~rVoiceoverInstance();

	void Init();
	bool Play();
	bool Stop();

	bool AttachToMixer(ALLEGRO_MIXER * targetMixer);

	ALLEGRO_SAMPLE * GetSamplePtr();
	ALLEGRO_SAMPLE_INSTANCE * GetSampleInstancePtr();
	ALLEGRO_MIXER * GetMixerPtr();
	
	float * GetVoiceIntensityPtr();
	void UpdateVoice(int *buf, unsigned int samples, void *data);

	char name[256];

	float voiceIntensity = 0.0f;
private:

	ALLEGRO_SAMPLE * sample;
	ALLEGRO_SAMPLE_INSTANCE * sampleInstance;
	ALLEGRO_MIXER * mixer;
};

