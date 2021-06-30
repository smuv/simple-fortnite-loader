DWORD GetGamePID() {
	HWND hwGame = FindWindowA(0, "Fortnite");
	if (!hwGame) return 0;
	DWORD ret = 0;
	GetWindowThreadProcessId(hwGame, &ret);
	return ret;
}

DWORD processID;
HWND hwnd = NULL;

void injection()
{
	while (hwnd == NULL)
	{
		hwnd = FindWindowA(0, _xor_("Fortnite").c_str());
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		system("color B");
		system("cls");
		printf("\n    [>] Waiting for Fortnite!n\n");
		DWORD gamePID = GetGamePID();
		if (!gamePID) {
			printf("    [>] Fortnite Not Found!\n\n");
		}
		else
		{
			printf("    [>] Fortnite Found!\n\n");
		}
		Sleep(300);  //slowed it down a bit 4u
	}
	GetWindowThreadProcessId(hwnd, &processID);

	system("pause");
}

void checkprivileges() { /// check admin

	bool IsRunningAsAdmin = false;

	BOOL fRet = FALSE;
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
			fRet = Elevation.TokenIsElevated;
		}
	}
	if (hToken) {
		CloseHandle(hToken);
	}
	IsRunningAsAdmin = fRet;

	if (!IsRunningAsAdmin) {

		int msgboxID = MessageBoxA(
			NULL,
			(LPCSTR)"please, run as admin.",
			(LPCSTR)"please, run as admin.",
			MB_OK
		);
		exit(-1);


	}
}

std::string RandomString(const size_t length)
{
	std::string r;
	static const char bet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxyzZ1234567890" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}

std::string path()  /// path of exe
{
	char shitter[_MAX_PATH];
	GetModuleFileNameA(NULL, shitter, _MAX_PATH);
	return std::string(shitter);
}
