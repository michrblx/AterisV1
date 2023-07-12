#pragma once
#include "baseplayer.h"

class CUserCmd
{
public:
	virtual ~CUserCmd() { };
	int	command_number;
	int	tick_count;
	QAngle viewangles;
	float forwardmove;
	float sidemove;
	float upmove;
	int buttons;
	byte impulse;
	int weaponselect;
	int weaponsubtype;
	int random_seed;
	short mousedx;
	short mousedy;
	bool hasbeenpredicted;
};

enum
{
	MM_NONE = 0,
	MM_SAY,
	MM_SAY_TEAM,
};

struct HeadtrackMovementMode_t;

class IClientMode
{
public:
	virtual ~IClientMode() {}
	virtual void InitViewport() = 0;
	virtual void Init() = 0;
	virtual void VGui_Shutdown() = 0;
	virtual void Shutdown() = 0;
	virtual void Enable() = 0;
	virtual void Disable() = 0;
	virtual void Layout() = 0;
	virtual unsigned int *GetViewport() = 0;
	virtual void *GetViewportAnimationController() = 0;
	virtual void ProcessInput(bool bActive) = 0;
	virtual bool ShouldDrawDetailObjects() = 0;
	virtual bool ShouldDrawEntity(CBaseEntity *pEnt) = 0;
	virtual bool ShouldDrawLocalPlayer(CBasePlayer *pPlayer) = 0;
	virtual bool ShouldDrawParticles() = 0;
	virtual bool ShouldDrawFog(void) = 0;
	virtual void OverrideView(CViewSetup *pSetup) = 0;
	virtual int	KeyInput(int down, ButtonCode_t keynum, const char *pszCurrentBinding) = 0;
	virtual void StartMessageMode(int iMessageModeType) = 0;
	virtual unsigned int *GetMessagePanel() = 0;
	virtual void OverrideMouseInput(float *x, float *y) = 0;
	virtual bool CreateMove(float flInputSampleTime, CUserCmd *cmd) = 0;
	virtual void LevelInit(const char *newmap) = 0;
	virtual void LevelShutdown(void) = 0;
	virtual bool ShouldDrawViewModel(void) = 0;
	virtual bool ShouldDrawCrosshair(void) = 0;
	virtual void AdjustEngineViewport(int &x, int &y, int &width, int &height) = 0;
	virtual void PreRender(CViewSetup *pSetup) = 0;
	virtual void PostRender(void) = 0;
	virtual void PostRenderVGui() = 0;
	virtual void ActivateInGameVGuiContext(unsigned int *pPanel) = 0;
	virtual void DeactivateInGameVGuiContext() = 0;
	virtual float GetViewModelFOV(void) = 0;
	virtual bool CanRecordDemo(char *errorMsg, int length) const = 0;
	virtual void ComputeVguiResConditions(KeyValues *pkvConditions) = 0;
	virtual wchar_t *GetServerName() = 0;
	virtual void SetServerName(wchar_t *name) = 0;
	virtual wchar_t *GetMapName() = 0;
	virtual void SetMapName(wchar_t *name) = 0;
	virtual bool DoPostScreenSpaceEffects(const CViewSetup *pSetup) = 0;
	virtual void DisplayReplayMessage(const char *pLocalizeName, float flDuration, bool bUrgent, const char *pSound, bool bDlg) = 0;
	virtual void Update() = 0;
	virtual bool ShouldBlackoutAroundHUD() = 0;
	virtual HeadtrackMovementMode_t ShouldOverrideHeadtrackControl() = 0;
	virtual bool IsInfoPanelAllowed() = 0;
	virtual void InfoPanelDisplayed() = 0;
	virtual bool IsHTMLInfoPanelAllowed() = 0;
	virtual void OnDemoRecordStart(char const *pDemoBaseName) = 0;
	virtual void OnDemoRecordStop() = 0;
};