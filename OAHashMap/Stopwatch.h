//==========================================================
//  Project   : Stopwatch
//  Descr.    : A utility high-resolution stopwatch class
//  
//  Ver   Date/author   Description
//----------------------------------------------------------
//  1.0   061027/TFJ    Initial revision
//==========================================================

#pragma once

#include <windows.h>

//---------------------------------------
// Class  : stopwatch
//---------------------------------------
class Stopwatch
{
public:
	enum Resolution
	{
		NANOSECONDS,
		MICROSECONDS,
		MILLISECONDS,
		SECONDS
	};

	Stopwatch(void);
	void start(void);
	void stop(void);
	size_t getDuration(Resolution res = MICROSECONDS) const;

	static bool raisePri()
	{
		// Increase resource allocation to program to allow
		// as-near-real-time behaviour as possible
		// TO USE:
		// Open the Administrative Tools menu under the "Programs" item in the Start Menu.
		// Choose "Local Security Policy" in the Administrative Tools menu.
		// In the left-pane, choose "User Rights Assignment".
		// In the pane to the right, double-click "Increase scheduling priority".
		// Click Add to add users or groups to the list of entities that have this right.

		oldProcessClass= GetPriorityClass(GetCurrentProcess());
		oldThreadPri = GetThreadPriority(GetCurrentThread());
		SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
		SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
		return(GetPriorityClass(GetCurrentProcess()) == REALTIME_PRIORITY_CLASS);
	}

	static void resetPri()
	{
		// Reset process/thread priority
		SetPriorityClass(GetCurrentProcess(), oldProcessClass);
		SetThreadPriority(GetCurrentThread(), oldThreadPri);
	}

private:
	static DWORD oldProcessClass;
	static DWORD oldThreadPri;
	LARGE_INTEGER startTime;
	LARGE_INTEGER stopTime;

	LONGLONG frequency;
	LONGLONG correction;
};

DWORD Stopwatch::oldProcessClass = 0;
DWORD Stopwatch::oldThreadPri = 0;

//---------------------------------------
// Constructor
//---------------------------------------
inline Stopwatch::Stopwatch(void)
{
	LARGE_INTEGER freq;

	QueryPerformanceFrequency(&freq);
	frequency = freq.QuadPart;

	// Calibration
	raisePri();
	start();
	stop();
	resetPri();
	correction = stopTime.QuadPart-startTime.QuadPart;
}

//---------------------------------------
// start()
//---------------------------------------
inline void Stopwatch::start(void)
{
	// Ensure we will not be interrupted by any other thread for a while
	Sleep(0);
	QueryPerformanceCounter(&startTime);
}

//---------------------------------------
// stop()
//---------------------------------------
inline void Stopwatch::stop(void)
{
	QueryPerformanceCounter(&stopTime);
}



//---------------------------------------
// getDuration()
//---------------------------------------
inline size_t Stopwatch::getDuration(Resolution res) const
{
  double time = (double)(stopTime.QuadPart-startTime.QuadPart-correction)/frequency;
  switch(res)
  {
  case NANOSECONDS :
    return (size_t)(time*1000000000.0+0.5);  
    break;
  
  case MICROSECONDS:
    return (size_t)(time*1000000.0+0.5);     
    break;

  case MILLISECONDS:
    return (size_t)(time*1000.0+0.5);        
    break;
  
  case SECONDS:
    return (size_t)(time+0.5);               
    break;
  
  default:       
    return (size_t)(time*1000000.0+0.5);               
    break;
  }
}
