#pragma once

#include <thread>
#include <atomic>

namespace th
{
	class HookThread
	{
	public:
		HookThread();
		~HookThread();

		bool isDone() const;

	private:
		void hookProc();

		std::thread m_thread;
		std::atomic_bool m_done;
	};
}
