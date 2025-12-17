#pragma once
#include "main.h"
enum class TimerTypes
{
	Continuous,
	CallOnceAfterInterval,
};

class Timer
{
private:
	typedef void (*p_td_callback)();
	p_td_callback p_callback{};
	std::function<void()> p_fcallback{};
	std::chrono::steady_clock::time_point p_start{};
	std::chrono::steady_clock::time_point p_end{};
	bool p_isForceExpired{};
	DWORD p_interval{};
	TimerTypes p_timertype{};
	void pExpire()
	{
		isExpired = true;
		isThreadRunning = false;
	}
	void Tick()
	{
		while (!p_isForceExpired)
		{
			isThreadRunning = true;
			Sleep(p_interval);

			p_fcallback();

			if (p_timertype == TimerTypes::CallOnceAfterInterval)
			{
				pExpire();
				return;
			}
		}
		pExpire();
	}

public:
	bool isExpired;
	bool isThreadRunning;
	/*Creates a timer without any callbacks or threads*/

	void ChangeInterval(DWORD Interval)
	{
		p_interval = Interval;
	}

	Timer() {
		isExpired = false;
		isThreadRunning = false;
		p_start = std::chrono::high_resolution_clock::now();
		p_isForceExpired = false;
	}


	/*TimerTypes include continuous and call once after interval (this creates a thread waits x amount of time and then executes) Asynchronously*/
	template <class F>
	Timer(F&& Callback, DWORD Interval, TimerTypes TimerType = TimerTypes::Continuous)
	{
		p_isForceExpired = false;
		p_fcallback = Callback;
		p_timertype = TimerType;
		p_interval = Interval;
		p_start = std::chrono::high_resolution_clock::now();
		std::thread t_thread(&Timer::Tick, this);
		t_thread.detach();
	}

	/*This only affects timers that are not doing interval callbacks*/
	void Reset() {
		p_start = std::chrono::high_resolution_clock::now();
		p_isForceExpired = false;
	}

	/*This sets the isExpired flag to true no matter what, it also kills the interval timer thread*/
	void ForceExpire()
	{
		p_end = std::chrono::high_resolution_clock::now();
		p_isForceExpired = true;
		isExpired = true;
	}

	/*Returns the number of elapsed milliseconds since creation or since last Reset()*/
	long long Elapsed()
	{
		if (p_isForceExpired)
		{
			return std::chrono::duration_cast<std::chrono::milliseconds>(p_end - p_start).count();
		}
		else
		{
			auto current = std::chrono::high_resolution_clock::now();
			return std::chrono::duration_cast<std::chrono::milliseconds>(current - p_start).count();
		}
	}
	float fElapsed()
	{
		if (p_isForceExpired)
		{
			std::chrono::duration<float> elapsedTime = p_end - p_start;
			return elapsedTime.count();
		}
		else
		{
			auto current = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> elapsedTime = current - p_start;
			return elapsedTime.count();
		}
	}

	std::string minimumDigitString(int minimum_digits, const std::string& str_in)
	{
		if ((int)str_in.length() < minimum_digits)
			return std::string(minimum_digits - str_in.length(), '0') + str_in;
		else
			return str_in;
	}

	std::string StrTime()
	{
		std::stringstream ss;
		double hours = static_cast<double>((((Elapsed() / 1000) / 60) / 60) % 59);
		double minutes = static_cast<double>((((Elapsed() / 1000) / 60)) % 59);
		double seconds = static_cast<double>((((Elapsed() / 1000))) % 59);
		std::string sHours = minimumDigitString(2, std::to_string((int)floor(hours)));
		std::string sMinutes = minimumDigitString(2, std::to_string((int)floor(minutes)));
		std::string sSeconds = minimumDigitString(2, std::to_string((int)floor(seconds)));

		ss << sHours << ":" << sMinutes << ":" << sSeconds << std::endl;
		return ss.str();
	}

	/*Returns if the duration you provide has been passed since creation or the last Reset()*/
	bool Expired(long long duration)
	{
		bool expired = (Elapsed() >= duration || p_isForceExpired);
		return expired;
	}
};