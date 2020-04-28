#include <iostream>
#include "portaudio.h"

#define SAMPLE_RATE 44100

#define paErrChk(ret) { paAssert((ret), __FILE__, __LINE__); }
inline void paAssert(PaError *err, const char *file, int line, bool abort=true)
{
	if(err != paNoError)
	{
		fprintf(stderr, "PAassert: %s %s %d\n", Pa_GetErrorText(err), file, line);
		if (abort) exit(err);
	}
}

typedef int PaStreamCallback(
			const void *input,
			void *output,
			unsigned long frameCount,
			const PaStreamCallbackTimeInfo *timeInfo,
			PaStreamCallbackFlags statusFlags,
			void *userData);


static paTestData data;
PaStream *stream;

int main()
{
/*	PaError *err;

	// Initialize
	if(Pa_Initialize() == paNoError)
	{
		printf("PortAudio operative!\n");		
	}
	else
	{
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
		return EXIT_FAILURE;
	}
*/
	paAssert(Pa_Initialize());
	printf("PortAudio operative!\n");

	// Open an audio I/O stream
/*	err = Pa_OpenDefaultStream(
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
*/

	paAssert(Pa_OpenDefaultStream(
				&stream,
				0,			// no input channels
				2,			// stereo output
				paFloat32,		// 32-bit floating point output
				SAMPLE_RATE,
				256,			// Frames per buffer
				patestCallback,		// Callback function
				&data);			// Callback function pauload
	printf("Stream opened!\n");

	// while key is down
		// record audio
	// save recording to file
	// stage audiofile
	// transfer audifile to shield
	
	// Terminate program
/*	if(Pa_Terminate() == paNoError)
	{
		printf("PortAudio terminated successfully!\n");
	}
	else
	{
		printf("PortAudio error: %s\n", Pa_GetErrorText(err));
		return EXIT_FAILURE;
	}
*/
	paAssert(Pa_Terminate());
	printf("PortAudio terminated successfully!\n");

	return EXIT_SUCCESS;
}
