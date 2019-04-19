#pragma once

#include <vector>
#include <Windows/Process.h>

#include "TH10Bot/Entity/Player.h"
#include "TH10Bot/Entity/Item.h"
#include "TH10Bot/Entity/Enemy.h"
#include "TH10Bot/Entity/Bullet.h"
#include "TH10Bot/Entity/Laser.h"

namespace th
{
	// https://github.com/binvec/TH10_DataReversing
	class TH10Reader
	{
	public:
		TH10Reader(Process& process);

		bool getPlayer(Player& player) noexcept;
		bool getItems(std::vector<Item>& items) noexcept;
		bool getEnemies(std::vector<Enemy>& enemies) noexcept;
		bool getBullets(std::vector<Bullet>& bullets) noexcept;
		bool getLasers(std::vector<Laser>& lasers) noexcept;

	private:
		template <typename T>
		inline T readMemory(uint_t baseAddress) noexcept
		{
			T data = T();
			ReadProcessMemory(m_process, reinterpret_cast<LPCVOID>(baseAddress), &data, sizeof(data), nullptr);
			return data;
		}

		inline void readMemoryBuffer(uint_t baseAddress, byte_t* buffer, uint_t size) noexcept
		{
			ReadProcessMemory(m_process, reinterpret_cast<LPCVOID>(baseAddress), buffer, size, nullptr);
		}

		template <typename T>
		inline T readBuffer(byte_t* buffer) noexcept
		{
			return *reinterpret_cast<T*>(buffer);
		}

		Process& m_process;
	};
}
