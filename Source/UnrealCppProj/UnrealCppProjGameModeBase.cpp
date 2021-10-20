// Copyright Epic Games, Inc. All Rights Reserved.


#include "UnrealCppProjGameModeBase.h"
#include "global.h"

// Blueprint'/Game/BP_CPlayer.BP_CPlayer'

AUnrealCppProjGameModeBase::AUnrealCppProjGameModeBase()
{
	CHelpers::GetClass<APawn>(&DefaultPawnClass, L"Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'");

}