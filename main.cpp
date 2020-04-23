#include <iostream>
#include "portaudio.h"

int main()
{
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
