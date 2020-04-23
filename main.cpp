#include <iostream>
#include "portaudio.h"

#define SAMPLE_RATE 44100

static paTestData data;

int main()
{
	PaError *err;

	// Iniitalize
	if(Pa_Initialize() == paNoError)
	{
		printf("PortAudio operative!\n");		
	}
	else
	{
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
		return EXIT_FAILURE;
	}

	PaStream *stream;

	// Open an audio I/O stream
	err = Pa_OpenDefaultStream(
				&stream,
				0,			// no input channels
				2,			// stereo output
				paFloat32,		// 32-bit floating point output
				SAMPLE_RATE,
				256,			// Frames per buffer
				patestCallback,		// Callback function
				&data);			// Callback function pauload

	if(err != paNoError)
	{
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
	}

	// while key is down
		// record audio
	// save recording to file
	// stage audiofile
	// transfer audifile to shield
	
	// Terminate program
	if(Pa_Terminate() == paNoError)
	{
		printf("PortAudio terminated successfully!\n");
	}
	else
	{
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
