#pragma once
#include "util.h"
#include "constants.h"

enum class Action
{
	NO_ACTION = 1000,
	UNEXPECTED_ERROR = 1001,
	INSTALL_INTEGRATIONS = 1002,
	REMOVE_INTEGRATIONS = 1003,
	NOTHING_TO_INSTALL = 1004,
};

namespace IntegrationWizard
{

constexpr auto ALL_PLATFORMS = -1;
extern vector<wstring> alteredPlatforms;

enum class Architecture { x32, x64 };

struct PlatformInstallation
{
	struct Target {
		path path;
		Architecture architecture;
		string process;
		bool installed;
	};

	wstring name;
	vector<Target> targets;

	bool isInstalled() const {
		for (const auto& t : targets) if (t.installed) return true;
		return false;
	}
};

struct PlatformRegistry
{
	Architecture architecture;
	string process;
	string key;
	string value;
};

map<int, PlatformInstallation> getInstalledPlatforms();
void alterPlatform(Action action, int platformID, map<int, PlatformInstallation> platforms);

}
